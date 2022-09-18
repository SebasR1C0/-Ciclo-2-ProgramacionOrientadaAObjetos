pragma once
#include <iostream>
#include <vector>
#include <string>
#define wConsola 120
#define hConsola 40
#define Rectangle System::Drawing::Rectangle
using namespace std;
using namespace System;
class CBase{
public:
	CBase(int pancho, int palto){
		ancho = pancho;
		alto = palto;
		eliminar = false;
		y = 0;
		do {
			dx = rand() % 3 - 1;
			dy = rand() % 3 - 1;
		} while (dx == 0 && dy == 0);
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
	virtual void mover() {
		validarMovimiento(dx * -1, dy * -1);
	}
	void validarMovimiento(int pdx, int pdy) {
		if (x + dx < 0 || x + dx + ancho > wConsola) dx = pdx;
		if (y + dy < 0 || y + dy + alto > hConsola) dy = pdy;
		x += dx;
		y += dy;
	}

	int getdy() { return dy;}
	int getdx() { return dx;}
	Rectangle getRec() {
		return Rectangle(x, y, ancho, alto);
	}
	bool getEliminar() { return eliminar; }
	void setEliminar() { eliminar = true; }
protected:
	int x, y, dx, dy, ancho, alto, tipo;
	bool eliminar;
	vector<string> dibujo;
};
