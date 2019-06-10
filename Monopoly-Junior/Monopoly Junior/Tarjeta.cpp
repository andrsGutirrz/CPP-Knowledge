#include"Tarjeta.h"

Tarjeta::Tarjeta()
{
	renta=0;
}

Tarjeta::Tarjeta(int renta)
{
	this->renta=renta;
}

Tarjeta::~Tarjeta(){}

void Tarjeta::setRenta(int unaRenta)
{
	renta=unaRenta;
}

int Tarjeta::getRenta()
{
	return renta;
}
