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

class CasillaTren:public CasillaPropiedad
{
	public:
		CasillaTren(string, bool, int);
		~CasillaTren();	
		void toString(int,int);
};