#include "CJuego.h"
void main() {
	srand(time(0));
	Console::SetWindowSize(wConsola, hConsola);
	Console::CursorVisible = false;
	CJuego* objJ = new CJuego();
	objJ->jugar();
}
