#pragma once
#include "Movimiento.h"

class CBus : public CMovimiento{

public:
	CBus():CMovimiento(){
		dx = rand() % 2 + 3;
		ancho = 14; //RECORDAR CAMBIAR CUANDO SE DIBUJA
		alto = 3;
	}
	~CBus(){}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "             ";
		Console::SetCursorPosition(x, y + 1); cout << "             ";
		Console::SetCursorPosition(x, y + 2); cout << "             ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " _/_|[][][][]";
		Console::SetCursorPosition(x, y + 1); cout << "(           |";
		Console::SetCursorPosition(x, y + 2); cout << "=-OO     OO-=";
	}
};
