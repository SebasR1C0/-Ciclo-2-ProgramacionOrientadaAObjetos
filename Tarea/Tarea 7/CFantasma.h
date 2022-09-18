#pragma once
#include "CBase.h"
class CFantasna : public CBase
{
public:
	CFantasna() : CBase(13, 6) {
		x = rand()%50+50;
		dibujo.push_back("  ___");
		dibujo.push_back("_/ .oo .\\");
		dibujo.push_back("(.\\..-../__");
		dibujo.push_back("\\.......\\__)");
		dibujo.push_back("/........\\");
		dibujo.push_back("/,,,,,,,,,\\");
	}
	~CFantasna();
	void mover() {
		validarMovimiento(dx * -1, dy * -1);
	}
};
