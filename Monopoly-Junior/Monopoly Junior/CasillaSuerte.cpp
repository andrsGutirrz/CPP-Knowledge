#include"CasillaSuerte.h"

CasillaSuerte::CasillaSuerte(/*TarjetaSuerte *ts*/):Casilla('R')
{
	//this->ts=ts;
}

CasillaSuerte::~CasillaSuerte(){}

void CasillaSuerte::toString(int x, int y)
{

	unsigned char a=200; //Imprime ╚
	unsigned char b=186; //Imprime ║
	unsigned char c=205; //Imprime ═
	unsigned char d=188; //Imprime ╝
	unsigned char e=201; //Imprime ╔
	unsigned char f=187; //Imprime ╗
	unsigned char g=204; //Imprime ╠
	unsigned char h=185; //Imprime ╣
	unsigned char j=174; //Imprime «
	unsigned char k=202; //Imprime ╩
	unsigned char l=203; //Imprime ╦
	unsigned char o=206; //Imprime ╬
	unsigned char n=169; //Imprime ®
	unsigned char m=178; //Imprime Ficha

	if (y==41 || y==1)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<" "<<e<<c<<c<<c<<c<<f<<" "<<b<<endl; 
	gotoxy(x,y+2); cout<<b<<" "<<a<<c<<c<<f<<" "<<b<<" "<<b<<endl; 
	gotoxy(x,y+3); cout<<b<<"  "<<e<<c<<o<<c<<d<<" "<<b<<endl; 
	gotoxy(x,y+4); cout<<b<<"  "<<a<<c<<d<<"   "<<b<<endl; 
	gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<d<<endl;
	}

	if (x==0 || x==88)
	{
		gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f<<endl;
		gotoxy(x,y+1); cout<<b<<"     "<<e<<c<<c<<c<<c<<f<<"     "<<b<<endl; 
		gotoxy(x,y+2); cout<<b<<"     "<<a<<c<<c<<f<<" "<<b<<"     "<<b<<endl; 
		gotoxy(x,y+3); cout<<b<<"      "<<e<<c<<o<<c<<d<<"     "<<b<<endl; 
		gotoxy(x,y+4); cout<<b<<"      "<<a<<c<<d<<"       "<<b<<endl; 
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d<<endl;
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