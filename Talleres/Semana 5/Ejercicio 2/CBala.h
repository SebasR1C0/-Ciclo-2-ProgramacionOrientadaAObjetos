
#pragma once
#include "CBase.h"
class CBala : public CBase{
public:
	CBala(int pxpersona, int pypersona, int pdx, int pdy) : CBase(1,1) {
		x = pxpersona;
		y = pypersona;
		dx = pdx;
		dy = pdy;
		dibujo.push_back("*");
	}
	~CBala(){}
	void mover() {
		validarMovimiento(0, 0);
	}
};

