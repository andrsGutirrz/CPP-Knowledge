#pragma once

#include<iostream>

class Nodo {
	public:
		Nodo* iz;//nodo Izquierdo
		Nodo* der;//Nodo derecho
		bool hoja;
		bool raiz;
		bool padre;
		int num;//contenido
		Nodo(int);
		bool esRaiz();
		bool esHoja();
};