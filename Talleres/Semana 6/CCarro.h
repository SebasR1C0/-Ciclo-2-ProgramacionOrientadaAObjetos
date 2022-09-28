#pragma once
#include "CTerrestre.h"
class CCarro : public CTerrestre
{
public:
	CCarro();
	~CCarro();
	void mover();
private:
	
};

CCarro::CCarro() : CTerrestre(8, 3)
{
	dx = 3;
	tipo = 1;
	dibujo.push_back("  | ~\\_");
	dibujo.push_back("[| _ | -"	);
	dibujo.push_back(" (_)(_)");
}

CCarro::~CCarro()
{
}

void CCarro::mover() {
	validarMover(dx * -1, dy * -1);
}
