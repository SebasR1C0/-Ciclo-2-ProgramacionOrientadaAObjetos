#pragma once
#include "CFigura.h"
class CTriangulo : public CFigura {
private:
public:
	CTriangulo() : CFigura() {
		lado = rand() % 3 + 3;
	}
	~CTriangulo() {}
	void dibujar() {
		ttipo();
		if (relleno % 2 == 1) {
			for (int i = 0; i < lado; i++) {
				for (int j = 0; j <= i; j++) {
						Console::SetCursorPosition(x + j, y + i);
						cout << cara;
				}
			}
		}
		else {
			for (int i = 0; i < lado; i++) {
				for (int j = 0; j <= i; j++) {
					if (j == 0 || j==i || i + 1 == lado) {
						Console::SetCursorPosition(x + j, y + i);
						cout << cara;
					}
				}
			}
		}
	}
	void borrar() {
		for (int i = 0; i < lado; i++) {
			for (int j = 0; j <= i; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}
};
