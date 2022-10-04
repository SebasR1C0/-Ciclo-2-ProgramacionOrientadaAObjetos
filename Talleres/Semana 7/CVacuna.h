#pragma once
#include "CBase.h"
class CVirus : public CBase {
public:
	CVirus() : CBase(5, 12) {
		x = rand() % (100) + 4;
		y = rand() % (20) + 4;
	}
	~CVirus(){}
	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "           ";
		Console::SetCursorPosition(x, y + 1); cout << "           ";
		Console::SetCursorPosition(x, y + 2); cout << "           ";
		Console::SetCursorPosition(x, y + 3); cout << "           ";
		Console::SetCursorPosition(x, y + 3); cout << "           ";
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << "     q     ";
		Console::SetCursorPosition(x, y + 1); cout << "  o.-o-.o  ";
		Console::SetCursorPosition(x, y + 2); cout << "o-(o o o)-o";
		Console::SetCursorPosition(x, y + 3); cout << "  o.-o-.o  ";
		Console::SetCursorPosition(x, y + 3); cout << "     b     ";
	}
	void mover() {
		validarMovimiento(dx * -1, dy * -1);
	}
};
