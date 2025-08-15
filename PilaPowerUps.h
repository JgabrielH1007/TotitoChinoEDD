#ifndef PILAPOWERUPS_H
#define PILAPOWERUPS_H
#include "NodoPila.h"
class PilaPowerUps {
    private:
        NodoPila* cima;
    public:
        PilaPowerUps();
        ~PilaPowerUps();
        void agregarPowerUp(const PowerUp& powerUp);
        PowerUp quitarPowerUp();
        bool estaVacia() const;
        PowerUp verCima() const;
};


#endif