#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona {
public:
	Persona(string,int);
	string toString();
private:
	int edad;
	string nombre;
};

#endif

