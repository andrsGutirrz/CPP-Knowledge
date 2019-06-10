#include "TarjetaTren.h"

TarjetaTren::TarjetaTren(){}

TarjetaTren::TarjetaTren(string tit, int rent, int cod,int pHipo):TarjetaPropiedad(tit,rent,cod,pHipo)// titulo, due, mont,
{

}

TarjetaTren::~TarjetaTren()
{

}

void TarjetaTren::gotoxy(int x, int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void TarjetaTren::toString(int x,int y)//immprime el detalle de la propiedad
{
	char a=200; //Imprime ╚
	char b=186; //Imprime ║
	char c=205; //Imprime ═
	char d=188; //Imprime ╝
	char e=201; //Imprime ╔
	char f=187; //Imprime ╗
	char g=204; //Imprime ╠
	char h=185; //Imprime ╣
	char i =203;//Imprime ╦
	char j= 202;//imprime ╩

	gotoxy(x,y);cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1);cout<<b<<"        "<<titulo<<"       "<<b<<endl;	
	gotoxy(x,y+2);cout<<g<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<h<<endl;
	gotoxy(x,y+3);cout<<b<<"     Renta:              "<<b<<endl;
	gotoxy(x,y+4);cout<<b<<"     1 Estacion: $120    "<<b<<endl;
	gotoxy(x,y+5);cout<<b<<"     2 Estacion: $205    "<<b<<endl;
	gotoxy(x,y+6);cout<<b<<"     3 Estacion: $315    "<<b<<endl;
	gotoxy(x,y+7);cout<<b<<"     4 Estacion: $450    "<<b<<endl;
	gotoxy(x,y+8);cout<<b<<"                         "<<b<<endl;
	gotoxy(x,y+9);cout<<b<<" Valor hipotecario: $174 "<<b<<endl;
	gotoxy(x,y+10);cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d<<endl;

}