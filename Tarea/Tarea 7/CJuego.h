#pragma once
#include "CDibujos1.h"
#include <conio.h>
class CJuego
{
public:
	CJuego(){
		persona = new CPersona();
		for (int i = 0; i < 1 + rand() % 8; i++)
			switch (rand() % 2)
			{
			case 0: vehiculos.push_back(new CCarro()); break;
			case 1: vehiculos.push_back(new CBus()); break;
			}
	}
	~CJuego(){}
	bool colision(){
		for (int i = 0; i < vehiculos.size(); i++) {
			if (vehiculos[i]->colision(persona->getx(), persona->gety(), persona->getancho(), persona->getalto()))
				return true;
		}
		return false;
	}
	void jugar(){
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
	void gestionarTodo(){
		for (int i = 0; i < vehiculos.size(); i++) {
			vehiculos[i]->borrar();
			vehiculos[i]->mover();
			vehiculos[i]->dibujar();
		}
		persona->borrar();
		persona->mover();
		persona->dibujar();
	}
private:
	CPersona* persona;
	vector<CTerrestre*> vehiculos;
};

