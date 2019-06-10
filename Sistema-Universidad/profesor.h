/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   profesor.h
 * Author: Andrés Gutiérrez
 *
 * Created on 25 de abril de 2017, 10:43 PM
 */

#ifndef PROFESOR_H
#define PROFESOR_H
#include "lista.h"

class curso;
class grupo;
#include "curso.h"
#include "grupo.h"
#include "coleccionBuscable.h"

class profesor{
public:
    profesor(istream&);
    profesor(string, string,string,string);
    virtual ~profesor();
    virtual void guardarProfesor(ostream&);
    virtual string toString();
    virtual string getNombre();
    virtual string getApe1();
    virtual string getApe2();
    virtual string getId();
    virtual string obtenerLlave();
    string nombreCompleto();
    //virtual lista* getCurs();
    virtual void setNombre(string);
    virtual void setApe1(string);
    virtual void setApe2(string);
    virtual void insertarCursoProf(grupo*);
    bool yaTengoEseCurso(grupo*);
    string imprimirMisCursos();
    void setMiEscuela(string);
    bool getTengoEscuela();
    bool esDirector();
    void setDirector(bool);
    string getNombreEscuela();
private:
    coleccionBuscable<grupo>* misCursos;
    string nombre;
    string id;
    string ape1;
    string ape2;
    string miEscuela;//para saber cual escuela pertenece el profesor
    bool tengoEscuela;//cada profesor debe pertenecer a una unica escuela
    bool director;//true si es director
};

#endif /* PROFESOR_H */

