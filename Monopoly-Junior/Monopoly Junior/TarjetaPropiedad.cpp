#include "TarjetaPropiedad.h"
#include "CasillaPropiedad.h"

TarjetaPropiedad::TarjetaPropiedad()
{
	titulo = "NULL";
	renta=0;
	codigo=-2;
	hipotecada=false;
	
}

TarjetaPropiedad::TarjetaPropiedad(string tit, int mont,int codi, int pHipo):Tarjeta(mont)//Tarjeta(renta,codigo)
{
	titulo=tit;
	codigo=codi;
	hipotecada=false;
	precioHipoteca=pHipo;
}

TarjetaPropiedad::~TarjetaPropiedad(){}

void TarjetaPropiedad::setPrecioHipoteca(int n)
{
	precioHipoteca=n;
}

int TarjetaPropiedad::getPrecioHipoteca()
{
	return precioHipoteca;
}

void TarjetaPropiedad::setCodigo(int c)
{
	codigo=c;
}

int TarjetaPropiedad::getCodigo()
{
	return codigo;
}

void TarjetaPropiedad::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

string TarjetaPropiedad::getTitulo()
{
	return titulo;
}

void TarjetaPropiedad::setHipoteca(bool b)//hipoteca para tarjeta
{
	hipotecada=b;
}

bool TarjetaPropiedad::getHipoteca()
{
	return hipotecada;
}