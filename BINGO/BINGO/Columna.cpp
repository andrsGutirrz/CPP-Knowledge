#include "Columna.h"

Columna::Columna(int num) : num(num) {
	this->primero = NULL;
	initNodos();
}

bool Columna::vacio() {
	return (primero == NULL);
}

int Columna::getNum()const {
	return num;
}

Nodo* Columna::getPrimero() {
	return primero;
}

void Columna::initNodos() { //Nodo(fila,columna)
	Nodo*  aux = primero;
	vector<int> v = shuffle(); //5 numeros aleatorios.
	for (int i = 0; i < 5; i++) {
		if (vacio()) {
			primero = aux = new Nodo(i + 1, getNum(), v[i]); //Se inicializa la primer casilla "Nodo".
		}											   
		else {
			aux->abajo = new Nodo(i + 1, getNum(), v[i]); //Inicializacion de casillas restantes.
			aux->abajo->arriba = aux;
			aux = aux->abajo;
		}
	}
}

void Columna::fusionar(Columna* cl) { //Fusiona con otra lista recibida por parametro.
	Nodo * a = primero;
	Nodo * b = cl->getPrimero();

	while (a->abajo != NULL && b->abajo != NULL) { //Se unen los enlaces entre las dos listas.
		a->derecha = b; // →
		b->izquierda = a; // ←
		a->abajoDerecha = b->abajo; // ↓→ 
		b->abajo->arribaIzquierda = a; // ↑←
		b->abajoIzquierda = a->abajo; // ↓←
		a->abajo->arribaDerecha = b;  // ↑→
		a = a->abajo; // Avanzar
		b = b->abajo; // Avanzar
	}
	a->derecha = b; //→
	b->izquierda = a; //←
}

Nodo* Columna::obtenerPorFila(int i)const {
	Nodo* aux = primero;
	while (aux != NULL) {
		if (aux->fila == i){
			return aux;
		}
		aux = aux->abajo;
	}
	return aux;
}

Nodo* Columna::obtenerPorDato(int n) {
	Nodo* aux = primero;
	while (aux != NULL) {
		if (aux->dato == n) {
			return aux;
		}
		aux = aux->abajo;
	}
	return NULL;
}

string Columna::toString() {
	stringstream s;
	Nodo* aux = primero;
	while (aux != NULL) {
		s << aux->dato << endl;
		aux = aux->abajo;
	}
	return s.str();
}

vector<int> Columna::shuffle() { //Genera un vector con los numeros aleatorios.
	vector<int> v;
	switch (this->getNum())
	{
	case 1:
		v = vector<int>{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
		break;
	case 2:
		v = vector<int>{ 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
		break;
	case 3:
		v = vector<int>{ 31,32,33,34,35,36,37,38,39,40,41,42,43,44,45 };
		break;
	case 4:
		v = vector<int>{ 46,47,48,49,50,51,52,53,54,55,56,57,58,59,60 };
		break;
	case 5:
		v = vector<int>{ 61,62,63,64,65,66,67,68,69,70,71,72,73,74,75 };
		break;
	}
	Sleep(1);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(v.begin(), v.end(), std::default_random_engine(seed)); v.resize(5);

	return v;
}