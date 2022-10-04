#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace System;
using namespace std;
#define wConsola 120
#define hConsola 30
char caracteres[3] = { '*','+','-' };
class CFigura {
protected:
	int lado, x, y, dx, dy, tipo, relleno;
	char cara;
public:
	CFigura() {
		x = rand() % 110;
		y = rand() % 25;
		dx = rand() % 6 + 2;
		dy = rand() % 4 + 2;
		tipo = rand() % 2;
		relleno = rand() % 2;
		cara = caracteres[rand() % 3];
	}
	~CFigura() {}
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	int getDy() { return dy; }
	int getDx() { return dx; }
	void setRelleno(int relleno) { this->relleno += relleno; }

	void mover() {
		if (x + dx <= 0 || x + lado + dx >= wConsola) { dx *= -1; }
		if (y + dy <= 0 || y + lado + dy >= hConsola) { dy *= -1; }
		x += dx;
		y += dy;
	}
	void ttipo() {
		if (tipo % 2 == 1) {
			Console::ForegroundColor = ConsoleColor::Green;
		}
		else {
			Console::ForegroundColor = ConsoleColor::Yellow;
		}
	}
};
