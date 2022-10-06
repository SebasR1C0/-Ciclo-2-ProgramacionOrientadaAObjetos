#pragma once
#include <conio.h>
#include "CBase.h"
#include "CFantasma.h"
#include "Monigote.h"
class CControlador {
private:
	CMono* mono;
	vector<CFantasma*>fanta;
	char key;
	int tiempo;
public:
	CControlador(int cant){
		mono = new CMono();
		for (int i = 0; i < cant; i++) {
			fanta.push_back(new CFantasma);
		}
	}
	~CControlador(){}
	void juego() {
		tiempo = 600;
		do {
			key = NULL;
			if (_kbhit()) {
				key = _getch();
				key = toupper(key);
			}
			mono->direccion(key);
			if (key == ' ') {
				mono->agrebala();
				key = NULL;
			}
			balafanta();
			gestionar();
			if (tiempo == 0 || fanta.size() == 0 || monofanta()) break;
			_sleep(100);
			tiempo--;
		} while (1);
	}
	void gestionar() {
		for (int i = 0; i < fanta.size(); i++) {
			fanta[i]->borrar();
			fanta[i]->mover();
			fanta[i]->dibujar();
		}
		mono->borrar();
		mono->mover();
		mono->dibujar();
		mono->gesbala();
	}
	bool monofanta() {
		for (int i = 0; i < fanta.size(); i++) {
			if (colision(mono->getX(), mono->getY(), mono->getAncho(), mono->getAlto(),
				fanta[i]->getX(), fanta[i]->getY(), fanta[i]->getAncho(), fanta[i]->getAlto())) {
				return true;
			}
		}
		return false;
	}
	void balafanta() {
		for (int i = 0; i < fanta.size(); i++) {
			for (int j = 0; j < mono->getBala().size(); j++) {
				if (colision(mono->getBala()[j]->getX(), mono->getBala()[j]->getY(),
					mono->getBala()[j]->getAncho(), mono->getBala()[j]->getAlto(),
					fanta[i]->getX(), fanta[i]->getY(), fanta[i]->getAncho(), fanta[i]->getAlto())) {
					fanta[i]->setEliminar(true);
					mono->getBala()[j]->setEliminar(true);
				}
			}
		}
		for (int k = 0; k < fanta.size(); k++) {
			if (fanta[k]->getEliminar()) {
				fanta[k]->borrar();
				fanta.erase(fanta.begin() + k);
			}
		}
	}
	bool colision(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2) {
		if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
			return true;
		}
		return false;
	}
};
