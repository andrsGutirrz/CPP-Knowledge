//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  * Autores/derechos: Andrés Romero Hernández
  *                   Andrés Gutierrez Arcía.
  */

/*
	*Clase base de objetos tipo tarjeta (Propiedades y suerte).
*/
#pragma once


class Tarjeta
{
protected:
	int renta;
	
public:
	Tarjeta();
	Tarjeta(int);
	~Tarjeta();
	void setRenta(int);
	int getRenta();
	virtual void toString(int, int)=0;
};