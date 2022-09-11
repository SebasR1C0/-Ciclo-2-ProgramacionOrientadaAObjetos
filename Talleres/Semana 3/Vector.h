#pragma once
#include <vector>
#include "Eclipse.h"

class CVector{
private:
	vector<CEclipse*> vecEclipse;

public:
	CVector(){}
	~CVector(){}

//-----------REALIZAR EL CRUD (Create/ Read/ Update/ Delete)-----------

	void agregarEclipse(string fecha) {
		CEclipse* objEclipse = new CEclipse(fecha);
		vecEclipse.push_back(objEclipse);
	}

	void insertarEclipseEnPosicion(int posicion, string fecha) {
		CEclipse* objEclipse = new CEclipse(fecha);
		vecEclipse.insert(vecEclipse.begin() + posicion, objEclipse);
	}

	void editarTipoEclipse(int posicion, string tipoEclipse) {
		vecEclipse.at(posicion)->setTipoEclipse(tipoEclipse);
	}

	void borrarEclipseEnPosicion(int posicion) {
		vecEclipse.erase(vecEclipse.begin() + posicion);
	}

	void borrarEclipse() {
		vecEclipse.pop_back();
	}

	void imprimirDatosVector() {
		for (int i = 0; i < vecEclipse.size(); i++){
			cout << "Eclipse " << i << endl;
			vecEclipse[i]->datosEclipse();
		}
	}

//--------------REPORTES----------------

	void eclipseVisibleEuropa() {
		for (int i = 0; i < vecEclipse.size(); i++){
			if (vecEclipse[i]->getVisibilidad() == "Europa") {
				vecEclipse[i]->datosEclipse();
			}
		}
	}

	void eclipsesOcasionaronSismos() {
		for (int i = 0; i < vecEclipse.size(); i++){
			if (vecEclipse[i]->getSismos() == 1) {
				vecEclipse[i]->datosEclipse();
			}
		}
	}

	void eclipseNoche() {
		for (int i = 0; i < vecEclipse.size(); i++){
			if (vecEclipse[i]->getHora() >= 1800) {
				vecEclipse[i]->datosEclipse();
			}
		}
	}
};
