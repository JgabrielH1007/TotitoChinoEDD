#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "PilaPowerUps.h"
#include <iostream>

class Jugador {
private:
    std::string caracter;
    int puntos;
    PilaPowerUps pilaPowerUps;

public:
    Jugador(const std::string& caracter);
    ~Jugador();
    void agregarPowerUp(const PowerUp& powerUp);
    PowerUp quitarPowerUp();
    bool tienePowerUps() const;

};


#endif 