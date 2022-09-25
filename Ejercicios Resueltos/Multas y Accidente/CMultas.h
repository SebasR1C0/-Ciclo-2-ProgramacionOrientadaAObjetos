#pragma once
#include <iostream>
#include<vector>
#include "CAccidentes.h"
using namespace std;
string distritos[3] = { "Lince", "Surco", "La Molina" };
class CMultas{
	int dia, ano, mes, hora,referencia;
	string lugar;
	double importe;
public:
	CMultas() {
		referencia = rand() % 9000 + 1000;
		dia = rand() % 30 + 1;
		ano = rand() % 5 + 2018;
		mes = rand() % 12 + 1;
		hora = rand() % 23 * 100 + 100;
		lugar = distritos[rand() % 3];
		importe = rand() % 2001 + 1000;
	}
	~CMultas(){}
	void datos() {
		cout << "Multa:" << endl;
		cout << "Numero de referencia: " << referencia << endl;
		cout << "Fecha de la infraccion: " << dia << "/" << mes << "/" << ano << endl;
		cout << "Hora de la infraccion: " << hora << endl;
		cout << "Lugar de la infraccion: " << lugar << endl;
		cout << "Importe de la infraccion: " << importe << endl;
		cout << endl;
	}
};
