//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

#pragma once
#include "Librerias.h"
#include "CasillaPropiedad.h"

class CasillaSolar:public CasillaPropiedad
{
	private:
		int numCasa;
		int hotel;
		char color; //Utilizado para llevar control de los monopolios. 'C'=celeste, 'A'=amarillo, 'R'=rojo y 'V'=verde.
	
	public:
		CasillaSolar();
		CasillaSolar(char,int,int,string, bool, int);
		~CasillaSolar();
		void setNumCasa(int);
		void setHotel(int);
		void setColor(char);
		char getColor();
		int getNumCasa();
		int getHotel();
		void toString(int,int);
		void imprimeCasa();
};