#pragma once
#include "CAccidentes.h"
string marcas[4] = { "Kia", "Toyota", "Hyundai", "Nissan"};
string modelos[4] = { "Yaris", "Camry", "Corolla","Prius" };
class CCarro {
	string matricula, marca, modelo;
	vector<CAccidentes*> Acc;
	char v = NULL;
public: 
	CCarro(string matricula) {
		marca = marcas[rand() % 4];
		modelo = modelos[rand() % 4];
		this->matricula = matricula;
	}
	~CCarro() {}
	void agregar() {
		do {
			cout << "Este usuario tiene accidentes? (S:SI , N:NO ): ";
			cin >> v;
			v = toupper(v);
			if (v == 'S') {
				CAccidentes* objAcc = new CAccidentes();
				Acc.push_back(objAcc);
			}
		} while (v != 'N');
		for (int i = 0; i < Acc.size(); i++) {
			Acc[i]->agregarM();
		}
		cout << endl;
	}
	void datos() {
		cout << "Marca del carro: " << marca << endl;
		cout << "Modelo del carro: " << modelo << endl;
		cout << "Matricula del carro: " << matricula << endl;
		for (int i = 0; i < Acc.size(); i++) {
			Acc[i]->datos();
		}
		cout << endl;
	}
};
