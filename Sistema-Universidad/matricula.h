/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matricula.h
 * Author: Elmer MB
 *
 * Created on 9 de mayo de 2017, 23:44
 */

#ifndef MATRICULA_H
#define MATRICULA_H
#include "librerias.h"
#include "grupo.h"
#include "estudiante.h"
#include "curso.h"
#include "lista.h"
#include "universidad.h"
#include "coleccion.h"
#include "iteradorLista.h"

class matricula {
public:
    matricula();
    virtual ~matricula();
    virtual void matricular(universidad*,estudiante*);//Recibe la universidad para accerder a la escuela y al estudiante para poder matricular
    virtual void montoPagarCreditos(estudiante*);//recibe el estudiante para pagar los creditos, 
    static const int gastosAdministrativos;
    static const int costoPorCredito;
    virtual void desglosePagoCreditos(estudiante *, double, double);
private:
};


#endif /* MATRICULA_H */

