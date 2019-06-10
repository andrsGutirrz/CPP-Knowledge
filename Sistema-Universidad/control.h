/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   control.h
 * Author: Andrés Gutiérrez
 *
 * Created on 15 de marzo de 2017, 06:44 PM
 */

#ifndef CONTROL_H
#define CONTROL_H
#include "universidad.h"
#include "interfazControl.h"
#include "escuela.h"
#include "profesor.h"
#include "curso.h"
#include "estudiante.h"
#include "matricula.h"
#include "sistema.h"
class control {
public:
    control(universidad* u);
    virtual ~control();
    char opcionInicio();
    char modoAdministrativo();
    void switchInicio();
    void switchModoAdministrativo();
    char modoEscuela();
    void switchModoEscuela();
    /***/
    void switchModoProfesor();
    char modoProfesor();
    /***/
    void switchModoEstudianteAdmin();
    char modoEstudianteAdmin();
    void switchModoEstudiante();
    char modoEstudiante(string);
    
private:
    universidad * uni;
    interfazControl* intfz;
    estudiante* es;//PARA ALMACENAR AL ESTUDIANTE QUE INICIA SESION
    matricula *matri;
};
#endif 

