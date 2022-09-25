#pragma once
#include<iostream>
using namespace std;
class CPersona {
	string nombre, apellido, direccion;
	int DNI, telefono;
public: 
	CPersona(string nombre, string apellido, string direccion) {
		this->nombre =  nombre;
		this->apellido =  apellido;
		this->direccion =  direccion;
		DNI = rand() % 90000000 + 10000000;
		telefono = rand() % 100000000 + 900000000;
	}
	~CPersona(){}
	void datos() {
		cout << "Apellido y nombre: " << apellido << ", " << nombre << endl;
		cout << "Direccion: " << direccion << endl;
		cout << "DNI: " << DNI << endl;
		cout << "Telfono: " << telefono << endl;
	}
};
