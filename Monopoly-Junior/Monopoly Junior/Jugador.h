//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  * Autores/derechos: Andrés Romero Hernández
  *                   Andrés Gutierrez Arcía.
  */

#pragma once
#include "Librerias.h"
#include "Tarjeta.h"
#include "VectorTarjetasPropiedad.h"


const int tam=34;

class Jugador
{
private:

    string nombre;
	int id;
  	int capital;
    int casas;
    int hoteles;
	VectorTarjetasPropiedad *v;

  public:
  	
  	Jugador();
  	Jugador(string, int, int, int, int);
  	~Jugador();
	void setNombre(string);
	void setId(int);
  	void setCapital(int);
	string getNombre();
	int getId();
  	int getCapital();
	int getCantidadVector();
	void insertarTarjeta(TarjetaPropiedad *);
	TarjetaPropiedad* getTarjeta(int);
	void gotoxy(int,int);
	bool tengoLaPropiedad(int);//recibe una posicion de casilla, busca si tiene tarjeta de esa casilla
	void eliminarTarjeta(int);
	int cuantosTrenes();
    void toString();
};