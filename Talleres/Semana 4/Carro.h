#pragma once
#include "Movimiento.h"

class CCarro : public CMovimiento{

public:
	CCarro() : CMovimiento(){
		dx = rand() % 2 + 2;
		ancho = 8; //RECORDAR CAMBIAR CUANDO SE DIBUJA
		alto = 3;
	}
	~CCarro(){}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "       ";
		Console::SetCursorPosition(x, y + 1); cout << "       ";
		Console::SetCursorPosition(x, y + 2); cout << "       ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " __|~\_";
		Console::SetCursorPosition(x, y + 1); cout << "[__|_|-";
		Console::SetCursorPosition(x, y + 2); cout << "(_) (_)";
	}
};
