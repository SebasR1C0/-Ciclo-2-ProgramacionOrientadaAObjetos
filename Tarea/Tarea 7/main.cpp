#include "Dino.h"
#include "CControladora.h"
#include "CControlador1.h"
void menu(int& opcion) {
	do {
		cout << "1. Dibujar dinosaurio" << endl;
		cout << "2. Atrapar fantasmas" << endl;
		cout << "3. Comenzar una invasion (Presione A para aumentar las naves)" << endl;
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
	CControladora* objB = new CControladora();
	CControlador1* objC = new CControlador1();
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
		cout << "Presione espacio para disparar"<< endl;
		cout << "Sus movimientos son con las tecla A,W,S,D"<<endl;
		system("cls");
		objB->juego();
		getch();
		break;
	case 3:
		cout << "Presione A para agregar una nave"<< endl;
		cout << "Sus movimientos son con las tecla A,W,S,D"<<endl;
		system("cls");
		objC->juego();
		getch();
		break;
	case 4:
	}
}
