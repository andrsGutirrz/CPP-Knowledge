/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estudiante.h
 * Author: User
 *
 * Created on 27 de abril de 2017, 05:23 PM
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
class grupo;
#include "lista.h"
#include "grupo.h"
#include "coleccionBuscable.h"
#include "nota.h"

class estudiante{
public:
    estudiante(istream&);
    estudiante();
    estudiante(string, string, string, string, string, bool,float);
    virtual ~estudiante();
    virtual void setNombre(string);
    virtual void setApe1(string);
    virtual void setApe2(string);
    virtual void guardarEstudiante(ostream&);
    //virtual void setMatricula(lista<grupo>*);//revisar
    virtual string getNombre();
    virtual string getId();
    virtual string obtenerLlave();
    virtual string getApe1();
    virtual string getApe2();
    virtual string getNumCarnet();
    virtual bool getExtranjero();
    //virtual lista<grupo>* getMatri(); //revisar
    int getNumCreditos();
    virtual string toString();
    virtual string verMisCursos();
    virtual void insetarCurso(grupo*);
    void sumarCreditos();
    int getNumeroDeCursos();
    float getPorcentajeBeca();
    void setPorcentajeBeca(float);
    void registrarNota(nota*);
    string verMiNotas();
    lista<grupo>* retornaListaGrupos();
    double retornarNotaGrupo(string);
private:
    string nombre;
    string id;
    string ape1;
    string ape2;
    string numCarnet;
    int numCreditos;
    bool extranjero;
    
    lista<grupo>* matricula; //grupo
    lista<nota>* notas;
    int numeroDeCursos;
    float porcentajeBeca;

};

#endif /* ESTUDIANTE_H */

