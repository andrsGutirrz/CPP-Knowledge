/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfazUniversidad.h
 * Author: Andrés Gutiérrez
 *
 * Created on 4 de mayo de 2017, 10:10 PM
 */

#ifndef INTERFAZUNIVERSIDAD_H
#define INTERFAZUNIVERSIDAD_H
#include "librerias.h"

class interfazUniversidad {
public:
    interfazUniversidad();
    virtual ~interfazUniversidad();
    string pedirNombreEscuela();
    string pedirDireccionEscuela();
    string pedirTelefonoEscuela();
    string pedirCodigoEscuela();
    void escuelaNoExiste();
    void escuelaSinCursos();
    void logginPresentacion();
    
    /**PROFESOR Y ESTUDIANTE*/
    string pedirNombre();
    string pedirApellido1();
    string pedirApellido2();
    string pedirCedula();
    string pedirCarnet();
    string pedirNacionalidad();
    void profesorNoRegistrado();
    float pedirPorcentajeBeca();
    
    
private:

};

#endif /* INTERFAZUNIVERSIDAD_H */

