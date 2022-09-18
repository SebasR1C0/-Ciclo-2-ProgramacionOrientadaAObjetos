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
		validarMovimiento(dx * -1, dy * -1);
	}
};
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
		validarMovimiento(dx * -1, dy * -1);
	}
};
class CGamma : public CBase
{
public:
	CGamma() : CBase(17, 10) {
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
	~CGamma() {}
	void mover() {
		validarMovimiento(dx * -1, dy * -1);
	}
};
