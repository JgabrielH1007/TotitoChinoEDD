#ifndef LISTAJUGADORES_H
#define LISTAJUGADORES_H
#include "NodoJugadores.h"
#include <iostream>

class ListaJugadores {
    private:
        NodoJugadores * inicio;
        NodoJugadores * final;
        int cantidad;
    public:
        ListaJugadores();
        void agregarJugador(const Jugador& jugador);
        void eliminarJugador(const std::string& caracter);
        int getCantidad() const;
        bool estaVacia() const;
};
#endif