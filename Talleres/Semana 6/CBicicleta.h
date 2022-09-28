#pragma once
#include "CTerrestre.h"
class CBicicleta : public CTerrestre
{
public:
	CBicicleta();
	~CBicicleta();
	void mover();
	void dibujar();
private:
	int direccion;
};

CBicicleta::CBicicleta() : CTerrestre(6, 2)
{
	dx = 2;
	tipo = 3;
	dibujo.push_back(".._\\");
	dibujo.push_back("(o)(o)");
	dibujo.push_back("/_..");
	dibujo.push_back("(o)(o)");
}

CBicicleta::~CBicicleta()
{
}

void CBicicleta::mover() {
	validarMover(dx * -1, dy * -1);
}

void CBicicleta::dibujar()
{
	if (dx > 0) direccion = 0;
	else  direccion = 2;
	for (int i = 0; i < alto; i++) { //0 1
		Console::SetCursorPosition(x, y + i);

		cout << dibujo[i + direccion];
	}
}
