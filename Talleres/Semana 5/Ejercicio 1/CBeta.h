#pragma once
#include "CBase.h"
class CBeta : public CBase
{
public:
	CBeta() : CBase(11, 3) {
		x = (wConsola - ancho) / 2;
		dibujo.push_back("  .---. ");
		dibujo.push_back("_/__~0_\\_");
		dibujo.push_back("(_________)");
	}
	~CBeta() {}
	void mover() {
		validarMovimiento(0, dy*-1);
	}
};
