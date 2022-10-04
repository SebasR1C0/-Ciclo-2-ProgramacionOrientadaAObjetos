#pragma once
#include <iostream>
using namespace System;
using namespace std;
#define wConsola 120
#define hConsola 30
class CCuadrado {
private: 
	int lado, x, y, dx, dy,tipo, relleno;
public:
	CCuadrado(int dx , int dy, int lado, int tipo, int relleno) {
		this->lado = lado;
		x = rand() % (wConsola - lado);
		y = rand() % (hConsola - lado-5) +5;
		this->dx = dx;
		this->dy = dy;
		this->tipo = tipo;
		this->relleno = relleno;
		this->lado = lado;
	}
	~CCuadrado(){}
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	int getDy() { return dy; }
	int getDx() { return dx; }
	void setRelleno(int relleno) { this->relleno += relleno; }
	void dibujar() {
		ttipo();
		if (relleno % 2 == 1) {
			for (int i = 0; i < lado; i++) {
				for (int j = 0; j < lado; j++) {
					Console::SetCursorPosition(x+j, y+i);
					cout << "*";
				}
			}
		}
		else {
			for (int i = 0; i < lado; i++) {
				for (int j = 0; j < lado; j++) {
					if(i == 0 || j == 0||i+1==lado||j+1==lado){
						Console::SetCursorPosition(x + j, y + i);
						cout << "*";
					}
				}
			}
		}
	}
	void borrar(){
		for (int i = 0; i < lado; i++) {
			for (int j = 0; j < lado; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}
	void mover() {
		if (x + dx <= 0 || x + lado + dx >= wConsola) { dx *= -1; }
		if (y + dy <= 0 || y + lado + dy >= hConsola) { dy *= -1; }
		x += dx;
		y += dy;
	}
	void ttipo() {
		if (tipo % 2 == 1) {
			Console::ForegroundColor = ConsoleColor::Green;
		}
		else {
			Console::ForegroundColor = ConsoleColor::Yellow;
		}
	}
};
