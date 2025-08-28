#ifndef NODOTABLERO_H
#define NODOTABLERO_H

template <typename T>

class NodoTablero {
    public:
        T* dato;
        NodoTablero<T>* arriba;
        NodoTablero<T>* abajo;
        NodoTablero<T>* izquierda;
        NodoTablero<T>* derecha;

        NodoTablero(T* valor) : dato(valor), arriba(nullptr), abajo(nullptr), izquierda(nullptr), derecha(nullptr) {}
};

#endif 