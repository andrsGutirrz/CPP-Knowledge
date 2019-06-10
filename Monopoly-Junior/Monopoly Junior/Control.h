//Universidad Nacional De Costa Rica
/*  Proyecto #2 de Programación 1
  *  Versión 1.0
  *  Fecha:
  *  Autores/derechos: Andrés Romero Hernández
  *                    Andrés Gutierrez Arcía.
  */

#pragma once
#include"Librerias.h"
#include"Interfaz.h"
#include"Tablero.h"
#include"Jugador.h"
#include"Dado.h"
#include"Banco.h"
#include"MazoSuerte.h"

/*
*	ESTA CLASE SE ENCARGARA DE LLEVAR EL CONTROL DEL JUEGO.
*/

class Control{

private:
	Tablero *t;
	Interfaz *i;
	Dado *d1;
	Dado *d2;
	Jugador *j1;
	Jugador *j2;
	Banco *bc;
	MazoSuerte *m;
	//Banco *b;

public:
	Control();
	~Control();
	Tablero* getTablero();
	Dado* getDado1();
	Dado* getDado2();
	Jugador* getJugador1();
	Jugador* getJugador2();
	//Banco* getBanco();
	void iniciar();//Inicia la aplicacion.
	void jugar(Jugador*,Jugador*);
	void menuPrincipal();
	void avanzar(int, Jugador *);//Recibe el numero obtenido de los dados y avanza la ficha.
	int lanzar();//Lanza los dados.
	void insertarCasillas();
	void llenarMazo();//Llena la pila de cartas del tipo suerte.
	int validadNumeroDado(int);
	bool verificaSuerte(Jugador*);
	char verificaMonopolio(Jugador*);
	void aplicaSuerte(TarjetaSuerte*, Jugador*);
	TarjetaSuerte* tarjetaSuerte();
	bool carcel(Jugador*);
	int fianzaCarcel();
	void pagaFianza(Jugador *);
	bool bancaRota(Jugador *);
	void go(Jugador*, int, int);
	void gotoxy(int,int);
	void opcionesJugador(Jugador*, int);
	void pagarRentaSolar(Jugador*,int, Jugador*);
	void pagarRentaTren(Jugador*,int, Jugador*);
	void pagarRentaServicio(Jugador*,int, Jugador*);
	void verificaImpuesto(Jugador*);
	void cantidadCasasHoteles(Casilla*);
	void ventaPropiedad(Jugador*);
	void hipotecarPropiedad(Jugador*);//para hipotecar
	void levantarHipoteca(Jugador*);//para pagar hipoteca
	bool terminarJuego();
};