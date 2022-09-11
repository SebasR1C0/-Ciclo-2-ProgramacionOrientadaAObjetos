#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;
string nombreIngredientes[3] = { "Azucar", "Harina", "Polvo para hornear" };
string unidadesMedidas[3] = { "Gramos", "Kilogramos","Litros" };
class CIngredientes {
	string nombreI, unidad;
	int cantidad;
	double caloriasPorcion;
public:
	CIngredientes() {
		nombreI = nombreIngredientes[rand() % 3];
		unidad = unidadesMedidas[rand() % 3];
		cantidad = rand() % 9 + 1;
		caloriasPorcion = rand() % 400 + 100 + (rand() % 10) / 10;
	}
	~CIngredientes() {
		cout << "Destructor Ingredientes Ejecutandose" << endl;
	}
	int& getCantidad() { return cantidad; }
	double& getCaloriasPorcion() { return caloriasPorcion; }
	void datoIngredientes() {
		cout << "Nombre ingredientes: " << nombreI << endl;
		cout << "Unidad medida: " << unidad << endl;
		cout << "Cantidad: " << cantidad << endl;
		cout << "Calorias por porcion: " << caloriasPorcion << endl;
	}
};
