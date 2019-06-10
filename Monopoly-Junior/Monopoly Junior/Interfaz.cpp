#include "Interfaz.h"

unsigned char a=200; //Imprime ╚
unsigned char b=186; //Imprime ║
unsigned char c=205; //Imprime ═
unsigned char d=188; //Imprime ╝
unsigned char e=201; //Imprime ╔
unsigned char f=187; //Imprime ╗
unsigned char n=248; //Imprime ®

Interfaz::Interfaz(void)
{
}

Interfaz::~Interfaz(void)
{
}

void Interfaz::gotoxy(int x,int y) //Funcion que imprime en pantalla mediante coordenadas
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Interfaz::colorear(int x)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,x|FOREGROUND_INTENSITY);
}

void Interfaz::titulo()
{
limpiarPantalla();
colorear(12);
gotoxy(0,5);cout<<"                 M      M        OOOOOOOOOOO  NN        NN  OOOOOOOOOOO  PPPPPPPPPPP  OOOOOOOOOOO  LL        $      $"<<endl;
gotoxy(0,6);cout<<"                MM      MM       OO       OO  NN N      NN  OO       OO  PP        P  OO       OO  LL         $    $"<<endl;
gotoxy(0,7);cout<<"               MMM      MMM      OO       OO  NN  N     NN  OO       OO  PP        P  OO       OO  LL          $  $"<<endl;
gotoxy(0,8);cout<<"              MMM M    M MMM     OO       OO  NN   N    NN  OO       OO  PPPPPPPPPPP  OO       OO  LL           $$"<<endl;
gotoxy(0,9);cout<<"             MMM   MMMM   MMM    OO       OO  NN    N   NN  OO       OO  PP           OO       OO  LL           $$"<<endl;
gotoxy(0,10);cout<<"            MMM            MMM   OO       OO  NN     N  NN  OO       OO  PP           OO       OO  LL           $$"<<endl;
gotoxy(0,11);cout<<"           MMM              MMM  OO       OO  NN      N NN  OO       OO  PP           OO       OO  LL           $$"<<endl;
gotoxy(0,12);cout<<"          MMM                MMM OOOOOOOOOOO  NN        NN  OOOOOOOOOOO  PP           OOOOOOOOOOO  LLLLLLLLL    $$ "<<endl;
colorear(15);
}

void Interfaz::indicaciones()
{
	unsigned char q=165;
	gotoxy(10,5); cout<<"INDICACIONES PARA MAXIMO FUNCIONAMIENTO:";
	gotoxy(10,7); cout<<"ANTES DE COMENZAR EL JUEGO DIRIGIRSE A LA ESQUINA SUPERIOR IZQUIERDA, CLICK IZQUIERDO, ";
    gotoxy(10,8); cout<<"PROPIEDADES, FUENTE, TAMA"<<q<<"O, EN ESTE ULTIMO ESTABLECER LA FUENTE EN 15 O 14 DEPENDIENDO DE LA RESOLUCION DE SU PANTALLA.";
	cin.get();
}

void Interfaz::menuGeneneral()
{
	gotoxy(30,30);cout<<" __________________";
	gotoxy(30,31);cout<<"|[1] Jugar.        |";
	gotoxy(30,32);cout<<"|[2] Instrucciones.|";
	gotoxy(30,33);cout<<"|[3] Salir.        |";
	gotoxy(30,34);cout<<"|__________________|";
	gotoxy(30,35);cout<<" ->";
}


void Interfaz::musica()
{
	PlaySound(TEXT("Monopoly.wav"), NULL, SND_FILENAME|SND_ASYNC);
}

