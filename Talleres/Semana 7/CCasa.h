#pragma once
#include "CBase.h"
class CCasa : public CBase {
public:
	CCasa() : CBase(4, 11,80,20) {
	}
	~CCasa() {}
	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "          ";
		Console::SetCursorPosition(x, y + 1); cout << "          ";
		Console::SetCursorPosition(x, y + 2); cout << "          ";
		Console::SetCursorPosition(x, y + 3); cout << "          ";
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);   cout << "  __I_    ";
		Console::SetCursorPosition(x, y+1); cout << " /\\-_--\\  ";
		Console::SetCursorPosition(x, y+2); cout << "/  \\_-__\\ ";
		Console::SetCursorPosition(x, y+3); cout << "|[]| [] | ";
	}
	void mover() {
		validarMovimiento(0,0);
	}
};
