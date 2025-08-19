#include "ListaJugadores.h"
#include "Jugador.h"
#include "NodoJugadores.h"
#include <iostream>

ListaJugadores::ListaJugadores() : inicio(nullptr),final(nullptr), cantidad(0) {}

void ListaJugadores::agregarJugador(const Jugador& jugador) {
    NodoJugadores* nuevoNodo = new NodoJugadores();
    nuevoNodo->jugador = new Jugador(jugador);
    if(inicio == nullptr) {
        inicio = nuevoNodo;
        final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        nuevoNodo->siguiente = inicio;
        final = nuevoNodo;
    }
    cantidad++;
}

void ListaJugadores::eliminarJugador(const std::string& caracter) {
    if (estaVacia()) return;

    NodoJugadores* actual = inicio;
    NodoJugadores* anterior = nullptr;

    do {
        if (actual->jugador->getCaracter() == caracter) {
            if (anterior == nullptr) { 
                inicio = actual->siguiente;
                final->siguiente = inicio; 
            } else {
                anterior->siguiente = actual->siguiente;
                if (actual == final) {
                    final = anterior;
                }
            }
            delete actual->jugador;
            delete actual;
            cantidad--;
            return; 
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != inicio);
}

bool ListaJugadores::estaVacia() const {
    return cantidad == 0;
}

int ListaJugadores::getCantidad() const {
    return cantidad;
}