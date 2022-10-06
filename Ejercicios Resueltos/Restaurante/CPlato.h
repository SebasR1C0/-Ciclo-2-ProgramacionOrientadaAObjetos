#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
string nombre[3] = { "Crepe a la parisienne", "Arepas rellenas", "Pollo a la olla" };
string sabor[2] = { "Picante", "No Picante" };
class CPlato {
private:
	string plato, saborp;
	int tem, caloria, precio;
public:
	CPlato() {
		plato = nombre[rand() % 3];
		saborp = sabor[rand() % 2];
		tem = rand() % 2;
		caloria = rand() % 51 + 10;
		precio = rand() % 101 + 50;
	}
	CPlato(string plato, string saborp,int tem,int caloria,int precio) {
		this->plato   = plato ;
		this->saborp = saborp;
		this->tem = tem;
		this->caloria = caloria ;
		this->precio = precio ;
	}
	~CPlato() {}
	string getSabor() { return saborp; }
	int getPrecio() { return precio; }
	void setPlato(string plato) { this->plato = plato; }
	void setSabor   (string saborp) { this->saborp = saborp; }
	void setTem    (int tem) { this->tem = tem; }
	void setCaloria(int caloria) { this->caloria = caloria; }
	void setPrecio  (int precio) { this->precio = precio; }

	void datos() {
		cout << "Tipo de plato: " << plato << endl;
		cout << "Sabor: " << saborp << endl;
		cout << "Temperatura: " << tem << endl;
		cout << "Calorias: " << caloria << endl;
		cout << "Precio: " << precio << endl;
	}
};
