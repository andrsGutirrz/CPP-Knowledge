/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nota.h
 * Author: Andrés Gutiérrez
 *
 * Created on 2 de junio de 2017, 09:50 PM
 */

#ifndef NOTA_H
#define NOTA_H
#include "librerias.h"
class nota {
public:
    nota(istream&);
    nota(string,double);
    virtual void guardarNota(ostream&);
    nota(const nota& orig);
    virtual ~nota();
    double obtenerPromedio();
    string obtenerNombreCurso();
    string toString();
private:
    string nombre;//nombre del curso
    double promedio;//el promedio final
};

#endif /* NOTA_H */

