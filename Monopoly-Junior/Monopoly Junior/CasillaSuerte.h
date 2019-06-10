//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

/*
	*Casillas para tarjetas del tipo suerte.
*/

#pragma once
#include"Librerias.h"
#include"Casilla.h"
#include"TarjetaSuerte.h"

class CasillaSuerte:public Casilla
{
private:
	//TarjetaSuerte *ts;

public:
	CasillaSuerte(/*TarjetaSuerte **/);
	~CasillaSuerte();
	//string muestraMensaje(); //Muestra el mensaje de la carta de la suerte tomada de la pila.
	void toString(int,int);
};