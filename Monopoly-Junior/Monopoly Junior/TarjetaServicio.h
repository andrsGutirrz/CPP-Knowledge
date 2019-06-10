#include "Librerias.h"
#include "TarjetaPropiedad.h"

class TarjetaServicio:public TarjetaPropiedad{
private:
	string tipo;//luz o agua
public:
	TarjetaServicio();
	TarjetaServicio(string, int, int, string,int);// titulo, mont, codigo,tip
	~TarjetaServicio();
	void setTip(string);
	void gotoxy(int,int);
	void toString(int,int);//immprime el detalle de la propiedad
};