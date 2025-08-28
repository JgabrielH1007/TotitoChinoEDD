#ifndef PUNTO_H
#define PUNTO_H
#include "Linea.h"
class Punto {
private:
    char const caracter = '.';
    int x;
    int y;
    Linea* derecha = nullptr;  
    Linea* abajo = nullptr;  
    Linea* izquierda = nullptr;
    Linea* arriba = nullptr;
public:
    Punto(int x = 0, int y = 0) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int newX) {
        x = newX;
    }

    void setY(int newY) {
        y = newY;
    }

    Linea* getDerecha() const {
        return derecha;
    }

    Linea* getAbajo() const {
        return abajo;
    }

    void setDerecha(Linea* linea) {
        derecha = linea;
    }

    void setAbajo(Linea* linea) {
        abajo = linea;
    }

    Linea* getIzquierda() const {
        return izquierda;
    }
    Linea* getArriba() const {
        return arriba;
    }

    void setIzquierda(Linea* linea) {
        izquierda = linea;
    }

    void setArriba(Linea* linea) {
        arriba = linea;
    }
    
    char getCaracter() const {
        return caracter;
    }
};

#endif 