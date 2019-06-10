#include"Tombola.h"

Tombola::Tombola() {
	vector<int> numeros = this->shuffle();
	for each (int var in numeros){
		bolitas.push(var);
	}
}

bool Tombola::vacio() {
	return bolitas.empty();
}

int Tombola::sacar() //Saca una bolita.
{
	int bolita = bolitas.top();
	bolitas.pop();

	return bolita;
}

int Tombola::tope() {
	return bolitas.top();
}

vector<int> Tombola::shuffle() {
	vector<int> v; v.resize(75);
	for (int i = 0; i < 75; i++) {
		v[i] = i + 1;
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
	return v;
}