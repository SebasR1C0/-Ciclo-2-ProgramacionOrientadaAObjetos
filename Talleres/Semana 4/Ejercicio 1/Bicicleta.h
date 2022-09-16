#pragma once
#include "Movimiento.h"

class CBicicleta : public CMovimiento{

public:
	CBicicleta() : CMovimiento(){
		dx = 1;
		ancho = 7; //RECORDAR CAMBIAR CUANDO SE DIBUJA
		alto = 2;
	}
	~CBicicleta(){}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "      ";
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " .._\ ";
		Console::SetCursorPosition(x, y + 1); cout << "(o)(o)";
	}
};
