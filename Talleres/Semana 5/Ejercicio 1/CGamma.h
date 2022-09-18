#pragma once
#include "CBase.h"
class CGamma : public CBase
{
public:
	CGamma() : CBase(17, 10){
		x = (wConsola - ancho);
		dibujo.push_back("      .");
		dibujo.push_back("      |");
		dibujo.push_back("   .-\"^\"-.");
		dibujo.push_back("  /_....._\\");
		dibujo.push_back("  .-\"` `\"-.  ");
		dibujo.push_back("( ooo ooo ooo ) ");
		dibujo.push_back("'-.,_________,.-'");
		dibujo.push_back("     / \\  ");
		dibujo.push_back("    _/ \\_  ");
		dibujo.push_back("    `\"` `\"`  ");
	}
	~CGamma(){}
	void mover() {
		validarMovimiento(0, dy*-1);
	}
};
