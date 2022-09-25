#include "Dino.h"
#include "CControladora.h"
#include "CControlador1.h"
#include "CManejo.h"
#include "Piloto.h"
#include "CJuego.h"
void menu(int& opcion) {
	do {
		cout << "1. Dibujar dinosaurio" << endl;
		cout << "2. Atrapar fantasmas" << endl;
		cout << "3. Comenzar una invasion" << endl;
		cout << "4. Raton atrapa queso" << endl;
		cout << "5. Piloto de avion" << endl;
		cout << "6. Evita ser chocado" << endl;
		cout << "7. No quiero jugar" << endl;
		cout << "Ingresa una opcion: ";
		cin >> opcion;
	} while (opcion < 1 || opcion>7);
	system("cls");
}
int main() {
	int opcion=0;
	char t;
	srand(time(NULL));
	Console::SetWindowSize(120, 40);
	Console::CursorVisible = false;
	CControladora* objB = new CControladora();
	CControlador1* objC = new CControlador1();
	Dinosaurio1* objA = new Dinosaurio1();
	CManejo* objD = new CManejo();
	CPiloto* objE = new CPiloto();
	CJuego* objF = new CJuego();
	while (opcion != 7) {
		Console::ForegroundColor = (ConsoleColor)(7);
		menu(opcion);
		switch (opcion) {
		case 1:
			cout << "Instrucciones" << endl;
			cout << "Sus movimientos son con las tecla A,W,S,D" << endl;
			cout << "Presione X para acabar con el juego" << endl;
			getch();
			system("cls");
			while (t != 'X') {
				t = _getch();
				t = toupper(t);
				objA->Borrar();
				objA->Mover(t);
				objA->Mostrar();
			}
			break;
		case 2:
			cout << "Instrucciones" << endl;
			cout << "Presione espacio para disparar" << endl;
			cout << "Sus movimientos son con las tecla A,W,S,D" << endl;
			getch();
			system("cls");
			objB->juego();
			getch();
			break;
		case 3:
			cout << "Instrucciones" << endl;
			cout << "Presione A para agregar una nave" << endl;
			getch();
			system("cls");
			objC->juego();
			getch();
			break;
		case 4:
			cout << "Instrucciones" << endl;
			cout << "Presione espacio para agregar un raton" << endl;
			cout << "Presione cualquier otra tecla diferente a espacio y X para agregar un queso" << endl;
			cout << "Presione X para acabar con el juego" << endl;
			getch();
			system("cls");
			objD->juego();
			getch();
			break;
		case 5:
			cout << "Instrucciones" << endl;
			cout << "Sus movimientos son con las tecla A,W,S,D" << endl;
			cout << "Presione X para acabar con el juego" << endl;
			getch();
			system("cls");
			objE->jugar();
			getch();
			break;
		case 6:
			cout << "Instrucciones" << endl;
			cout << "Sus movimientos son con las flechas" << endl;
			getch();
			system("cls");
			objF->jugar();
			getch();
			break;
		}
		system("cls");
	}
	return 0;
}
