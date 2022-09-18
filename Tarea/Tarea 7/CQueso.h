#pragma once
#include <iostream>
#define anchoConsola 120
#define altoConsola 40
#define Rectangle System::Drawing::Rectangle
using namespace std;
using namespace System;
class CQueso
{
public:
    CQueso() {
        ancho = 11;
        alto = 7;
        x = rand() % (anchoConsola - ancho);
        y = rand() % (altoConsola - alto);
        color = ConsoleColor(rand() % 16);
    }
    ~CQueso(){}
    void dibujar() {
        Console::SetCursorPosition(x, y);
        cout << "     ___";
        Console::SetCursorPosition(x, y + 1);
        cout << "  .'o O'-._";
        Console::SetCursorPosition(x, y + 2);
        cout << " / O o_.-`|";
        Console::SetCursorPosition(x, y + 3);
        cout << "/O_.-'  O |";
        Console::SetCursorPosition(x, y + 4);
        cout << "| o   o .-`";
        Console::SetCursorPosition(x, y + 5);
        cout << "   |o O_.-'";
        Console::SetCursorPosition(x, y + 6);
        cout << "     '--`";
    }
    void borrar() {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                Console::SetCursorPosition(x + j, y + i);
                    cout << " ";
            }
        }
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    Rectangle getRectangle() {
        return Rectangle(x, y, ancho, alto);
    }
private:
    int x, y, ancho, alto;
    ConsoleColor color;
};
