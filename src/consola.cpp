#include "consola.h"
#include <iostream>
#include <windows.h>

using namespace std;

void consola::goToXY(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    
    SetConsoleCursorPosition(hCon, dwPos);
}

void consola::ocultarCursor() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;      // Tamaño del cursor
    cci.bVisible = FALSE; // ¡Adiós cursor!
    SetConsoleCursorInfo(hCon, &cci);
}