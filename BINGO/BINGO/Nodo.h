#pragma once
#include <string>
using namespace std;

class Nodo  // Cada Nodo, representa una casila en el carton de BINGO.
{
public:
	Nodo(int, int, int); //Fila, Columna y Dato(numero) del nodo en el carton.
	Nodo(); //Constructor sin parametros.

	int fila;
	int columna;
	int dato;

//Enlaces:

	//ARRIBA//
	Nodo *arriba;
	Nodo *arribaDerecha;
	Nodo *arribaIzquierda;
	//ABAJO//
	Nodo *abajo;
	Nodo *abajoDerecha;
	Nodo *abajoIzquierda;
	//EXTREMOS//
	Nodo *derecha;
	Nodo *izquierda;
};