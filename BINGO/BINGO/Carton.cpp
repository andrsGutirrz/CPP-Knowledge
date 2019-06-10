#include "Carton.h"

Carton::Carton() {
	columnas.resize(5);
	for (int i = 0; i < 5; i++){
		columnas[i] = new Columna(i+1);
	}
	fusionarColumnas();
}

Nodo* Carton::getPrimerNodo() {
	return columnas[0]->getPrimero();
}

Nodo* Carton::getNodo(int n) {
	int columna = numColumna(n);
	for (int i = 0; i < 5; i++) {
		if (columnas[columna]->obtenerPorFila(i + 1)->dato == n) {
			return columnas[columna]->obtenerPorFila(i + 1);
		}
		else {
			return NULL;
		}
	}
}

void Carton::fusionarColumnas() {
	for (int i = 0; i < 4; i++) {
		columnas[i]->fusionar(columnas[i + 1]);
	}
}

void Carton::marcarCasilla(int n) {
	int columna = numColumna(n);
	Nodo* aux;
	for (int i = 0; i < 5; i++) {
		aux = columnas[columna]->obtenerPorDato(n);
		if (aux != NULL) {
			aux->dato = 0;
		}
		else {
			return;
		}
	}
}

int Carton::numColumna(int n) {
	if (n >= 1 && n <= 15) {
		return 0;
	}
	else if (n >= 16 && n <= 30) {
		return 1;
	}
	else if (n >= 31 && n <= 45) {
		return 2;
	}
	else if (n >= 46 && n <= 60) {
		return 3;
	}
	else if (n >= 61 && n <= 75) {
		return 4;
	}
}

string Carton::toString() {
	stringstream s;
	s << "[B]    [I]     [N]     [G]     [O]" << endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
			if (columnas[j]->obtenerPorFila(i + 1)->dato != 0) {
				s << columnas[j]->obtenerPorFila(i + 1)->dato << "\t";
			}
			else {
				s << "X" << "\t";
			}
		}
		s << endl;
	}
	return s.str();
}

vector<Columna*> Carton::getColumnas() {
	return columnas;
}