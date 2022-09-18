#pragma once
#include "CBala.h"
class CMonigote : public CBase
{
public:
	CMonigote() : CBase(1, 2){
		y = 0;
		x = 0;
		dx = 0;
		dy = 0;
		dibujo.push_back("0");
		dibujo.push_back("|");
	}
	~CMonigote(){}
	void direccion(char tecla){
		dx = dy = 0;
		switch (tecla)
		{
		case 'A': dx = -1; auxdx = -1; auxdy = 0; break;
		case 'S': dy = 1; auxdy = 1; auxdx = 0; break;
		case 'D': dx = 1; auxdx = 1; auxdy = 0; break;
		case 'W': dy = -1; auxdy = -1; auxdx = 0; break;
		}
	}
	void disparar() {
		balas.push_back(new CBala(x, y, auxdx, auxdy));
	}
	void gestionarBalas() {
		for (int i = 0; i < balas.size(); i++) {
			balas[i]->borrar();
			balas[i]->mover();
			balas[i]->dibujar();
		}
		for (int i = 0; i < balas.size(); i++)
			if (balas[i]->getdy() == 0 && balas[i]->getdx() == 0) {
				balas[i]->borrar();
				balas.erase(balas.begin() + i);
			}
		for (int i = 0; i < balas.size(); i++)
			if (balas[i]->getEliminar()) {
				balas[i]->borrar();
				balas.erase(balas.begin() + i);
			}
	}
	vector<CBala*> getbalas(){
		return balas;
	}
	void mover() {
		validarMovimiento(0, 0);
	}
private:
	vector<CBala*> balas;
	int auxdx, auxdy;
};
