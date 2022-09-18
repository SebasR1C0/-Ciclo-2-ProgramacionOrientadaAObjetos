#pragma once
#include "CBase.h"
class CAlfa : public CBase
{
public:
	CAlfa() : CBase(19, 5) {
		x = 0;
		dibujo.push_back("      _.---._");
		dibujo.push_back("    .'       '.");
		dibujo.push_back("_.-~===========~-._");
		dibujo.push_back("(_________________)");
		dibujo.push_back("    \\_______/");
	}
	~CAlfa();
	void mover() {
		validarMovimiento(0, dy * -1);
	}
};
