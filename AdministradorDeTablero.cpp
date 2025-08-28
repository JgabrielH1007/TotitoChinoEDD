#include "AdministradorDeTablero.h"
#include "Jugador.h"
#include "PowerUp.h"
#include "AQueCosto.h"
#include "Bloqueo.h"
#include "DobleLinea.h"
#include "Escurridizo.h"
#include "LlaveSecreta.h"
#include "NuevasTierras.h"
#include "Pase.h"
#include "TrampaSecreta.h"
#include "UnionFuturo.h"
#include "ListaLineas.h"
#include "Linea.h"
#include "Punto.h"
#include "Tablero.h"
#include <cmath>
#include <iostream>
#include <iomanip>
namespace Colores {
    const std::string RESET    = "\033[0m";
    const std::string ROJO     = "\033[31m";  // Trampa
    const std::string AMARILLO = "\033[33m";  // Bloqueo
    const std::string VERDE    = "\033[32m";  // Unión futuro
    const std::string AZUL     = "\033[34m";  // A qué costo
    const std::string BLANCO   = "\033[37m";  // Normal
}

    AdministradorDeTablero::AdministradorDeTablero() {
        matrizCasillaInterior = nullptr;
        matrizPuntos = nullptr;
        listaLineas = new ListaLineas(); 
    }
    AdministradorDeTablero::~AdministradorDeTablero() {
        
    }

    void AdministradorDeTablero::construirTablero(int filas, int columnas) {
        if (matrizPuntos) delete matrizPuntos;
        if (matrizCasillaInterior) delete matrizCasillaInterior;

        matrizPuntos = new Tablero<Punto>(filas, columnas);
        matrizCasillaInterior = new Tablero<std::string>(filas - 1, columnas - 1);

        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                Punto* punto = new Punto(i, j);
                matrizPuntos->agregarElemento(i, j, punto);
            }
        }

        for (int i = 0; i < filas - 1; ++i) {
            for (int j = 0; j < columnas - 1; ++j) {
                matrizCasillaInterior->agregarElemento(i, j, nullptr);
                
            }
        }
        ubicarPowerUp(filas-1, columnas-1);
        
    }

void AdministradorDeTablero::ubicarPowerUp(int fila, int columna) {
    int cantidadPowerUps = (fila-1) * (columna-1) * 0.3;

    for (int i = 0; i < cantidadPowerUps; ++i) {
        int filaRandom = rand() % (fila - 1);
        int columnaRandom = rand() % (columna - 1);
        if (matrizCasillaInterior->obtenerElemento(filaRandom, columnaRandom) == nullptr) {
            int tipoPowerUp = rand() % 9;
            PowerUp* powerUp = nullptr;

            switch (tipoPowerUp) {
                case 0:
                    powerUp = new AQueCosto();
                    break;
                case 1:
                    powerUp = new Bloqueo();
                    break;
                case 2:
                    powerUp = new DobleLinea();
                    break;
                case 3:
                    powerUp = new Escurridizo();
                    break;
                case 4:
                    powerUp = new LlaveSecreta();
                    break;
                case 5:
                    powerUp = new NuevasTierras();
                    break;
                case 6:
                    powerUp = new Pase();
                    break;
                case 7:
                    powerUp = new TrampaSecreta();
                    break;
                case 8:
                    powerUp = new UnionFuturo();
                    break;
            }
            agregarPowerUp(filaRandom, columnaRandom, powerUp);
        } else {
            --i; 
        }
    }
   
}

void AdministradorDeTablero::agregarPowerUp(int fila, int columna, PowerUp* powerUp) {
    std::string* valor = new std::string(powerUp->getNombre());
    matrizCasillaInterior->agregarElemento(fila, columna, valor);
}

PowerUp* AdministradorDeTablero::obtenerPowerUp(int fila, int columna) const {
    std::string* nombre = matrizCasillaInterior->obtenerElemento(fila, columna);
    if (nombre == nullptr) {
        return nullptr;
    }
    if (*nombre == "AC") {
        return new AQueCosto();
    } else if (*nombre == "BL") {
        return new Bloqueo();
    } else if (*nombre == "DL") {
        return new DobleLinea();
    } else if (*nombre == "ES") {
        return new Escurridizo();
    } else if (*nombre == "LL") {
        return new LlaveSecreta();
    } else if (*nombre == "NT") {
        return new NuevasTierras();
    } else if (*nombre == "PS") {
        return new Pase();
    } else if (*nombre == "TS") {
        return new TrampaSecreta();
    } else if (*nombre == "UF") {
        return new UnionFuturo();
    }
    return nullptr; 
}


void AdministradorDeTablero::eliminarJugador(int fila, int columna) {
    matrizCasillaInterior->eliminarElemento(fila, columna);
}

void AdministradorDeTablero::eliminarPowerUp(int fila, int columna) {
    matrizCasillaInterior->eliminarElemento(fila, columna);
}

