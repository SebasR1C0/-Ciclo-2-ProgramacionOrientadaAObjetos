#include "Dino.h"
void menu(int& opcion) {
	do {
		cout << "1. Dibujar dinosaurio" << endl;
		cout << "2. Dibujar una casa" << endl;
		cout << "Ingresa una opcion: ";
		cin >> opcion;
	} while (opcion < 1 || opcion>6);
	system("cls");
}
int main() {
	int opcion;
	srand(time(NULL));
	Console::SetWindowSize(120, 40);
	Console::CursorVisible = false;
	Dinosaurio1* obj = new Dinosaurio1();
	menu(opcion);
	switch (opcion) {
	case 1:
		while (true) {
			obj->Mostrar();
			_sleep(200);
			obj->Borrar();
			obj->Mover();
		}
		break;
	case 2:
	}
}
