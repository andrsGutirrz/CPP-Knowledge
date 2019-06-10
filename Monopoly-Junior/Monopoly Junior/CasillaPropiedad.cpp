#include "CasillaPropiedad.h"

CasillaPropiedad::CasillaPropiedad()
{
	titulo = "NULL";
	monto=0;
	hipotecada=false;
}

CasillaPropiedad::CasillaPropiedad(string tit, bool due, int mont, char t):Casilla(t)
{
	titulo=tit;
	monto=mont;
	duenno=due;
	hipotecada=false;
}

CasillaPropiedad::~CasillaPropiedad(){}

void CasillaPropiedad::setTitulo(string titu)
{
	titulo=titu;
}
string CasillaPropiedad::getTitulo()
{
	return titulo;
}

void CasillaPropiedad::setDuenno(bool b)
{
	duenno=b;
}

bool CasillaPropiedad::getDuenno()
{
	return duenno;
}

void CasillaPropiedad::setMonto(int mont)
{
	monto=mont;
}

int CasillaPropiedad::getMonto()
{
	return monto;
}

void CasillaPropiedad::setHipoteca(bool b)
{
	hipotecada=b;
}

bool CasillaPropiedad::getHipoteca()
{
	return hipotecada;
}
