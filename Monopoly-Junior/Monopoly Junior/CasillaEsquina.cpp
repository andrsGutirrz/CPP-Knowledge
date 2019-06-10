#include "CasillaEsquina.h"

CasillaEsquina::CasillaEsquina()
{
	titulo = "NULL";
}

CasillaEsquina::CasillaEsquina(string tit):Casilla('Q')
{
	titulo=tit;
}

CasillaEsquina::~CasillaEsquina(){}

void CasillaEsquina::toString(int x, int y)
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

	if(x==88 && y==41)///////IMPRIME LA CASILLA "GO"
	{
		gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;
		gotoxy(x,y+1); cout<<b<<"                "<<b<<endl;
		gotoxy(x,y+2); cout<<b<<"      "<<titulo<<"      "<<b<<endl;
		gotoxy(x,y+3); cout<<b<<"      "<<j<<j<<j<<j<<"      "<<b<<endl;
		gotoxy(x,y+4); cout<<b<<"                "<<b<<endl;
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
	}

	if(x==0 && y==41)///////IMPRIME LA CASILLA "CARCEL"
	{
		gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;//18
		gotoxy(x,y+1); cout<<b<<"     "<<titulo<<"     "<<b<<endl;
		gotoxy(x,y+2); cout<<b<<"  "<<e<<c<<l<<c<<l<<c<<l<<c<<l<<c<<l<<c<<f<<" "<<b<<endl;
		gotoxy(x,y+3); cout<<b<<"  "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<endl;
		gotoxy(x,y+3); cout<<b<<"  "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<" "<<b<<endl;
		gotoxy(x,y+4); cout<<b<<"  "<<a<<c<<k<<c<<k<<c<<k<<c<<k<<c<<k<<c<<d<<" "<<b<<endl;
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
	}


	if(y==1 && x==0)///////IMPRIME LA CASILLA "PARKING FREE"
	{
		gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;//18
		gotoxy(x,y+1); cout<<b<<"     "<<titulo<<"    "<<b<<endl;
		gotoxy(x,y+2); cout<<b<<"      FREE      "<<b<<endl;
		gotoxy(x,y+3); cout<<b<<"       :)       "<<b<<endl;
		gotoxy(x,y+4); cout<<b<<"                "<<b<<endl;
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
	}
	
	if(y==1 && x==88)///////IMPRIME LA CASILLA "VE A LA CARCEL"
	{
		gotoxy(x,y);   cout<<e<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<f;//18
		gotoxy(x,y+1); cout<<b<<"                "<<b<<endl;
		gotoxy(x,y+2); cout<<b<<"    VE A LA     "<<b<<endl;
		gotoxy(x,y+3); cout<<b<<"    "<<titulo<<"!!!   "<<b<<endl;
		gotoxy(x,y+4); cout<<b<<"                "<<b<<endl;
		gotoxy(x,y+5); cout<<a<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<d;
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