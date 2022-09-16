#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
using namespace std;
class CDonaciones {
	double dona, donaS=0,donaI=0,donaP=0, totalS, totalP, totalI;
public:
	friend class CMonto;
	CDonaciones(double dona) {
		if (dona > 0 && dona <= 5000) {
			donaS = dona;
			donaP = 0;
			donaI = 0;
		}
		else if (dona > 5000 && dona <= 10000) {
			donaS = dona * 6 / 10;
			donaP = dona * 4 / 10;
			donaI = 0;
		}
		else if(dona>10000) {
			donaS = dona* 9/20 ;
			donaP = dona* 7/ 20;
			donaI = dona/5 ;
		}
	}
	CDonaciones(double totalS, double totalP, double totalI) {
		  this->totalS = totalS;
		  this->totalP = totalP;
		  this->totalI = totalI;
	}
	~CDonaciones(){}
	 void setdonaS (double donaS){this->donaS=donaS;}
	 void setdonaP (double donaP){this->donaP=donaP;}
	 void setdonaI (double donaI){this->donaI=donaI;}
	 double getdonaS (){ return donaS; }
	 double getdonaP (){ return donaP; }
	 double getdonaI (){ return donaI; }
};
class CMonto {
public:
	CMonto(){}
	~CMonto(){}
	void datos(CDonaciones&vec) {
		cout << "La cantidad de donaciones a la seccion Secundaria es: " << vec.totalS << endl;
		cout << "La cantidad de donaciones a la seccion Primaria es: " << vec.totalP << endl;
		cout << "La cantidad de donaciones a la seccion Inicial es: " << vec.totalI << endl;
	}
};
