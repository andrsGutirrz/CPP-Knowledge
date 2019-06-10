//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  * Autores/derechos: Andrés Romero Hernández
  *                   Andrés Gutierrez Arcía.
  */

/*
	*Tarjetas tipo suerte.
*/

#pragma once
#include"Tarjeta.h"
#include"Librerias.h"

class TarjetaSuerte:public Tarjeta
{
private:
	string enunciado;//Muestra al jugador la accion de lo que pasa o pasara.
	int monto;//Monto devuelto o tomado segun el enunciado de la tarjeta "cobre $500","pague $300", etc.
	int accion;//Numero entero que definira ciertas acciones (avanze n espacios o viceversa).
	char tipoAccion;// A= avanze, R= retroceda, P= pague, C= cobre U=ubicasion(casilla) .

public:
	TarjetaSuerte();
	TarjetaSuerte(string,int,int,char);
	~TarjetaSuerte();
	void setEnunciado(string);
	void setMonto(int);
	void setAccion(int);
	string getEnunciado();
	int getMonto();
	int getAccion();
	char getTipoAccion();
	void gotoxy(int, int);
	void toString(int, int);

};