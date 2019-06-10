#include "lista.h"

lista::lista():primero(NULL),actual(NULL),ultimo(NULL),cantidad(0) {
}

lista::~lista() {
}

void lista::insertarInicio(int _dato) {
	if (!primero) {
		primero = new nodo(_dato, NULL);
		cantidad++;
	}
	else {
		primero = new nodo(_dato, primero);
		cantidad++;
	}
}

void lista::insertarFinal(int _dato) {
	if (!primero) {
		primero = new nodo(_dato, NULL);
		cantidad++;
		ultimo = primero;
	}
	else {
		ultimo->setSiguiente(new nodo(_dato, NULL));
		ultimo = ultimo->getSiguiente();
	}
}

string lista::toString() {
	stringstream s;
	s << "\t" <<"LISTA"<<"\n";
	s << "=================================" << "\n";
	actual = primero;
	while (actual != NULL) {
		s<<actual->toString() << "\n";
		actual = actual->getSiguiente();
	}
	s << "=================================" << "\n";
	return s.str();
}

int lista::getCantidad() const {
	return this->cantidad;
}