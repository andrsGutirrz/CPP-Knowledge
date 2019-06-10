/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Control.h
 * Author: Andrés Gutiérrez
 *
 * Created on 16 de marzo de 2017, 11:35 AM
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include "librerias.h"
#include "universidad.h"
#include "escuela.h"
#include "control.h"
#include "lista.h"
#include "interfazControl.h"
#include "respaldo.h"
class control;class universidad;
class sistema {
public:
    sistema();
    virtual ~sistema();
    void empezar(); //se deberia escoger un mejor nombre, por ahora es "empezar"
    void ingresarDatosU();
    void saludo();
    void escogerFuente();
private:
    universidad* uni;
    control * ctrl;
    interfazControl* intfz;
};

#endif /* CONTROL_H */

