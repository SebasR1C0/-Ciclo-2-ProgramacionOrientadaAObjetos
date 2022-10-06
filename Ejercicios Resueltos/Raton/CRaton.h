#pragma once
#include <iostream>
using namespace std;
using namespace System;
#define wConsola 120
#define hConsola 30
class CRaton {
private: 
	int x, y, dx, dy, alto, ancho;
	ConsoleColor color;
public: 
	CRaton() {
		alto = 3;
		ancho = 18;
		x = rand() % 100;
		y = rand() % 20;
		do {
			dx = (rand() % 3 - 1) * rand() % 4 + 1;
			dy = (rand() % 3 - 1) * rand() % 3 + 1;
		} while (dx == 0 || dy == 0);
		color = ConsoleColor(rand() % 16);
	}
	~CRaton(){}
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	void dibujar() {
		Console::ForegroundColor = color;
		if (dx < 0) {
			Console::SetCursorPosition(x, y);
			cout << "  ()()____";
			Console::SetCursorPosition(x, y + 1);
			cout << "@@         \\";
			Console::SetCursorPosition(x, y + 2);
			cout << "o<_.m__m;_/~~~~~`";
		}
		else {
			Console::SetCursorPosition(x, y);
			cout << "        ____()()";
			Console::SetCursorPosition(x, y + 1);
			cout << "      /       @@ ";
			Console::SetCursorPosition(x, y + 2);
			cout << "`~~~~~\\_;m__m._>o";
		}
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
	void mover() {
		if (x + dx <0 || x + dx + ancho> wConsola) { dx *= -1; }
		if (y + dy <0 || y + dy + alto > hConsola) { dy *= -1; }
		x += dx;
		y += dy;
	}
	void direccionar(int px, int py) {
		if (px < x) {
			dx = abs(dx) * -1;
		}
		else {
			dx = abs(dx);
		}
		if (py < y) {
			dy = abs(dy) * -1;
		}
		else {
			dy = abs(dy);
		}
	}
};
