#include <iostream>
#include <time.h>
#include <cstdlib>

#include "juego.h"

int main (){
    juego tetris;

    srand(time(NULL));
    tetris.ejecutar();

    char ex;
    std::cin>>ex;
    return 0;
}

//g++ -Iinclude main.cpp src/*.cpp -o tetris.exe