#include "nodo.h"

nodo::nodo(int _dato,nodo* _sig):siguente(_sig),dato(_dato){
}

nodo::~nodo(){
}

void nodo::setSiguiente(nodo* _dato){
	this->siguente = _dato;
}

nodo* nodo::getSiguiente() const {
	return this->siguente;
}

string nodo::toString() {
	stringstream s;
	s << "Dato: " << this->dato << "\n";
	return s.str();
}