bool AdministradorDeTablero::esMovimientoValido(int filaInicial, int columnaInicial,
    int filaFinal, int columnaFinal) const {
    if (filaInicial < 0 || filaInicial >= matrizPuntos->getFilas() ||
        columnaInicial < 0 || columnaInicial >= matrizPuntos->getColumnas() ||
        filaFinal < 0 || filaFinal >= matrizPuntos->getFilas() ||
        columnaFinal < 0 || columnaFinal >= matrizPuntos->getColumnas()) {
        return false;
    }

    if (filaInicial == filaFinal && columnaInicial == columnaFinal) {
        return false;
    }

    if (listaLineas->getCantidad() > 0) {
        NodoLineas* actual = listaLineas->getInicio();
        for (int i = 0; i < listaLineas->getCantidad(); i++) {
            Linea* linea = actual->linea;
            if ((linea->getXInicial() == filaInicial && linea->getYInicial() == columnaInicial &&
            linea->getXFinal() == filaFinal && linea->getYFinal() == columnaFinal) ||
            (linea->getXInicial() == filaFinal && linea->getYInicial() == columnaFinal &&
            linea->getXFinal() == filaInicial && linea->getYFinal() == columnaInicial)) {
                return false; 
            }
        actual = actual->siguiente;
        }
    }

    if ((filaInicial == filaFinal && std::abs(columnaInicial - columnaFinal) == 1) ||
    (columnaInicial == columnaFinal && std::abs(filaInicial - filaFinal) == 1)) {
        return true;
    }

    return false;
}

bool AdministradorDeTablero::validarCasillaCerrada(int fila, int columna, Jugador* jugador) const {
    if (fila < 0 || fila >= matrizCasillaInterior->getFilas() ||
        columna < 0 || columna >= matrizCasillaInterior->getColumnas()) {
        return false;
    }

    Punto* supIzq = matrizPuntos->obtenerElemento(fila, columna);
    Punto* supDer = matrizPuntos->obtenerElemento(fila, columna + 1);
    Punto* infIzq = matrizPuntos->obtenerElemento(fila + 1, columna);
    Punto* infDer = matrizPuntos->obtenerElemento(fila + 1, columna + 1);

    if (!supIzq || !supDer || !infIzq || !infDer) {
        return false;
    }

    bool lineaSuperior = supIzq->getDerecha() != nullptr || supDer->getIzquierda() != nullptr;
    bool lineaInferior = infIzq->getDerecha() != nullptr || infDer->getIzquierda() != nullptr;
    bool lineaIzquierda = supIzq->getAbajo() != nullptr || infIzq->getArriba() != nullptr;
    bool lineaDerecha = supDer->getAbajo() != nullptr || infDer->getArriba() != nullptr;


    bool cerrada = lineaSuperior && lineaInferior && lineaIzquierda && lineaDerecha;

    if (cerrada) {
        std::string* propietario = matrizCasillaInterior->obtenerElemento(fila, columna);
        if (propietario == nullptr) {
            matrizCasillaInterior->agregarElemento(fila, columna, new std::string(jugador->getCaracter()));
        }
        return true;
    }

    return false;
}


void AdministradorDeTablero::agregarLinea(int filaInicial, int columnaInicial,
    int filaFinal, int columnaFinal, Jugador* jugador, PowerUp* powerUp) {
    if (!esMovimientoValido(filaInicial, columnaInicial, filaFinal, columnaFinal)) {
        std::cout << "Movimiento no válido." << std::endl;
        return;
    }

    Punto* puntoInicial = matrizPuntos->obtenerElemento(filaInicial, columnaInicial);
    Punto* puntoFinal = matrizPuntos->obtenerElemento(filaFinal, columnaFinal);

    if (!puntoInicial || !puntoFinal) return;

    Linea* linea = new Linea();
    linea->setPosiciones(filaInicial, columnaInicial, filaFinal, columnaFinal);
    linea->setJugador(jugador);

    if (powerUp != nullptr) {
        establecerLineaConPowerUp(filaInicial, columnaInicial, filaFinal, columnaFinal, powerUp, linea);
    }

    listaLineas->agregarLinea(*linea);

    if (filaInicial == filaFinal) { 
        if (columnaFinal > columnaInicial) { 
            puntoInicial->setDerecha(linea);
            puntoFinal->setIzquierda(linea);
        } else { // Izquierda
            puntoInicial->setIzquierda(linea);
            puntoFinal->setDerecha(linea);
        }
    } else if (columnaInicial == columnaFinal) { 
        if (filaFinal > filaInicial) { 
            puntoInicial->setAbajo(linea);
            puntoFinal->setArriba(linea);
        } else { 
            puntoInicial->setArriba(linea);
            puntoFinal->setAbajo(linea);
        }
    }

    validarCasillaCerrada(filaInicial, columnaInicial, jugador);
    validarCasillaCerrada(filaFinal, columnaFinal, jugador);
}




