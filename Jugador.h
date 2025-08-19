#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "PilaPowerUps.h"
#include <iostream>

class Jugador {
private:
    std::string caracter = "";
    int puntos = 0;
    bool enTurno = false;
    PilaPowerUps pilaPowerUps;

public:
    Jugador(const std::string& caracter);
    ~Jugador();
    void agregarPowerUp(const PowerUp& powerUp);
    PowerUp quitarPowerUp();
    bool getEnTurno() const;
    void setEnTurno(bool enTurno);
    std::string getCaracter() const;
    int getPuntos() const;
    void setPuntos(int puntos);

};


#endif 