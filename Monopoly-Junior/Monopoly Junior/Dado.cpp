#include"Dado.h"

Dado::Dado()
{
	//numero=0;
}

/*void Dado::setNumero(int unNumero)
{
	numero=unNumero;
}

int Dado::getNumero()
{
	return numero;
}*/

int Dado::ram()
{
	srand(time(NULL));
	return 1+(rand()%6);
}