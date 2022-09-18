#include "Dino.h"
#include "CControladora.h"
#include "CControlador1.h"
#include "CManejo.h"
void menu(int& opcion) {
	do {
		cout << "1. Dibujar dinosaurio" << endl;
		cout << "2. Atrapar fantasmas" << endl;
		cout << "3. Comenzar una invasion" << endl;
		cout << "4. Raton atrapa queso" << endl;
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
	Dinosaurio1* objA = new Dinosaurio1();
	CManejo* objD = new CManejo();
	menu(opcion);
	switch (opcion) {
	case 1:
		while (true) {
			objA->Mostrar();
			_sleep(200);
			objA->Borrar();
			objA->Mover();
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
		cout << "Presione espacio para agregar un raton"<<endl;
		cout << "Presione cualquier otra tecla diferente a espacio y X para agregar un queso"<<endl;
		cout << "Presione X para acabar con el juego" << endl;
		system("cls");
		objD->juego();
		getch();
		break;
	}
}
