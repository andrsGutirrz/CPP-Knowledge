#include <iostream>
#include "Arbol.h"
using namespace std;

int main() {
	Arbol* arbol = new Arbol();
	/*INSERTAR NODOS*/
	arbol->insertar(arbol->primero,6);
	arbol->insertar(arbol->primero, 3);
	arbol->insertar(arbol->primero, 2);
	arbol->insertar(arbol->primero, 5);
	arbol->insertar(arbol->primero, 9);
	arbol->insertar(arbol->primero, 7);
	arbol->insertar(arbol->primero, 10);
	/*FIN INSERTAR*/
	/*RECORRIDOS*/
	cout << "\nPREORDEN" << endl;
	arbol->preOrden(arbol->primero);
	cout << "\nFIN PREORDEN" << endl;
	cout << "\nINORDEN" << endl;
	arbol->inOrden(arbol->primero);
	cout << "\nFIN INORDEN" << endl;
	cout << "\nPOSTORDEN" << endl;
	arbol->postOrden(arbol->primero);
	cout << "\nFIN POSTORDEN" << endl;
	/*FIN RECORRIDOS*/
	system("pause");

	return 0;
}