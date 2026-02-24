#include "juego.h"

//Librerias
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <thread>
#include <iostream>
#include <clocale>

int juego::velocidad(int puntaje){
    int nivel = puntaje/1000;
    int velBase = 600;
    int reduccion = 50;
    return velBase - (nivel * reduccion);
}

int juego::velocidadFinal(int velInicial){
    if(softDropActivo){
        return velInicial / 2;
    }
        return velInicial;
}

void juego::ejecutar(){
        accesoConsola.ocultarCursor();

    do
    {
        velocidadInicial = velocidad(jugador.puntaje);

        accesoConsola.goToXY(0, 0);

        renderizar();
        
        jugador.verPuntaje();

        jugador.alertaCombo();

        input();

        actualizarJuego();

        Sleep(velocidadFinal(velocidadInicial));

    } while (bucle==true);
}

void juego::renderizar(){
    tetromino sombra = tablero.calcularSombra(pieza);
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            /*
            Se verifica si la posicion actual coincide con alguno de los bloques
            de la pieza, si no es asi se activa el switch
            */
            if (pieza.ocupaCelda(x, y))
            {
                std::cout<<"██";
            }
            else if(sombra.ocupaCelda(x,y)){
                std::cout<<"░░";
            }
            else {
                int celda = tablero.obtenerCelda(x, y);
                switch (celda)
            {
                case 0: std::cout << "  "; break;
                case 1: std::cout << "██"; break;
                case 10: std::cout << "══"; break;
                case 11: std::cout << "║"; break;
                case 12: std::cout << "╔"; break;
                case 13: std::cout << "╗"; break;
                case 14: std::cout << "╚"; break;
                case 15: std::cout << "╝"; break;
                default: std::cout << "  "; break;
            }
            }
        }
        std::cout<<endl;
    }
}

void juego::input(){
    //Comprobación de colision al moverse a un lado
    if(GetAsyncKeyState('A') & 0x8000){
        if (tablero.colision({.pieza = pieza, .lado = -1}) == false)
        {
            pieza.mover(-1,0);
        }
    }
    else if(GetAsyncKeyState('D') & 0x8000){
        if (tablero.colision({.pieza = pieza, .lado = 1}) == false)
        {
            pieza.mover(1,0);
        }
    }

    //Comprobación de colision en las rotaciones
    if(GetAsyncKeyState('L') & 0x8000){
        int nuevaRotacion = pieza.rotacion(+1);

        if (tablero.colision({.pieza = pieza, .rotacion = nuevaRotacion}) == false)
            {
                pieza.indiceRotacion = nuevaRotacion;
            }
    } else if(GetAsyncKeyState('K') & 0x8000){
        int nuevaRotacion = pieza.rotacion(-1);

        if (tablero.colision({.pieza = pieza, .rotacion = nuevaRotacion}) == false)
            {
                pieza.indiceRotacion = nuevaRotacion;
            }
    }

    //Caida mas rápida
    softDropActivo = (GetAsyncKeyState('S') & 0x8000);

    //Caida instantanea
    if(GetAsyncKeyState('W') & 0x0001){
        int dX = 0;
        while(!tablero.colision({.pieza = pieza, .caida = dX})){
            dX++;
        }
        pieza.drop+=(dX-1)*2;
        pieza.Y+= (dX-1);
    }
}

void juego::actualizarJuego(){
    if (tablero.colision({.pieza = pieza, .caida = 1}))
        {
            tablero.fijarPieza(pieza);

            int lineas = tablero.lineaCompleta();

            jugador.sumarPuntos(lineas, pieza.drop);

            pieza.inicializar();

            if (tablero.colision({.pieza = pieza})==true)
            {
                bucle = false;
            }
        }
        else if (!tablero.colision({.pieza = pieza, .caida = 1}))
        {
            pieza.mover(0,1);
            if (softDropActivo) { pieza.drop+=1; }
        }
}