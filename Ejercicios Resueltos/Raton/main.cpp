#include "CQueso.h"
#include "CRaton.h"
#include <conio.h>
#include <vector>
bool colision(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2) {
	if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
		return true;
	}
	return false;
}
int main() {
	srand(time(NULL));
	vector<CRaton*> rata;
	CQueso* queso ;
	Console::CursorVisible = false;
	Console::SetWindowSize(wConsola, hConsola);
	char key;
	while (1) {
		key = NULL;
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			if (key == ' ') {
				rata.push_back(new CRaton());
			}
		}
		if (key != ' ' && key != NULL) {
			queso->borrar();
			queso = new CQueso();
			queso->dibujar();
			for (int i = 0; i < rata.size(); i++) {
				rata[i]->direccionar(queso->getX(), queso->getY());
			}
		}
		for (int i = 0; i < rata.size(); i++) {
			if (colision(rata[i]->getX(), rata[i]->getY(), rata[i]->getAncho(), rata[i]->getAlto()
				, queso->getX(), queso->getY(), queso->getAncho(), queso->getAlto())) {
				queso->borrar();
			}
		}

		for (int i = 0; i < rata.size(); i++) {
			rata[i]->borrar();
			rata[i]->mover();
			rata[i]->dibujar();
		}
		_sleep(200);
	}
	getch();
	return 0;
}
