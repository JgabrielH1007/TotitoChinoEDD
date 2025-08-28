#include "PilaPowerUps.h"
#include "NodoPila.h"
#include "PowerUp.h"
#include <iostream>

PilaPowerUps::PilaPowerUps() : cima(nullptr) {}

void PilaPowerUps::apilar(PowerUp* powerUp) {
    NodoPila* nuevoNodo = new NodoPila();
    nuevoNodo->powerUp = powerUp;
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

PowerUp* PilaPowerUps::desapilar() {
    if (isEmpty()) return nullptr;
    NodoPila* nodoAEliminar = cima;
    PowerUp* powerUp = nodoAEliminar->powerUp;
    cima = cima->siguiente;
    delete nodoAEliminar;
    return powerUp;
}

void PilaPowerUps::imprimir() const {
    NodoPila* actual = cima;
    if (cima == nullptr) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }
    while (actual != nullptr) {
        std::cout<< actual->powerUp->getNombre() << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

bool PilaPowerUps::isEmpty() {
    return cima == nullptr;
}

void PilaPowerUps::clear() {
    while (!isEmpty()) {
        desapilar();
    }
}
