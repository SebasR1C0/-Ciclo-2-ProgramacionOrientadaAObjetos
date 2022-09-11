#include "util1.h"
using namespace std;
void menu(int &opciones) {
	do {
		Sleep(400);
		system("cls");
		cout << "1. Agregar ingredientes al pastel" << endl;
		cout << "2. Contar ingredientes" << endl;
		cout << "3. Listar pastel" << endl;
		cout << "Al seleccionar el numero 3 se cerrara la compra" << endl;
		cout << "Ingrese la opcion: "; cin >> opciones;
	} while (opciones > 3 || opciones < 1);
}
void abc(int opciones, CPastel *objPastel) {
	switch (opciones) {
	case 1:
		objPastel->agregarIngrediente();
		cout << "SE AGREGO" << endl;
		break;

	case 2:
		cout << "Cantidad de ingredientes es: " << objPastel->contarIngredientes() << endl;
		break;
	case 3:
		cout << "LISTA PASTEL" << endl;
		objPastel->datoPastel();
		break;
	}
}
int main() {
	srand(time(NULL));
	string name,torta;
	int opciones = 0, invitados;
	double precio;
	CPastel* objPastel = new CPastel();
	CPastel* objPastel1;
	CPastel* objPastel3 = new CPastel();
	CTorta* objPastel2 = new CTorta();
	cout << "Primer cliente" << endl;
	cout << "El nombre del cliente (sin espacios) es: ";
	cin >> name;
	objPastel->setComprador(name);
	while (opciones != 3) {
		menu(opciones);
		abc(opciones, objPastel);
	}
	cout << endl << "Segundo cliente" << endl;
	cout << "El nombre del cliente (sin espacios) es: ";
	cin >> name;
	cout << "Ingrese el precio de torta que quiere comprar: ";
	cin >> precio;
	cout << "Ingrese el numero de invitados: ";
	cin >> invitados;
	objPastel1 = new CPastel(precio, invitados);
	objPastel1->setComprador(name);
	opciones = 0;
	while (opciones != 3) {
		menu(opciones);
		abc(opciones, objPastel1);
	}
	cout << endl << "Tercer cliente" << endl;
	cout << "El nombre del cliente (sin espacios) es: ";
	cin >> name;
	cout << "Ingrese el nombre de la torta (sin espacios): ";
	cin >> torta;
	cout << "Ingrese el precio de torta que quiere comprar: ";
	cin >> precio;
	cout << "Ingrese el numero de invitados: ";
	cin >> invitados;
	objPastel2->amigo(precio,invitados,torta, *objPastel3);
	objPastel2->setComprador(name, *objPastel3);
	opciones = 0;
	while (opciones != 3) {
		menu(opciones);
		abc(opciones, objPastel3);
	}
	Sleep(600);
	system("cls");
	cout << "Datos de la venta del dia:" << endl;
	cout << "Primer cliente:" << endl;
	objPastel->datoPastel();
	cout << endl << "Segundo cliente:" << endl;
	objPastel1->datoPastel();
	cout << endl << "Tercer cliente:" << endl;
	objPastel3->datoPastel();
	_getch();
	return 0;
}
