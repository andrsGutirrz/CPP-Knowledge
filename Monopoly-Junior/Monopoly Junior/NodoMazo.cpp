#include "NodoMazo.h"

NodoMazo::NodoMazo(TarjetaSuerte * t, NodoMazo* s)
{
	this->t= t;
	sig= s;
}

 NodoMazo:: ~NodoMazo()
 {
	  delete t; 
 }

 void NodoMazo::setTarjeta(TarjetaSuerte* unaTarjeta)
 {
	 t= unaTarjeta;
 }

 TarjetaSuerte *  NodoMazo::getTarjeta()
 { 
	 return t;
 }

 void NodoMazo::setSig(NodoMazo* s)
 { 
	 sig= s;
 }

 NodoMazo* NodoMazo::getSig()
 {
	 return sig;
 }


 void NodoMazo::toStringNodo()
 {
     t->toString(1,1);
 }