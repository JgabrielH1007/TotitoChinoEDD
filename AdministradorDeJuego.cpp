#include "Jugador.h"
#include "PowerUp.h"
#include "UnionFuturo.h"
#include "AQueCosto.h"
#include "Bloqueo.h"
#include "DobleLinea.h"
#include "Escurridizo.h"
#include "LlaveSecreta.h"
#include "NuevasTierras.h"
#include "Pase.h"
#include "TrampaSecreta.h"
#include "ListaJugadores.h"
#include "PilaPowerUps.h"
#include "AdministradorDeJuego.h"
#include "AdministradorDeTablero.h"
#include <limits>
#include <iostream>

AdministradorDeJuego::AdministradorDeJuego() {
    listaJugadores = ListaJugadores();
    administradorDeTablero = AdministradorDeTablero();
}

void AdministradorDeJuego::iniciarJuego() {
    recolectarInfomacionJugadores();
    registrarTamanioTablero();
    Jugar();
    mostrarGanador();

}

void AdministradorDeJuego::registrarTamanioTablero() {
    int filas, columnas;
    do {
        std::cout << "Ingrese el numero de filas (minimo 2): ";
        std::cin >> filas;
        std::cout<<"Ingrese el numero de columnas (minimo 2): ";
        std::cin >> columnas;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Entrada inválida. Ingrese un número entero.\n";
            continue; 
        }
        if (filas < 2  || columnas < 2) {
            std::cout << "El número mínimo de filas y columnas es 2." << std::endl;
        }
    } while (filas < 2 || columnas < 2);        
    administradorDeTablero.construirTablero(filas, columnas);
    
}

void AdministradorDeJuego::recolectarInfomacionJugadores() {
    int numJugadores;
    do {
        std::cout << "Ingrese el número de jugadores: ";
        std::cin >> numJugadores;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Entrada inválida. Ingrese un número entero.\n";
            continue; 
        }
        if (numJugadores < 2) {
            std::cout << "Debe haber al menos 2 jugadores." << std::endl;
        } else if (numJugadores > 4) {
            std::cout << "El número máximo de jugadores es 4." << std::endl;
        }
    
    } while (numJugadores < 2);
    
    std::string caracter;
    for (int i = 0; i < numJugadores; ++i) {
        std::cout << "Ingrese el caracter del jugador " << (i + 1) << ": ";
        std::cin >> caracter;
        guardarJugadores(caracter);
    }
}

void AdministradorDeJuego::guardarJugadores(std::string caracter) {
    Jugador* jugador = new Jugador();
    jugador->setCaracter(caracter);
    listaJugadores.agregarJugador(jugador); 
}


Jugador* AdministradorDeJuego::obtenerJugadorEnTurno() const {
    if (listaJugadores.estaVacia()) {
        std::cout << "No hay jugadores en la lista." << std::endl;
        return nullptr;
    }

    NodoJugadores* actual = listaJugadores.getInicio();
    std::cout << "Jugador en turno: " << actual->getJugador()->getCaracter() << std::endl;
    return actual->getJugador();
}

