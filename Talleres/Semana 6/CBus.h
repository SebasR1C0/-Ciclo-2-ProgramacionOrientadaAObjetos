#pragma once
#include "CTerrestre.h"
class CBus : public CTerrestre
{
public:
	CBus();
	~CBus();
	void mover();
private:
};

CBus::CBus() : CTerrestre(21, 3)
{
	dx = 4;
	tipo = 2;
	dibujo.push_back(" _/_|[][][][][][][]|");
	dibujo.push_back("(                  |");
	dibujo.push_back(" =--OO ---------OO-=");
}

CBus::~CBus()
{
}

void CBus::mover() {
	validarMover(dx * -1, dy * -1);
}
