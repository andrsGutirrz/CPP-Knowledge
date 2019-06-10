#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class nodo {
public:
	nodo(int, nodo*);
	~nodo();
	void setSiguiente(nodo*);
	nodo* getSiguiente()const;
	string toString();
private:
	nodo* siguente;
	int dato;
};