#include"Nodo.h"

Nodo::Nodo(int fil, int col,int _dato) : fila(fil), columna(col),dato(_dato){
	arriba = NULL;
	arribaDerecha = NULL;
	arribaIzquierda = NULL;

	abajo = NULL;
	abajoDerecha = NULL;
	abajoIzquierda = NULL;

	derecha = NULL;
	izquierda = NULL;
}

Nodo::Nodo() : fila(0), columna(0) {
	arriba = NULL;
	arribaDerecha = NULL;
	arribaIzquierda = NULL;

	abajo = NULL;
	abajoDerecha = NULL;
	abajoIzquierda = NULL;

	derecha = NULL;
	izquierda = NULL;
}