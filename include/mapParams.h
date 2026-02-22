#ifndef MAPPARAMS_H
#define MAPPARAMS_H

#include "tetromino.h"

using namespace std;

struct mapParams{
    tetromino pieza;
    bool caida = false;
    int lado = 0;
    int rotacion = pieza.indiceRotacion;
};

#endif