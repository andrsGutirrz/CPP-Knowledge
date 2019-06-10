
#ifndef LISTA_H
#define	LISTA_H

#include "iteradorLista.h"
#include "nodo.h"
#include "coleccion.h"
#include <sstream>
template <class T>
class lista :public coleccion<T>{
public:
    lista();
    lista(const lista& orig);
    virtual ~lista();

    virtual bool vacio() const;
    virtual int numElementos() const;
    virtual void agregar(T*);
    virtual void eliminar();
    virtual void agregarInicio(T*);
    virtual void agregarFinal(T*);
    virtual iterador<T>* obtenerIterador();
	//friend ostream& operator<<(ostream&, const lista<T>&);
private:
    nodo<T>* primerNodo;
    nodo<T>* ultimoNodo;
    int cantidad;

};
//------------


//-----------
template<class T>
lista<T>::lista() {
    primerNodo = NULL;
    ultimoNodo = NULL;
    cantidad = 0;
}
template<class T>
lista<T>::~lista() {
}
template<class T>
bool lista<T>::vacio() const {
    return primerNodo == NULL;
}
template<class T>
int lista<T>::numElementos() const {
    return cantidad;
}
template<class T>
void lista<T>::agregar(T* nuevaInfo) {

    // Cuando se agrega un elemento a una lista
    // que está inicialmente vacía, hay que fijar
    // el apuntador al último nodo.

    bool iniciandoLista = vacio();

    primerNodo = new nodo<T>(nuevaInfo, primerNodo);
    if (iniciandoLista) {
        ultimoNodo = primerNodo;
    }
    cantidad++;
}
template<class T>
void lista<T>::eliminar()
{
    if (!vacio()) {
	iterador<T>* i = obtenerIterador();
	while (i->masElementos()) {
	    T* e = i->proximoElemento();
            delete e;
	}
	delete i;
    }
}
template<class T>
void lista<T>::agregarInicio(T* nuevaInfo) {
    agregar(nuevaInfo);
}
template<class T>
void lista<T>::agregarFinal(T* nuevaInfo) {
    if (!vacio()) {

        // Si la lista no está vacía, la operación no afecta
        // al primer nodo, pero se debe actualizar el apuntador
        // al último nodo.

        ultimoNodo->fijarSiguiente(new nodo<T>(nuevaInfo, NULL));
        ultimoNodo = ultimoNodo->obtenerSiguiente();
        cantidad++;

    } else {

        // Si la lista está vacía, agregar al inicio o
        // al final es la misma operación.

        agregar(nuevaInfo);
    }
}
template<class T>
iterador<T>* lista<T>::obtenerIterador() {
    return new iteradorLista<T>(primerNodo);
}


#endif	/* LISTA_H */
/*
template <class T>
ostream& lista<T>::operator<<(ostream& salida, const lista<T>& e) {
	salida << e.toString();
	return salida;
}*/