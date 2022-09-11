#pragma once
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
string nombreIngredientes[3] = { "Huevos", "Harina" , "Vainilla" };
string unidadesMedidas[3] = { "Gramos", "Kilogramos" , "Mililitros" };
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
		cantidad = rand()%9 + 1;
		caloriasPorcion = rand() % 400 + 100;

	}
	~CIngredientes() {}
	// SET Y GET
	int getCantidad() { return cantidad; } //GETs RETURN VALORES
	int getCaloriasPorcion() { return caloriasPorcion; } //SETs EDITAN NOMBRE
	// Metodos y Funciones
	void datoIngredientes() {
		cout << "Nombre Ingredientes: " << nombreI << endl;
		cout << "Unidad Medida: " << unidadMedida << endl;
		cout << "Cantidad: " << cantidad << endl;
		cout << "Calorias por Porcion: " << caloriasPorcion << endl;
	}
};
