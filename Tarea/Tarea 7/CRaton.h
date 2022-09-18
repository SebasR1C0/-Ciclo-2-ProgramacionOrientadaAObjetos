#pragma once
#include <iostream>
#define anchoConsola 120
#define altoConsola 40
#define Rectangle System::Drawing::Rectangle
using namespace std;
using namespace System;
class CRaton
{
public:
	CRaton() {
		ancho = 17;
		alto = 3;
		x = rand() % (anchoConsola - ancho);
		y = rand() % (altoConsola - alto);
		dx = (rand() % 2 * 2 - 1) * (3 + rand() % 5);
		dy = (rand() % 2 * 2 - 1) * (1 + rand() % 3);
		color = ConsoleColor(rand() % 16);
	}
	~CRaton() {}
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
			cout << "         ____()()";
			Console::SetCursorPosition(x, y + 1);
			cout << "       /       @@ ";
			Console::SetCursorPosition(x, y + 2);
			cout << "`~~~~~\\_;m__m._>o";
		}
		Console::ForegroundColor = ConsoleColor::Gray;
	}
	void mover() {
		if (x + dx < 0 || x + dx + ancho > anchoConsola) dx = dx * -1;
		if (y + dy < 0 || y + dy + alto > altoConsola) dy = dy * -1;
		x += dx;
		y += dy;
	}
	void borrar() {
		for (int i = 0; i < alto; i++)
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
	}
	void redireccionar(int xQueso, int yQueso) {
		if (xQueso < x)
			dx = abs(dx) * -1;
		else
			dx = abs(dx);
		if (yQueso < y)
			dy = abs(dy) * -1;
		else
			dy = abs(dy);
	}
	Rectangle getRectangle() {
		return Rectangle(x,y,ancho,alto);
	}
private:
	int x, y, dx, dy, ancho, alto;
	ConsoleColor color;
};
