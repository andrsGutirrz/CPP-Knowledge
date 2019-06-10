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

class CasillaImpuesto:public Casilla
{
	protected:
		string titulo;
		int monto;
	public:
		CasillaImpuesto();
		CasillaImpuesto(string, int);
		~CasillaImpuesto();
		void setTitulo(string);
		string getTitulo();
		void setMonto(int);
		int getMonto();
		void toString(int,int);
};