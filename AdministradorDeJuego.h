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
#include "AdministradorDeTablero.h"

class AdministradorDeJuego {
    private:
        int indiceEnTurno = 0;
        ListaJugadores listaJugadores;
        AdministradorDeTablero administradorDeTablero;
    public:
        AdministradorDeJuego();
        void iniciarJuego();
        void registrarTamanioTablero();
        void recolectarInfomacionJugadores();
        void guardarJugadores(std::string caracter);
        Jugador* obtenerJugadorEnTurno() const;
        void Jugar();
        int menuJuego()const;
        void mostrarGanador() const;
        
};

#endif