void AdministradorDeTablero::establecerLineaConPowerUp(int filaInicial, int columnaInicial,
    int filaFinal, int columnaFinal, PowerUp* powerUp, Linea* linea) {
    if (powerUp == nullptr || linea == nullptr) {
        return;
    }
    std::string nombre = powerUp->getNombre();
    if (nombre == "TS") {
        linea->setEsTrampa(true);
    } else if (nombre == "BL") {
        linea->setEsBloqueo(true);
    } else if (nombre == "UF") {
        linea->setEsUnionFuturo(true);
    } else if (nombre == "AC") {
        linea->setEsAQueCosto(true);
    }
}

void AdministradorDeTablero::mostrarTableroClarividente() {
    int filas = matrizPuntos->getFilas();
    int columnas = matrizPuntos->getColumnas();

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            Punto* punto = matrizPuntos->obtenerElemento(i, j);
            std::cout << punto->getCaracter();

            if (punto->getDerecha() != nullptr) {
                Linea* linea = punto->getDerecha();
                std::string color = Colores::BLANCO;
                if (linea->getEsTrampa()) color = Colores::ROJO;
                else if (linea->getEsBloqueo()) color = Colores::AMARILLO;
                else if (linea->getEsUnionFuturo()) color = Colores::VERDE;
                else if (linea->getEsAQueCosto()) color = Colores::AZUL;

                std::cout << color << "-----" << Colores::RESET;
            } else if (punto->getIzquierda() != nullptr) { 
                Linea* linea = punto->getIzquierda();
                std::string color = Colores::BLANCO;
                if (linea->getEsTrampa()) color = Colores::ROJO;
                else if (linea->getEsBloqueo()) color = Colores::AMARILLO;
                else if (linea->getEsUnionFuturo()) color = Colores::VERDE;
                else if (linea->getEsAQueCosto()) color = Colores::AZUL;

                std::cout << color << "-----" << Colores::RESET;
            } else {
                std::cout << "     ";
            }
        }
        std::cout << std::endl;

        if (i < filas - 1) {
            for (int j = 0; j < columnas; ++j) {
                Punto* punto = matrizPuntos->obtenerElemento(i, j);

                if (punto->getAbajo() != nullptr) {
                    Linea* linea = punto->getAbajo();
                    std::string color = Colores::BLANCO;
                    if (linea->getEsTrampa()) color = Colores::ROJO;
                    else if (linea->getEsBloqueo()) color = Colores::AMARILLO;
                    else if (linea->getEsUnionFuturo()) color = Colores::VERDE;
                    else if (linea->getEsAQueCosto()) color = Colores::AZUL;

                    std::cout << color << "|" << Colores::RESET;
                } else if (punto->getArriba() != nullptr) { // línea hacia arriba
                    Linea* linea = punto->getArriba();
                    std::string color = Colores::BLANCO;
                    if (linea->getEsTrampa()) color = Colores::ROJO;
                    else if (linea->getEsBloqueo()) color = Colores::AMARILLO;
                    else if (linea->getEsUnionFuturo()) color = Colores::VERDE;
                    else if (linea->getEsAQueCosto()) color = Colores::AZUL;

                    std::cout << color << "|" << Colores::RESET;
                } else {
                    std::cout << " ";
                }

                if (j < columnas - 1) {
                    std::string* casilla = matrizCasillaInterior->obtenerElemento(i, j);
                    if (casilla != nullptr) {
                        std::cout << " " << *casilla << " ";
                    } else {
                        std::cout << "    ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

void AdministradorDeTablero::mostrarTableros() {
    int filas = matrizPuntos->getFilas();
    int columnas = matrizPuntos->getColumnas();
    const int anchoCasilla = 5; 

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            Punto* punto = matrizPuntos->obtenerElemento(i, j);
            std::cout << punto->getCaracter();

            if (j < columnas - 1 && punto->getDerecha() != nullptr) {
                for (int k = 0; k < anchoCasilla; ++k) std::cout << "-";
            } else if (j < columnas - 1) {
                for (int k = 0; k < anchoCasilla; ++k) std::cout << " ";
            }
        }
        std::cout << std::endl;

        if (i < filas - 1) {
            for (int j = 0; j < columnas; ++j) {
                Punto* punto = matrizPuntos->obtenerElemento(i, j);

                if (punto->getAbajo() != nullptr) {
                    std::cout << "|";
                } else {
                    std::cout << " ";
                }

                if (j < columnas - 1) {
                    std::string* casilla = matrizCasillaInterior->obtenerElemento(i, j);
                    std::string contenido = casilla ? *casilla : "";
                    int espacios = anchoCasilla - contenido.size();
                    int izquierda = espacios / 2;
                    int derecha = espacios - izquierda;
                    for (int k = 0; k < izquierda; ++k) std::cout << " ";
                    std::cout << contenido;
                    for (int k = 0; k < derecha; ++k) std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

bool AdministradorDeTablero::esTableroFinalizado() const {
    int filas = matrizCasillaInterior->getFilas();
    int columnas = matrizCasillaInterior->getColumnas();

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::string* casilla = matrizCasillaInterior->obtenerElemento(i, j);
            if (casilla == nullptr) {
                return false; 
            }
        }
    }
    return true; 
}