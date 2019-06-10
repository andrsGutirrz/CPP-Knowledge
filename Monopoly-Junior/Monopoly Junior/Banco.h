#pragma once

#include "Librerias.h"
#include "Tablero.h"
#include "Jugador.h"
#include "VectorTarjetasPropiedad.h"
#include "MazoSuerte.h"
#include "Tarjeta.h"
#include "TarjetaPropiedad.h"
#include "TarjetaSolar.h"
#include "TarjetaServicio.h"
#include "TarjetaTren.h"
#include "Interfaz.h"
#include "Casilla.h"
#include <typeinfo> 
#include "Jugador.h"


class Banco
{
private:
	Tablero *tb;
	VectorTarjetasPropiedad *vt;
	MazoSuerte *ms;
	int cant;
	Interfaz *intfz;
	string nombre;
	string nombre2;
	
public:
	Banco(Tablero* );//para prueba :D
	Banco(Tablero* , VectorTarjetasPropiedad* , MazoSuerte*);
	void venderSolar(int, Jugador*);//Recibe una posicion del tablero, si esta dueño=false se puede comprar
	void instanciarTarjetas(Jugador*,Jugador*);
	void imprimeTarjetaPropiedad(int);//imprime la tarjeta en funcion de la posicion
	void seleccionarConstruccion(Jugador*, char c[]);
	void gotoxy(int x,int y);
	void controlDeMonopolio(char,Jugador*);
	void construye(Casilla*);
	

};
