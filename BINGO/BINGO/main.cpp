#include <iostream>
#include "Juego.h"

using namespace std;

void main() {
	int cantJugadores, cantCartones, tipoJuego;
	bool jugando = true;
	char opcion;
	Juego* juego = NULL;

	while (jugando) { 
		system("cls");  cout << endl << endl;
		cout << "BIENVENIDO AL SIMULADOR DE [B][I][N][G][O]!!!" << endl << endl;

		cout << "A continuacion digite la opcion en la flecha inferior:" << endl << endl;
		cout << "[1] Iniciar la simulacion." << endl;
		cout << "[2] Salir." << endl << endl;;
		cout << "Opcion -> "; 
		
		try{
			cin >> opcion;
			if (opcion != '1' && opcion != '2') throw std::exception();
		}
		catch (const std::exception &e){
			cerr << " No es una opcion valida, por favor inserte una opcion valida."; 
			cin.get(); cin.get(); opcion = '0';
		}

		switch (opcion)
		{
			case '0':
				break;
			case '1':
				system("cls"); cout << endl << endl;
				cout << "Para iniciar necesitamos cierta informacion, podrias indicar el numero de jugadores? ->"; cin >> cantJugadores;
				cout << "Podrias indicar tambien el numero maximo de cartones por jugador? ->"; cin >> cantCartones;
				cout << "Ya estamos casi listos, podrias escoger una modalidad de juego de la siguiente lista: " << endl << endl;
				cout << "[1]Carton lleno." << endl;
				cout << "[2]Carton horizontal." << endl;
				cout << "[3]Carton vertical." << endl;
				cout << "[4]Carton en X." << endl;
				cout << "[5]Carton en C." << endl;
				cout << "[6]Carton en U." << endl;
				cout << "[7]carton en O" << endl << endl;
				cout << "Tipo de juego ->"; cin >> tipoJuego; system("cls");

				juego = new Juego(cantJugadores, cantCartones, tipoJuego);
				juego->jugar();   cin.get(); cin.get();

				break;
			case '2': 
				cout << endl << "Hasta pronto! :D";
				jugando = false;
		}
	}
	

	cout << endl; system("pause");
}
