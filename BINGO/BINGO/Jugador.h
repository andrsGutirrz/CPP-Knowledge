#pragma once
#include<iostream>
#include<vector>
#include"Carton.h"
using namespace std;

class Jugador {
public:
	Jugador(int, int); //ID y Tipo de juego.
	vector<Carton*> getCartones(); 
	int getId();

	void marcarCasilla(int); //Funcion para marcar en los cartones "X".
	void initCartones();
	void impCartones();
	bool bingo();

private:
	int id;
	int tipoJuego;
	vector<Carton*> cartones;
};