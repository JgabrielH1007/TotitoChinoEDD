#include "Jugador.h"
#include <iostream>

Jugador::Jugador() : caracter("  "), puntos(0), enTurno(false), pilaPowerUps() {}

void Jugador::agregarPowerUp(const PowerUp& powerUp) {
    PowerUp* nuevoPowerUp = new PowerUp(powerUp);
    pilaPowerUps.apilar(nuevoPowerUp);
}

PowerUp Jugador::quitarPowerUp() {
    if (pilaPowerUps.isEmpty()) {
        throw std::runtime_error("No hay PowerUps para quitar.");
    }
    PowerUp* powerUp = pilaPowerUps.desapilar();
    PowerUp copiaPowerUp = *powerUp;
    delete powerUp; 
    return copiaPowerUp;
}

bool Jugador::getEnTurno() const {
    return enTurno;
}

void Jugador::setEnTurno(bool enTurno) {
    this->enTurno = enTurno;
}

std::string Jugador::getCaracter() const {
    return caracter;
}

int Jugador::getPuntos() const {
    return puntos;
}

void Jugador::setPuntos(int puntos) {
    this->puntos = puntos;
}

int Jugador::getCasillasGanadas() const {
    return casillasGanadas;
}

void Jugador::setCasillasGanadas(int casillasGanadas) {
    this->casillasGanadas = casillasGanadas;
}

PilaPowerUps& Jugador::getPilaPowerUps() {
    return pilaPowerUps;
}

void Jugador::setCaracter(const std::string& caracter) {
    this->caracter = caracter;
}


