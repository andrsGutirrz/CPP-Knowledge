/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Universidad.h
 * Author: User
 *
 * Created on 14 de marzo de 2017, 07:53 PM
 */

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "librerias.h"
#include "lista.h"
#include "interfazControl.h"
#include "escuela.h"
#include "iteradorLista.h"
#include "profesor.h"
#include "estudiante.h"
#include "interfazUniversidad.h"
#include "coleccion.h"
#include "coleccionBuscable.h"
class universidad{
public:
    universidad(string, string, string);
    universidad(istream&);
    void respaldarEstudiantes(ostream&);
    void respaldarProfesores(ostream&);
    virtual void respaldarEscuelas(ostream&);
    virtual void restaurarEscuela(istream&);
    virtual void restaurarEstudiante(istream&);
    virtual void restaurarProfesor(istream&);
    virtual ~universidad();
    void iniciarlizarListaEscuelas();
    void setDireccion(string);
    void setTelefono(string);
    string getDireccion();
    string getTelefono();
    string getNombre();
    string toString();
    /**Para Escuela*/
    void registrarEscuela();
    void consultarEscuela();
    void cambiarNumero();
    void cambiarDireccion();
    string imprimirTodasEscuelas();
    string imprimeCodigoEscuela();
    escuela* retornaEscuela();//retorna la escuela en funcion del codigo
    /**PARA CURSO*/
    void insertarCurso();//pide el codigo de la escuela, lo busca en la lista escuelas y luego inserta el curso en el nodo de la escuela
    void imprimirCursosEscuela();//imprime todos los cursos de una escuela
    void imprimirTodosCursos();//organizados por escuelas
    void cambiarNombreCurso();//cambia el nombre del curso
    void eliminarCurso();//Elimina un curso especifico
    /**PARA PROFESOR*/
     void registrarProfesores();
     bool validadorID(string);
     void imprimirProfes();
     profesor* retornaProfesor(string);
     void buscarProfeEspecifico();
     void eliminarProfesor();
     void modificarDatosProfe();
     void asignarProfeCursoU();
     void imprimirCargaAcademica();
     void imporimirProfesEscuela();
     void consultarProfesSegunCurso();
     void relacionarProfesor();
   /**Para Estudiante*/
     void registrarEstudiante();
     bool validarIDCarnet(string);
     bool esExtranjero(string);
     void desplegarEstudiantes();
     estudiante* retornaEstudiante(string);
     void verCursosEstudiante();
     estudiante* log();
     void actualizarDatosEstudiante(estudiante*);
     void matricularCursos(estudiante*);
     void relacionarEstudiante();
     void reportePorGrupos(ostream&);
     void reportePorEstudiantes(ostream&);
     /**PARA GRUPOS*/
     void verGrupos();
     void verEstudiantesMatriculados();
     void fijarNotas();
     void verNotasEstudiante(estudiante*);

private:
    string nombre;
    string direccion;
    string telefono;

    lista<profesor>* listaProf;
    lista<estudiante>* listaEstu;
    lista<escuela>* listaEsc;
    interfazControl* intfz;
    interfazUniversidad* inter;
};

#endif /* UNIVERSIDAD_H */

