#include "Jugador.h"

 Jugador::Jugador()
{
	nombre=" ";
	capital=0;
	casas=0;
	hoteles=0;
	v=new VectorTarjetasPropiedad(30);
}

Jugador::Jugador(string nom,/*char fic,*/ int id, int cap, int cas, int hot)
{
    nombre=nom;
	this->id=id;
    capital=cap;
    casas=cas;
    hoteles=hot;
	v=new VectorTarjetasPropiedad(30);
}

Jugador::~Jugador()
{
 
}

void Jugador::setNombre(string n)
{
	nombre=n;
}

void Jugador::setId(int d)
{
	id=d;
}

void Jugador::setCapital(int cap)
{
	capital=cap;
}

int Jugador::getCantidadVector()
{
	return v->getCan();
}

void Jugador::insertarTarjeta(TarjetaPropiedad * tp)
{
	v->insertarTarjetaPropiedad(tp);
}

TarjetaPropiedad* Jugador::getTarjeta(int n)
{
	return v->getTarjetaPropiedad(n);
}

string Jugador::getNombre()
{
	return nombre;
}

int Jugador::getId()
{
	return id;
}

int Jugador::getCapital()
{
  return capital;
}

void Jugador::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

bool Jugador::tengoLaPropiedad(int pos)
{
	for (int i = 0; i < this->getCantidadVector(); i++)
	{
		if (this->getTarjeta(i)->getCodigo()==pos)
		{
			return true;
		}
	}
	return false;
}

void Jugador::eliminarTarjeta(int pos)
{
	v->eliminarTarjeta(pos);
}

void Jugador::toString()
{
	gotoxy(110,1);cout<<"Nombre: "<<nombre; //<<" ficha: "<<ficha;
	gotoxy(110,2);cout<<"Capital: "<<capital<<" casas: "<<casas<<" hoteles:"<<hoteles;
	gotoxy(109,3);cout<<"Propiedades: ";
	gotoxy(109,4);v->imprimirNombres();//esta funcion imprime lo snombres de las propiedades, pero no funca bien  :D
	//gotoxy(109,3);cout<<v->getCan()<<endl;
}

int Jugador::cuantosTrenes()
{
	int cont=0;
	for (int i = 0; i < v->getCan(); i++)
	{
		string auxtitulo=v->getTarjetaPropiedad(i)->getTitulo();
		if (auxtitulo=="  TREN 1  "||auxtitulo=="  TREN 2  "||auxtitulo=="  TREN 3  "||auxtitulo=="  TREN 4  ")
		{
			cont++;
		}
	}
	return cont;
}

