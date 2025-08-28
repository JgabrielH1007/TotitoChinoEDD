#ifndef TABLERO_H
#define TABLERO_H
#include "NodoTablero.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class Tablero {
    private:
        NodoTablero<T>* raiz;
        int filas;
        int columnas;
    public:
        Tablero(int f, int c) : filas(f), columnas(c) {
            raiz = new NodoTablero<T>(nullptr);
        }

        void agregarElemento(int fila, int columna, T* dato) {
            if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
            std::cout << "Índice fuera de rango al agregar elemento." << std::endl;
            return;
            }
            NodoTablero<T>* actual = raiz;
            for (int i = 0; i < fila; ++i) {
            if (actual->abajo == nullptr) {
                actual->abajo = new NodoTablero<T>(nullptr);
                actual->abajo->arriba = actual;
            }
            actual = actual->abajo;
            }
            for (int j = 0; j < columna; ++j) {
            if (actual->derecha == nullptr) {
                actual->derecha = new NodoTablero<T>(nullptr);
                actual->derecha->izquierda = actual;
            }
            actual = actual->derecha;
            }
            if (actual->dato != nullptr) {
            delete actual->dato;
            }
            actual->dato = dato;
        }

        T* obtenerElemento(int fila, int columna) const {
            if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
                std::cout << "Índice fuera de rango al obtener elemento." << std::endl;
                return nullptr;
            }
            NodoTablero<T>* actual = raiz;
            for (int i = 0; i < fila; ++i) {
                if (actual->abajo == nullptr) {
                    return nullptr;
                }
                actual = actual->abajo;
            }
            for (int j = 0; j < columna; ++j) {
                if (actual->derecha == nullptr) {
                    return nullptr;
                }
                actual = actual->derecha;
            }
            return actual->dato;
        }  

        void eliminarElemento(int fila, int columna) {
            if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
                std::cout << "Índice fuera de rango al eliminar elemento." << std::endl;
                return;
            }
            NodoTablero<T>* actual = raiz;
            for (int i = 0; i < fila; ++i) {
                if (actual->abajo == nullptr) {
                    return;
                }
                actual = actual->abajo;
            }
            for (int j = 0; j < columna; ++j) {
                if (actual->derecha == nullptr) {
                    return;
                }
                actual = actual->derecha;
            }
            if (actual->dato != nullptr) {
                delete actual->dato;
                actual->dato = nullptr;
            }
        }

        int getFilas() const { return filas; }
        int getColumnas() const { return columnas; }
        
};
#endif 

