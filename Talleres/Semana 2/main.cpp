#include "util.h"
using namespace std;
int main() {
	srand(time(NULL));
	CPersona* persona1;
	CPersona* persona2;
	CPersona* persona3;
	// Primera persona
	persona1 = new CPersona("Jesus", 23, 'H');
	persona1->devolverinfo();
	cout << "El resultado del IMC es: " << persona1->calcularIMC() << endl;
	cout << "La persona es mayor de edad? " << persona1->esMayorEdad() << endl;
	// Segunda persona
	persona2 = new CPersona("Jesus",23,'H',85.5,1.83);
	persona2->devolverinfo();
	cout << "El resultado del IMC es: " << persona2->calcularIMC() << endl;
	cout << "La persona es mayor de edad? " << persona2->esMayorEdad() << endl; 
	// Tercera persona
	persona3 = new CPersona();
	persona3->setNombre("Juan");
	persona3->devolverinfo();
	cout << persona3->getNombre() << endl;
	_getch();
	return 0;
}
