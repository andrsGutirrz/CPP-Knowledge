#include "TarjetaServicio.h"

TarjetaServicio::TarjetaServicio()
{
	tipo="NULL";
}

TarjetaServicio::TarjetaServicio(string tit, int rent, int cod, string tip, int pHipo):TarjetaPropiedad(tit,rent,cod,pHipo)// titulo, mont, codigo,tip
{
	tipo=tip;
}

void TarjetaServicio::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void TarjetaServicio::toString(int x,int y)//immprime el detalle de la propiedad
{
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

	gotoxy(x,y);cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;
	gotoxy(x,y+1);cout<<b<<"          "<<titulo<<"          "<<b<<endl;	
	gotoxy(x,y+2);cout<<g<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<h;
	gotoxy(x,y+3);cout<<b<<" Renta:                      "<<b;
	gotoxy(x,y+4);cout<<b<<" 1 Servicio:                 "<<b;
	gotoxy(x,y+5);cout<<b<<" 10 veces el numero obtenido "<<b;
	gotoxy(x,y+6);cout<<b<<" por los dados               "<<b;
	gotoxy(x,y+7);cout<<b<<"                             "<<b;
	gotoxy(x,y+8);cout<<b<<" 2 Servicios:                "<<b;
	gotoxy(x,y+9);cout<<b<<" 20 veces el numero obtenido "<<b;
	gotoxy(x,y+10);cout<<b<<" por los dados               "<<b;
	gotoxy(x,y+11);cout<<b<<"                             "<<b;
	gotoxy(x,y+12);cout<<b<<" Valor hipotecario: $300     "<<b;
	gotoxy(x,y+13);cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
}