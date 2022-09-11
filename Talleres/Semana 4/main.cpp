#include "Controlador.h"

int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	char key;
	CControlador* objControlador = new CControlador();

	while (true){
		objControlador->borrarTodo();
		
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			objControlador->getPersona()->moverPersona(key);
		}

		objControlador->moverTodo();
		objControlador->dibujarTodo();

		_sleep(100);
	}

	_getch();
	return 0;
}
