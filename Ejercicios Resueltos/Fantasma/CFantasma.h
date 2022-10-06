#pragma once
#include "CBase.h"
class CFantasma:public CBase {
public:
	CFantasma() : CBase(6, 13) {
		x = rand()%100;
		y = rand()%20;
		dibujo.push_back("  ___");
		dibujo.push_back("_/ .oo .\\");
		dibujo.push_back("(.\\..-../__");
		dibujo.push_back("\\.......\\__)");
		dibujo.push_back("/........\\");
		dibujo.push_back("/,,,,,,,,,\\");
	}
	~CFantasma() {}
	void mover() {
		vmover(-1, -1);
	}
};
