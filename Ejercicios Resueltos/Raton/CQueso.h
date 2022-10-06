#pragma once
#include <iostream>
using namespace std;
using namespace System;
#define wConsola 120
#define hConsola 30
class CQueso {
private:
	int x, y,alto, ancho;
	ConsoleColor color;
	bool eli;
public:
	CQueso() {
		alto = 7;
		ancho = 12;
		x = rand() % 100;
		y = rand() % 20;
	}
	~CQueso() {}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getE() { return eli; }
	void setE(bool eli) { this->eli=eli; }
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
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
		Console::ForegroundColor = ConsoleColor::Gray;
	}
	void borrar() {
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}
	
};
