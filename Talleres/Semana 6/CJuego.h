#pragma once
#include "CBicicleta.h"
#include "CPersona.h"
#include "CBus.h"
#include "CCarro.h"
#include <conio.h>
class CJuego
{
public:
	CJuego();
	~CJuego();
	bool colision();
	void jugar();
	void gestionarTodo();
private:
	CPersona* persona;
	vector<CTerrestre*> vehiculos;
};

CJuego::CJuego()
{
	persona = new CPersona();
	for (int i = 0; i < 1 + rand()% 8; i++)
		switch (rand() % 3)
		{
		case 0: vehiculos.push_back(new CCarro()); break;
		case 1: vehiculos.push_back(new CBicicleta()); break;
		case 2: vehiculos.push_back(new CBus()); break;
		}
}

CJuego::~CJuego()
{
}

bool CJuego::colision()
{
	for (int i = 0; i < vehiculos.size(); i++) {
		if (vehiculos[i]->gettipo() != 3) {
			if (vehiculos[i]->colision(persona->getx(), persona->gety(), persona->getancho(), persona->getalto()))
				return true;
		}
	}
	return false;
}

void CJuego::jugar()
{
	char tecla;
	do
	{
		tecla = NULL;
		if (kbhit()) {
			tecla = getch();
			tecla = toupper(tecla);
		}
		persona->direccion(tecla);
		gestionarTodo();
		_sleep(100);
	} while (!colision());
	Console::Clear();
	cout << "Perdiste";
	getch();
}

void CJuego::gestionarTodo()
{
	for (int i = 0; i < vehiculos.size(); i++) {
		vehiculos[i]->borrar();
		vehiculos[i]->mover();
		vehiculos[i]->dibujar();
	}
	persona->borrar();
	persona->mover();
	persona->dibujar();
}
