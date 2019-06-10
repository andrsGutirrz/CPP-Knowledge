#include "Arbol.h"

Arbol::Arbol() :primero(NULL){
}

void Arbol::insertar(Nodo* nodo, int n) {
	if (primero == NULL) {
		Nodo* nuevo = new Nodo(n);
		primero = nuevo;
	}
	else {
		if (n < nodo->num) {//lado izquierdo
			if (nodo->iz == NULL) {
				Nodo* nuevo = new Nodo(n);
				nodo->iz = nuevo;
			}
			else {
				insertar(nodo->iz, n);
			}
		}
		else {
			if (n > nodo->num) {//lado derecho
				if (nodo->der == NULL) {
					Nodo* nuevo = new Nodo(n);
					nodo->der = nuevo;
				}
				else {
					insertar(nodo->der, n);
				}
			}
		}
	}
}

void Arbol::preOrden(Nodo* nodo) { // raiz, izquierda, Derecha
	if (nodo != NULL) {
		cout <<nodo->num << ",";
		preOrden(nodo->iz);
		preOrden(nodo->der);
	}
}

void Arbol::inOrden(Nodo* nodo) {// Izquierdo, raiz, derecha
	if (nodo != NULL) {
		inOrden(nodo->iz);
		cout <<nodo->num << ",";
		inOrden(nodo->der);
	}
}

void Arbol::postOrden(Nodo* nodo) {
	if (nodo != NULL) {
		postOrden(nodo->iz);
		postOrden(nodo->der);
		cout << nodo->num << ",";
	}
}

/*
	Copyright postOrden,inOrden,preOrden by user4108694 
	https://stackoverflow.com/questions/30529275/binary-tree-class-implematation
*/