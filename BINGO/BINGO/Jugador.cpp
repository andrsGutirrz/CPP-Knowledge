#include"Jugador.h"
#include"Juego.h"

Jugador::Jugador(int id, int tipo) : id(id), tipoJuego(tipo) {
	initCartones();
}

void Jugador::initCartones() {
	srand(time(0));
	int num = rand() % Juego::MAX_CARTONES + 1;
	cartones.resize(num);
	for (int i = 0; i < num; i++) {
		cartones[i] = new Carton();
	}
}

vector<Carton*> Jugador::getCartones() {
	return this->cartones;
}

int Jugador::getId() { 
	return id; 
}

void Jugador::marcarCasilla(int n) {
	for each (Carton* c in this->cartones)
	{
		c->marcarCasilla(n);
	}
}

void Jugador::impCartones() {
	for each (Carton* c in cartones) {
		cout << c->toString() << endl;
	}
}

bool Jugador::bingo() {
	bool _bingo = false;
	for each (Carton* var in this->cartones) {
		switch (tipoJuego)
		{
			case Juego::CARTON_LLENO: _bingo = Juego::cartonLleno(var);
				break;
			case Juego::CARTON_HORIZONTAL: _bingo = Juego::cartonHorizontal(var);
				break;
			case Juego::CARTON_VERTICAL: _bingo = Juego::cartonVertical(var);
				break;
			case Juego::CARTON_X: _bingo = Juego::cartonX(var);
				break;
			case Juego::CARTON_C: _bingo = Juego::cartonC(var);
				break;
			case Juego::CARTON_U: _bingo = Juego::cartonU(var);
				break;
			case Juego::CARTON_O: _bingo = Juego::cartonO(var);
				break;
			default: false;
				break;
		}
		if (_bingo) {
			return _bingo;
		}
	}
	return false;
}