#include"Control.h"

Control::Control()
{
	t=new Tablero(36);
	i=new Interfaz;
	d1=new Dado;
	d2=new Dado;
	j1=new Jugador;
	j2=new Jugador;
	bc=new Banco(t);
	m=new MazoSuerte;
}

Control::~Control()
{
	delete t;
	delete i;
	delete d1;
	delete d2;
	delete j1;
	delete j2;
	delete bc;
	delete m;
}

void Control::iniciar()
{
	insertarCasillas();
	llenarMazo();

	Jugador *j1=new Jugador("Andres R.",1,10000,0,0);
	Jugador *j2=new Jugador("Andres G.",2,10000,0,0);
	t->getCasilla(0)->setJugador1(true);
	t->getCasilla(0)->setJugador2(true);

	//////////////////////////////////////////////////| Prueba |/////////////////////////////
	bc->instanciarTarjetas(j1,j2);
	CasillaSolar *s1=dynamic_cast<CasillaSolar*>(t->getCasilla(4));
	CasillaSolar *s2=dynamic_cast<CasillaSolar*>(t->getCasilla(6));
	CasillaSolar *s3=dynamic_cast<CasillaSolar*>(t->getCasilla(7));
	CasillaSolar *s4=dynamic_cast<CasillaSolar*>(t->getCasilla(12));
	CasillaSolar *s5=dynamic_cast<CasillaSolar*>(t->getCasilla(14));
	CasillaSolar *s6=dynamic_cast<CasillaSolar*>(t->getCasilla(17));
	CasillaServicio*s7=dynamic_cast<CasillaServicio*>(t->getCasilla(2));
	CasillaServicio*s8=dynamic_cast<CasillaServicio*>(t->getCasilla(18));
	s1->setDuenno(true);
	s2->setDuenno(true);
	s3->setDuenno(true);
	s4->setDuenno(true);s4->setNumCasa(4);
	s5->setDuenno(true);s5->setNumCasa(2);
	s6->setDuenno(true);s6->setNumCasa(3);
	s7->setDuenno(true);
	s8->setDuenno(true);

	
	char op=' ';
	do  
	{
		i->indicaciones();
		i->limpiarPantalla();
		i->musica();
		i->titulo();
		i->menuGeneneral();
		i->monopolyWorldEditionLogo();
		gotoxy(34,35);cin>>op;
		if(op!='1'&&op!='2'&&op!='3')
		{
			i->menuGeneneral();
			i->monopolyWorldEditionLogo();
			gotoxy(34,35); cin>>op;
		}
		
		
		switch(op)
		{
		case '1': this->jugar(j1,j2); break;

		case '3': op=3; break;
		}
	}
	while(op!='3');
	cin.get();
}

void Control::jugar(Jugador *j1,Jugador*j2)
{
	char opcion=' ';
	bool repetir=true;
	bool turno=1;
	bool carcelJ1=false;
	bool carcelJ2=false;
		do
	{
		i->limpiarPantalla();
		t->toString();
		///////////JUEGA JUGADOR 1
		if(turno==1)
		{ 

			j1->toString();

			if(i->msjAvanzar()=='x'){ avanzar(lanzar(),j1);}

			int p = t->getPosJugador1();

			this->pagarRentaSolar(j1,p,j2);
			this->pagarRentaServicio(j1,p,j2);
			this->pagarRentaTren(j1,p,j2);

			carcelJ1=carcel(j1);

			if(carcelJ1==true)
			{
				gotoxy(20,10); cout<<"Fuiste a la carcel, se te cobra "<<fianzaCarcel();
				pagaFianza(j1);
			}

			this->verificaImpuesto(j1);

			if(verificaSuerte(j1)!=0)
			{
				TarjetaSuerte* ts=tarjetaSuerte();
				ts->toString(120,40); cin.get();
				aplicaSuerte(ts,j1);
			}

			this->opcionesJugador(j1,p);
			

			turno=0; cin.get();
		}

		///////////JUEGA JUGADOR 2
		if(turno==0)
		{

			j2->toString();
			if(i->msjAvanzar()=='x'){ avanzar(lanzar(),j2);}

			int p = t->getPosJugador2();

			this->pagarRentaSolar(j2,p,j1);
			this->pagarRentaServicio(j2,p,j1);
			this->pagarRentaTren(j2,p,j1);

			carcelJ2=carcel(j2);

			if(carcelJ2==true)
			{
				gotoxy(20,10); cout<<"Fuiste a la carcel, se te cobra "<<fianzaCarcel();
				pagaFianza(j1);
			}

			this->verificaImpuesto(j2);
			if(verificaSuerte(j2)!=0)
			{
				TarjetaSuerte* ts=tarjetaSuerte();
				ts->toString(120,40);cin.get();
				aplicaSuerte(ts,j2);
			}

			this->opcionesJugador(j2,p);
			

			turno=1; cin.get();
		}

	}while(repetir);
}

