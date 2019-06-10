#pragma once
#include <iostream>
#include <sstream>
#include "nodo.h"
using namespace std;

class lista {
public:
	lista();
	~lista();
	void insertarInicio(int);
	void insertarFinal(int);
	string toString();
	int getCantidad() const;
private:
	nodo* primero;
	nodo* actual;
	nodo* ultimo;
	int cantidad;
};