#pragma once
#include "CTerrestre.h"
#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77
class CPersona : public CTerrestre{
public:
	CPersona() : CTerrestre(3, 2) {
		dibujo.push_back(" O");
		dibujo.push_back("-|-");
	}
	~CPersona(){}
	void mover(){ validarMover(0, 0); }
	void direccion(char tecla){
		dx = dy = 0;
		switch (tecla)
		{
		case arriba: dy = -1; break;
		case abajo: dy = 1; break;
		case izquierda: dx = -1;  break;
		case derecha: dx = 1; break;
		}
	}
};
class CCarro : public CTerrestre{
public:
	CCarro():CTerrestre(8, 3){
		dx = 3;
		dibujo.push_back("  | ~\\_");
		dibujo.push_back("[| _ | -");
		dibujo.push_back(" (_)(_)");
	}
	~CCarro(){}
	void mover(){ validarMover(dx * -1, dy * -1); }
};
class CBus : public CTerrestre
{
public:
	CBus() :CTerrestre(21, 3) {
		dx = 4;
		dibujo.push_back(" _/_|[][][][][][][]|");
		dibujo.push_back("(                  |");
		dibujo.push_back(" =--OO ---------OO-=");
	}
	~CBus(){}
	void mover(){ validarMover(dx * -1, dy * -1); }
};
