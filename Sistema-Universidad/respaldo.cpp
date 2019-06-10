/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   respaldo.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 12 de junio de 2017, 09:05 PM
 */

#include "respaldo.h"

respaldo::respaldo() {
}

respaldo::respaldo(const respaldo& orig) {
}

respaldo::~respaldo() {
}

void respaldo::crearRespaldo(universidad* uni){
    stringstream s;
    string ruta = " ";
    cout<<"INGRESE UN NOMBRE DE ARCHIVO PARA GUARDAR:  "; cin>>ruta;
    s<<"Data/"<<ruta;
    string nuevaRuta = s.str();
    ofstream salida(nuevaRuta.c_str());
    /*GUARDAR UNIVERSIDAD*/
    salida<<uni->getNombre()<<" "<<uni->getDireccion()<<" "<<uni->getTelefono()<<" ";
    /*GUARDAR ESCUELAS*/
    uni->respaldarEscuelas(salida); 
    uni->respaldarEstudiantes(salida);
    uni->respaldarProfesores(salida);
    uni->reportePorEstudiantes(salida);
    uni->reportePorGrupos(salida);
    salida.close();
}

void respaldo::restaurarRespaldo(universidad* uni, istream& entrada){
    uni->restaurarEscuela(entrada);
    uni->restaurarEstudiante(entrada);
    uni->restaurarProfesor(entrada);
    uni->relacionarProfesor();
    uni->relacionarEstudiante();
}

