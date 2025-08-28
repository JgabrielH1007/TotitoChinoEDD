#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "PilaPowerUps.h"
#include <iostream>

class Jugador {
private:
    std::string caracter;
    int puntos = 0;
    int casillasGanadas = 0;
    bool enTurno = false;
    PilaPowerUps pilaPowerUps;

public:
    Jugador();
    void agregarPowerUp(const PowerUp& powerUp);
    PowerUp quitarPowerUp();
    bool getEnTurno() const;
    void setEnTurno(bool enTurno);
    int getPuntos() const;
    void setPuntos(int puntos);
    int getCasillasGanadas() const;
    void setCasillasGanadas(int casillasGanadas);
    std::string getCaracter() const;
    void setCaracter(const std::string& caracter);
    PilaPowerUps& getPilaPowerUps();

};


#endif 