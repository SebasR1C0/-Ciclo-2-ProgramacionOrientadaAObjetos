#include "CControlador.h"
void main() {
	srand(time(NULL));
	Console::SetWindowSize(wConsola, hConsola);
	CControlador* objC = new CControlador(10);
	objC->juego();
	_getch();
}
