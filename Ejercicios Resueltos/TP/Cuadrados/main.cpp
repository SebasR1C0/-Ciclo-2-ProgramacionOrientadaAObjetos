#include "CCuadrado.h"
#include <vector>
#include <conio.h>
void menu(char &t) {
		cout << "Presionar I se insertan" << endl;
		cout << "Presionar H cambia su direccion horizontal" << endl;
		cout << "Presionar V cambia su direccion vertical" << endl;
		cout << "Presionar R cambia su de ser cuadrados rellenos a cuadrados huecos y viceversa" << endl;
		cout << "Elija una tecla";
		_sleep(700);
		system("cls");
}
int main() {
	srand(time(NULL));
	char t=NULL;
	int pdx, pdy, relleno, tipo;
	vector<CCuadrado*> cuadrado;
	Console::CursorVisible = false;
	Console::SetWindowSize(wConsola, hConsola);
	menu(t);
	while (true) {
		if (_kbhit()) {
			t = _getch();
			t = toupper(t);
			switch (t) {
			case 'I':
				switch (rand() % 2 +1) {
				case 1:
					pdy = rand() % 4 + 2;
					pdx = 0;
					tipo = 1;
					relleno = 1;
					cuadrado.push_back(new CCuadrado(pdx, pdy, rand() % 5 + 3, tipo, relleno));
					break;
				case 2:
					pdx = rand() % 6 + 2;
					pdy = 0;
					tipo = 2;
					relleno = 2;
					cuadrado.push_back(new CCuadrado(pdx, pdy, rand() % 5 + 3, tipo, relleno));
				}
				break;
			case 'H':
				for (int i = 0; i < cuadrado.size(); i++) {
					cuadrado[i]->setDx(cuadrado[i]->getDx() * -1);
				} break;
			case 'V':
				for (int i = 0; i < cuadrado.size(); i++) {
					cuadrado[i]->setDy(cuadrado[i]->getDy() * -1);
				} break;
			case 'R':
				for (int i = 0; i < cuadrado.size(); i++) {
					cuadrado[i]->setRelleno(1);
				}
			}
		}
		for (int i = 0; i < cuadrado.size(); i++) {
			cuadrado[i]->borrar();
			cuadrado[i]->mover();
			cuadrado[i]->dibujar();
		}
		_sleep(200);
	}
	getch();
	return 0;
}
