#include "CControladora.h"
void main() {
	Console::SetWindowSize(wConsola, hConsola);
	CControladora* objC = new CControladora();
	objC->juego();
	getch();
}
