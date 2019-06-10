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
#include "Casilla.h"

class CasillaServicio:public CasillaPropiedad
{
	private:
		string tipo;
	public:
		CasillaServicio();
		CasillaServicio(string, string, bool, int);
		~CasillaServicio();
		void setTipo(string);
		string getTipo();
		void toString(int,int);
};