void AdministradorDeJuego::Jugar() {
    bool finDelJuego = false;
    NodoJugadores* jugadorActual = listaJugadores.getInicio();
    while (!finDelJuego) {
        
        Jugador* jugadorEnTurno = jugadorActual->getJugador();
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Turno del jugador: " << jugadorEnTurno->getCaracter() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Power Ups disponibles: ";
        jugadorEnTurno->getPilaPowerUps().imprimir();
        std::cout << std::endl;
        int opcion = menuJuego();
        int filaInicial, columnaInicial, filaFinal, columnaFinal;
        if (opcion == 1) {
            do{
            std::cout << "Ingrese coordenada de fila inicial: ";
            std::cin >> filaInicial;
            std::cout<<std::endl;
            std::cout << "Ingrese coordenada de columna inicial: ";
            std::cin >> columnaInicial;
            std::cout<<std::endl;
            std::cout << "Ingrese coordenada de fila final: ";
            std::cin >> filaFinal;
            std::cout<<std::endl;
            std::cout << "Ingrese coordenada de columna final: ";
            std::cin >> columnaFinal;
            std::cout<<std::endl;
            if (administradorDeTablero.esMovimientoValido(filaInicial, columnaInicial, filaFinal, columnaFinal)) {
                administradorDeTablero.agregarLinea(filaInicial, columnaInicial, filaFinal, columnaFinal, jugadorEnTurno, nullptr);
                if (administradorDeTablero.validarCasillaCerrada(std::min(filaInicial, filaFinal), std::min(columnaInicial, columnaFinal), jugadorEnTurno)) {
                    std::cout << "¡Has cerrado una casilla y ganado 5 punto!" << std::endl;
                        jugadorEnTurno->setPuntos(jugadorEnTurno->getPuntos() + 5);
                        jugadorEnTurno->setCasillasGanadas(jugadorEnTurno->getCasillasGanadas() + 1);
                }else {
                    std::cout << "No se cerró ninguna casilla con este movimiento." << std::endl;
                }
            } else {
                std::cout << "Movimiento no válido. Intente de nuevo." << std::endl;
            }
            } while(administradorDeTablero.esMovimientoValido(filaInicial, columnaInicial, filaFinal, columnaFinal));
            jugadorActual = jugadorActual->getSiguiente();
            administradorDeTablero.mostrarTableros();
        }
        else if(opcion == 2){
            if(jugadorEnTurno->getPilaPowerUps().isEmpty()){
                std::cout << "No tienes power ups disponibles" << std::endl;
                continue;
            }
        
            PowerUp* powerUp = jugadorEnTurno->getPilaPowerUps().desapilar();
            std::string nombrePowerUp = powerUp->getNombre();
        
            if(nombrePowerUp == "AC" || nombrePowerUp == "BL" || nombrePowerUp == "TS" || nombrePowerUp == "UF"){
                bool movimientoValido = false;
        
                while(!movimientoValido){
                    std::cout << "Ingrese coordenada de fila inicial: ";
                    std::cin >> filaInicial;
                    std::cout << "Ingrese coordenada de columna inicial: ";
                    std::cin >> columnaInicial;
                    std::cout << "Ingrese coordenada de fila final: ";
                    std::cin >> filaFinal;
                    std::cout << "Ingrese coordenada de columna final: ";
                    std::cin >> columnaFinal;
        
                    if(administradorDeTablero.esMovimientoValido(filaInicial, columnaInicial, filaFinal, columnaFinal)){
                        administradorDeTablero.agregarLinea(filaInicial, columnaInicial, filaFinal, columnaFinal, jugadorEnTurno, powerUp);
        
                        if(administradorDeTablero.validarCasillaCerrada(
                            std::min(filaInicial, filaFinal), std::min(columnaInicial, columnaFinal), jugadorEnTurno)) 
                        {
                            std::cout << "¡Has cerrado una casilla y ganado 5 puntos!" << std::endl;
                            jugadorEnTurno->setPuntos(jugadorEnTurno->getPuntos() + 5);
                            jugadorEnTurno->setCasillasGanadas(jugadorEnTurno->getCasillasGanadas() + 1);
                        } else {
                            std::cout << "No se cerró ninguna casilla con este movimiento." << std::endl;
                        }
        
                        administradorDeTablero.mostrarTableros();
                        movimientoValido = true; // rompe el ciclo
                    } else {
                        std::cout << "Movimiento no válido. Intente de nuevo." << std::endl;
                    }
                }
        
            } else if(nombrePowerUp == "LS"){
            } else if(nombrePowerUp == "NT"){
            } else if(nombrePowerUp == "DL"){
            } else if(nombrePowerUp == "ES"){
            } else if(nombrePowerUp == "PS"){
            }
        
            jugadorActual = jugadorActual->getSiguiente();
        }
        
        else if(opcion == 3){
            administradorDeTablero.mostrarTableroClarividente();
        }
        finDelJuego = administradorDeTablero.esTableroFinalizado();
    }
}

int AdministradorDeJuego::menuJuego() const{
    int opcion;
    do{
    std::cout << "----- Menú de Opciones -----" << std::endl;
    std::cout << "1. ingresar linea..." << std::endl;
    std::cout << "2. Utilizar power up..." << std::endl;
    std::cout << "3. Mostrar tablero clarividente..." << std::endl;
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    } while(opcion<1 || opcion>3);
    return opcion;
}
    
void AdministradorDeJuego::mostrarGanador() const {
    if (listaJugadores.estaVacia()) {
        std::cout << "No hay jugadores en la lista." << std::endl;
        return;
    }

    NodoJugadores* actual = listaJugadores.getInicio();
    Jugador* ganador = actual->getJugador();
    Jugador* posibleEmpate = nullptr;
    bool hayEmpate = false;

    while (actual != nullptr) {
        Jugador* jugador = actual->getJugador();
        if (jugador->getPuntos() > ganador->getPuntos()) {
            ganador = jugador;
            posibleEmpate = nullptr;
            hayEmpate = false;
        } else if (jugador->getPuntos() == ganador->getPuntos() && jugador != ganador) {
            posibleEmpate = jugador;
            hayEmpate = true;
        }
        actual = actual->getSiguiente();
    }

    if (!hayEmpate) {
        std::cout << "El ganador es el jugador con caracter '" << ganador->getCaracter() 
                  << "' con " << ganador->getPuntos() << " puntos y " 
                  << ganador->getCasillasGanadas() << " casillas ganadas." << std::endl;
    } else {
        std::cout << "Hay un empate entre los siguientes jugadores:" << std::endl;
        std::cout << "Jugador con caracter '" << ganador->getCaracter() 
                  << "' con " << ganador->getPuntos() << " puntos y " 
                  << ganador->getCasillasGanadas() << " casillas ganadas." << std::endl;
        std::cout << "Jugador con caracter '" << posibleEmpate->getCaracter() 
                  << "' con " << posibleEmpate->getPuntos() << " puntos y " 
                  << posibleEmpate->getCasillasGanadas() << " casillas ganadas." << std::endl;
    }
}


