#include "Nodo.h"

Nodo::Nodo(int n):
	num(n),iz(NULL),der(NULL),hoja(false),raiz(false),padre(false) {
}

bool Nodo::esRaiz() {
	return this->iz != NULL || this->der != NULL;
}
bool Nodo::esHoja() {
	return this->iz == NULL && this->der == NULL;
}