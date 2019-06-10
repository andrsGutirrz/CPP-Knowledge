#include "MazoSuerte.h"

MazoSuerte::MazoSuerte()
{
	inicio= NULL;
	actual=NULL;
}

void MazoSuerte::insertar(TarjetaSuerte *t)
{
	/* Crear un nodo nuevo */
   NodoMazo *nuevo=new NodoMazo(t, inicio);;
  
   /* Ahora, el comienzo de nuestra pila es en el nuevo nodo */
   inicio = nuevo;
}

TarjetaSuerte* MazoSuerte::sacar()
{
   TarjetaSuerte *t= new TarjetaSuerte();     /* Objeto auxiliar para retorno */
   
   actual = inicio; 
  
   inicio = actual->getSig();       /* Asignamos a actual toda la pila */
   
   t = actual->getTarjeta();       /* Guardamos el objeto de retorno */

   devolver(t);                    /* Devuelve el elemento tomado de la pila al final de esta */

   return t;
}

void MazoSuerte::devolver(TarjetaSuerte* t)
{
	actual=inicio;

		 while (actual->getSig () != NULL) //Este ciclo posiciona el puntero en el ultimo de la lista
		 {
			 actual= actual-> getSig();
		 }
		 actual->setSig( new NodoMazo(t, NULL));
}

void MazoSuerte::toString()
{
	actual= inicio;
	while (actual != NULL)
	{
		actual->toStringNodo();
		actual= actual->getSig();
	}
}

MazoSuerte::~MazoSuerte()
{
	while(inicio!=NULL)
	{
	actual=inicio;
	inicio=inicio->getSig();
	delete actual;
	}
	delete inicio;
}