#include "Banco.h"



Banco::Banco(Tablero* tt )
{
	tb=tt;
	vt=new VectorTarjetasPropiedad(30);
	intfz=new Interfaz();
}

Banco::Banco(Tablero* tt ,VectorTarjetasPropiedad* vT, MazoSuerte *mS)
{
	tb=tt;
	vt=vT;
	ms=mS;
	intfz=new Interfaz();
}

void Banco::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Banco::venderSolar(int pos, Jugador * j)//Recibe una posicion del tablero, si esta dueño=false se puede comprar
{		
	imprimeTarjetaPropiedad(pos);//imprime la tarjeta de propiedad
	if (tb->getCasilla(pos)->getTipoCasilla()=='P')//Si la casilla es de tipo Solar
	{
		CasillaSolar *cs=dynamic_cast < CasillaSolar* > ( tb->getCasilla(pos) );
		if (!cs->getDuenno())//si es falso, me devuelve true por la negación, entonces, se puede comprar
		{
			char a=intfz->comprarPropiedad(cs->getMonto(),j,tb);
			if (a!='1')
			{
				gotoxy(20,19);cout<<"NOOO";cin.get();cin.get();
				system("cls"); tb->toString();j->toString();venderSolar(pos,j);
			}
			if (a=='1')
			{
				j->setCapital(j->getCapital()-cs->getMonto()); intfz->compraSatisfactoria();
				cs->setDuenno(true); /*    */ j->insertarTarjeta(vt->getTarjetaPropiedadPorCodigo(pos));//inserta en el vector de jugador, la tarjeta
				tb->insertarCasilla(cs,pos);
			}if(a=='2'){return;}
		}else{ intfz->yaTienePropiedad();}
	}

	if (tb->getCasilla(pos)->getTipoCasilla()=='T')
	{
		CasillaTren *cs=dynamic_cast < CasillaTren* > ( tb->getCasilla(pos) );
		if (!cs->getDuenno())//si es falso, me devuelve true por la negación, entonces, se puede comprar
		{
			char a=intfz->comprarPropiedad(cs->getMonto(),j,tb);
			if (a!='1')
			{
				gotoxy(20,19);cout<<"NOOO";cin.get();cin.get();
				system("cls"); tb->toString();j->toString();venderSolar(pos,j);
			}
			if (a=='1')
			{
				j->setCapital(j->getCapital()-cs->getMonto()); intfz->compraSatisfactoria();
				cs->setDuenno(true); /*    */ j->insertarTarjeta(vt->getTarjetaPropiedadPorCodigo(pos));//inserta en el vector de jugador, la tarjeta
				tb->insertarCasilla(cs,pos);
			}
			if(a=='2'){return;}
		}else{ intfz->yaTienePropiedad();}
	}

	if (tb->getCasilla(pos)->getTipoCasilla()=='S')
	{
		CasillaServicio *cs=dynamic_cast < CasillaServicio* > ( tb->getCasilla(pos) );
		if (!cs->getDuenno())//si es falso, me devuelve true por la negación, entonces, se puede comprar
		{
			char a=intfz->comprarPropiedad(cs->getMonto(),j,tb);
			if (a!='1')
			{
				gotoxy(20,19);cin.get();
				system("cls"); tb->toString();j->toString();venderSolar(pos,j);
			}
			if (a=='1')
			{
				j->setCapital(j->getCapital()-cs->getMonto()); intfz->compraSatisfactoria();
				cs->setDuenno(true); /*    */ j->insertarTarjeta(vt->getTarjetaPropiedadPorCodigo(pos));//inserta en el vector de jugador, la tarjeta
				tb->insertarCasilla(cs,pos);
			}
			if(a=='2'){return;}
		}else{ intfz->yaTienePropiedad();}
	}
}

