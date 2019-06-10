//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

#pragma once
#include"Librerias.h"

class Casilla
{
protected:
	bool jugador1;
	bool jugador2;
	char tipoCasilla;
public:
	Casilla();
	Casilla(char);
	~Casilla();
	void setJugador1(bool);
	void setJugador2(bool);
	bool getJugador1();
	bool getJugador2();
	void setTipoCasilla(char);
	char getTipoCasilla();
	void gotoxy(int, int); //Funcion para imprimir en pantalla mediante coordenadas.
	void colorear(int); //Funcion para dar color si la casilla asi lo requiere.
	virtual void toString(int,int)=0;
};