#ifndef NODOJUGADORES_H
#define NODOJUGADORES_H
#include "Jugador.h"

class NodoJugadores {
    private:
        Jugador* jugador;
        NodoJugadores* siguiente;
    
    public:
        NodoJugadores(Jugador* j = nullptr) : jugador(j), siguiente(nullptr) {}
    
        Jugador* getJugador() const {
            return jugador;
        }
    
        void setJugador(Jugador* j) {
            jugador = j;
        }
    
        NodoJugadores* getSiguiente() const {
            return siguiente;
        }
    
        void setSiguiente(NodoJugadores* sig) {
            siguiente = sig;
        }
    };
    

#endif