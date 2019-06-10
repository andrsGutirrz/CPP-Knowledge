/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Curso.h
 * Author: Elmer MB
 *
 * Created on 24 de marzo de 2017, 8:53
 */

#ifndef CURSO_H
#define CURSO_H

class profesor;
#include "librerias.h"
#include "profesor.h"
#include "grupo.h"
#include "coleccionBuscable.h"

using namespace std;

class curso{
public:
    curso(istream&);
    curso(string,string, string,int);
    virtual void restaurarGrupo(istream&,int);
    virtual ~curso();
    virtual void guardarCurso(ostream&);
    virtual void registrarEcuela();
    virtual string toString();
    virtual void setNombre(string);
    virtual void setMiProfe(profesor*);
    virtual void setCreditos(int);
    virtual string getNombre();
    virtual string getPertenece();
    virtual int getCreditos();
    virtual string getCodigoCurso();
    virtual string obtenerLlave();
    virtual profesor* getMisProfes();
    bool operator==(curso&);
    virtual void insetarGrupo(grupo*);
    virtual void desplegarGrupos();/*con toString*/
    virtual string verGrupos();
    virtual bool estaGrupo(string);
    grupo* retornarGrupo(string);
    virtual string recuperarProfesoresCurso();
    virtual void relacionarEstudiante(estudiante*);
    virtual void reporteNotas(ostream&);
private:
    string nombre;
    string pertenece;
    string cod;
    int creditos;
    profesor* miProfesor;
    lista<grupo>* grupos;
};

#endif /* CURSO_H */
