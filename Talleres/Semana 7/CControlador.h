#pragma once
#include "CMonigote.h"
#include "CCasa.h"
#include "CVacuna.h"
#include "CVirus.h"
class CControlador {
private:
	vector<CVacuna*> vacuna;
	vector<CVirus*> virus;
	CMonigote* mono;
	CCasa* casa;
public:
	CControlador(int cant){
		mono = new CMonigote();
		casa = new CCasa();
		for (int i = 0; i < cant; i++) {
			virus.push_back(new CVirus());
		}
	}
	~CControlador(){}
	void borrartodo() {
		mono->borrar();
		casa->borrar();
		for (int i = 0; i < virus.size(); i++) {
			virus[i]->borrar();
		}
		for (int i = 0; i < vacuna.size(); i++) {
			vacuna[i]->borrar();
		}
	}
	void agregarVacuna() {
		CVacuna* objVacuna = new CVacuna();
		if (vacuna.size() < 5) {
			vacuna.push_back(objVacuna);
		}
	}
	void movertodo() {
		for (int i = 0; i < virus.size(); i++) {
			virus[i]->mover();
		}
		for (int i = 0; i < vacuna.size(); i++) {
			vacuna[i]->mover();
		}
	}
	bool colision(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2) {
		if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
			return true;
		}
		return false;
	}
	void monovac() {
		for (int i = 0; i < vacuna.size(); i++) {
			if (colision(mono->getX(), mono->getY(), mono->getAncho(), mono->getAlto(),
				vacuna[i]->getX(), vacuna[i]->getY(), vacuna[i]->getAncho(), vacuna[i]->getAlto())) {
				mono->setInmunidad(true);
				mono->getMovi(10);
			}
		}
	}
	bool monovi() {
		for (int i = 0; i < virus.size(); i++) {
			if (colision(mono->getX(), mono->getY(), mono->getAncho(), mono->getAlto(),
				virus[i]->getX(), virus[i]->getY(), virus[i]->getAncho(), virus[i]->getAlto())) {
				mono->menosvida();
				mono->setX(1);
				mono->setY(1);
				if (mono->getVida() == 0) {
					return true;
				}
			}
		}
		return false;
	}
	bool monocasa() {
		if (colision(mono->getX(), mono->getY(), mono->getAncho(), mono->getAlto(),
			casa->getX(), casa->getY(), casa->getAncho(), casa->getAlto())) {
			return true;
			}
		return false;
	}
	void dibujartodo() {
		mono->dibujar();
		casa->dibujar();
		for (int i = 0; i < virus.size(); i++) {
			virus[i]->dibujar();
		}
		for (int i = 0; i < vacuna.size(); i++) {
			vacuna[i]->dibujar();
		}
	}
	CMonigote* getMono() { return mono; }
};
