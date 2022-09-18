#pragma once
#include <conio.h>
#include "CBase.h"
#include "CFantasma.h"
#include "CMonigote.h"
class CControladora
{
public:
	CControladora() {
		jugador = new CMonigote();
		for (int i = 0; i < rand() % 15 + 5; i++) {
			naves.push_back(new CFantasna());
		}
		tiempoInicio = time(0);
	}
	~CControladora(){}
	void juego() {
		char tecla = NULL;
		do
		{
			if (kbhit()) {
				tecla = getch();
				tecla = toupper(tecla);
			}
			jugador->direccion(tecla);
			if (tecla == ' ') {
				jugador->disparar();
				tecla = NULL;
			}
			gestionarTodo();
			colision();
			_sleep(100);
		} while (!(difftime(time(0), tiempoInicio) > 60));
	}
	void gestionarTodo() {
		for (int i = 0; i < naves.size(); i++) {
			naves[i]->borrar();
			naves[i]->mover();
			naves[i]->dibujar();
			if (naves[i]->getdy() == 0) {
				naves[i]->borrar();
				naves.erase(naves.begin() + i);
			}
		}
		jugador->borrar();
		jugador->mover();
		jugador->dibujar();
		jugador->gestionarBalas();
	}
	void colision() {
		for (int i = 0; i < naves.size(); i++)
			for (int j = 0; j < jugador->getbalas().size(); j++) {
				if (naves[i]->getRec().IntersectsWith(jugador->getbalas()[j]->getRec())) {
					jugador->getbalas()[j]->setEliminar();
					naves[i]->setEliminar();
				}
			}
		for (int i = 0; i < naves.size(); i++)
			if (naves[i]->getEliminar()) {
				naves[i]->borrar();
				naves.erase(naves.begin() + i);
			}
	}
private:
	vector<CBase*> naves;
	vector<CBala*> balas;
	CMonigote* jugador;
	time_t tiempoInicio;
};

