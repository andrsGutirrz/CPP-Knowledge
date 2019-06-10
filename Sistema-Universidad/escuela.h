/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuela.h
 * Author: User
 *
 * Created on 12 de marzo de 2017, 08:28 PM
 */

#ifndef ESCUELA_H
#define ESCUELA_H

#include "librerias.h"
#include "lista.h"
#include "curso.h"
#include "profesor.h"
#include "interfazEscuela.h"
#include "coleccionBuscable.h"
#include <fstream>


class escuela{
    public:
    escuela(istream&);
    escuela(string,string,string,string);
    virtual void restaurarCurso(istream&,int);
    virtual ~escuela();
    string getDireccion();
    void setDireccion(string);
    string getTelef();
    void setTelef(string);
    string getNombre() const;
    virtual string toString();
    virtual string getCodigoEscuela();
    virtual void establecerDirector(profesor* );
    virtual string obtenerLlave();
    virtual void guardarEscuela(ostream&);
    /**cursos*/
    curso* retornaCurso();
    void registrarCurso();
    void consultarCurso();
    string imprimeCodigoCursos();
    void consultarCursos();
    void insertarCurso(curso*);
    void imprimirCursos();
    void eliminarCurso(curso*);
    void cambiarNombreCurso();
    bool validadorCodigo(string);
    string imprimeNombresCursos();
    bool listaEscVacia();
    bool estaCurso(string);
    /**sobrecarga*/
    escuela& operator=(const escuela&);
    /***/
    void imprimirProfes();
    void insertarProfesor(profesor*);
    void asignarProfeCurso();
    profesor* retornaProfesor(string);
    bool hayProfes();
    bool validadorID(string);
    void consultaProfes();//para buscar los cursos de un profesor x
    /**PARA GRUPOS*/
    grupo* retornaGrupo();
    void verGrupos();
    grupo* retornaGrupo(string,string);
    void reporteGrupos(ostream&);
    void relacionarEstudiante(estudiante*);
private:
   string codigoEscuela;
   string nombre;
   string direccion;
   string numeroTelef;
   
   lista<curso>* listaCursos;
   lista<profesor>* profesores;
   
   interfazEscuela* intfz;
   profesor* director;
};
#endif /* ESCUELA_H */

