#pragma once
#include "util.h"
#include <vector>
using namespace std;
string nombrePastel[2] = { "Selva Negra", "Torta Helada" };
class CPastel {
private:
	string nombreP;
	int cantidadPersonas;
	double precio;
	vector<CIngredientes*> Ingredientes;
public:
	CPastel() {
		nombreP = nombrePastel[rand() % 2];
		cantidadPersonas = rand() % 17 + 3;
		precio = rand() % 40 + 20;

	}
	~CPastel() {}
	// SET Y GET
	int getCantidadPersonas() { return cantidadPersonas; } //GETs RETURN VALORES
	// Metodos y Funciones
	void agregarIngredientes() {
		CIngredientes* objIngredientes = new CIngredientes();
		Ingredientes.push_back(objIngredientes);
	}
	void datosPasteles() {
		cout << "Nombre del pastel: " << nombreP << endl;
		cout << "Cantidad de personas: " << cantidadPersonas << endl;
		cout << "Precio: " << precio << endl;
		for (int i = 0; i < Ingredientes.size(); i++) {
			Ingredientes[i]->datoIngredientes();
		}
	}
	int contarIngredientes() {
		return Ingredientes.size();
	}
	double caloriasPastel() {
		for (int i = 0; i < Ingredientes.size(); i++) {
			return Ingredientes[i]->getCaloriasPorcion() * getCantidadPersonas();
		}
	}
};
