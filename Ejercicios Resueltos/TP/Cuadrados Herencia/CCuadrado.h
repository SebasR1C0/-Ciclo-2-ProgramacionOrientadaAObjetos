#pragma once
#include "CFigura.h"
class CCuadrado : public CFigura {
private:
public:
	CCuadrado() : CFigura() {
		lado = rand()%3+3;
	}
	~CCuadrado() {}
	void dibujar() {
		ttipo();
		if (relleno % 2 == 1) {
			for (int i = 0; i < lado; i++) {
				for (int j = 0; j < lado; j++) {
					Console::SetCursorPosition(x + j, y + i);
					cout << cara;
				}
			}
		}
		else {
			for (int i = 0; i < lado; i++) {
				for (int j = 0; j < lado; j++) {
					if (i == 0 || j == 0 || i + 1 == lado || j + 1 == lado) {
						Console::SetCursorPosition(x + j, y + i);
						cout << cara;
					}
				}
			}
		}
	}
	void borrar() {
		for (int i = 0; i < lado; i++) {
			for (int j = 0; j < lado; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}
};
