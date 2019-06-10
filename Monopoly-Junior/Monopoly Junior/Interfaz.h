//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  * Autores/derechos: Andrés Romero Hernández
  *                   Andrés Gutierrez Arcía.
  */

#pragma once
#include"Librerias.h"
#include "Jugador.h"
#include "Tablero.h"

/*
	*Clase encargada de llevar la interfaz a la aplicación.
*/

class Interfaz{

public:
	Interfaz();
	~Interfaz();
	void gotoxy(int,int);// Funcion de sistema para establecer la posicion de pantalla a usar
	void colorear(int);// Funcion para colorear en pantalla.
	void titulo();//Imprime titulo del juego
	void indicaciones();
	void monopolyWorldEditionLogo();
	void musica();
	void menuGeneneral();//Muestra el menu general
	char msjAvanzar();
	void msjCarcel();
	char msjMulta();
	void msjBancaRota();
	void msjGo();
	void limpiarPantalla();
	void interfazDado(int, int, int);
	char comprarPropiedad(int, Jugador*,Tablero*);
	void compraSatisfactoria();
	void yaTienePropiedad();
	void monopolio(int);
	int opcionConstruir(string v[]);
	char opcionesJugador();
	void errorValidacion();
	char terminarJuego();

};