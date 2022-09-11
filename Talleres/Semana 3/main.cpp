#include "Vector.h"

void menu() {
	cout << "1. Agregar Eclipse" << endl;
	cout << "2. Insertar Eclipse en posicion" << endl;
	cout << "3. Editar tipo eclipse" << endl;
	cout << "4. Borrar eclipse en posicion" << endl;
	cout << "5. Borrar eclipse" << endl;
	cout << "6. Listar Eclipses" << endl;
	cout << "7. Reporte Eclipses en Europa" << endl;
	cout << "8. Reporte Eclipses que ocasionaron sismos" << endl;
	cout << "9. Reporte Eclipses en la noche" << endl;
}

int main() {
	srand(time(NULL));
	int opcion, posicion;
	string fecha;
	string tipoEclipse;
	CVector* objVector = new CVector();

	while (true){
		menu(); cout << "Ingrese opcion: "; cin >> opcion;

		switch (opcion){
		case 1:
			cout << "Ingrese la fecha (dd/mm/aa): "; cin >> fecha;
			objVector->agregarEclipse(fecha);
			cout << "SE AGREGO CON EXITO";
			break;
		case 2:
			cout << "Ingrese la posicion: "; cin >> posicion;
			cout << "Ingrese la fecha (dd/mm/aa): "; cin >> fecha;
			objVector->insertarEclipseEnPosicion(posicion, fecha);
			cout << "SE AGREGO CON EXITO";
			break;
		case 3:
			cout << "Ingrese la posicion: "; cin >> posicion;
			cout << "Ingrese el nuevo tipo de eclipse: "; cin >> tipoEclipse;
			objVector->editarTipoEclipse(posicion, tipoEclipse);
			cout << "SE EDITO CON EXITO";
			break;
		case 4:
			cout << "Ingrese la posicion: "; cin >> posicion;
			objVector->borrarEclipseEnPosicion(posicion);
			cout << "SE BORRO CON EXITO";
			break;
		case 5:
			objVector->borrarEclipse();
			cout << "SE BORRO CON EXITO";
			break;
		case 6:
			objVector->imprimirDatosVector();
			break;
		case 7:
			objVector->eclipseVisibleEuropa();
			break;
		case 8:
			objVector->eclipsesOcasionaronSismos();
			break;
		case 9:
			objVector->eclipseNoche();
			break;
		}
		_getch();
		system("cls");
	}

	_getch();
	return 0;
}
