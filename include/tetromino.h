#ifndef TETROMINO_H
#define TETROMINO_H

struct posLista{
    int X;
    int Y;
};

struct tetromino{
    int tipoPieza;
    int indiceRotacion;
    int X;
    int Y;
    static const posLista tipos[7][4][4];
    
    tetromino(); // constructor
    void inicializar();
    bool ocupaCelda(int X, int Y) const;
    void mover(int dX, int dY);
    int rotacion(int direccion);
};
#endif