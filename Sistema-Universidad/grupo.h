/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   grupo.h
 * Author: Andrés Gutiérrez
 *
 * Created on 8 de mayo de 2017, 04:03 PM
 */

#ifndef GRUPO_H
#define GRUPO_H
#include "librerias.h"
class profesor;
class estudiante;
#include "profesor.h"
#include "estudiante.h"
#include "coleccionBuscable.h"
#include "nota.h"
class grupo {
public:
    grupo(istream&);
    grupo(string,string,int);//nombre, nrc, creditos;
    virtual ~grupo();
    virtual void guardarGrupo(ostream&);
    virtual string toString();
    virtual void setNombre(string);
    virtual void setMiProfe(profesor*);
    profesor* getProfesor();
    virtual void setCreditos(int);
    virtual string getNombre();
    virtual int getCreditos();
    virtual string getNRC();
    virtual string obtenerLlave();
    virtual int getCantidad();
    bool operator==(grupo&);
    void insertarEstudianteGrupo(estudiante*);
    virtual void verEstudiantesMatriculados();
    void asignarNotas();
    void reporteNotas(ostream&);
private:
    string nrc;
    string nombre;
    profesor* miProfesor;
    int creditos; 
    lista<estudiante> * estudiantesMatriculados;
    int tam;//tamano de la capacidad del curso
    int cant;//cantidad de estudiantes del curso
};

#endif /* GRUPO_H */

