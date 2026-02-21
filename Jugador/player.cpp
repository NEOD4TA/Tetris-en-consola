#include "player.h"
#include <iostream>

using namespace std;

player::player(){
    puntaje = 0;
    Combo = "";
}

void player::sumarPuntos(int lineas){
    if (lineas == 0) return;

    puntaje += 100 * lineas;

    contadorMensaje = 5;

    switch (lineas)
    {
        case 1: Combo = "¡Single!"; break;
        case 2: Combo = "¡Double!"; break;
        case 3: Combo = "¡Triple!"; break;
        case 4: Combo = "¡Tetris!"; break;
        default: Combo = "¡Tetris!"; break;
    }
}

void player::verPuntaje(){
    cout<<"\nScore: "<<puntaje<<endl;
}

void player::alertaCombo(){
    if (contadorMensaje!=0)
    {
        cout<<Combo;
        contadorMensaje--;
    }else{
        cout<<"\033[2K\r";
    }
}