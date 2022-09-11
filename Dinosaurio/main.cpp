#include "util.h"
int main() {
	srand(time(NULL));
	Console::SetWindowSize(ANCHO, ALTO);
	Console::CursorVisible = false;
	Dinosaurio1* obj = new Dinosaurio1();

	while (true) {
		obj->Mostrar();
		if (_kbhit()) {
			char tecla = toupper(_getch());
			obj->Borrar();
			obj->Mover(tecla);

		}

	}


}
