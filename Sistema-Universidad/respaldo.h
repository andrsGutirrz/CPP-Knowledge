/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   respaldo.h
 * Author: Andrés Gutiérrez
 *
 * Created on 12 de junio de 2017, 09:05 PM
 */

#ifndef RESPALDO_H
#define RESPALDO_H
#include "universidad.h"
#include "sistema.h"
#include "universidad.h"
#include <fstream>
class respaldo {
public:
    respaldo();
    respaldo(const respaldo& orig);
    virtual ~respaldo();
    static void crearRespaldo(universidad*);
    static void restaurarRespaldo(universidad*,istream&);
private:

};

#endif /* RESPALDO_H */

