
#ifndef COLECCIONBUSCABLE_H
#define COLECCIONBUSCABLE_H

#include "coleccion.h"


template<class T>
class coleccionBuscable : public coleccion<T> {
public:
        coleccionBuscable(coleccion<T>*);
        virtual int numElementos() const;
        virtual void agregar(T*);
        virtual iterador<T>* obtenerIterador() ;
        /*@diferentes*/
        virtual int buscarPosicion(string) ;
        virtual T* buscar(string) ;
private:
        coleccion<T>* _c;
};
	
template<class T>
coleccionBuscable<T>::coleccionBuscable(coleccion<T>* c) : _c(c) {
}
template<class T>
int coleccionBuscable<T>::numElementos() const {
	return _c->numElementos();
}

template <class T>
void coleccionBuscable<T>::agregar(T* obj) {
	_c->agregar(obj);
}

template <class T>
iterador<T>* coleccionBuscable<T>::obtenerIterador()  {
	return _c->obtenerIterador();
}

template <class T>
int coleccionBuscable<T>::buscarPosicion(string llave)  {
	int r = 0;

	iterador<T>* i = obtenerIterador();
	bool encontrado = false;
	while (i->masElementos()) {
		T* obj = i->proximoElemento();
		if (encontrado = (obj->obtenerLlave() == llave)) {
			break;
		}
		else {
			r++;
		}
	}
	if (!encontrado) {
		return -1;
	}

	return r;
}

template <class T>
T* coleccionBuscable<T>::buscar(string llave)  {
    T* r = NULL;
    iterador<T>* i = obtenerIterador();
    bool encontrado = false;
    while (i->masElementos()) {
            T* obj = i->proximoElemento();
            if (encontrado = (obj->obtenerLlave() == llave)) {
                    r = obj;
                    break;
            }
    }
    return r;
}

#endif /* COLECCIONBUSCABLE_H */
