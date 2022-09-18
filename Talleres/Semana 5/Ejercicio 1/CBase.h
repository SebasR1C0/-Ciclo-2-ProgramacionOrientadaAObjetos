#pragma once
#include <iostream>
#include <vector>
#include <string>
#define wConsola 110
#define hConsola 30
using namespace std;
using namespace System;
class CBase
{
public:
	CBase(int pancho, int palto) {
		ancho = pancho;
		alto = palto;
		y = 0;
		dx = 0;
		dy = (1 + rand() % 3);
	}
	~CBase() {}
	void borrar() {
		for (int i = 0; i < alto; i++)
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
	}
	void dibujar() {
		for (int i = 0; i < dibujo.size(); i++) {
			Console::SetCursorPosition(x, y + i);
			cout << dibujo[i];
		}
	}
	void validarMovimiento(int pdx, int pdy) {
		if (x + dx < 0 || x + dx + ancho > wConsola) dx = pdx;
		if (y + dy < 0 || y + dy + alto > hConsola) dy = pdy;
		x += dx;
		y += dy;
	}
	virtual void mover() {
		validarMovimiento(0, dy * -1);
	}
protected:
	int x, y, dx, dy, ancho, alto;
	vector<string> dibujo;
};
