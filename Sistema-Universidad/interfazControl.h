/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfazControl.h
 * Author: Andrés Gutiérrez
 *
 * Created on 16 de marzo de 2017, 11:53 AM
 */

#ifndef INTERFAZCONTROL_H
#define INTERFAZCONTROL_H
#include "librerias.h"
#include "escuela.h"
#include "curso.h"

class interfazControl {
public:
    /////////////////////////////////
    interfazControl();
    virtual ~interfazControl();
    void menuPrincipal();
    void menuUniversidad();
    void gotoxy(int, int);
    void presentacion();
    void salirSeguro();
    bool esNumero(string);
    void advertencia();
    void listaVacia();
    string cambiarDireccion();
    string ingresaCodigo();
    void exito();
    void mayuscula(string&);
    string intToString(int);
    /////////////////////////////////
    void menuEscuela();
    ///////////////
    void menuProfesor();
    //////////////
    void menuEstudianteAdmin();
    void menuEstudiante(string);
private:

};

#endif /* INTERFAZCONTROL_H */

