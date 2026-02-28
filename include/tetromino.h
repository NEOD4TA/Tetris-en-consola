#ifndef TETROMINO_H
#define TETROMINO_H

#include "piezaCore.h"

struct tetromino{
    TipoPieza tipoPieza;
    TipoPieza siguientePieza;
    int indiceRotacion;
    int drop;
    int X;
    int Y;

    static constexpr int totalPiezas = 7;
    static constexpr int totalRotaciones = 4;
    static constexpr int Bloques = 4;

    static const vector2D tipos[totalPiezas][totalRotaciones][Bloques];
    
    tetromino(); // constructor
    void inicializar();
    bool ocupaCelda(int X, int Y) const;
    void mover(int dX, int dY);
    int rotacion(int direccion);
};
#endif