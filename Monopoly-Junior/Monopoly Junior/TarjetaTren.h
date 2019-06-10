#include "Librerias.h"
#include "TarjetaPropiedad.h"

class TarjetaTren:public TarjetaPropiedad{

public:
	TarjetaTren();
	TarjetaTren(string, int, int, int);// titulo, mont, codigo,hipo
	~TarjetaTren();
	void gotoxy(int,int);
	void toString(int,int);//immprime el detalle de la propiedad
};