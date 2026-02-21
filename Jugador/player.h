#ifndef PLAYER_H
#define PLAYER_H

#include <string>

struct player{
    int puntaje;
    int contadorMensaje = 0;
    std::string Combo;

    player();
    void sumarPuntos(int lineas);
    void verPuntaje();
    void alertaCombo();
};

#endif