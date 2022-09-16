#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;
using namespace System;
class Dinosaurio1 {
protected:
	int x, y, alto, ancho, px,py;
	ConsoleColor color;
public:
	Dinosaurio1() {
		ancho = 18;
		alto = 6;
		x = rand() % (120 - ancho);
		y = rand() % (40 - alto);
		color = (ConsoleColor)(rand() % 15 + 1);
	}
	~Dinosaurio1() {}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "               __ ";
		Console::SetCursorPosition(x, y + 1); cout << "              / _)";
		Console::SetCursorPosition(x, y + 2); cout << "     _/\\/\\/\\_/ /  ";
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
	void Mover(){
		px = (rand() % 2) * 2 - 1;
		py = (rand() % 2) * 2 - 1;
		if (px < 0) {
			if (x > 0)x--;
		}
		else {
			if (x + ancho < 120) x++;
		}
		if (py < 0) {
			if (y > 0) y--;
		}
		else {
			if (y + alto < 40) y++;
		}
	}
};
