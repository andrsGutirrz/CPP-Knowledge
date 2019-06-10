/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfazEscuela.h
 * Author: Andrés Gutiérrez
 *
 * Created on 3 de mayo de 2017, 11:39 PM
 */

#ifndef INTERFAZESCUELA_H
#define INTERFAZESCUELA_H
#include "librerias.h"
class interfazEscuela {
public:
    interfazEscuela();
    virtual ~interfazEscuela();
    /**OTROS*/
    bool esNumero(string);
    void mayuscula(string&);
    void advertencia();
    /**PARA CURSO*/
    string pedirNRC();
    string imprimeCodigosHeader();
    void listaVacia();
    void cursoBorrado();
    void cursoNoExiste();
    int pedirCreditos();
    string pedirCantidadCursos();
    string pedirSiglas();
    /**PARA PROFESOR*/
    string pedirId();
    void noSeEncuentraProfesor();
    void profeTieneCurso();
    string pedirNombreCurso();
private:

};

#endif /* INTERFAZESCUELA_H */

