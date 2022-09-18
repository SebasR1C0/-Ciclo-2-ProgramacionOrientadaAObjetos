#include "CControladora.h"
void main() {
	srand(time(NULL));
	Console::SetWindowSize(wConsola, hConsola);
	CControladora* objC = new CControladora();
	objC->juego();
	getch();
}
