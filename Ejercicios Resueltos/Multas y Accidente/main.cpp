#include "CCarro.h"
#include "CPersona.h"
#include <conio.h>
int main() {
	vector<CPersona*> persona;
	char letra;
	vector<CCarro*> carro;
	string nombre, apellido, direccion, matricula;
	cout << "El ciclo acaba cuando se presiona la letra Z" << endl;
	while (letra != 'Z') {
		cout << "El nombre de la persona es: ";
		cin >> nombre;
		cout << "El apellido de la persona es: ";
		cin >> apellido;
		cout << "La direccion de la persona es: ";
		cin >> direccion;
		cout << "La matricula del carro es: ";
		cin >> matricula;
		CPersona* obj = new CPersona(nombre, apellido, direccion);
		persona.push_back(obj);
		CCarro* obj1 = new CCarro(matricula);
		carro.push_back(obj1);
		obj1->agregar();
		letra = _getch();
		letra = toupper(letra);
	}
	for (int i = 0; i < persona.size(); i++) {
		persona[i]->datos();
		carro[i]->datos();
		cout << endl;
	}
	_getch();
	return 0;
}
