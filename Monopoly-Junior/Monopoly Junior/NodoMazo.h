//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

#pragma once
#include "Librerias.h"
#include "TarjetaSuerte.h"

class NodoMazo
{
private:
	TarjetaSuerte * t;
	NodoMazo * sig;
public:
   NodoMazo(TarjetaSuerte *, NodoMazo*);
   ~NodoMazo();
   void setTarjeta(TarjetaSuerte*);
   TarjetaSuerte *getTarjeta();
   void setSig(NodoMazo*);
   NodoMazo* getSig();
   void toStringNodo();
};