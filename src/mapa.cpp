#include "mapa.h"
#include <iostream>

using namespace std;

mapa::mapa() { //inicialización
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 10; x++)
            {
            if (y==0||y==19)
            {
                espacio[y][x] = 10; //superior e inferior
            }
            else if (x==0||x==9)
            {
                espacio[y][x] = 11; //laterales
            }
             else {
                espacio[y][x] = 0;
            }
            
        }        
    }

    //esquinas
    espacio[0][0] = 12;
    espacio[0][9] = 13;
    espacio[19][0] = 14;
    espacio[19][9] = 15;
}

int mapa::obtenerCelda(int X, int Y){
    return espacio[Y][X];
}

bool mapa::colision(const mapParams& config){
    bool colisiona = true;

    for (int i = 0; i < 4; i++)
    {
        
        int Y = config.pieza.Y + config.pieza.tipos[config.pieza.tipoPieza][config.rotacion][i].Y;
        int X = config.pieza.X + config.pieza.tipos[config.pieza.tipoPieza][config.rotacion][i].X;

        if (config.caida != 0) {  Y += config.caida; }

        if (config.lado != 0) { X += config.lado; }

        if (Y<19 && X<9 && X>0 && espacio[Y][X]==0)
        {
            colisiona = false;
        }
        else{
            colisiona = true;
            break;
        }
    }
    return colisiona;
/**
 * @brief Comprueba si una pieza colisiona en el mapa bajo ciertas condiciones.
 *
 * Evalúa si el tetromino produciría una colisión al intentar:
 * - Descender una posición (caída).
 * - Desplazarse horizontalmente (lado).
 * - Aplicar una rotación específica.
 *
 * La función analiza los 4 bloques que componen la pieza y verifica:
 * - Que no salgan de los límites del mapa.
 * - Que no ocupen un espacio ya utilizado.
 *
 * @param config Estructura que contiene:
 * - La pieza actual.
 * - La rotación que se desea comprobar.
 * - Si se intenta aplicar caída vertical.
 * - El desplazamiento horizontal (izquierda = -1, derecha = 1, 0 = sin movimiento).
 *
 * @return true  Si existe colisión (movimiento no permitido).
 * @return false Si no hay colisión (movimiento válido).
 */
}

void mapa::fijarPieza(const tetromino &pieza){
    for (int i = 0; i < 4; i++)
        {
            int Y = pieza.Y+pieza.tipos[pieza.tipoPieza][pieza.indiceRotacion][i].Y;
            int X = pieza.X+pieza.tipos[pieza.tipoPieza][pieza.indiceRotacion][i].X;
            espacio[Y][X] = 1;
        }
}

tetromino mapa::calcularSombra(tetromino pieza){
    int dX = 0;
    while(!colision({.pieza = pieza, .caida = dX})){
        dX++;
    }
    pieza.Y+= (dX-1);
    return pieza;
}

int mapa::lineaCompleta(){
    int contador = 0;
    for (int y = 18; y > 0; y--)
    {
        bool lineaCompleta = true;
        for (int x = 1; x <= 8; x++)
        {
            if (espacio[y][x]==0)
            {
                //Si hay un espacio vacio la condicion no se cumple y avanza a la siguiente linea
                lineaCompleta = false;
                break;
            }
        }
        if (lineaCompleta==true) //Mueve las lineas para arriba
        {
            for (int y_b = y; y_b > 0; y_b--)
            {
                for (int x_b = 1; x_b <= 8; x_b++)
                {
                    espacio[y_b][x_b] = espacio[y_b-1][x_b];
                }
            }
            for (int i = 1; i <= 8; i++) //vuelve a vaciar la primer linea
            {
                espacio[1][i] = 0;
            }
            contador++;
            y++;
        }
    }
    return contador;
}