void Interfaz::monopolyWorldEditionLogo()
{
colorear(14);
gotoxy(120,1); cout<<"                                .-"""""- ""<<endl;
gotoxy(120,2); cout<<"                               /<I>\ /<I>\""<<endl;
gotoxy(120,3); cout<<"                              (  _ ._. _  )"<<endl;
gotoxy(120,4); cout<<"                               '. V   V .'"<<endl;
gotoxy(120,5); cout<<"                                | >===< |"<<endl;
gotoxy(120,6); cout<<"                                | >===< |"<<endl;
gotoxy(120,7); cout<<"                              __| >===< |__"<<endl;
gotoxy(120,8); cout<<"                        _..- x, | >===< | ,X -.._ "<<endl;
gotoxy(120,9); cout<<"                   _.- `Xx,   'X  >===<  X'   ,xX`  .  "<<endl;
gotoxy(120,10); cout<<"               _.'`X.    'Xx.  'X,>===<,X'  .xX'    .X`._"<<endl;
gotoxy(120,11); cout<<"             .'X    `X,   'Xx   'X === X'   xX'   ,X'   X'."<<endl;
gotoxy(120,12); cout<<"           .xXXXXx,   'X    'Xx  'X = X'  xX'    X'   ,xXXXXx."<<endl;
gotoxy(120,13); cout<<"         .'       'X.   'X   'Xx  'X X'  xX'   X'   .X'       '."<<endl;
gotoxy(120,14); cout<<"       .xXXXXXXXXXXXXX,  `Xx. 'Xx, .X. ,xX' .xX'  ,XXXXXXXXXXXXXx. "<<endl;
gotoxy(120,15); cout<<"      /               `X   XX  'XX//^\\XX'  XX   X`               \""<<endl;
gotoxy(120,16); cout<<"     /XXXXXXXXXXXXXXXXXXX   XX  'X\\_//X'  XX   XXXXXXXXXXXXXXXXXXX\""<<endl;
gotoxy(120,17); cout<<"    /                    X_.XX___XX'='XX___XX._X                    \""<<endl;
gotoxy(120,18); cout<<"    |XXXXXXXXXXXXXXXXXXX.'                     '.XXXXXXXXXXXXXXXXXXX|"<<endl;
gotoxy(120,19); cout<<"    |                  /                         \                  |"<<endl;
gotoxy(120,20); cout<<"    |XXXXXXXXXXXXXXXXX/   ..::::.       .::::..   \XXXXXXXXXXXXXXXXX|"<<endl;
gotoxy(120,21); cout<<"    |                /  .'       '     '       '.  \                |"<<endl;
gotoxy(120,22); cout<<"    /XXXXXXXXXXXXXXXX|  _.-````"-       "````-._  |XXXXXXXXXXXXXXXX\"";
gotoxy(120,22); cout<<"   |              .==.;   '._(')_.'\    '._(')_.'   ;.==.             |"<<endl;
gotoxy(120,24); cout<<"   |XXXXXXXXXXX.'.-, |            |   |            | ,-.'.XXXXXXXXXXX|"<<endl;
gotoxy(120,25); cout<<"   |           |; (               |   |               ) ;|           |"<<endl;
gotoxy(120,26); cout<<"   |XXXXXXXXXXX|;  `,            /    .\            ,'  ;|XXXXXXXXXXX|"<<endl;
gotoxy(120,27); cout<<"   |           ;;'--            ( _   _ )            --';;           |"<<endl;
gotoxy(120,28); cout<<"   |XXXXXXXXXXXX\' o                                 o '/XXXXXXXXXXXX|"""""<<endl;
gotoxy(120,29); cout<<"   |             '-J-'|            : :            |'-L-'             |"<<endl;
gotoxy(120,30); cout<<"   |XXXXXXXXXXXXXX(_)X\          __   __          /X(_)XXXXXXXXXXXXXX|"<<endl;
gotoxy(120,31); cout<<"   |                   \      .-'  `'`  '-.      /                   |"<<endl;
gotoxy(120,32); cout<<"   |XXXXXXXXXXXXXXXXXXXX\    `- """""""" - ´            /XXXXXXXXXXXXXXXXXXXX|"""<<endl;
gotoxy(120,33); cout<<"   |                     \      `-.....-'      /                     |"<<endl;
gotoxy(120,34); cout<<"   |XXXXXXXXXXXXXXXXXXXXXX'.                 .'XXXXXXXXXXXXXXXXXXXXXX|"<<endl;
gotoxy(120,35); cout<<"    \                       `;-._       _.-;`                       /"<<endl;
gotoxy(120,36); cout<<"     \XXXXXXXXXXXXXXXXXXXXXXX|   `}}}}}`   |XXXXXXXXXXXXXXXXXXXXXXX/"<<endl;
gotoxy(120,37); cout<<"      '.                     |    {{{{{    |                     .'"<<endl;
gotoxy(120,38); cout<<"        '.XXXJGSXXXXXXXXXXXXX|     }}}}    |XXXXXXXXXXXXXXXXXXX.'"<<endl;
gotoxy(120,39); cout<<"          \                  |     {{{     |                  /"<<endl;
gotoxy(120,40); cout<<"            \                |      (      |                /"<<endl;
gotoxy(120,41); cout<<"             'XXXXXXXXXXXXXXX|             |XXXXXXXXXXXXXXX'"<<endl;
gotoxy(120,42); cout<<"              \              |             |              /"<<endl;
gotoxy(120,43); cout<<"               \XXXXXXXXXXXXX|             |XXXXXXXXXXXXX/"<<endl;
gotoxy(120,44); cout<<"               |             |             |             |"<<endl;
gotoxy(120,45); cout<<"               |XXXXXXXXXXXXX|             |XXXXXXXXXXXXX|"<<endl;
gotoxy(120,46); cout<<"               |             |             |             |"<<endl;
gotoxy(120,47); cout<<"               |XXXXXXXXXXXXX|             |XXXXXXXXXXXXX|"<<endl;
gotoxy(120,48); cout<<"               \             |             |             /"<<endl;
gotoxy(120,49); cout<<"                'XXXXXXXXXXXX|             |XXXXXXXXXXXX'"<<endl;
gotoxy(120,50); cout<<"                  `-.________/             \________.-`"<<endl;
 

colorear(15);
}

char Interfaz::msjAvanzar()
{
	char x;
	gotoxy(110,10); cout<<"Digite 'x' para lanzar los dados.";
	gotoxy(110,11); cin>>x;

	return x;
}

void Interfaz::msjCarcel()
{
	gotoxy(30,15); cout<<"PIERDES UN TURNO!.";
}

