#pragma once
#include <iostream>
#include <vector>

#define wConsola 110
#define hConsola 30

using namespace std;
using namespace System;

class CTerrestre
{
public:
	CTerrestre(int pancho, int palto);
	~CTerrestre();
	void dibujar();
	void validarMover(int pdx, int pdy);
	virtual void mover() = 0;
	void borrar();
	bool colision(int px, int py, int pancho, int palto);

	int getx	();
	int gety	();
	int getdx 	();
	int getdy	();
	int getancho();
	int getalto	();
	int gettipo	();

	void setx    (int value);
	void sety    (int value);
	void setdx   (int value);
	void setdy   (int value);
	void setancho(int value);
	void setalto (int value);
protected:
	int x, y, dx, dy, ancho, alto, tipo;
	vector<string> dibujo;
};

CTerrestre::CTerrestre(int pancho, int palto)
{
	ancho = pancho;
	alto = palto;
	x = rand() % (wConsola - ancho);
	y = rand() % (hConsola - alto);
	dy = 0;
}

CTerrestre::~CTerrestre()
{
}

void CTerrestre::dibujar()
{
	for (int i = 0; i < dibujo.size(); i++) {
		Console::SetCursorPosition(x, y + i);
		cout << dibujo[i];
	}
}

void CTerrestre::validarMover(int pdx, int pdy) // dx*-1 0
{
	if (x + dx < 0 || x + dx + ancho > wConsola) dx = pdx;
	if (y + dy < 0 || y + dy + alto > hConsola) dy = pdy;
	x += dx;
	y += dy;
}

void CTerrestre::borrar()
{
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}

bool CTerrestre::colision(int px, int py, int pancho, int palto)
{
	return (x + ancho > px && x < px + pancho && y + alto > py && y < py + palto);
}

int CTerrestre::getx() { return x; }
int CTerrestre::gety() { return y; }
int CTerrestre::getdx() { return dx; }
int CTerrestre::getdy() { return dy; }
int CTerrestre::getancho() { return ancho; }
int CTerrestre::getalto() { return alto; }
int CTerrestre::gettipo() { return tipo; }

void CTerrestre::setx    (int value){  x     = value;}  
void CTerrestre::sety    (int value){  y     = value;} 
void CTerrestre::setdx   (int value){  dx    = value;} 
void CTerrestre::setdy   (int value){  dy    = value;} 
void CTerrestre::setancho(int value){  ancho = value;}
void CTerrestre::setalto (int value){  alto  = value;}
