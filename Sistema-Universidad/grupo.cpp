/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   grupo.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 8 de mayo de 2017, 04:03 PM
 */

#include "grupo.h"

grupo::grupo(istream& entrada):tam(35){
    entrada>>nombre;
    entrada>>nrc;
    entrada>>creditos;
    entrada>>cant;
    cant = 0;
    estudiantesMatriculados = new lista<estudiante>();
    this->miProfesor = NULL;
}

grupo::grupo(string nomb,string nrc,int credi):nombre(nomb),nrc(nrc),creditos(credi),tam(35),cant(0){
    estudiantesMatriculados = new lista<estudiante>();
    this->miProfesor = NULL;
}

void grupo::guardarGrupo(ostream& salida){
    salida<<nombre<<" "<<nrc<<" "<<creditos<<" "<<cant<<" ";
}

grupo::~grupo(){
    delete estudiantesMatriculados;
}
void grupo::setNombre(string nom){this->nombre = nom;}
string grupo::getNombre(){return this->nombre;}
void grupo::setMiProfe(profesor* prof){ this->miProfesor = prof;}
profesor* grupo::getProfesor(){return this->miProfesor;}
string grupo::getNRC(){return this->nrc;}
string grupo::obtenerLlave(){return this->nrc;}
int grupo::getCantidad(){return cant;}

string grupo::toString(){
    stringstream s;
    s<<"----------------------------------------------------------------"<<endl;
    s<<"\tNombre: "<<this->getNombre()<<endl<<"\tNRC: "<<this->getNRC()<<endl;
    if(miProfesor==NULL){s<<"\t(PROFESOR SIN ASIGNAR)"<<endl;}
    else{
        s<<"\tPROFESOR A CARGO"<<endl;
        s<< miProfesor->toString()<<endl;
    }
    s<< "\tCreditos: "<< this->getCreditos() <<endl;
    s<< "Numero de estudiantes matriculados: "<<cant<<endl;
    s<<"----------------------------------------------------------------"<<endl;
    return s.str();
}

bool grupo::operator==(grupo& c){
    return this->nrc == c.nrc;
}

void grupo::setCreditos(int cred){
    this->creditos = cred;
}

int grupo::getCreditos(){
    return this->creditos;
}
void grupo::insertarEstudianteGrupo(estudiante* obj){
    estudiantesMatriculados->agregar(obj);
    cant++;
}

void grupo::verEstudiantesMatriculados(){
    cout<<estudiantesMatriculados->toString()<<endl;
}

void grupo::asignarNotas(){//un ciclo para asignarle notas a todos sus estudiantes
    double notaAux = 0;
    iterador<estudiante>* it = estudiantesMatriculados->obtenerIterador();
    while(it->masElementos()){
        estudiante* est = it->proximoElemento();
        cout<<est->getNombre()<<endl;
        cout<<"INGRESE NOTA FINAL: ";cin>>notaAux;
        nota* nt = new nota(nombre,notaAux);
        est->registrarNota(nt);
    }
}

void grupo::reporteNotas(ostream& salida){//
    iterador<estudiante>* it = estudiantesMatriculados->obtenerIterador();
    while(it->masElementos()){
        estudiante* est = it->proximoElemento();
        salida<<est->getNombre()<<" ";
        iterador<grupo>* itGrupo = est->retornaListaGrupos()->obtenerIterador();
        while(itGrupo->masElementos()){
            grupo* gr = itGrupo->proximoElemento();
            if(*this == *gr){
                salida<<est->retornarNotaGrupo(nombre);
            }
        }
    }
    salida<<"\n";
}