char Interfaz::msjMulta()
{
	char x;
	gotoxy(110,13); cout<<"Digite S para pagar o N si aun no desea pagar.";
	gotoxy(110,14); cin>>x;

	return x;
}

void Interfaz::msjBancaRota()
{
	gotoxy(110,13); cout<<"Quedastes en BANCA ROTA, Juego Perdido :(";
}

void Interfaz::msjGo()
{
	gotoxy(45,10); cout<<"Pasas por GO, Recibes 200 :D";
}

void Interfaz::limpiarPantalla()
{
	system("cls");
}

void Interfaz::interfazDado(int x, int y, int k)
{
	if (k==1)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<"     "<<b<<endl;
	gotoxy(x,y+2); cout<<b<<"  "<<n<<"  "<<b<<endl;
	gotoxy(x,y+3); cout<<b<<"     "<<b<<endl;
	gotoxy(x,y+4); cout<<a<<c<<c<<c<<c<<c<<d<<endl;
	}
	if (k==2)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<n<<"    "<<b<<endl;
	gotoxy(x,y+2); cout<<b<<"     "<<b<<endl;
	gotoxy(x,y+3); cout<<b<<"    "<<n<<b<<endl;
	gotoxy(x,y+4); cout<<a<<c<<c<<c<<c<<c<<d<<endl;
	}
	if (k==3)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<n<<"    "<<b<<endl;
	gotoxy(x,y+2); cout<<b<<"  "<<n<<"  "<<b<<endl;
	gotoxy(x,y+3); cout<<b<<"    "<<n<<b<<endl;
	gotoxy(x,y+4); cout<<a<<c<<c<<c<<c<<c<<d<<endl;
	}
	if (k==4)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+2); cout<<b<<"     "<<b<<endl;
	gotoxy(x,y+3); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+4); cout<<a<<c<<c<<c<<c<<c<<d<<endl;
	}
	if (k==5)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+2); cout<<b<<"  "<<n<<"  "<<b<<endl;
	gotoxy(x,y+3); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+4); cout<<a<<c<<c<<c<<c<<c<<d<<endl;
	}
	if (k==6)
	{
	gotoxy(x,y); cout<<e<<c<<c<<c<<c<<c<<f<<endl;
	gotoxy(x,y+1); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+2); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+3); cout<<b<<n<<"   "<<n<<b<<endl;
	gotoxy(x,y+4); cout<<a<<c<<c<<c<<c<<c<<d<<endl;
	}
}

char Interfaz::comprarPropiedad(int montoCompra,Jugador* j,Tablero* t)
{
	char op=' ';
	gotoxy(110,10);cout<<"JUGADOR, LA PROPIEDAD " <<"VALE: " <<montoCompra;
	gotoxy(110,11);cout<<"QUIERE COMPRARLA: 1=SI  2=NO ";
	gotoxy(110,12);cin>>op; 
	return op;
	//if (op=='1'||op=='2'){return op;}
	/*else
	{
		comprarPropiedad(montoCompra,j,t);
	}*/
}

void Interfaz::compraSatisfactoria()
{
	gotoxy(110,13);cout<<"COMPRA SATISFACTORIA"<<endl;
}

void Interfaz::yaTienePropiedad()
{
	gotoxy(110,10);cout<<"Esta propiedad tiene propietario debe pagar RENTA"<<endl;
}

void Interfaz::monopolio(int n)
{
	
}

int Interfaz::opcionConstruir(string v[])//recive las tarjetas donde see puede construir
{
	const int size = sizeof(v)/sizeof(v[0]);//tamaño del vector de char
	if (size>=1)
	{
		int op;
		int aux=0;
		for (int i = 0; i < size; i++)
		{	
			if (v[i]!="NULL")
			{
				gotoxy(110,40+i);cout<<"OPCION "<<i+1<<" : "<<v[i];
				aux=i;
			}
		}
		aux=aux+1;
		gotoxy(110,40+aux);cin>>op;

		return op;
	}
	return -1;	
}//ELIMINAR

char Interfaz::opcionesJugador()
{

	char op=0;
	gotoxy(110,35);cout<<"OPCIONES";
	gotoxy(110,36);cout<<"1) Comprar Propiedad";
	gotoxy(110,37);cout<<"2) Construir";
	gotoxy(110,38);cout<<"3) Hipotecar";
	gotoxy(110,39);cout<<"4) Levantar Hipoteca";
	gotoxy(110,40);cout<<"5) Vender";
	gotoxy(110,41);cout<<"6) Lanzar";
	gotoxy(110,42);cout<<"7) Salir";
	gotoxy(110,43);cin>>op;

	return op;
}

void Interfaz::errorValidacion()
{
	gotoxy(20,10);cout<<"Error en la lectura, debe ingresar datos nuevamente";
}


char Interfaz::terminarJuego()
{
	char op=' ';
	gotoxy(25,25);cout<<"Seguro que desea salir";
	gotoxy(25,26);cout<<"1) Si 2) No";
	gotoxy(25,27);cin>>op;
	if (op!='1' && op!='2'){ this->terminarJuego();}
	return op;
}