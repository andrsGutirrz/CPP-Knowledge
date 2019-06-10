#include"Casilla.h"

Casilla::Casilla()
{
	jugador1= false;
	jugador2= false;
}

Casilla::Casilla(char c)
{
	jugador1= false;
	jugador2= false;
	tipoCasilla=c;
}

Casilla::~Casilla()
{

}

void Casilla::setJugador1(bool jugador)
{
	jugador1=jugador;
}

void Casilla::setJugador2(bool jugador)
{
	jugador2=jugador;
}

void Casilla::setTipoCasilla(char c)
{
	tipoCasilla= c;
}

char Casilla::getTipoCasilla()
{
	return tipoCasilla;
}

bool Casilla::getJugador1()
{
	return jugador1;
}

bool Casilla::getJugador2()
{
	return jugador2;
}

void Casilla::gotoxy(int x ,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Casilla::colorear(int x)
{
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,x);
}