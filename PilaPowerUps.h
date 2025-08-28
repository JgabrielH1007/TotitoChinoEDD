#ifndef PILAPOWERUPS_H
#define PILAPOWERUPS_H
#include "NodoPila.h"
class PilaPowerUps {
    private:
        NodoPila* cima;
    public:
        PilaPowerUps();
        void apilar(PowerUp* powerUp);
        PowerUp* desapilar();
        void imprimir() const;
        bool isEmpty();
        void clear();
};
#endif