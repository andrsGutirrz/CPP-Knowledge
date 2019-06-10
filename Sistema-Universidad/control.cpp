/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   control.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 15 de marzo de 2017, 06:44 PM
 */

#include "control.h"

control::control(universidad *u){
    uni = u;
    intfz = new interfazControl();
    matri = new matricula();
}

control::~control() {
    delete intfz;
}

char control::opcionInicio(){
    system("cmd /c cls"); 
    char aux= ' ';
    intfz->menuPrincipal();
    cin>>aux;
    return aux;
}

char control::modoAdministrativo(){
    system("cmd /c cls"); 
    char aux= ' ';
    intfz->menuUniversidad();
    cin>>aux;
    return aux;
}

void control::switchInicio(){
    char aux =' ';
    aux=opcionInicio();
    if (isdigit(aux)!=0){
        switch(aux){
        case '1':switchModoAdministrativo();
                break;
        case '2':es=uni->log();switchModoEstudiante();
                break;    
        case '3':respaldo::crearRespaldo(uni);intfz->salirSeguro();
                break;      
        default:cout<<"no"<<endl;
        }
    }else{
            cout<<"DATOS INCORRECTOS"<<endl;cin.get();cin.get();
    }
    this->switchInicio();
}

void control::switchModoAdministrativo(){
  char aux = ' ';
  aux= modoAdministrativo();
   if (isdigit(aux)!=0){
        switch(aux){
        case '1': cout<<uni->toString()<<endl; cin.get();cin.get();switchModoAdministrativo();//llama al toString de la universidad
            break;
        case '2': uni->cambiarNumero();cin.get();switchModoAdministrativo();
            break;
        case '3': uni->cambiarDireccion();cin.get();switchModoAdministrativo();
            break;
        case '4':this->switchModoEscuela();
            break;
        case '5':this->switchModoProfesor();
            break;
        case '6':switchModoEstudianteAdmin();cin.get();switchModoAdministrativo();
            break;
        case '7':switchInicio();
            break;
       default:cout<<"no"<<endl;
        }
   }
   else{
     cout<<"DATOS INCORRECTOS"<<endl;cin.get();cin.get();
   }
  this->switchModoAdministrativo();
}
char control::modoEscuela(){
    system("cmd /c cls"); 
    char aux= ' ';
    intfz->menuEscuela();
    cin>>aux;
    return aux;
}

void control::switchModoEscuela(){//opciones de escuela
  char aux = ' ';
  aux= modoEscuela();
   //if (isdigit(aux)!=0){
        switch(aux){
        case '1': cout<<uni->imprimirTodasEscuelas()<<endl; cin.get(); cin.get(); switchModoEscuela();//llama al toString de Escuela*/ 
            break;
        case '2': uni->registrarEscuela();switchModoEscuela();
            break;
        case '3':uni->consultarEscuela();cin.get();cin.get();switchModoEscuela();//CONSULTAR 
            break;
        case '4':uni->insertarCurso();cin.get();cin.get();switchModoEscuela();//registrar Curso 
            break;
        case '5':uni->imprimirCursosEscuela();cin.get();cin.get();switchModoEscuela();//imprimir curso 
            break;
        case '6':uni->imprimirTodosCursos();cin.get();cin.get();switchModoEscuela();//imprimir cursos de toda la U 
            break;
        case '7':uni->cambiarNombreCurso();cin.get();cin.get();switchModoEscuela();//cambiar nombre
            break;
        case '8':uni->eliminarCurso();cin.get();cin.get();switchModoEscuela();
            break;
        case '9':uni->verGrupos();cin.get();cin.get();switchModoEscuela();
            break;
        case 'a':uni->verEstudiantesMatriculados();cin.get();cin.get();switchModoEscuela();
            break;
        case 'b':uni->asignarProfeCursoU();cin.get();cin.get();switchModoEscuela();
            break;
        case 'c':uni->imporimirProfesEscuela();cin.get();cin.get();switchModoEscuela();
            break;
        case 'd':uni->consultarProfesSegunCurso();cin.get();cin.get();switchModoEscuela();
            break;
        case 'e':switchModoAdministrativo();//atras
            break;
       default:cout<<"No entendi!"<<endl;
        }
}


