#ifndef JUEGO_H
#define JUEGO_H

//Archivos del juego
#include "mapa.h"
#include "player.h"
#include "tetromino.h"
#include "consola.h"

class juego
{
    private:
    mapa tablero;
    tetromino pieza;
    player jugador;
    consola accesoConsola;
    int bucle = true;
    int velocidadInicial = 0;
    bool softDropActivo = false;

    public:
    void ejecutar();
    int velocidad(int puntaje);
    int velocidadFinal(int velInicial);
    void renderizar();
    void input();
    void actualizarTablero();
};


#endif