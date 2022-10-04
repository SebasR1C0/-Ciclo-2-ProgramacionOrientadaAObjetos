#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#define wConsola 120
#define hConsola 30
using namespace std;
using namespace System;
class CBase {
protected:
	int alto, ancho, x, y, dy, dx;
	vector<string> dibujo;
public:
	CBase(){}
	CBase(int alto, int ancho) {
		this->alto = alto;
		this->ancho = ancho;
		x = rand() % (100) + 4;
		y = rand() % (20) + 4;
		dx = rand() % 5 + 2;
		dy = rand() % 3 + 2;
	}
	CBase(int alto, int ancho, int x, int y) {
		this->alto = alto;
		this->ancho = ancho;
		this->x = x; 
		this->y = y;
	}
	~CBase(){}
	void setX(int x) { this->x=x; }
	void setY(int y) { this->y=y; }
	int getX() { return x; }
	int getY() { return y; }
	int getAlto() { return alto; }
	int getAncho() { return ancho; }
	void validarMovimiento(int pdx, int pdy) {
		if (x + dx < 0 || x + dx + ancho > wConsola) dx = pdx;
		if (y + dy < 0 || y + dy + alto > hConsola) dy = pdy;
		x += dx;
		y += dy;
	}
	virtual void mover(){}
	virtual void dibujar() {}
	virtual void borrar() {}
};
