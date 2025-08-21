#ifndef LINEA_H
#define LINEA_H
#include "Jugador.h"
class Linea {
    private:
        Jugador* jugador;
        int x = 0;
        int y = 0;
        bool esHorizontal = false;
        bool esVertical = false;
        char const caracterHorizontal = '-';
        char const caracterVertical = '|';
    public:

        Jugador* getJugador() const {
            return jugador;
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

        bool isHorizontal() const {
            return esHorizontal;
        }

        bool isVertical() const {
            return esVertical;
        }

        char getCaracter() const {
            return esHorizontal ? caracterHorizontal : caracterVertical;
        }
        
        void setX(int newX) {
            x = newX;
        }

        void setY(int newY) {
            y = newY;
        }
        void setJugador(Jugador* nuevoJugador) {
            jugador = nuevoJugador;
        }

        void setEsHorizontal(bool nuevoEsHorizontal) {
            esHorizontal = nuevoEsHorizontal;
        }
        void setEsVertical(bool nuevoEsVertical) {
            esVertical = nuevoEsVertical;
        }

};

#endif 