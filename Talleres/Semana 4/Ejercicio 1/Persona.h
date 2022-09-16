#pragma once
#include "Movimiento.h"

class CPersona : public CMovimiento{

public:
	CPersona(int x, int y) : CMovimiento(x, y){
		dx = 2;
		dy = 2;
		ancho = 2;
		alto = 2;
	}
	~CPersona(){}

	void moverPersona(char key) {
		switch (key){
		case 'A':
			if (x >= 2) x -= dx;
			break;
		case 'D':
			if (x + ancho <= 100) x += dx;
			break;
		case 'W':
			if (y >= 2)y -= dy;
			break;
		case 'S':
			if (y + alto <= 60) y += dy;
			break;
		}
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y); cout << "@";
		Console::SetCursorPosition(x, y + 1); cout << char(197);
	}
};
