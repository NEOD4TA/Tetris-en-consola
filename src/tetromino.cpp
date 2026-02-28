#include "tetromino.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const vector2D tetromino::tipos[7][4][4]  = {
    {
        {{0,0}, {1,0}, {0,1}, {1,1}}, //O
        {{0,0}, {1,0}, {0,1}, {1,1}},
        {{0,0}, {1,0}, {0,1}, {1,1}},
        {{0,0}, {1,0}, {0,1}, {1,1}}
    },
    {
        {{0,0}, {0,1}, {0,2}, {0,3}}, //|
        {{0,0}, {1,0}, {2,0}, {3,0}},
        {{0,0}, {0,-1}, {0,-2}, {0,-3}},
        {{0,0}, {-1,0}, {-2,0}, {-3,0}}
    },
    {
        {{0,0}, {1,0}, {0,1}, {-1,1}}, //S
        {{0,0}, {0,-1}, {1,0}, {1,1}},
        {{0,0}, {1,0}, {0,1}, {-1,1}},
        {{0,0}, {0,-1}, {1,0}, {1,1}}
    },
    {
        {{0,0}, {-1,0}, {0,1}, {1,1}}, //Z
        {{0,0}, {0,-1}, {-1,0}, {-1,1}},
        {{0,0}, {-1,0}, {0,1}, {1,1}},
        {{0,0}, {0,-1}, {-1,0}, {-1,1}}
    },
    {
        {{0,0}, {0,1}, {0,2}, {1,2}}, //L
        {{0,0}, {1,0}, {2,0}, {2,-1}},
        {{0,0}, {0,-1}, {0,-2}, {-1,-2}},
        {{0,0}, {-1,0}, {-2,0}, {-2,1}}
    },
    {
        {{0,0}, {0,1}, {0,2}, {-1,2}}, //J
        {{0,0}, {1,0}, {2,0}, {2,1}},
        {{0,0}, {0,-1}, {0,-2}, {1,-2}},
        {{0,0}, {-1,0}, {-2,0}, {-2,-1}}
    },
    {
        {{0,0}, {0,1}, {1,0}, {-1,0}}, //T
        {{0,0}, {0,1}, {1,0}, {0,-1}},
        {{0,0}, {0,-1}, {1,0}, {-1,0}},
        {{0,0}, {0,1}, {-1,0}, {0,-1}}
    }
};

tetromino::tetromino(){
    inicializar();
}

void tetromino::inicializar(){
    tipoPieza = siguientePieza;
    int ran = rand() % totalPiezas;
    siguientePieza = static_cast<TipoPieza>(ran);
    X = 5;
    Y = 1;
    indiceRotacion = 0;
    drop = 0;
}

bool tetromino::ocupaCelda(int cX, int cY) const{
    for (int i = 0; i < 4; i++)
    {
        int pY = Y + tipos[static_cast<int>(tipoPieza)][indiceRotacion][i].Y;
        int pX = X + tipos[static_cast<int>(tipoPieza)][indiceRotacion][i].X;
        if (cY == pY && cX == pX)
        {
            return true;
        }
    }
    return false;
}

void tetromino::mover(int dX, int dY){
    X += dX;
    Y += dY;
}

int tetromino::rotacion(int direccion){
    return ((indiceRotacion+direccion+4)%4);
}
