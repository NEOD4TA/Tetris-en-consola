#ifndef MAPA_H
#define MAPA_H

#include "../Pieza/tetromino.h"
#include "../Jugador/player.h"
#include "../Structs de configuración/mapParams.h"

struct mapa{
    int espacio[20][10];
    mapa();
    bool colision(const mapParams& config);
    void fijarPieza(tetromino &pieza);
    int lineaCompleta();
    int obtenerCelda(int X, int Y);
};

#endif