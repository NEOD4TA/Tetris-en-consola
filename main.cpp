#include <iostream>
#include <time.h>
#include <cstdlib>

#include "Control/juego.h"

int main (){
    juego tetris;

    srand(time(NULL));
    tetris.ejecutar();

    char ex;
    std::cin>>ex;
    return 0;
}
//g++ main.cpp Consola/consola.cpp Control/juego.cpp Jugador/player.cpp Mapa/mapa.cpp Pieza/tetromino.cpp -std=c++20 -o tetris