#pragma once
#include <conio.h>
#include "CAlfa.h"
#include "CBeta.h"
#include "CGamma.h"
class CControladora
{
public:
	CControladora() {
		cA = cB = 0;
		contador = 0;
	}
	~CControladora(){}
	void juego() {
		char tecla;
		string mensaje = "Comienza la invasion!!!!";
		Console::SetCursorPosition((wConsola - mensaje.size()) / 2, (hConsola - 1) / 2);
		cout << mensaje;
		getch();
		Console::Clear();
		do{
			tecla = NULL;
			if (kbhit()) {
				tecla = getch();
				tecla = toupper(tecla);
			}
			if (tecla == 'A') {
				naves.push_back(new CAlfa());
				cA++;
				contador++;
			}
			if (cA == 2) {
				naves.push_back(new CBeta());
				cB++;
				cA = 0;
				contador++;
			}
			if (cB == 2) {
				naves.push_back(new CGamma());
				cB = 0;
				contador++;
			}
			gestionarTodo();
			_sleep(100);
		} while (!(contador >= 20));
		Console::Clear();
		cout << "Fuiste invadido";
	}
	void gestionarTodo() {
		for (int i = 0; i < naves.size(); i++) {
			naves[i]->borrar();
			naves[i]->mover();
			naves[i]->dibujar();
		}
	}
private:
	int cA, cB, contador;
	vector<CBase*> naves;
};
