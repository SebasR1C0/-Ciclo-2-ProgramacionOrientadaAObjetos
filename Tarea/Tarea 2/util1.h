#pragma once
#include "util.h"
using namespace std;
string nombrePastel[2] = { "Tres leches", "Torta helada" };
class CPastel {
	string nombre, comprador;
	int personas;
	double precio;
	vector<CIngredientes*> ingredientes;
public:
	friend class CTorta;
	CPastel() {
		nombre = nombrePastel[rand() % 2];
		personas = rand() % 12 + 3;
		precio = rand() % 40 + 20 + (rand()%10)/10;
	}
	CPastel(double precio, int personas) {
		nombre = nombrePastel[rand() % 2];
		this->personas = personas;
		this->precio = precio;
	}
	~CPastel() {
		cout << "Destructor Pastel Ejecutandose" << endl;
	}
	void setComprador(string comprador) { this->comprador = comprador; }
	void agregarIngrediente() {
		CIngredientes* obj= new CIngredientes();
		ingredientes.push_back(obj);
	}
	int contarIngredientes() {
		return ingredientes.size();
	}
	double caloriasPastel() {
		double suma=0;
		for (int i = 0; i < ingredientes.size(); i++) {
			suma += ingredientes[i]->getCaloriasPorcion() * ingredientes[i]->getCantidad();
		}
		return suma;
	}

	void datoPastel() {
		cout << "Nombre del cliente: " << comprador << endl;
		cout << "Nombre del pastel: " << nombre << endl;
		cout << "Cantidad personas: " << personas << endl;
		cout << "Precio: " << precio << endl;
		cout << "Calorias: " << caloriasPastel() << endl;
		for (int i = 0; i < ingredientes.size(); i++) {
			ingredientes[i]->datoIngredientes();
		}
	}
};
class CTorta {
public:
	~CTorta() {
		cout << "Destructor Torta Ejecutandose" << endl;
	}
	void amigo(double precio, int personas,string nombre, CPastel&amigo) {
		amigo.nombre = nombre;
		amigo.personas = personas;
		amigo.precio = precio;
	}
	void setComprador(string comprador, CPastel& amigo) { amigo.comprador = comprador; }
};
