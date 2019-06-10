#include "CasillaSolar.h"

 CasillaSolar:: CasillaSolar()
{
	numCasa=0;
	hotel=0;
	color='n';//negro
}

 CasillaSolar:: CasillaSolar(char c, int cas, int hot, string tit, bool due, int mont):CasillaPropiedad(tit,due,mont,'P')
{
	numCasa=hot;
	hotel=cas;
	color=c;
}

 CasillaSolar::~ CasillaSolar(){}

void  CasillaSolar::setNumCasa(int n)
{
	numCasa=n;
}

void  CasillaSolar::setHotel(int h)
{
	hotel=h;
}

void  CasillaSolar::setColor(char col)
{
	color=col;
}

char  CasillaSolar::getColor()
{
	return color;
}

int  CasillaSolar::getNumCasa()
{
	return numCasa;
}

int  CasillaSolar::getHotel()
{
	return hotel;
}

void  CasillaSolar::toString(int x, int y)
{

unsigned char a=200; //Imprime ╚
unsigned char b=186; //Imprime ║
unsigned char c=205; //Imprime ═
unsigned char d=188; //Imprime ╝
unsigned char e=201; //Imprime ╔
unsigned char f=187; //Imprime ╗
unsigned char g=204; //Imprime ╠
unsigned char h=185; //Imprime ╣
unsigned char i =203; //Imprime ╦
unsigned char j= 202;//imprime ╩
unsigned char m=178; //Imprime Ficha

if(this->color=='C')
{
	colorear(11);
	gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<f;   
    gotoxy(x,y+1); cout<<g<<c<<c<<c<<c<<c<<c<<c<<c<<h;
	colorear(15);
    gotoxy(x,y+2); cout<<b<<titulo<<b;
	gotoxy(x,y+3); cout<<b<<"  "<<"$"<<monto<<"  "<<b;
	gotoxy(x,y+4); cout<<b<<"        "<<b;
	gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<d;

}

if (this->color=='A')
{
	gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c; colorear(14); cout<<i<<c<<f; colorear(15);
    gotoxy(x,y+1); cout<<b<<"   "<<titulo<<"  "; colorear(14); cout<<b<<" "<<b; colorear(15);
	gotoxy(x,y+2); cout<<b<<"      "<<"$"<<monto<<"    "; colorear(14); cout<<b<<" "<<b; colorear(15);
	gotoxy(x,y+3); cout<<b<<"              "; colorear(14); cout<<b<<" "<<b; colorear(15);
    gotoxy(x,y+4); cout<<b<<"              "; colorear(14); cout<<b<<" "<<b; colorear(15);
	gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c; colorear(14); cout<<j<<c<<d; colorear(15);
}

if (this->color=='R')
{
	gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<f;   
    gotoxy(x,y+1); cout<<b<<titulo<<" "<<b;
	gotoxy(x,y+2); cout<<b<<"  "<<"$"<<monto<<"  "<<b;
	gotoxy(x,y+3); cout<<b<<"        "<<b;
	colorear(12);  
    gotoxy(x,y+4); cout<<g<<c<<c<<c<<c<<c<<c<<c<<c<<h;
	gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<d;
	colorear(15);
}

if (this->color=='V')
{
	gotoxy(x,y);  colorear(10);  cout<<e<<c<<i;  colorear(15);  cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;
	gotoxy(x,y+1);  colorear(10);  cout<<b<<" "<<b;  colorear(15);  cout<<"  "<<titulo<<"   "<<b;
	gotoxy(x,y+2);  colorear(10);  cout<<b<<" "<<b;  colorear(15);  cout<<"    "<<"$"<<monto<<"      "<<b;
    gotoxy(x,y+3);  colorear(10);  cout<<b<<" "<<b;  colorear(15);  cout<<"              "<<b;
	gotoxy(x,y+4);  colorear(10);  cout<<b<<" "<<b;  colorear(15);  cout<<"              "<<b;
	gotoxy(x,y+5);  colorear(10);  cout<<a<<c<<j;    colorear(15);  cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
}

if(this->jugador1!=false)
	{
		colorear(14);
		gotoxy(x+4,y+2); cout<<m;
		colorear(15);
	}

if(this->jugador2!=false)
	{
		colorear(13);
		gotoxy(x+4,y+4); cout<<m;
		colorear(15);
	}

}