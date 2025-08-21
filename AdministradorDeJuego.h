#ifndef ADMINISTRADORDEJUEGO_H
#define ADMINISTRADORDEJUEGO_H
#include <string>
#include "Jugador.h"
#include "PowerUp.h"
#include "UnionFuturo.h"
#include "AQueCosto.h"
#include "Bloqueo.h"
#include "DobleLinea.h"
#include "Escurridizo.h"
#include "LlaveSecreta.h"
#include "NuevasTierras.h"
#include "Pase.h"
#include "TrampaSecreta.h"
#include "ListaJugadores.h"
#include "PilaPowerUps.h"

class AdministradorDeJuego {
    private:
        ListaJugadores listaJugadores;
    public:
        AdministradorDeJuego();
        void recolectarInfomacionJugadores();
        void guardarJugadores(std::string caracter);
        void administrarTurnos();
        void mostrarTablero();
        bool hayGanador() const;
        void manejarPowerUp(Jugador& jugador, PowerUp* powerUp);
        void Jugar();
        
};

#endif