void control::switchModoProfesor(){
  char aux = ' ';
  aux= modoProfesor();
   if (isdigit(aux)!=0){
        switch(aux){
            case '1': uni->registrarProfesores(); cin.get(); cin.get(); switchModoProfesor();//se registra un profesor 
                break;
            case '2': uni->modificarDatosProfe(); cin.get(); switchModoProfesor();//moodifica los datos del profesor excepto la cedula
                break;
            case '3': uni->eliminarProfesor();cin.get();cin.get();switchModoProfesor();//elimina un profesor 
                break;
            case '4': uni->buscarProfeEspecifico();cin.get();cin.get();switchModoProfesor();//busca un profesor en especifico
                break;
            case '5': uni->imprimirProfes();cin.get();cin.get();switchModoProfesor();//imprimir los profesores
                break;
            case '6':uni->imprimirCargaAcademica();cin.get();cin.get();switchModoProfesor();
                break;
            case '7':switchModoAdministrativo();//atras
                break;
           default:cout<<"No entendi!"<<endl;
        }
    }
}

char control::modoProfesor(){
    system("cmd /c cls"); 
    char aux= ' ';
    intfz->menuProfesor();
    cin>>aux;
    return aux;
}

void control::switchModoEstudianteAdmin(){
    char aux = ' ';
  aux = modoEstudianteAdmin();
   if (isdigit(aux)!=0){
        switch(aux){
            case '1': uni->registrarEstudiante(); cin.get(); cin.get(); switchModoEstudianteAdmin();//se registra un estudiante 
                break;
            case '2': uni->desplegarEstudiantes(); cin.get(); cin.get(); switchModoEstudianteAdmin();//se registra un estudiante 
                break;
            case '3': uni->fijarNotas(); cin.get(); cin.get(); switchModoEstudianteAdmin();//se registra un estudiante 
                break;
            case '4': this->modoAdministrativo();//Atras
                break;
           default:cout<<"No entendi!"<<endl;
        }
    }
}

char control::modoEstudianteAdmin(){
    system("cmd /c cls"); 
    char aux= ' ';
    intfz->menuEstudianteAdmin();
    cin>>aux;
    return aux;
}

void control::switchModoEstudiante(){
  if(es==NULL){cout<<"Estudiante no registrado"; cin.get();return this->switchInicio();}
  estudiante* est = (estudiante*)es;
  char aux = ' ';
  aux = modoEstudiante(est->getNombre());
   if (isdigit(aux)!=0){
        switch(aux){
            case '1':uni->actualizarDatosEstudiante(est);cin.get(); cin.get(); switchModoEstudiante();//se registra un estudiante 
                break;
            case '2': cout<< est->verMisCursos()<<endl; cin.get(); cin.get(); switchModoEstudiante();//se registra un estudiante 
                break;
            case '3': cout<<est->toString()<<endl; cin.get(); cin.get(); switchModoEstudiante();
                break;
            case '4': matri->matricular(uni, es);cin.get(); cin.get(); switchModoEstudiante();
                break;
            case '5': matri->montoPagarCreditos(est);cin.get(); cin.get(); switchModoEstudiante();
                break;
            case '6': uni->verNotasEstudiante(est);cin.get(); cin.get(); switchModoEstudiante();
                break;
            case '7': switchInicio();//inicio
                break;
           default:cout<<"No entendi!"<<endl;
        }
    }
}

char control::modoEstudiante(string nombre){
system("cmd /c cls"); 
    char aux= ' ';
    intfz->menuEstudiante( nombre);
    cin>>aux;
    return aux;

}