#include "Vector.h"
void menu(int&t) {
	do{
		cout << "1. Agregar" << endl;
		cout << "2. Listar datos" << endl;
		cout << "3. Modificar" << endl;
		cout << "4. Borrar" << endl;
		cout << "5. Los mas picantes" << endl;
		cout << "6. Los mas caros" << endl;
		cout << "7. Salir" << endl;
		cout << "Elija una opcion: ";
		cin >> t;
	} while (t<1 && t>7);
}
int main() {
	Vector* vec = new Vector();
	int t=NULL, i,c,d,e;
	string a, b;
	while (t!=7) {
		menu(t);
		_sleep(200);
		system("cls");
		switch (t) {
		case 1:
			vec->agregar();
			cout << "Se agrego con exito" << endl;
			break;
		case 2:
			vec->registro();
			break;
		case 3:
			cout << "La posicion que quiere modificar es: ";
			cin >> i;
			cout << "Insertar informacion: " << endl; 
			cout << "Tipo de plato: "; cin >> a;
			cout << "Sabor: ";         cin >> b;
			cout << "Temperatura: ";   cin >> c;
			cout << "Calorias: ";      cin >> d;
			cout << "Precio: ";        cin >> e;
			vec->getPlato()[i-1]->setPlato(a);
			vec->getPlato()[i-1]->setSabor(b);
			vec->getPlato()[i-1]->setTem(c);
			vec->getPlato()[i-1]->setCaloria(d);
			vec->getPlato()[i-1]->setPrecio(e);
			break;
		case 4:
			cout << "Elija la posicion que quiere eliminar es: ";
			cin >> i;
			vec->eliminar(i-1);
			break;
		case 5:
			vec->picante();
			break;
		case 6:vec->dinero();
		}
		getch();
		system("cls");
	}
	_getch();
	return 0;
}
