#ifndef COLECCION_H
#define COLECCION_H
#include <sstream>
#include <iostream>
using namespace std;

template<class T>
class coleccion;
template <class T>
class iterador;
template <class T>
class coleccion {
public:
    virtual int numElementos() const = 0;
    virtual void agregar(T*) = 0;
    virtual iterador<T>* obtenerIterador() = 0;
    virtual string toString() ;
};

template <class T>
class iterador {
public:
        virtual bool masElementos() const = 0;
        virtual T* proximoElemento() = 0;
};


template <class T>
 string coleccion<T>::toString() {
    stringstream r;
    bool primerElemento = true;
    r << "[";
    iterador<T>* i = obtenerIterador();
    while (i->masElementos()) {
            if (!primerElemento) {
                    r << ", \n";
            }
            r << i->proximoElemento()->toString();//por ahora un toString()
            primerElemento = false;
    }
    r << "\n]\n";
    return r.str();
 }



#endif /* COLECCION_H */
