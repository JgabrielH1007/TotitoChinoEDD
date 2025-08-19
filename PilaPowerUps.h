#ifndef PILAPOWERUPS_H
#define PILAPOWERUPS_H
#include "NodoPila.h"
class PilaPowerUps {
    private:
        NodoPila* cima;
    public:
        PilaPowerUps();
        void push(PowerUp* powerUp);
        PowerUp* pop();
        PowerUp* peek();
        bool isEmpty();
        void clear();
};
#endif