void Control::menuPrincipal()
{
	i->titulo();
	cin.get();
}


void Control::avanzar(int n, Jugador *j)
{
	if(j->getId()==1)
	{
		j->toString();
		int p = t->getPosJugador1(); //Se obtiene la posicion actual de jugador 1.
		t->quitaFicha(p,1); //Se quita la ficha de la posicion actual.
		t->colocaFicha(validadNumeroDado(p+n),1);//Recibe cantidad de espacios devueltos por los dados y avanza n posiciones.
		cin.get();
		i->limpiarPantalla(); j->toString();
		t->toString(); //Se refresca la pantalla.
		go(j,p,n);
		this->cantidadCasasHoteles(t->getCasilla(validadNumeroDado(p+n)));
	}

	if(j->getId()==2)
	{
		j->toString();
		int p= t->getPosJugador2(); //Se obtiene la posicion actual de jugador .
		t->quitaFicha(p,2); //Se quita la ficha de la posicion actual.
		t->colocaFicha(validadNumeroDado(p+n),2); //Recibe cantidad de espacios devueltos por los dados y avanza n posiciones.
		cin.get();
		i->limpiarPantalla();j->toString(); 
		t->toString(); //Se refresca la pantalla
		go(j,p,n);
		this->cantidadCasasHoteles(t->getCasilla(validadNumeroDado(p+n)));
	}
}

int Control::lanzar()
{
	int x=d1->ram();
	Sleep(300);
	int y=d2->ram();
	if(x==y){ Sleep(300); y=d2->ram(); }
	int n= x + y;
	i->interfazDado(20,15,x);
	i->interfazDado(30,15,y);
	cin.get();

	return n;
}

void Control::insertarCasillas()
{
	Casilla *c1=new CasillaEsquina("'GO'");
	Casilla *c2=new CasillaSuerte();
	Casilla *c3=new CasillaServicio("Agua","  Agua  ",false,230);
	Casilla *c4=new CasillaSuerte();
	Casilla *c5=new CasillaSolar('C',0,0," SYDNEY ",false,280);
	Casilla *c6=new CasillaTren(" Tren 1 ",false,200);
	Casilla *c7=new CasillaSolar('C',0,0,"BEIJING ",false,295);
	Casilla *c8=new CasillaSolar('C',0,0,"  ROMA  ",false,260);
	Casilla *c9=new CasillaEsquina("CARCEL");
	Casilla *c10=new CasillaImpuesto("Impuesto",190);
	Casilla *c11=new CasillaSuerte();
	Casilla *c12=new CasillaTren(" Tren 2 ",false,200);
	Casilla *c13=new CasillaSolar('A',0,0,"BARCELONA",false,315);
	Casilla *c14=new CasillaSuerte();
	Casilla *c15=new CasillaSolar('A',0,0,"AMSTERDAN",false,360);
	Casilla *c16=new CasillaSolar('A',0,0,"SINGAPUR ",false,340);
	Casilla *c17=new CasillaEsquina("Parking");
	Casilla *c18=new CasillaSolar('R',0,0,"VENECIA",false,425);
	Casilla *c19=new CasillaServicio("LUZ","  Luz   ",false,225);
	Casilla *c20=new CasillaSolar('R',0,0," ATENAS",false,470);
	Casilla *c21=new CasillaSolar('R',0,0," LISBOA",false,490);
	Casilla *c22=new CasillaSuerte();
	Casilla *c23=new CasillaTren(" Tren 3 ",false,200);
	Casilla *c24=new CasillaImpuesto("Impuesto",160);
	Casilla *c25=new CasillaEsquina("CARCEL");
	Casilla *c26=new CasillaSolar('V',0,0," BUDAPEST",false,500);
	Casilla *c27=new CasillaSolar('V',0,0," SEVILLA ",false,550);
	Casilla *c28=new CasillaSuerte();
	Casilla *c29=new CasillaSolar('V',0,0," ESTAMBUL",false,600);
	Casilla *c30=new CasillaSuerte();
	Casilla *c31=new CasillaTren(" Tren 4 ",false,200);
	Casilla *c32=new CasillaSuerte();
	////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////
	t->insertarCasilla(c1);
	t->insertarCasilla(c2);
	t->insertarCasilla(c3);
	t->insertarCasilla(c4);
	t->insertarCasilla(c5);
	t->insertarCasilla(c6);
	t->insertarCasilla(c7);
	t->insertarCasilla(c8);
	t->insertarCasilla(c9);
	t->insertarCasilla(c10);
	t->insertarCasilla(c11);
	t->insertarCasilla(c12);
	t->insertarCasilla(c13);
	t->insertarCasilla(c14);
	t->insertarCasilla(c15);
	t->insertarCasilla(c16);
	t->insertarCasilla(c17);
	t->insertarCasilla(c18);
	t->insertarCasilla(c19);
	t->insertarCasilla(c20);
	t->insertarCasilla(c21);
	t->insertarCasilla(c22);
	t->insertarCasilla(c23);
	t->insertarCasilla(c24);
	t->insertarCasilla(c25);
	t->insertarCasilla(c26);
	t->insertarCasilla(c27);
	t->insertarCasilla(c28);
	t->insertarCasilla(c29);
	t->insertarCasilla(c30);
	t->insertarCasilla(c31);
	t->insertarCasilla(c32);
}

