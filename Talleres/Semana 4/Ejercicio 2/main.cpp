#include "CRaton.h"
#include "CQueso.h"
#include <conio.h>
#include <vector>
void main() {
	srand(time(NULL));
	Console::SetWindowSize(anchoConsola, altoConsola);
	Console::CursorVisible = false;
	vector<CRaton*> ratones;
	CQueso* queso = new CQueso();
	char tecla = NULL;
	do{
		if (kbhit()) {
			tecla = getch();
			tecla = toupper(tecla);
			if (tecla == ' ')
				ratones.push_back(new CRaton());
		}
		for (int i = 0; i < ratones.size(); i++) {
			if (ratones[i]->getRectangle().IntersectsWith(queso->getRectangle())) {
				queso->borrar();
			}
		}
		if (tecla != NULL && tecla != ' ' && tecla != 'X') {
			queso->dibujar();
			for (int i = 0; i < ratones.size(); i++) {
				ratones[i]->redireccionar(queso->getX(),queso->getY());
			}	
		}
		for (int i = 0; i < ratones.size(); i++) {
			ratones[i]->borrar();
			ratones[i]->mover();
			ratones[i]->dibujar();
		}
		_sleep(100);
	} while (tecla != 'X');
}
