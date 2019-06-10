/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso.cpp
 * Author: Elmer MB
 * 
 * Created on 24 de marzo de 2017, 8:53
 */

#include "curso.h"
curso::curso(istream& entrada){
    int cantidadGrupos = 0;
    entrada>>cantidadGrupos;
    entrada>>nombre;
    entrada>>cod;
    entrada>>pertenece;
    entrada>>creditos;
    grupos = new lista<grupo>();
    restaurarGrupo(entrada,cantidadGrupos);
}

void curso::restaurarGrupo(istream& entrada,int cantidadGrupos){
    int cont = 1;
    grupo* gr = NULL;
    while(cont<=cantidadGrupos){
        gr = new grupo(entrada); 
        grupos->agregar(gr);
        cont++;
    } 
    
}

curso::curso(string nomb, string siglas, string pertenece,int credito):nombre(nomb),pertenece(pertenece),cod(siglas),creditos(credito){    
    grupos = new lista<grupo>();
}

void curso::guardarCurso(ostream& salida){
    salida<<grupos->numElementos()<<" "<<nombre<<" "<<cod<<" "<<pertenece<<" "<<creditos<<"\n";
    iterador<grupo>*it = grupos->obtenerIterador();
    grupo* gr = NULL;
    while(it->masElementos()){
        gr = it->proximoElemento();
        gr->guardarGrupo(salida);
    }
}


curso::~curso() {
}

void curso::setNombre(string nombre){this->nombre=nombre;}

string curso::getNombre(){return nombre;}

string curso::getPertenece(){return pertenece;}
string curso::getCodigoCurso(){return this->cod;}
string curso::obtenerLlave(){return this->cod;}

void curso::registrarEcuela(){
    cout<<"Ingrese nombre del curso"<<endl;getline(cin,nombre, '\n');cin.ignore(256,'\n');
    std::transform(nombre.begin(), nombre.end(),nombre.begin(), ::toupper);
   
    cout<<"Ecuela a la que pertenece"<<endl;getline(cin,pertenece, '\n');cin.ignore(256,'\n');
}//revisar, se especula que no se usa ese metodo

void curso::setMiProfe(profesor* prof){ this->miProfesor = prof;}

profesor* curso::getMisProfes(){return this->miProfesor;}

string curso::toString(){
    stringstream s;
    s<<"\tNombre: "<<this->getNombre()<<endl<<"\tSiglas: "<<this->getCodigoCurso()<<endl<<"\tPertenece: "<<this->getPertenece()<<endl;
    s<< "\tCreditos: "<< this->getCreditos() <<endl;
    return s.str();
}

bool curso::operator==(curso& c){
    return this->cod == c.cod;
}

void curso::setCreditos(int cred){
    this->creditos = cred;
}

int curso::getCreditos(){
    return this->creditos;
}

void curso::insetarGrupo(grupo* ob){
    grupos->agregar(ob);    
}

void curso::desplegarGrupos(){
    cout<<grupos->toString()<<endl;
}

string curso::verGrupos(){
    stringstream s;
    iterador <grupo> *it = grupos->obtenerIterador();
    grupo* aux = NULL;
    while(it->masElementos()){
        aux = it->proximoElemento();
        s<<aux->toString();        
    }
    return s.str();
}

bool curso::estaGrupo(string s){
  iterador <grupo>*it = grupos->obtenerIterador();
    string aux = " ";
    while(it->masElementos()){
        aux = it->proximoElemento()->getNRC();
        if(aux==s){return true;}
    }
    return false;
}

grupo* curso::retornarGrupo(string s){
    coleccionBuscable<grupo>* cB = new coleccionBuscable<grupo>(grupos);
    grupo* gr = cB->buscar(s);
    delete cB;
    return gr;
}

string curso::recuperarProfesoresCurso(){
    stringstream s;
    iterador <grupo>* it = grupos->obtenerIterador();
    s<<"\tPROFESORES\n";
    while(it->masElementos()){
        grupo* gr = it->proximoElemento();
        profesor* p = gr->getProfesor();
        if(p!=NULL){s<<"\t\t-"<<p->getNombre()<<"\n";}
    }
    return s.str();
}

void curso::relacionarEstudiante(estudiante* _estudiante){
    iterador<grupo>* iteradorGrupoCurso = grupos->obtenerIterador();
    
    grupo* grCurso = NULL;
    grupo* grEstudiante = NULL;
    while(iteradorGrupoCurso->masElementos()){
        grCurso = iteradorGrupoCurso->proximoElemento();
        iterador<grupo>* iteradorGrupoEstudiante =  _estudiante->retornaListaGrupos()->obtenerIterador();
        while(iteradorGrupoEstudiante->masElementos()){
            grEstudiante = iteradorGrupoEstudiante->proximoElemento();
            if(*grCurso == *grEstudiante){
                grCurso->insertarEstudianteGrupo(_estudiante);
            }
        }
        delete iteradorGrupoEstudiante;
    }    

}


void curso::reporteNotas(ostream& salida){
    salida<<"---"<<nombre<<"---\n";
    iterador<grupo>* iteradorGrupoCurso = grupos->obtenerIterador();
    while(iteradorGrupoCurso->masElementos()){
        iteradorGrupoCurso->proximoElemento()->reporteNotas(salida);
    }
}