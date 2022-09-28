#pragma once
#include "CTerrestre.h"
#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77
class CPersona : public CTerrestre
{
public:
	CPersona();
	~CPersona();
	void mover();
	void direccion(char tecla);
private:

};

CPersona::CPersona() : CTerrestre(3, 2)
{
	dibujo.push_back(" O");
	dibujo.push_back("-|-");
}

CPersona::~CPersona()
{
}

void CPersona::mover() {
	validarMover(0, 0);
}

void CPersona::direccion(char tecla ){
	dx = dy = 0;
	switch (tecla)
	{
	case arriba: dy = -1; break;
	case abajo: dy = 1; break;
	case izquierda: dx = -1;  break;
	case derecha: dx = 1; break;
	}
}
