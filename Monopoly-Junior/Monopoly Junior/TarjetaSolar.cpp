#include "TarjetaSolar.h"

TarjetaSolar::TarjetaSolar()
{
	precioConstruccion=0;
	numeroCasa=0;
	color='C';
}

TarjetaSolar::TarjetaSolar(string tit, int rent ,int cod,int prCons, int numCs, char col,int pHipo):TarjetaPropiedad(tit,rent,cod,pHipo)//titulo, mont, cod, precoConstr, numeroCasas, color
{
	precioConstruccion=prCons;
	numeroCasa=numCs;
	color=col;
	titulo=tit;
}

TarjetaSolar::~TarjetaSolar(){}


void TarjetaSolar::setPrecioConstruccion(int n)
{
	precioConstruccion=n;
}

char TarjetaSolar::getColorSolar()
{
	return color;
}

int TarjetaSolar::getPrecioConstruccion()
{
	return precioConstruccion;
}

void TarjetaSolar::setMonto(int n)
{
	renta=n;
}

int TarjetaSolar::getMonto()
{
	return renta;
}

void TarjetaSolar::setNumCasa(int n)
{
	numeroCasa=n;
}

int TarjetaSolar::getNumCasa()
{
	return numeroCasa;
}

void TarjetaSolar::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void TarjetaSolar::toString(int x,int y)//immprime el detalle de la propiedad
{
	HANDLE hConsole;//Objeto de la libreria windows.h utilizado para dar color.
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char a=200; //Imprime ╚
	char b=186; //Imprime ║
	char c=205; //Imprime ═
	char d=188; //Imprime ╝
	char e=201; //Imprime ╔
	char f=187; //Imprime ╗
	char g=204; //Imprime ╠
	char h=185; //Imprime ╣
	char i =203; //Imprime ╦
	char j= 202;//imprime ╩
	//debe haber algo que cambie de color
	int z=0;
	if (color=='C')
	{
		z=176;	
	}
	if (color=='A')
	{
		z=224;
	}
	if (color=='V')
	{
		z=164;
	}
	if (color=='R')
	{
		z=192;
	}
	
		gotoxy(x,y);cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;
		gotoxy(x,y+1);cout<<b; SetConsoleTextAttribute(hConsole,z); cout<<"        "<<titulo<<"        ";SetConsoleTextAttribute(hConsole,15);cout<<b;	
		gotoxy(x,y+2);cout<<g<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<h;
		gotoxy(x,y+3);cout<<b<<"     Renta:              "<<b;
		gotoxy(x,y+4);cout<<b<<"     Sin edificar: $80   "<<b;
		gotoxy(x,y+5);cout<<b<<"     1 casa: $120        "<<b;
		gotoxy(x,y+6);cout<<b<<"     2 casa: $160        "<<b;
		gotoxy(x,y+7);cout<<b<<"     3 casa: $180        "<<b;
		gotoxy(x,y+8);cout<<b<<"     4 casa: $200        "<<b;
		gotoxy(x,y+9);cout<<b<<"     Hotel   $300        "<<b;
		gotoxy(x,y+10);cout<<b<<"                         "<<b;
		gotoxy(x,y+11);cout<<b<<" Precio Construccion     "<<b;
		gotoxy(x,y+12);cout<<b<<" Costo x casa: $100c/u   "<<b;
		gotoxy(x,y+13);cout<<b<<" Costo x hotel: $400c/u  "<<b;
		gotoxy(x,y+14);cout<<b<<"                         "<<b;
		gotoxy(x,y+15);cout<<b<<" Valor hipotecario: $174 "<<b;
		gotoxy(x,y+16);cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
}
