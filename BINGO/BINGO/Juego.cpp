#include "Juego.h"

int Juego::MAX_CARTONES = 0;

Juego::Juego(int a, int b, int c): numJugadores(a),tipoJuego(c) { //Numero de jugadores, maxCartones, tipo de juego.
	tombola = new Tombola();
	jugadorGanador = NULL;
	MAX_CARTONES = b;
	initJugadores();

	ui = new HTMLInterface();
}

bool Juego::bingo() {
	for each (Jugador* j in jugadores){
		if (j->bingo()) { 
			jugadorGanador = j;
			return true; 
		}
	}
	return false;
}

void Juego::jugar()
{
	int bolita;
	while (!tombola->vacio()) {

		bolita = tombola->sacar();
		cout << endl << "Tombola: " << bolita << endl << endl;

		for each (Jugador* j in jugadores){
			j->marcarCasilla(bolita);
		}

		jugadores.front()->impCartones();
		ui->serialize(jugadores, bolita);

		if (this->bingo()) {
			cout << "Jugador GANADOR:" << jugadorGanador->getId() << endl;
			ui->write(jugadorGanador->getId());
			return;
		}
	}
}

void Juego::initJugadores() {
	for (int i = 1; i <= numJugadores; i++){
		jugadores.push_back(new Jugador(i, tipoJuego));
	}
}

list<Jugador*> Juego::getJugadores() {
	return this->jugadores;
}

bool Juego::cartonLleno(Carton* cr) {
	Nodo* aux = cr->getPrimerNodo();
	while (aux != NULL) {
		 	if (aux->dato != 0) {
		 		return false;
		 	}

			if (aux->derecha == NULL) {
			aux = aux->izquierda->izquierda->izquierda->izquierda->abajo;
			}

			if (aux != NULL) {
			aux = aux->derecha;
			}
	}
	return true;
}

bool Juego::cartonHorizontal(Carton* cr) {
	Nodo *primero = cr->getPrimerNodo();
	Nodo *aux = cr->getPrimerNodo();
	int cont = 0;

	while (aux != NULL) {                //Llegamos al final de la fila.
		if (aux->dato == 0) {
			cont++; 
		}
		if (cont == 5) { 
			return true; 
		}
		aux = aux->derecha;

		if (aux == NULL) {
			cont = 0;
			aux = primero->abajo;
			primero = aux;
		}
	}
	return false;
}

bool Juego::cartonVertical(Carton* cr) {
	Nodo* aux = cr->getPrimerNodo();
	int cont = 0;

	for each(Columna* var in cr->getColumnas()) {
		aux = var->getPrimero();
		while (aux != NULL) {
			if (aux->dato == 0) { 
				cont++; 
				if (cont == 5) {return true; }
			}

			else { 
				cont = 0; break; 
			}
			aux = aux->abajo;
		}	
	}
	return false;
}

bool Juego::cartonX(Carton* cr) {
	Nodo* aux = cr->getPrimerNodo();
	int recorrido = 1; //Cambia la direccion del recorrido.

	while (aux != NULL) {
		if (aux->abajoDerecha == NULL && aux->columna == 5) {
			aux = cr->getColumnas()[4]->getPrimero(); //Ultimo de la primer fila.
			recorrido = 2;
		}
		if (aux->dato != 0) { 
			return false;
		}
		switch (recorrido)
		{
		case 1: aux = aux->abajoDerecha;
			break;
		case 2: aux = aux->abajoIzquierda;
			break;
		default: return false;
			break;
		}
	}
	return true;
}

bool Juego::cartonC(Carton* cr) {
	Nodo *aux = cr->getColumnas()[4]->getPrimero();
	int recorrido = 1; //Cambia la direccion del recorrido.
	while (aux != NULL) {
		if (aux->dato != 0) { return false; }
		if (aux->izquierda == NULL) { recorrido = 2; }
		if (aux->izquierda == NULL && aux->abajo == NULL) { recorrido = 3; }
		switch (recorrido)
		{
		case 1: aux = aux->izquierda;
			break;
		case 2: aux = aux->abajo;
			break;
		case 3: aux = aux->derecha;
			break;
		default:
			break;
		}
	}return true;
}

bool Juego::cartonU(Carton* cr) {
	Nodo* aux = cr->getPrimerNodo();
	int recorrido = 1;
	while (aux != NULL) {
		if (aux->dato != 0) { return false; }
		if (aux->izquierda == NULL && aux->abajo == NULL) { recorrido = 2;}
		if (aux->derecha == NULL && aux->abajo == NULL) { recorrido = 3;}
		switch (recorrido)
		{
		case 1: aux = aux->abajo;
			break;
		case 2: aux = aux->derecha;
			break;
		case 3: aux = aux->arriba;
			break;
		default:
			break;
		}
	}
	return true;
}

bool Juego::cartonO(Carton* cr) {
	Nodo* aux = cr->getPrimerNodo();
	int recorrido = 1;
	while (aux != NULL) {
		if (aux->dato != 0) { return false; }
		if (aux->izquierda == NULL && aux->abajo == NULL) { recorrido = 2; }
		if (aux->derecha == NULL && aux->abajo == NULL) { recorrido = 3; }
		if (aux->arriba == NULL && aux->derecha == NULL) { recorrido = 4; }
		switch (recorrido)
		{
		case 1: aux = aux->abajo;
			break;
		case 2: aux = aux->derecha;
			break;
		case 3: aux = aux->arriba;
			break;
		case 4: aux = aux->izquierda;
			break;
		default:
			break;
		}
	}
	return true;
}