/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   profesor.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 25 de abril de 2017, 10:43 PM
 */

#include "profesor.h"
#include "coleccionBuscable.h"


profesor::profesor(istream& entrada){
    misCursos = new coleccionBuscable<grupo>(new lista<grupo>());
    int cantidadGrupos = 0;
    int contGrupos = 1;int cantNotas = 1;
    entrada>>id;entrada>>nombre;entrada>>ape1;entrada>>ape2;entrada>>director;entrada>>miEscuela;entrada>>tengoEscuela;
    entrada>>cantidadGrupos;
    grupo* gr = NULL;
    while(contGrupos<=cantidadGrupos){
        gr = new grupo(entrada); 
        misCursos->agregar(gr);
        contGrupos++;
    }
    

}
profesor::profesor(string _id, string _nom,string _ape1,string _ape2):
    id(_id),nombre(_nom),ape1(_ape1),ape2(_ape2), director(false)
{
    misCursos = new coleccionBuscable<grupo>(new lista<grupo>());
    this->miEscuela = "SIN ESCUELA ASIGNADA";
    this->tengoEscuela =false;
}

void profesor::guardarProfesor(ostream& salida){
    salida<<"\n"<<id<<" "<<nombre<<" "<<ape1<<" "<<ape2<<" "<<director<<" "<<miEscuela<<" "<<tengoEscuela<<" ";
    iterador<grupo>*it = misCursos->obtenerIterador();
    salida<<"\n"<<misCursos->numElementos()<<" ";
    grupo* gr = NULL;
    while(it->masElementos()){
        gr = it->proximoElemento();
        gr->guardarGrupo(salida);
    }
}

profesor::~profesor() {
    delete misCursos;
}

bool profesor::esDirector(){
    return director;
}

void profesor::setDirector(bool b){
    director = b;
}
string profesor::getNombre(){
    return this->nombre;
}

string profesor::getApe1(){
    return this->ape1;
}

string profesor::getApe2(){
    return this->ape2;
}

string profesor::getId(){
    return this->id;
}

string profesor::obtenerLlave(){
    return this->id;
}


void profesor::setNombre(string nom){
    this->nombre = nom;
}

void profesor::setApe1(string _ape1){
    this->ape1 = _ape1;
}

void profesor::setApe2(string _ape2){
    this->ape2 = _ape2;
}

string profesor::toString(){
    stringstream s;
    s<<"\n\tEscuela: "<<this->miEscuela<<"\n"
    <<"\tNombre Completo : " << nombre << " " <<ape1 
    << " " << ape2 <<" " 
    <<"\n\tID : "<<id;
    return s.str();       
}

string profesor::nombreCompleto(){
    stringstream s;
    s<<this->nombre<<"  "<<this->ape1<<"  "<<this->ape2<<"  "<<this->id<<endl;
    return s.str();
}


void profesor::insertarCursoProf(grupo* c){//insertar curso
    this->misCursos->agregar(c);    
}

bool profesor::yaTengoEseCurso(grupo* c){
    //curso* c1 = (curso*)c;
    grupo* c2 = NULL;
    iterador<grupo>* it = misCursos->obtenerIterador();
    while(it->masElementos()){
        c2 = it->proximoElemento();
        if(*c2==*c){ return true;}  //operador sobrecargado
    }
    return false;
}

string profesor::imprimirMisCursos(){
    stringstream s;
    s<<this->misCursos->toString();
    return s.str();
}

void profesor::setMiEscuela(string s){
    this->miEscuela = s;
    this->tengoEscuela = true;
}

bool profesor::getTengoEscuela(){
    return this->tengoEscuela;
}

string profesor::getNombreEscuela(){
    stringstream s;
    s<<this->miEscuela;
    return s.str();
}