void Control::llenarMazo()
{
	TarjetaSuerte *ts1= new TarjetaSuerte("Ganas $500",500,0,'C');
	TarjetaSuerte *ts2=new TarjetaSuerte("Pierdes $200",200,0,'P');
	TarjetaSuerte *ts3=new TarjetaSuerte("Avanze 2 casillas",0,2,'A');
	TarjetaSuerte *ts4=new TarjetaSuerte("Retroceda 2 casillas",0,2,'R');
	TarjetaSuerte *ts5= new TarjetaSuerte("El proyecto esta funcionando. Ganas $1000",1000,0,'C');
	TarjetaSuerte *ts6= new TarjetaSuerte("Recibes una herencia desconocida. Cobras $500",500,0,'C');
	TarjetaSuerte *ts7=new TarjetaSuerte("Te vas de crucero pagas $400",400,0,'P');
	TarjetaSuerte *ts8=new TarjetaSuerte("Hoy no tienes prisa! Retrocede 6 espacios",0,6,'R');
	TarjetaSuerte *ts9= new TarjetaSuerte("Te encontraste $50 en el suelo!",50,0,'C');
	TarjetaSuerte *ts10=new TarjetaSuerte("Hoy tienes energía! Recorre todo el tablero",0,32,'A');
	TarjetaSuerte *ts11=new TarjetaSuerte("Te enfermas :( pagas $150",150,0,'P');
	TarjetaSuerte *ts12=new TarjetaSuerte("No quieres estar aqui. Avanza 5 espacios.",0,5,'A');
	TarjetaSuerte *ts13=new TarjetaSuerte("Oops! Olvidaste el amuerzo. Retrocede un espacio",0,1,'R');
	TarjetaSuerte *ts14= new TarjetaSuerte("Navidad! Recibes $800",800,0,'C');
	TarjetaSuerte *ts15=new TarjetaSuerte("Te quedas en esta casilla.",0,0,'R');
	TarjetaSuerte *ts16=new TarjetaSuerte("Avanza 3 casillas",0,3,'A');

	m->insertar(ts1);
	m->insertar(ts2);
	m->insertar(ts3);
	m->insertar(ts4);
	m->insertar(ts5);
	m->insertar(ts6);
	m->insertar(ts7);
	m->insertar(ts8);
	m->insertar(ts9);
	m->insertar(ts10);
	m->insertar(ts11);
	m->insertar(ts12);
	m->insertar(ts13);
	m->insertar(ts14);
	m->insertar(ts15);
	m->insertar(ts16);
}

int Control::validadNumeroDado(int n)
{
	int aux=0;
	if (n>=32)
	{
		aux=n-32;
		return aux;
	}
	return n;
}

bool Control::verificaSuerte(Jugador* j)
{
	if(j->getId()==1)
	{
		if(t->getCasilla(t->getPosJugador1())->getTipoCasilla()=='R')//"R" hace referencia a Random como carta de la suerte.
		{
			return true;
		}
	}
	if(j->getId()==2)
	{
		if(t->getCasilla(t->getPosJugador2())->getTipoCasilla()=='R')
		{
			return true;
		}
	}
	return false;
}

