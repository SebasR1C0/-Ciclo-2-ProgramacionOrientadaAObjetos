#pragma once
#include <iostream>
#include <vector>
using namespace std;
using namespace System;
class CTerrestre
{
public:
	CTerrestre(int pancho, int palto){
		ancho = pancho;
		alto = palto;
		x = rand() % (120 - ancho);
		y = rand() % (40 - alto);
		dy = 0;
	}
	~CTerrestre() {}
	void dibujar(){
		for (int i = 0; i < dibujo.size(); i++) {
			Console::SetCursorPosition(x, y + i);
			cout << dibujo[i];
		}
	}
	void validarMover(int pdx, int pdy){
		if (x + dx < 0 || x + dx + ancho > 120) dx = pdx;
		if (y + dy < 0 || y + dy + alto > 40) dy = pdy;
		x += dx;
		y += dy;
	}
	virtual void mover() = 0;
	void borrar(){
		for (int i = 0; i < alto; i++)
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
	}
	bool colision(int px, int py, int pancho, int palto) {
		return (x + ancho > px && x < px + pancho && y + alto > py && y < py + palto);
	}

	int getx() { return x; }
	int gety() { return y; }
	int getancho() { return ancho; }
	int getalto() { return alto; }
protected:
	int x, y, dx, dy, ancho, alto;
	vector<string> dibujo;
};
