#ifndef NODOPILA_H
#define NODOPILA_H
#include "PowerUp.h"

class NodoPila {
    private:
        PowerUp powerUp;
        NodoPila* siguiente;
    public:
        NodoPila(const PowerUp& powerUp, NodoPila* siguiente = nullptr)
            : powerUp(powerUp), siguiente(siguiente) {}
        PowerUp getPowerUp() const {
            return powerUp;
        }
        NodoPila* getSiguiente() const {
            return siguiente;
        }
        void setSiguiente(NodoPila* siguiente) {
            this->siguiente = siguiente;
        }
};  
#endif 