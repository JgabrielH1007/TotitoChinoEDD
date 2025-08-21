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
#include <limits>
#include <iostream>

AdministradorDeJuego::AdministradorDeJuego() {
    // Constructor implementation
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
    Jugador jugador(caracter);
    listaJugadores.agregarJugador(jugador);
}


    
