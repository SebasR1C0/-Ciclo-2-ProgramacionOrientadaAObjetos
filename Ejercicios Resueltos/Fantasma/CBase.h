#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
using namespace System;
#define wConsola 120
#define hConsola 30
class CBase {
protected: 
	int x, y, ancho, alto, dy, dx;
	vector<string>dibujo;
	bool eliminar;
public:
	CBase(int alto, int ancho) {
		this->ancho = ancho;
		this->alto = alto;
		eliminar = false;
		do {
			dx = (rand() % 3 - 1) * rand() % 2 + 1;
			dy = (rand() % 3 - 1) * rand() % 2 + 1;
		} while (dx == 0 && dy == 0);
	}
	~CBase(){}
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getY() { return y; }
	int getX() { return x; }
	int getDy() { return dy; }
	int getDx() { return dx; }
	bool getEliminar() { return eliminar; }
	void setEliminar(bool eliminar) { this->eliminar= eliminar; }
	void dibujar() {
		for (int i = 0; i < dibujo.size(); i++) {
			Console::SetCursorPosition(x, y + i);
			cout << dibujo[i];
		}
	}
	void borrar() {
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x+j, y + i);
				cout << " ";
			}
		}
	}
	void vmover(int a, int b) {
		if (x + dx<0 || x + dx + ancho > wConsola) dx *= a;
		if (y + dy<0 || y + dy + alto > hConsola) dy *= b;
		x += dx;
		y += dy;
	}
	virtual void mover() {}
};
