//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

#pragma once
#include "NodoMazo.h"
#include "Tarjeta.h"
#include "TarjetaSuerte.h"

class MazoSuerte
{
private:
	NodoMazo *inicio;
	NodoMazo * actual; 

public:
	MazoSuerte();
	void insertar(TarjetaSuerte*); //Inserta un elemento en la cima de la pila.
	TarjetaSuerte* sacar(); //Recupera, devuelve y elimina el último elemento en la cima de la pila.
	void devolver(TarjetaSuerte*); //Regresa el elemento tomado de la pila al final de esta.
    void toString();
	~MazoSuerte();
};