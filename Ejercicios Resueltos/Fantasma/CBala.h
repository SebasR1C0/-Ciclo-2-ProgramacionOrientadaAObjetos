#pragma once
#include "CBase.h"
class CBala : public CBase {
public:
	CBala(int px, int py, int pdy, int pdx) : CBase(1,1) {
		x = px;
		y = py;
		dx = pdx;
		dy = pdy;
		dibujo.push_back("*");
	}
	~CBala(){}
	void mover() {
		vmover(0, 0);
	}
};
