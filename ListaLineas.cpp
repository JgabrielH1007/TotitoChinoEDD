#include "ListaLineas.h"
#include "Linea.h"
#include "NodoLineas.h"
#include <iostream>

ListaLineas::ListaLineas() : inicio(nullptr), cantidad(0) {}

void ListaLineas::agregarLinea(Linea& linea) {
    NodoLineas* nuevoNodo = new NodoLineas();
    nuevoNodo->linea = new Linea(linea);
    
    if (estaVacia()) {
        inicio = nuevoNodo;
        nuevoNodo->siguiente = inicio; 
    } else {
        NodoLineas* actual = inicio;
        while (actual->siguiente != inicio) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = inicio; 
    }
    cantidad++;
}

void ListaLineas::eliminarLinea(int xInicial, int yInicial, int xFinal, int yFinal) {
    if (estaVacia()) {
        std::cout << "La lista está vacía. No se puede eliminar la línea." << std::endl;
        return;
    }

    NodoLineas* actual = inicio;
    NodoLineas* anterior = nullptr;
    bool encontrado = false;

    do {
        Linea* linea = actual->linea;
        if ((linea->getXInicial() == xInicial && linea->getYInicial() == yInicial &&
             linea->getXFinal() == xFinal && linea->getYFinal() == yFinal) ||
            (linea->getXInicial() == xFinal && linea->getYInicial() == yFinal &&
             linea->getXFinal() == xInicial && linea->getYFinal() == yInicial)) {
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != inicio);

    if (!encontrado) {
        std::cout << "Línea no encontrada en la lista." << std::endl;
        return;
    }

    if (actual == inicio && actual->siguiente == inicio) {
        inicio = nullptr; 
    } else {
        if (actual == inicio) {
            NodoLineas* ultimo = inicio;
            while (ultimo->siguiente != inicio) {
                ultimo = ultimo->siguiente;
            }
            inicio = inicio->siguiente; 
            ultimo->siguiente = inicio; 
        } else {
            anterior->siguiente = actual->siguiente; 
        }
    }

    delete actual->linea; 
    delete actual; 
    cantidad--;
}

bool ListaLineas::estaVacia() const {
    return cantidad == 0;
}

int ListaLineas::getCantidad() const {
    return cantidad;
}

NodoLineas* ListaLineas::getInicio() const {
    return inicio;
}
