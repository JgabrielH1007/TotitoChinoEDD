#include "ListaJugadores.h"
#include "NodoJugadores.h"
#include "Jugador.h"

ListaJugadores::ListaJugadores() : inicio(nullptr), final(nullptr), cantidad(0) {}

void ListaJugadores::agregarJugador(const Jugador* jugador) {
    NodoJugadores* nuevoNodo = new NodoJugadores();
    nuevoNodo->setJugador(new Jugador(*jugador));

    if (inicio == nullptr) {
        inicio = nuevoNodo;
        final = nuevoNodo;
        final->setSiguiente(inicio);
    } else {
        final->setSiguiente(nuevoNodo);
        nuevoNodo->setSiguiente(inicio);
        final = nuevoNodo;
    }
    cantidad++;
}


void ListaJugadores::eliminarJugador(const std::string& caracter) {
    if (estaVacia()) return;

    NodoJugadores* actual = inicio;
    NodoJugadores* anterior = nullptr;

    do {
        if (actual->getJugador()->getCaracter() == caracter) {
            if (anterior == nullptr) { 
                inicio = actual->getSiguiente();
                final->setSiguiente(inicio); 
            } else {
                anterior->setSiguiente(actual->getSiguiente());
                if (actual == final) {
                    final = anterior;
                }
            }
            delete actual->getJugador();
            delete actual;
            cantidad--;
            return; 
        }
        anterior = actual;
        actual = actual->getSiguiente();
    } while (actual != inicio);
}

bool ListaJugadores::estaVacia() const {
    return cantidad == 0;
}

int ListaJugadores::getCantidad() const {
    return cantidad;
}

NodoJugadores* ListaJugadores::getInicio() const {
    return inicio;
}

NodoJugadores* ListaJugadores::getFinal() const {
    return final;
}
