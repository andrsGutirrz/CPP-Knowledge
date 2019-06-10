#include"TarjetaSuerte.h"

TarjetaSuerte::TarjetaSuerte(){}

	TarjetaSuerte::TarjetaSuerte(string enunciado, int monto, int accion, char tipoAccion)
	{
		this->enunciado=enunciado;
		this->monto=monto;
		this->accion=accion;
		this->tipoAccion=tipoAccion;
	}

	TarjetaSuerte::~TarjetaSuerte()
	{
	}

	void TarjetaSuerte::setEnunciado(string unEnunciado)
	{
		enunciado==unEnunciado;
	}

	void TarjetaSuerte::setMonto(int unMonto)
	{
		monto=unMonto;
	}

	void TarjetaSuerte::setAccion(int unaAccion)
	{
		accion=unaAccion;
	}

	string TarjetaSuerte::getEnunciado()
	{
		return enunciado;
	}

	int TarjetaSuerte::getMonto()
	{
		return monto;
	}

	int TarjetaSuerte::getAccion()
	{
		return accion;
	}

	char TarjetaSuerte::getTipoAccion()
	{
		return tipoAccion;
	}

void TarjetaSuerte::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void TarjetaSuerte::toString(int, int)
{
char a=200; //Imprime ╚
char b=186; //Imprime ║
char c=205; //Imprime ═
char d=188; //Imprime ╝
char e=201; //Imprime ╔
char f=187; //Imprime ╗
char g=204; //Imprime ╠
char h=185; //Imprime ╣
char j=174; //Imprime «
char k=202; //Imprime ╩
char l=203; //Imprime ╦

		gotoxy(115,20);	cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;
		gotoxy(115,21); cout<<b<<"                                        "<<b;
		gotoxy(115,22); cout<<b<<"                                        "<<b;
		gotoxy(115,23); cout<<b<<"                                        "<<b;
		gotoxy(115,24); cout<<b<<"                                        "<<b;
		gotoxy(115,25); cout<<b<<"                                        "<<b;
		gotoxy(115,26); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
		gotoxy(117,23); cout<<enunciado;
	}