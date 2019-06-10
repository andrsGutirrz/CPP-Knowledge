#pragma once
#include <iostream>
#include <algorithm>    // std::shuffle
#include <windows.h>
#include <sstream>
#include <vector>
#include <chrono>
#include <random> 
#include "Nodo.h"

using namespace std;

class Columna  //Lista de casillas (Nodos) y representacion de cada columna del carton.
{
public:
	Columna(int);
	bool vacio();
	int getNum()const;
	Nodo* getPrimero();

	void initNodos();
	void fusionar(Columna*); //Recibe una lista y la fusiona con la recibida por parametro.

	Nodo* obtenerPorDato(int);      //Obtiene el nodo segun el dato contenido.
	Nodo* obtenerPorFila(int)const; //Obtiene el nodo segun su numero de fila.

	string toString();
	vector<int> shuffle();

private:
	Nodo *primero;
	int num; //Numero de fila.
};