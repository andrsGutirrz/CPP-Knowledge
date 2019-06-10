#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

class Arbol {
public:
	Nodo* primero;
	Arbol();
	void insertar(Nodo*,int);//insertar Ordenado
	void preOrden(Nodo*);
	void inOrden(Nodo*);
	void postOrden(Nodo*);
};