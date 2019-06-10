#include "Persona.h"
#include <sstream>
Persona::Persona(string _nom, int _edad) {
	this->edad = _edad;
	this->nombre = _nom;
}

string Persona::toString(){
	stringstream s;
	s<<nombre  << " " << edad <<endl;
	return s.str();	
}

