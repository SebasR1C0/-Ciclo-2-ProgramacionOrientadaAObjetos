#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
using namespace System;

#define ANCHO 90
#define ALTO 40

class Dinosaurio1 {
protected:
	int x, y, alto, ancho;
	ConsoleColor color;
public:
	Dinosaurio1() {
		ancho = 18;
		alto = 6;
		x = rand() % (ANCHO - ancho);
		y = rand() % (ALTO - alto);
		color = (ConsoleColor)(rand() % 15 + 1);
	}
	~Dinosaurio1() {}

	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "               __ ";
		Console::SetCursorPosition(x, y + 1); cout << "              / _)";
		Console::SetCursorPosition(x, y + 2); cout << "     _/\/\/\_/ /  ";
		Console::SetCursorPosition(x, y + 3); cout << "   _|         /   ";
		Console::SetCursorPosition(x, y + 4); cout << " _|  (  | (  |    ";
		Console::SetCursorPosition(x, y + 5); cout << "/__.-'|_|--|_|    ";
	}
	void Borrar()
	{
		for (int i = 0; i < alto; i++)
			for (int j = 0; j < ancho; j++)
			{
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
	}
	void Mover(char t)
	{
		switch (t)
		{
		case 'W':
			if (y > 0) y--; break; // arriba
		case 'D':if (x + ancho < ANCHO) x++; break; // derecha
		case 'A':if (x > 0)x--; break; // atras
		case 'S':if (y + alto <= ALTO)y++; break;//abajo
		}



	}




};
