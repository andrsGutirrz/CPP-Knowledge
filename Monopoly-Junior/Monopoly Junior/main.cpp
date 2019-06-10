#include"Librerias.h"
#include"Control.h"

void main()
{
	SetConsoleTitle(TEXT("MONOPOLY JUNIOR"));
	Control *control=new Control;
	control->iniciar();

	cin.get();
};