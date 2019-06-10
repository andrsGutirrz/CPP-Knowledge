#include "Librerias.h"
#include "TarjetaPropiedad.h"

class TarjetaSolar:public TarjetaPropiedad{

private:
	int precioConstruccion;//nuevo
	int numeroCasa;
	char color;
public:
	TarjetaSolar();
	TarjetaSolar(string,int, int,int,int, char,int);// titulo, mont, cod, precoConstr, numeroCasas, color
	~TarjetaSolar();
	void setMonto(int);
	int getMonto();
	void setPrecioConstruccion(int);
	int getPrecioConstruccion();
	void setNumCasa(int);
	int getNumCasa();
	char getColorSolar();
	void gotoxy(int,int);
	void toString(int,int);//immprime el detalle de la propiedad
};