void Banco::instanciarTarjetas(Jugador *j, Jugador*j2)
{
	TarjetaPropiedad *t1=new TarjetaServicio("  AGUA   ",0,2,"Agua",300);//string tit, int rent, int cod, string tip
	TarjetaPropiedad *t2=new TarjetaSolar(" SYDNEY  ",80,4,100,0,'C',175);//string tit, int rent ,int cod,int prCons, int numCs, char col
	TarjetaPropiedad *t3=new TarjetaTren("  TREN 1  ",100,5,250);//string tit, int rent, int cod
	TarjetaPropiedad *t4=new TarjetaSolar(" BEIGING ",80,6,100,0,'C',175);
	TarjetaPropiedad *t5=new TarjetaSolar("  ROMA   ",80,7,100,0,'C',175);
	TarjetaPropiedad *t6=new TarjetaTren("  TREN 2  ",100,11,250);//string tit, int rent, int cod
	TarjetaPropiedad *t7=new TarjetaSolar("BARCELONA",80,12,100,0,'A',175);
	TarjetaPropiedad *t8=new TarjetaSolar("AMSTERDAM",80,14,100,0,'A',175);
	TarjetaPropiedad *t9=new TarjetaSolar("SINGAPUR ",80,15,100,0,'A',175);
	TarjetaPropiedad *t10=new TarjetaSolar(" VENECIA ",80,17,100,0,'R',175);
	TarjetaPropiedad *t11=new TarjetaServicio("   LUZ   ",0,18,"luz",300);
	TarjetaPropiedad *t12=new TarjetaSolar(" ATENAS  ",80,19,100,0,'R',175);
	TarjetaPropiedad *t13=new TarjetaSolar(" LISBOA  ",80,20,100,0,'R',175);
	TarjetaPropiedad *t14=new TarjetaTren("  TREN 3  ",100,22,250);
	TarjetaPropiedad *t15=new TarjetaSolar("BUDAPEST ",80,25,100,0,'V',175);
	TarjetaPropiedad *t16=new TarjetaSolar(" SEVILLA ",80,26,100,0,'V',175);
	TarjetaPropiedad *t17=new TarjetaSolar(" ESTAMBUL",80,28,100,0,'V',175);
	TarjetaPropiedad *t18=new TarjetaTren("  TREN 4  ",100,30,250);
	vt->insertarTarjetaPropiedad(t1);
	vt->insertarTarjetaPropiedad(t2);
	vt->insertarTarjetaPropiedad(t3);
	vt->insertarTarjetaPropiedad(t4);
	vt->insertarTarjetaPropiedad(t5);
	vt->insertarTarjetaPropiedad(t6);
	vt->insertarTarjetaPropiedad(t7);
	vt->insertarTarjetaPropiedad(t8);
	vt->insertarTarjetaPropiedad(t9);
	vt->insertarTarjetaPropiedad(t10);
	vt->insertarTarjetaPropiedad(t11);
	vt->insertarTarjetaPropiedad(t12);
	vt->insertarTarjetaPropiedad(t13);
	vt->insertarTarjetaPropiedad(t14);
	vt->insertarTarjetaPropiedad(t15);
	vt->insertarTarjetaPropiedad(t16);
	vt->insertarTarjetaPropiedad(t17);
	vt->insertarTarjetaPropiedad(t18);

	j->insertarTarjeta(t2);/* nuevo, solo para prueba*/
	j->insertarTarjeta(t4);
	j->insertarTarjeta(t5);
	j->insertarTarjeta(t1);
	j->insertarTarjeta(t11);
	j2->insertarTarjeta(t7);
	j2->insertarTarjeta(t8);
	j2->insertarTarjeta(t10);


}

void Banco::imprimeTarjetaPropiedad(int pos)
{
	for (int i = 0; i < vt->getCan(); i++)
	{
		if (vt->getTarjetaPropiedad(i)->getCodigo()==pos)
		{
			vt->getTarjetaPropiedad(i)->toString(118,15);
		}
	} 
}


void Banco::controlDeMonopolio(char c,Jugador* j)
{
	int cont=1;int cont2=1;
	int opcion1,opcion2,opcion3;
	if (c=='n'){gotoxy(20,10);cout<<"No cuenta con monopolio";cin.get();return;}
	system("cls");tb->toString();
	for (int i = 0; i < tb->getTam(); i++)//recorre todo el vector de casillas
	{
		if (dynamic_cast<CasillaSolar*>( tb->getCasilla(i) ) )//Si es solar, entonces...
		{
			CasillaSolar *cs=dynamic_cast<CasillaSolar*>( tb->getCasilla(i) );
			if (cs->getColor()==c)
			{
				gotoxy(110,20+cont2);cout<<cont2<<") "<<"En : "<<cs->getTitulo()<<endl;cont2++;
				if(cont==1){ opcion1= i;cont++;}
				if(cont==2){ opcion2= i;cont++;}
				if(cont==3){ opcion3= i;cont++;}
			}	
		}
	}//fin for
	gotoxy(110,20);cout<<"ELIJA SOLAR";char op=0;
	gotoxy(110,24);cin>>op;cin.get();
	if (op=='1'){ construye(tb->getCasilla(opcion1));}
	if (op=='2'){ construye(tb->getCasilla(opcion2));}
	if (op=='3'){ construye(tb->getCasilla(opcion3));}
	if (op!='1'&& op!='2'&& op!='3'){controlDeMonopolio(c,j);}
	
	

}

void Banco::construye(Casilla* c)
{
	CasillaSolar *cps=dynamic_cast<CasillaSolar*>(c);
	cps->setNumCasa(cps->getNumCasa()+1);
	gotoxy(20,10);cout<<"Se construyo una casa"<<endl;
}