#ifndef MAPA_H
#define MAPA_H

#include "tetromino.h"
#include "player.h"
#include "mapParams.h"

struct mapa{
    int espacio[20][10];
    mapa();
    bool colision(const mapParams& config);
    void fijarPieza(tetromino &pieza);
    int lineaCompleta();
    int obtenerCelda(int X, int Y);
};

#endif