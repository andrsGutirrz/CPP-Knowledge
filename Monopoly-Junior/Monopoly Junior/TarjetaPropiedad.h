#pragma once
#include "Librerias.h"
#include "Tarjeta.h"

class TarjetaPropiedad:virtual public Tarjeta //virtual: para que las clases derivadas puedan usar metodos de la clase 'abuela'
{
	protected:
		string titulo;
		int precioHipoteca;
		int codigo;	
		bool hipotecada;
	public:
		TarjetaPropiedad();
		TarjetaPropiedad(string,int,int,int);
		~TarjetaPropiedad();
		void setPrecioHipoteca(int);
		int getPrecioHipoteca();
		void setCodigo(int);
		int getCodigo();
		void setHipoteca(bool);//hipoteca para tarjeta
		bool getHipoteca();
		string getTitulo();
		void gotoxy(int,int);
		virtual void toString(int,int)=0;//immprime el detalle de la propiedad
};