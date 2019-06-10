#include "CasillaImpuesto.h"

CasillaImpuesto::CasillaImpuesto()
{
	titulo = "NULL";
	monto=0;
}

CasillaImpuesto::CasillaImpuesto(string tit, int mont)
{
	titulo=tit;
	monto=mont;
}

CasillaImpuesto::~CasillaImpuesto(){}


void CasillaImpuesto::setMonto(int mont)
{
	monto=mont;
}


int CasillaImpuesto::getMonto()
{
	return monto;
}

void CasillaImpuesto::toString(int x, int y)
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
	unsigned char m=178; //Imprime Ficha

	if (x==0)
	{
		gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;//14
		gotoxy(x,y+1); cout<<b<<"    "<<titulo<<"    "<<b;
		gotoxy(x,y+2); cout<<b<<"      "<<"$"<<monto<<"      "<<b;
		gotoxy(x,y+3); cout<<b<<"                "<<b;
		gotoxy(x,y+4); cout<<b<<"                "<<b;
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
	}
	else
	{
		gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<f;   
		gotoxy(x,y+1); cout<<b<<"        "<<b;
		gotoxy(x,y+2); cout<<b<<titulo<<b;
		gotoxy(x,y+3); cout<<b<<"  "<<"$"<<monto<<"  "<<b;
		gotoxy(x,y+4); cout<<b<<"        "<<b;
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<d;
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
