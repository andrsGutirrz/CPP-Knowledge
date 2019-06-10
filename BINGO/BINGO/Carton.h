#pragma once
#include <iostream>
#include "Columna.h"
using namespace std;

class Carton  //Carton conformado de 5 columnas. (5x5)
{
public:
	Carton();
	Nodo* getPrimerNodo();
	Nodo* getNodo(int);

	void fusionarColumnas();
	void marcarCasilla(int);

	int numColumna(int); //Numero de columna segun rango en el que se encuentra el numero recibido.
	string toString();

	vector<Columna*> getColumnas();

private:
	vector<Columna*> columnas; 
};