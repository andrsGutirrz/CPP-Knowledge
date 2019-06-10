/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nota.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 2 de junio de 2017, 09:50 PM
 */

#include "nota.h"

nota::nota(istream& entrada){
    entrada>>nombre;entrada>>promedio;
}

nota::nota(string _nombre, double _promedio):promedio(_promedio),nombre(_nombre) {
}

void nota::guardarNota(ostream& salida){
    salida<<nombre<<" "<<promedio<<" ";
}

nota::nota(const nota& orig) {
}

nota::~nota() {
}

double nota::obtenerPromedio(){return promedio;}
string nota::obtenerNombreCurso(){return nombre;}
string nota::toString(){
    stringstream s;
    s<<"Nota: "<<promedio<<endl;
    s<<"Curso: "<<nombre<<endl;
    return s.str();
}