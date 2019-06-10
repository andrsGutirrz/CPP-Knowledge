#include"Tablero.h"

Tablero::Tablero(int tam)
{
	t=new Casilla*[tam];
	cant=0;
	this->tam=tam;
	for (int i = 0; i < tam; i++)
	{
		t[i]=NULL;
	}
}

Tablero::~Tablero(){
	for(int i=0;i<tam;i++)
	{
		delete t[i];
	}

	delete[]t;
}

void Tablero::setTam(int tam1)
{
	tam=tam1;
}

int Tablero::getTam()
{
	return tam;
}

void Tablero::setCan(int can1)
{
	cant=can1;
}

int Tablero::getCan()
{
	return cant;
}

void Tablero::insertarCasilla(Casilla* c)
{
	if(cant<tam)
  {
		t[cant]=c;
		cant=cant+1;
	}
}
void Tablero::insertarCasilla(Casilla* c, int pos)
{
	if(pos<tam)
    {
		t[pos]=c;
	}
}

Casilla* Tablero::getCasilla(int n)
{
	return t[n];
}

int Tablero::getPosJugador1()
{
	for (int i=0; i<cant; i++) 	
		if (t[i]->getJugador1()!=false) 
		return i; 
}

int Tablero::getPosJugador2()
{
	for (int i=0; i<cant; i++) 	
		if (t[i]->getJugador2()!=false) 
		return i; 
}

 void Tablero::colocaFicha(int n, int id)
 {
	
	if(id==1)
	{
		t[n]->setJugador1(true);
	}
	if(id==2)
	{
		t[n]->setJugador2(true);
	}
	 
 }

 void Tablero::quitaFicha(int n, int id)
 {
	 if(id==1)
	 {
		 t[n]->setJugador1(false);
	 }
	 if(id==2)
	 {
		 t[n]->setJugador2(false);
	 }
 }

void Tablero::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Tablero::toString()
{
int cont=0;
int x=88;
int y=41;

	for(int i=0;i<tam;i++)
	{
		if(cont<9)
		{
			if(t[cont]!=NULL)//Horizontal inferior
			{
				gotoxy(x,y); t[cont]->toString(x,y);
			}

			x=x-10;//Corrimiento de 10 espacios hacia la izquierda
			cont++;
			if(cont==8)//Antes de la primer esquina
			{
			x=x-8;}
			}
		//////////////////////////////////////////////////////////	

		int x=0;
		int y=36;
		while (cont>=9 && cont<17)//Vertical izquierda
		{
			if(t[cont]!=NULL)
			{
				gotoxy(x,y); t[cont]->toString(x,y);
			}
			cont++;
			y=y-5;
		}

		x=18;
		y=1;
		while (cont>=17 && cont<25)//Horizontal superior
		{
			if(t[cont]!=NULL)
			{
				gotoxy(x,y); t[cont]->toString(x,y);
			}
			cont++;
			x=x+10;
		}

		x=88;
		y=6;
		while (cont>=25 && cont<33)//Vertical Derecha
		{
			if(t[cont]!=NULL)
			{
				gotoxy(x,y); t[cont]->toString(x,y);
			}
			cont++;
			y=y+5;
		}
	}
}