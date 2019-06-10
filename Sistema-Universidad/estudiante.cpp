/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estudiante.cpp
 * Author: User
 * 
 * Created on 27 de abril de 2017, 05:23 PM
 */

#include "estudiante.h"
#include "curso.h"

estudiante::estudiante(istream& entrada){
    matricula = new lista<grupo>();
    notas = new lista<nota>;
    int cantidadGrupos, numNotas = 0;
    int contGrupos = 1;int cantNotas = 1;
    entrada>>nombre;entrada>>id;entrada>>ape1;entrada>>ape2;entrada>>numCarnet;entrada>>extranjero;entrada>>porcentajeBeca;
    entrada>>cantidadGrupos;
    grupo* gr = NULL;
    while(contGrupos<=cantidadGrupos){
        gr = new grupo(entrada); 
        matricula->agregar(gr);
        contGrupos++;
    }
    entrada>>numNotas;
    nota* nt = NULL;
    while(cantNotas<=numNotas){
        nt = new nota(entrada);
        notas->agregar(nt);
        cantNotas++;
    }
    
}

estudiante::estudiante(string nom, string _id, string _ape1, string _ape2,string cart,bool extr,float porcentajeBe): 
    nombre(nom),id(_id),ape1(_ape1),ape2(_ape2),numCarnet(cart),extranjero(extr),porcentajeBeca(porcentajeBe) {
    matricula = new lista<grupo>();
    notas = new lista<nota>;
}

void estudiante::guardarEstudiante(ostream& salida){
    salida<<"\n"<<nombre<<" "<<id<<" "<<ape1<<" "<<ape2<<" "<<numCarnet<<" "<<extranjero<<" "<<porcentajeBeca<<"\n";
    iterador<grupo>* it = matricula->obtenerIterador();
    grupo* gr = NULL;
    salida<<matricula->numElementos()<<" ";
    while(it->masElementos()){
        gr = it->proximoElemento();
        gr->guardarGrupo(salida);
    }
    iterador<nota>* itN = notas->obtenerIterador();
    nota* nt = NULL;
    salida<<"\n"<<notas->numElementos()<<" ";
    while(itN->masElementos()){
        nt = itN->proximoElemento();
        nt->guardarNota(salida);
    }
    
}

estudiante::~estudiante() {
    delete matricula;
}


void estudiante::setNombre(string nom){
    this->nombre = nom;
}

void estudiante::setApe1(string _ape1){
    this->ape1 = _ape1;
}

void estudiante::setApe2(string _ape2){
    this->ape2 = _ape2;
}

 void estudiante::registrarNota(nota* calificacion){
     notas->agregar(calificacion);
 }

string estudiante::getNombre(){
    return this->nombre;
}

string estudiante::getId(){
    return this->id;
}

string estudiante::obtenerLlave(){
    return this->id;
}

string estudiante::getApe1(){
    return this->ape1;
}

string estudiante::getApe2(){
    return this->ape2;
}

string estudiante::getNumCarnet(){
    return this->numCarnet;
}

bool estudiante::getExtranjero(){
    return this->extranjero;
}


int estudiante::getNumCreditos(){
    numCreditos = 0;
    sumarCreditos();
    return numCreditos;
    
}

string estudiante::toString(){
    stringstream s;
    s<<"Nombre Completo : " << nombre << " " << ape1 << " " << ape2 <<endl
    <<"ID : "<< id << endl
    <<"Numero de Carnet : "<< numCarnet <<endl;
    if(extranjero){
        s<<" Nacionalidad: Extranjero"<<endl;
    }else{
        s<<" Nacionalidad: Nacional"<<endl;
    }
            
    return s.str();
}

string estudiante::verMisCursos(){
    stringstream s;
    iterador<grupo>* it = matricula->obtenerIterador();
    if(!it->masElementos()){s<<"(SIN CURSOS MATRICULADOS ACTUALMENTE)";}
    while(it->masElementos()){
        grupo* gr = it->proximoElemento();
        s<<"NOMBRE: "<<gr->getNombre()<<"  NRC: "<<gr->getNRC()<<endl;
    }
    return s.str();
}

void estudiante::insetarCurso(grupo* ob){//dice agregar curso pero es agregar grupo
    matricula->agregar(ob);
}

int estudiante::getNumeroDeCursos(){
    return numeroDeCursos;
}

float estudiante::getPorcentajeBeca(){ return porcentajeBeca;}
void estudiante::setPorcentajeBeca(float porcentajeBeca){ this->porcentajeBeca = porcentajeBeca;}

void estudiante::sumarCreditos(){
    iterador <grupo>*it = matricula->obtenerIterador();
    grupo *auxGrupo = NULL;
    while(it->masElementos()){
        auxGrupo = it->proximoElemento();
        numCreditos += auxGrupo->getCreditos();
    }
}

string estudiante::verMiNotas(){
    stringstream s;
    s<<notas->toString()<<endl;
    return s.str();
}

lista<grupo>* estudiante::retornaListaGrupos(){return matricula;}

double estudiante::retornarNotaGrupo(string nombreCurso){
    iterador<nota>* it = notas->obtenerIterador();
    while(it->masElementos()){
        nota* nt = it->proximoElemento();
        if(nt->obtenerNombreCurso() == nombreCurso)
            return nt->obtenerPromedio();        
    }
}
