#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

string nombreIngredientes[3] = { "Huevo", "Harina", "Vainilla" };
string unidadesMedidas[3] = { "Gramos", "Kilogramos","Mililitros" };

class CIngredientes {
private:
	string nombreI;
	string unidadMedida;
	int cantidad;
	double caloriasPorcion;

public:
	CIngredientes() {
		nombreI = nombreIngredientes[rand() % 3];
		unidadMedida = unidadesMedidas[rand() % 3];
		cantidad = rand() % 9 + 1;
		caloriasPorcion = rand() % 400 + 100;
	}
	~CIngredientes() {}

	int getCantidad() { return cantidad; }
	int getCaloriasPorcion() { return caloriasPorcion; }

	void datoIngredientes() {
		cout << "Nombre ingredientes: " << nombreI << endl;
		cout << "Unidad medida: " << unidadMedida << endl;
		cout << "Cantidad: " << cantidad << endl;
		cout << "Calorias por porcion: " << caloriasPorcion << endl;
	}
};