void Control::aplicaSuerte(TarjetaSuerte* t, Jugador* j)
{
	char n= t->getTipoAccion();

	if(n=='A')
	{
		avanzar(t->getAccion(),j);
	}

	if(n=='R')
	{
		avanzar(-(t->getAccion()),j);
	}

	if(n=='P')
	{
		j->setCapital((j->getCapital())-(t->getMonto()));
	}

	if(n=='C')
	{
		j->setCapital((j->getCapital())+(t->getMonto()));
	}

}

void Control::gotoxy(int x,int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

TarjetaSuerte* Control::tarjetaSuerte()
{
	TarjetaSuerte *t= m->sacar();
	return t;
}

bool Control::carcel(Jugador *j)
{
	if(j->getId()==1)
	{
		if(t->getCasilla(8)->getJugador1()==true || t->getCasilla(24)->getJugador1()==true )
		{
			t->getCasilla(24)->setJugador1(false); 
			t->getCasilla(8)->setJugador1(true); 
			i->msjCarcel();
			return true;
		}
	}
	if(j->getId()==2)
	{
		if(t->getCasilla(8)->getJugador2()==true || t->getCasilla(24)->getJugador2()==true )
		{
			t->getCasilla(24)->setJugador2(false); 
			t->getCasilla(8)->setJugador2(true); 
			i->msjCarcel();
			return true;
		}
	}
	return false;
}

int Control::fianzaCarcel()
{
	srand(time(NULL));
	return 20+(rand()%300);
}

void Control::pagaFianza(Jugador *j)
{
	j->setCapital(j->getCapital() - fianzaCarcel());
}

bool Control::bancaRota(Jugador *j)
{
	if(j->getCapital()<=0)
	{
		i->msjBancaRota();
		return false;
	}
	return true;
}

void Control::go(Jugador *j, int n, int m)
{
	if((n+m)>=32)
	{
		i->msjGo();
		j->setCapital(j->getCapital() + 200);
		j->toString();
	}
}

char Control::verificaMonopolio(Jugador* j)
{
	int r=0,a=0,v=0,c=0;
	for (int i = 0; i < j->getCantidadVector(); i++)//recorremos el vector de jugador
	{
		if (dynamic_cast<TarjetaSolar*>(j->getTarjeta(i)))//Si es solar, entonces...
		{
			TarjetaSolar * ts =dynamic_cast<TarjetaSolar*>(j->getTarjeta(i));
			if (ts->getColorSolar()=='C'){c++;}
			if (ts->getColorSolar()=='A'){a++;}
			if (ts->getColorSolar()=='V'){v++;}
			if (ts->getColorSolar()=='R'){r++;}
		}
	}
	system("cls");t->toString();
	gotoxy(110,20);cout<<"Cuenta con los siguientes monopolios"<<endl;
	char op=0;
	if(c==3){gotoxy(110,21);cout<<"1) Celeste"<<endl;}
	if(r==3){gotoxy(110,22);cout<<"2) Rojo"<<endl;}
	if(v==3){gotoxy(110,23);cout<<"3) Verde"<<endl;}
	if(a==3){gotoxy(110,24);cout<<"4) Amarillo"<<endl;}
	if(c!=3&&r!=3&&v!=3&&a!=3){return 'n';}//en el caso de que no tenga monopolio
	gotoxy(110,25);cin>>op;
	if (op=='1'){return 'C';}
	if (op=='2'){return 'R';}
	if (op=='3'){return 'V';}
	if (op=='4'){return 'A';}
	if (op!='1'&& op!='2'&& op!='3'&& op!='4'){verificaMonopolio(j);}
}

void Control::opcionesJugador(Jugador* j, int pos)
{
	char op=i->opcionesJugador();
	if (isdigit(op)==0)
	{
		gotoxy(20,10);i->errorValidacion();cin.get();cin.get();
		system("cls");t->toString();j->toString();
		this->opcionesJugador(j,pos);
	}else{
		if (op=='1')//Para comprar Propiedad
		{
			if (dynamic_cast<CasillaPropiedad*>(t->getCasilla(pos)))
			{
				bc->venderSolar(pos,j);
				cin.get();cin.get();
				system("cls");t->toString();j->toString();
				this->opcionesJugador(j,pos);
			}else
			{
				gotoxy(20,10);cout<<"No se puede comprar";cin.get();
				return;
			}
		}

		if (op=='2')//Para construir
		{
			char m=verificaMonopolio(j);
			bc->controlDeMonopolio(m,j);
			cin.get();cin.get();
			system("cls");t->toString();j->toString();
			this->opcionesJugador(j,pos);
		}

		if (op=='3')//Para hipotecar
		{
			this->hipotecarPropiedad(j);
		}
		if(op=='4'){this->levantarHipoteca(j);}
		if(op=='5'){this->ventaPropiedad(j);}
		if (op=='6'){return;}//sale del menú
		if(op=='7'){exit(0);}
	}
}

void Control::pagarRentaSolar(Jugador* j,int pos,Jugador *j2)
{
	if (dynamic_cast<CasillaSolar*>(t->getCasilla(pos)))
	{
		CasillaSolar* cs =	dynamic_cast<CasillaSolar*>(t->getCasilla(pos));
		if (!j->tengoLaPropiedad(pos) && cs->getDuenno())//No la tengo, y tiene dueñox
		{
			if (cs->getNumCasa()==0){j->setCapital(j->getCapital()-80);j2->setCapital(j2->getCapital()+80);gotoxy(20,10);cout<<"Has pagado: "<<80;}
			if (cs->getNumCasa()==1){j->setCapital(j->getCapital()-120);j2->setCapital(j2->getCapital()+120);gotoxy(20,10);cout<<"Has pagado: "<<120;}
			if (cs->getNumCasa()==2){j->setCapital(j->getCapital()-160);j2->setCapital(j2->getCapital()+160);gotoxy(20,10);cout<<"Has pagado: "<<160;}
			if (cs->getNumCasa()==3){j->setCapital(j->getCapital()-180);j2->setCapital(j2->getCapital()+180);gotoxy(20,10);cout<<"Has pagado: "<<180;}
			if (cs->getNumCasa()==4){j->setCapital(j->getCapital()-200);j2->setCapital(j2->getCapital()+200);gotoxy(20,10);cout<<"Has pagado: "<<200;}
			if (cs->getHotel()==1){j->setCapital(j->getCapital()-300);j2->setCapital(j2->getCapital()+300);gotoxy(20,10);cout<<"Has pagado: "<<300;}
		}
		else
		{
			gotoxy(20,10);cout<<"NO PAGAS RENTA!";
		}
	}
}

void Control::pagarRentaServicio(Jugador* j, int pos, Jugador *j2)
{
	if (dynamic_cast<CasillaServicio*>(t->getCasilla(pos)))
	{
		CasillaServicio* cs =	dynamic_cast<CasillaServicio*>(t->getCasilla(pos));
		if (!j->tengoLaPropiedad(2) ^ !j->tengoLaPropiedad(18))//Paga 10%
		{
			gotoxy(20,10);cout<<"Debe lanzar jugador :"<<j->getNombre();//opcional
			int o=lanzar();
			j2->setCapital(j2->getCapital()+(o*10));
			j1->setCapital(j1->getCapital()-(o*10));
		}

		if (!j->tengoLaPropiedad(2) && !j->tengoLaPropiedad(18))//Paga 20%
		{
			gotoxy(20,10);cout<<"Debe lanzar jugador :"<<j->getNombre();//opcional
			int o=lanzar();
			j2->setCapital(j2->getCapital()+(o*20));
			j1->setCapital(j1->getCapital()-(o*20));
		}
		else
		{
			gotoxy(20,10);cout<<"NO PAGAS RENTA!";
		}
	}
}

void Control::pagarRentaTren(Jugador* j, int pos, Jugador *j2)
{
	if (dynamic_cast<CasillaTren*>(t->getCasilla(pos)))
	{
		CasillaTren* cs =	dynamic_cast<CasillaTren*>(t->getCasilla(pos));
		if (!j->tengoLaPropiedad(pos) && cs->getDuenno())
		{
			if(j2->cuantosTrenes()==1){j->setCapital(j->getCapital()-120);j2->setCapital(j2->getCapital()+120);gotoxy(20,10);cout<<"Has pagado 120";}
			if(j2->cuantosTrenes()==2){j->setCapital(j->getCapital()-205);j2->setCapital(j2->getCapital()+205);gotoxy(20,10);cout<<"Has pagado 205";}
			if(j2->cuantosTrenes()==3){j->setCapital(j->getCapital()-315);j2->setCapital(j2->getCapital()+315);gotoxy(20,10);cout<<"Has pagado 315";}
			if(j2->cuantosTrenes()==4){j->setCapital(j->getCapital()-450);j2->setCapital(j2->getCapital()+450);gotoxy(20,10);cout<<"Has pagado 450";}
			
		}
		else
		{
			gotoxy(20,10);cout<<"NO PAGAS RENTA!";
		}
	}
}


void Control::verificaImpuesto(Jugador* j)
{

	//////////////| jugador 1 |/////////////
	if(j->getId()==1)
	{
		if(t->getPosJugador1()==9)//"R" hace referencia a Random como carta de la suerte.
		{
			gotoxy(20,10);cout<<"Pagas 190";j->setCapital(j->getCapital()-190);cin.get();
		}

		if(t->getPosJugador1()==23)//"R" hace referencia a Random como carta de la suerte.
		{
			gotoxy(20,10);cout<<"Pagas 160";j->setCapital(j->getCapital()-160);cin.get();
		}
	}
	//////////////| jugador 2 |/////////////

	if(j->getId()==2)
	{
		if(t->getPosJugador2()==9)//"R" hace referencia a Random como carta de la suerte.
		{
			gotoxy(20,10);cout<<"Pagas 190";j->setCapital(j->getCapital()-190);cin.get();
		}

		if(t->getPosJugador2()==23)//"R" hace referencia a Random como carta de la suerte.
		{
			gotoxy(20,10);cout<<"Pagas 160";j->setCapital(j->getCapital()-160);cin.get();
		}
	}


}

void Control::cantidadCasasHoteles(Casilla* c)
{
	if (dynamic_cast<CasillaSolar*>(c))
	{
		CasillaSolar* cs =	dynamic_cast<CasillaSolar*>(c);
		gotoxy(118,32);cout<<cs->getTitulo()<<" Casas: "<<cs->getNumCasa()<<" Hotel: "<<cs->getHotel();
	}

}

void Control::ventaPropiedad(Jugador* j)
{
	int con=0;int op=0;int aux=0;int pos=0;int aux2=0;
	if (j->getCantidadVector()>0)
	{
		for (int i = 0; i < j->getCantidadVector(); i++)
		{
			gotoxy(25,17+con);cout<<i+1<<") "<<j->getTarjeta(i)->getTitulo();con++;aux=i;
		}
		gotoxy(25,17+con);cin>>op;
		pos=j->getTarjeta(op-1)->getCodigo();
		CasillaPropiedad *tj=dynamic_cast<CasillaPropiedad*>(t->getCasilla(pos));cout<<tj->getTitulo();
		int aux3=tj->getMonto()*0.25;
		j->setCapital(j->getCapital()+aux3);
		tj->setDuenno(false);
		j->eliminarTarjeta(op-1);

	}else{
		gotoxy(22,17);cout<<"No tiene nada que vender";
	
	}
}

void Control::hipotecarPropiedad(Jugador* j)
{
	int con=0;int op=0;int aux=0;int pos=0;int aux2=0;
	if (j->getCantidadVector()>0)
	{
		for (int i = 0; i < j->getCantidadVector(); i++)
		{
			gotoxy(25,17+con);cout<<i+1<<") "<<j->getTarjeta(i)->getTitulo();con++;aux=i;
		}
		gotoxy(25,17+con);cin>>op;
		int aux3=j->getTarjeta(op-1)->getPrecioHipoteca();
		j->setCapital(j->getCapital()+aux3);
		j->getTarjeta(op-1)->setHipoteca(true);
	}else{
		gotoxy(20,10);cout<<"No tiene nada que hipotecar";
	
	}
}

bool Control::terminarJuego()
{
	if (i->terminarJuego()==1)// 1 para salir 2) seguir con el juego
	{
		return false;
	}else
	{
		return true;
	}

}

void Control::levantarHipoteca(Jugador* j)
{
	int aux1=0;int aux2=0;
	for (int i = 0; i < j->getCantidadVector(); i++)//recorrer el vector de jugador para encontrar hipotecas
	{
		if (j->getTarjeta(i)->getHipoteca())//si tiene hipoteca
		{
			aux1=j->getTarjeta(i)->getPrecioHipoteca();
			aux2=j->getTarjeta(i)->getPrecioHipoteca()*0.20 ;//el 20% de interes
			j->setCapital(j->getCapital()-(aux1+aux2));
		}
	}
}
