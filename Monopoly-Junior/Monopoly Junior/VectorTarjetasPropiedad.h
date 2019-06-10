#pragma once
#include "Librerias.h"
#include "TarjetaPropiedad.h"

class VectorTarjetasPropiedad
{
private:
	TarjetaPropiedad **vt;//vector de tarjetas
	int cant;
	int tam;
public:
	VectorTarjetasPropiedad(int);
	~VectorTarjetasPropiedad();
	void setCan(int);
	int getCan();  
	void insertarTarjetaPropiedad(TarjetaPropiedad* c);
	void setTarjeta(TarjetaPropiedad*);
	TarjetaPropiedad *getTarjetaPropiedad(int);
	TarjetaPropiedad *getTarjetaPropiedadPorCodigo(int);
	void imprimirNombres();
	void eliminarTarjeta(int);
	virtual void toString();
};
