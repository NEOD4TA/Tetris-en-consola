#ifndef MAPPARAMS_H
#define MAPPARAMS_H

#include "../Pieza/tetromino.h"

using namespace std;

struct mapParams{
    tetromino pieza;
    bool caida = false;
    int lado = 0;
    int rotacion = pieza.indiceRotacion;
};

#endif