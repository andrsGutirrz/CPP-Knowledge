/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   persona.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 22 de abril de 2017, 04:02 PM
 */

#include "persona.h"

persona::persona(string nom, string _id, string _ape1, string _ape2): nombre(nom),id(_id),
        ape1(_ape1),ape2(_ape2) {
}

persona::~persona() {
}

string persona::getNombre(){
    return nombre;
}

string persona::getID(){
    return id;
}

string persona::getPrimerApe(){
    return ape1;
}

string persona::getSegundoApe(){
    return ape2;
}

void persona::setNombre(string nom){ 
    this->nombre = nom;
}

void persona::setPrimerApe(string _ap1){
    this->ape1 = _ap1;
} 

void persona::setSegundoApe(string _ap2){
    this->ape2 = _ap2;
}
string persona::toString(){
    stringstream s;
    
    s<<"Nombre Completo : "<< nombre << " "  
            << ape1 <<" "<<ape2 <<endl
            <<"Cedula: "<<id<<endl << endl;
    
    return s.str();
            
}