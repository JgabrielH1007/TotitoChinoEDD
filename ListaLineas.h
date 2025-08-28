#ifndef LISTALINEAS_H
#define LISTALINEAS_H
#include "Linea.h"
#include "NodoLineas.h"
#include <iostream>

class ListaLineas {
    private:
        NodoLineas* inicio;
        int cantidad;
    public:
        ListaLineas();
        void agregarLinea(Linea& linea);
        void eliminarLinea(int xInicial, int yInicial, int xFinal, int yFinal);
        bool estaVacia() const;
        int getCantidad() const;
        NodoLineas* getInicio() const;
        NodoLineas* getFinal() const;
}; 

#endif