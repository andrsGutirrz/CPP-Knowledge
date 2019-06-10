//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

#pragma once
#include "Librerias.h"
#include "Casilla.h"

class CasillaEsquina:public Casilla
{
	protected:
		string titulo;
	public:
		CasillaEsquina();
		CasillaEsquina(string);
		~CasillaEsquina();
		void setTitulo(string);
		string getTitulo();
	    void toString(int,int);
};