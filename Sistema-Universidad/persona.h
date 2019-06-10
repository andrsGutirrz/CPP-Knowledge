/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   persona.h
 * Author: Andrés Gutiérrez
 *
 * Created on 22 de abril de 2017, 04:02 PM
 */

#ifndef PERSONA_H
#define PERSONA_H
#include"objetoBase.h"

class persona :virtual public objetoBase{
public:
    persona(string,string,string,string);//nombre,id,ape1,ape2
    virtual ~persona();
    virtual string toString();
    virtual string getNombre();
    virtual string getID();
    virtual string getPrimerApe();
    virtual string getSegundoApe();
    virtual void setNombre(string);
    virtual void setPrimerApe(string);
    virtual void setSegundoApe(string);
private:
    string nombre;
    string id;
    string ape1;
    string ape2;
};

#endif /* PERSONA_H */

