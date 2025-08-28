#ifndef LINEA_H
#define LINEA_H
#include "Jugador.h"
class Linea {
    private:
        Jugador* jugador;
        int xInicial = 0;
        int yInicial = 0;
        int xFinal = 0;
        int yFinal = 0;
        bool esTrampa = false;
        bool esBloqueo = false;
        bool esUnionFuturo = false;
        bool esAQueCosto = false;
        
    public:

        Jugador* getJugador() const {
            return jugador;
        }

        int getXInicial() const {
            return xInicial;
        }
        int getYInicial() const {
            return yInicial;
        }
        int getXFinal() const {
            return xFinal;
        }
        int getYFinal() const {
            return yFinal;
        }

        bool getEsTrampa() const {
            return esTrampa;
        }
        bool getEsBloqueo() const {
            return esBloqueo;
        }
        bool getEsUnionFuturo() const {
            return esUnionFuturo;
        }
        bool getEsAQueCosto() const {
            return esAQueCosto;
        }

        void setEsTrampa(bool valor) {
            esTrampa = valor;
        }
        void setEsBloqueo(bool valor) {
            esBloqueo = valor;
        }
        void setEsUnionFuturo(bool valor) {
            esUnionFuturo = valor;
        }
        void setEsAQueCosto(bool valor) {
            esAQueCosto = valor;
        }

        void setPosiciones(int xIni, int yIni, int xFin, int yFin) {
            xInicial = xIni;
            yInicial = yIni;
            xFinal = xFin;
            yFinal = yFin;
        }

        void setJugador(Jugador* nuevoJugador) {
            jugador = nuevoJugador;
        }

        

};

#endif 