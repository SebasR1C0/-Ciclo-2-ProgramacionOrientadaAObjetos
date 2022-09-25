#pragma once
#include "CMultas.h"
class CAccidentes {
protected:
	int dia, ano, mes, hora, referencia;
	char v;
	string lugar;
	vector<CMultas*> Multas;
public: 
	CAccidentes() {
		referencia = rand() % 9000 + 1000;
		dia = rand() % 30 + 1;
		ano = rand() % 5 + 2018;
		mes = rand() % 12 + 1;
		hora = rand() % 23 * 100 + 100;
		lugar = distritos[rand() % 3];
	}
	~CAccidentes() {}
	void agregarM() {
		cout << "Este usuario tiene multas? (S:SI , N:NO ): ";
		cin >> v;
		v = toupper(v);
		if (v == 'S') {
			CMultas* objMultas = new CMultas();
			Multas.push_back(objMultas);
		}
	}
	void datos() {
		cout << "Accidente:" << endl;
		cout << "Numero de referencia: " << referencia << endl;
		cout << "Fecha del accidente: " << dia << "/" << mes << "/" << ano << endl;
		cout << "Hora del accidente: " << hora << endl;
		cout << "Lugar del accidente: " << lugar << endl;
		for (int i = 0; i < Multas.size(); i++) {
			Multas[i]->datos();
		}
		cout << endl;
	}
};
