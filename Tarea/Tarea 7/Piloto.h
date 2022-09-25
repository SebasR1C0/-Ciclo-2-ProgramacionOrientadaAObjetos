#include "Avion.h"
#include "Nube.h"
class CPiloto {
public:
	void jugar() {
		srand(time(NULL));
		Console::CursorVisible = false;
		char key;
		CAvion* objAvion = new CAvion();
		CNube* objNube = new CNube();
		CNube* objNube2 = new CNube();

		do {
			objNube->borrar();
			objNube2->borrar();
			objAvion->borrar();

			if (_kbhit()) {
				key = _getch();
				key = toupper(key);
				objAvion->mover(key);
			}

			objNube->mover();
			objNube2->mover();
			objNube->dibujar();
			objNube2->dibujar();
			objAvion->dibujar();

			_sleep(100);
		} while (key != 'X');
		_getch();
	}
};
