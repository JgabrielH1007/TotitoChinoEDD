#ifndef ADMINISTRADORDETABLERO_H
#define ADMINISTRADORDETABLERO_H
#include <string>
#include "Tablero.h"
#include "ListaLineas.h"
#include "Jugador.h"
#include "PowerUp.h"
#include "Punto.h"
#include "Linea.h"

class AdministradorDeTablero {
    private:
        Tablero<std::string>* matrizCasillaInterior;
        Tablero<Punto>* matrizPuntos;
        ListaLineas* listaLineas;

    public:
        AdministradorDeTablero();
        ~AdministradorDeTablero();
        void construirTablero(int filas, int columnas);
        void ubicarPowerUp(int fila, int columna);
        void agregarPowerUp(int fila, int columna, PowerUp* powerUp);
        PowerUp* obtenerPowerUp(int fila, int columna) const;
        void eliminarJugador(int fila, int columna);
        void eliminarPowerUp(int fila, int columna);
        bool esMovimientoValido(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal) const;
        bool validarCasillaCerrada(int fila, int columna, Jugador* Jugador) const;
        void agregarLinea(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal, Jugador* jugador, PowerUp* powerUp);
        void establecerLineaConPowerUp(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal, PowerUp* powerUp, Linea* linea);
        void mostrarTableroClarividente();
        void mostrarTableros();
        bool esTableroFinalizado() const;
};

#endif