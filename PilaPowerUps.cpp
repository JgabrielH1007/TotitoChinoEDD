#include "PilaPowerUps.h"
#include "NodoPila.h"
#include "PowerUp.h"

PilaPowerUps::PilaPowerUps() : cima(nullptr) {}

void PilaPowerUps::push(PowerUp* powerUp) {
    NodoPila* nuevoNodo = new NodoPila();
    nuevoNodo->powerUp = powerUp;
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

PowerUp* PilaPowerUps::pop() {
    if (isEmpty()) return nullptr;
    NodoPila* nodoAEliminar = cima;
    PowerUp* powerUp = nodoAEliminar->powerUp;
    cima = cima->siguiente;
    delete nodoAEliminar;
    return powerUp;
}

PowerUp* PilaPowerUps::peek() {
    if (isEmpty()) return nullptr;
    return cima->powerUp;
}
bool PilaPowerUps::isEmpty() {
    return cima == nullptr;
}

void PilaPowerUps::clear() {
    while (!isEmpty()) {
        pop();
    }
}
