#include "VectorTarjetasPropiedad.h"

VectorTarjetasPropiedad::VectorTarjetasPropiedad(int tam )
{
	vt=new TarjetaPropiedad*[tam];
	cant=0;
	this->tam=tam;
	for (int i = 0; i < tam; i++)
	{
		vt[i]=NULL;
	}
}

VectorTarjetasPropiedad::~VectorTarjetasPropiedad()
{
	for(int i=0;i<tam;i++)
	{
		delete vt[i];
	}

	delete[]vt;
}

void VectorTarjetasPropiedad::setCan(int n)
{
	cant = cant=n;
}

int VectorTarjetasPropiedad::getCan()
{
	return cant;
}

void VectorTarjetasPropiedad::setTarjeta(TarjetaPropiedad* tj)
{
	if(cant<tam)
	{
		vt[cant]=tj;
		cant=cant+1;
	}
}

TarjetaPropiedad *VectorTarjetasPropiedad::getTarjetaPropiedad(int n)
{
	return vt[n];
}

TarjetaPropiedad *VectorTarjetasPropiedad::getTarjetaPropiedadPorCodigo(int n)//el parametro es el código
{
	for (int i = 0; i < tam; i++)
	{
		if (vt[i]!=NULL)
		{
			if (vt[i]->getCodigo()==n)
			{
				return vt[i];
			}
		}
	}
	
}

void VectorTarjetasPropiedad::insertarTarjetaPropiedad(TarjetaPropiedad* c)
{
	if(cant<tam)
	{
		vt[cant]=c;
		cant=cant+1;
	}
}

void VectorTarjetasPropiedad::imprimirNombres()
{
	for (int i = 0; i < tam; i++)
	{
		if (vt[i]!=NULL)
		{
			cout<<vt[i]->getTitulo()<<" ";
		}
	}
}

void VectorTarjetasPropiedad::toString()
{
	for (int i = 0; i < tam; i++)
	{
		if (vt[i]!=NULL)
		{
			vt[i]->toString(99,99);
		}
	}
}

void VectorTarjetasPropiedad::eliminarTarjeta(int pos)
{

	delete vt[pos];
	for (int i = pos; i < cant; i++)
	{
		vt[i]=vt[i+1];
	}
	
}