#include "CBase.h"
class CMonigote : public CBase {
private: 
	int vida, movi, paso;
	bool inmunidad;
public:
	CMonigote() : CBase(2, 1, 20, 1) {
		dy = 1;
		dx = 1;
		vida = 3;
		movi = 0;
		paso = 0;
		inmunidad = false;
	}
	~CMonigote() {}
	int getVida() { return vida; }
	int getMovi() { return movi; }
	int getPaso() { return paso; }
	int getInmunidad() { return inmunidad; }
	void getMovi(int movi) { this-> movi =  movi; }
	void setInmunidad(bool inmunidad) { this->inmunidad = inmunidad; }
	void menosvida() {
		vida--;
	}
	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);   cout << "0";
		Console::SetCursorPosition(x, y+1); cout << "I";
	}
	void mover(char key) {
		switch (key) {
		case 'A':
			if (x + dx >= 0) {
				x -= dx;
				paso++;
				movi--;
			}
			break;
		case 'D':
			if (x + dx + ancho <= wConsola) {
				x += dx;
				paso++;
				movi--;
			}
			break;
		case 'W':
			if (y + dy >= 0) {
				y -= dy;
				paso++;
				movi--;
			}
			break;
		case 'S':
			if (y + dy + alto <= hConsola) {
				y += dy;
				paso++;
				movi--;
			}
			break;
		}
	}
};
