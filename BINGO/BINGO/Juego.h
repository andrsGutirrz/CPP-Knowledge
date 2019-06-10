#pragma once
#include<iostream>
#include<list>
#include"Jugador.h"
#include"Tombola.h"
#include"HTMLInterface.h"

using namespace std;

class Juego {
public:
	Juego(int,int,int); //Numero de jugadores, maxCartones, tipo de juego.
	void initJugadores();
	list<Jugador*> getJugadores();
	void jugar();

	static bool cartonLleno(Carton*);
	static bool cartonHorizontal(Carton*);
	static bool cartonVertical(Carton*);
	static bool cartonX(Carton*);
	static bool cartonC(Carton*);
	static bool cartonU(Carton*);
	static bool cartonO(Carton*);

	bool bingo();

	static int MAX_CARTONES;
	Tombola *tombola;

	static const int CARTON_LLENO = 1;
	static const int CARTON_HORIZONTAL = 2;
	static const int CARTON_VERTICAL = 3;
	static const int CARTON_X = 4;
	static const int CARTON_C = 5;
	static const int CARTON_U = 6;
	static const int CARTON_O = 7;

private:
	list<Jugador*> jugadores;
	Jugador* jugadorGanador;
	int numJugadores;
	int tipoJuego;

	HTMLInterface *ui;
};