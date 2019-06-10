#ifndef ITERADORLISTA_H
#define	ITERADORLISTA_H

#include <sstream>
#include "nodo.h"
#include "coleccion.h"
using namespace std;

template <class T>
class iteradorLista: public iterador<T> 
{
public:
    
    iteradorLista(nodo<T>*);
    virtual ~iteradorLista();

    virtual bool masElementos() const;
    virtual T* proximoElemento();

private:
    nodo<T>* cursor;

};

///////////////////////////////////////Declaracion///////////////////////////////////////////

template <class T>
iteradorLista<T>::iteradorLista(nodo<T>* primerNodo) : iterador<T>() 
{
    cursor = primerNodo;
}

template <class T>
bool iteradorLista<T>::masElementos() const 
{
    return (cursor != NULL);
}

template <class T>
T* iteradorLista<T>::proximoElemento() 
{
    T* r = NULL;
    if(masElementos()) {
        r = cursor->obtenerInfo();
        cursor = cursor->obtenerSiguiente();
    }
    return r;
}

template <class T>
iteradorLista<T>::~iteradorLista()
{
    
}

#endif	/* ITERADORLISTA_H */

