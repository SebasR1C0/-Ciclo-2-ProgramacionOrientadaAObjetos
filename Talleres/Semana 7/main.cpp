#include "CControlador.h"
int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	Console::SetWindowSize(wConsola, hConsola);
	int tiempo = 600;
	int cantVirus;
	char key;
	CControlador* vec;
	cout << "Ingrese una cantidad de virus a mostrar: "; cin >> cantVirus;
	vec = new CControlador(cantVirus);
	Console::Clear();
	while(tiempo!=0){
		for (int i = 0; i < 3; i++) {
			Console::SetCursorPosition(1, i); cout << "              ";
		}
		Console::SetCursorPosition(1, 0); cout << "Tiempo: " << tiempo / 10;
		Console::SetCursorPosition(1, 1); cout << "Inmunidad: " << vec->getMono()->getInmunidad();
		Console::SetCursorPosition(1, 2); cout << "Vida: " <<vec->getMono()->getVida();
		vec->borrartodo();
		if (tiempo % 100 == 0) vec->agregarVacuna();
		if (vec->getMono()->getInmunidad()== false) { if (vec->monovi()) break; }
		vec->monovac();
		if (vec->getMono()->getMovi() < 0) {
			vec->getMono()->setInmunidad(false);
		}
		if (vec->monocasa()) break;

		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			vec->getMono()->mover(key);
		}
		vec->movertodo();
		vec->dibujartodo();
		_sleep(100);
		tiempo--;
	}
	Console::Clear();
	cout << "GAME OVER" << endl;
	cout << "Los pasos fueron: " << vec->getMono()->getPaso() << endl;;
	_getch();
	return 0;
}
