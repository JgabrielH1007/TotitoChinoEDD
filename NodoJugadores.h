#ifndef NODOJUGADORES_H
#define NODOJUGADORES_H
#include <string>
#include "Jugador.h"

class NodoJugadores {
    public:
        Jugador* jugador;
        NodoJugadores* siguiente;

};

#endif