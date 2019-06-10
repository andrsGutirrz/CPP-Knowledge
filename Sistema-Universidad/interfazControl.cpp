/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfazControl.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 16 de marzo de 2017, 11:53 AM
 */

#include "interfazControl.h"

interfazControl::interfazControl() {
}

void interfazControl::menuPrincipal(){
    cout<<"----------Menu Principal---------"<<endl;
    cout<<"---------------------------------"<<endl<<endl;
    cout<<"1) Modo administrador"<<endl;
    cout<<"2) Modo Estudiante"<<endl;
    cout<<"3) Salir del Programa y guardar informacion en archivo"<<endl;
}

void interfazControl::menuUniversidad(){
     cout<<"----------Menu Universidad---------"<<endl;
    cout<<"---------------------------------"<<endl<<endl;
    cout<<"1) Consultar informacion de contacto de la universidad"<<endl;
    cout<<"2) Cambiar numero de telefono"<<endl;
    cout<<"3) cambiar direccion"<<endl;
    cout<<"4) Opciones Escuela"<<endl;
    cout<<"5) Opciones de Profesor"<<endl;
    cout<<"6) Opciones de Estudiante"<<endl;
    cout<<"7) Atras"<<endl;
}

interfazControl::~interfazControl() {
}

void interfazControl::gotoxy(int x, int y){
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}
void interfazControl::menuEscuela(){
    cout<<"Menu de Escuelas " << endl;
    cout<<"-------------------------" <<endl;
    cout<<"1) Desplegar Escuelas"<<endl;
    cout<<"2) Ingresar Escuela Nueva"<<endl;
    cout<<"3) Consultar Escuela Particular"<<endl;
    cout<<"4) Insertar Curso"<<endl;
    cout<<"5) Desplegar Cursos"<<endl;
    cout<<"6) Desplegar Todos los Cursos"<<endl;
    cout<<"7) Cambiar Nombre Cursos"<<endl;
    cout<<"8) Eliminar Cursos"<<endl;
    cout<<"9) Ver grupos"<<endl;
    cout<<"a) Ver estudiantes Matriculados"<<endl;
    cout<<"b) Asignar un profesor a un curso"<<endl;
    cout<<"c) Ver profesores de la escuela"<<endl;
    cout<<"d) Consultar profesores segun curso"<<endl;
    cout<<"e) Atras"<<endl;
}

void interfazControl::menuProfesor(){
    cout<<"Menu de Profesor " << endl;
    cout<<"-------------------------" <<endl;
    cout<<"1) Registrar profesor"<<endl;
    cout<<"2) Actualizar datos"<<endl;
    cout<<"3) Despedir profesor"<<endl;
    cout<<"4) Buscar profesor especifico"<<endl;
    cout<<"5) Desplegar Todos los Profesores"<<endl;
    cout<<"6) Ver carga academica"<<endl;
    cout<<"7) Atras"<<endl;
}

void interfazControl::menuEstudianteAdmin(){
    cout<<"Menu de Estudiante Administrador" << endl;
    cout<<"-------------------------" <<endl;
    cout<<"1) Registrar estudiante"<<endl;
    cout<<"2) Desplegar estudiantes"<<endl;
    cout<<"3) Agregar Notas"<<endl;
    cout<<"4) Atras"<<endl;
}

void interfazControl::menuEstudiante(string nombre){
    cout<<"HOLA "<<nombre<<"!"<<endl;
    cout<<"Menu de Estudiante " << endl;
    cout<<"-------------------------" <<endl;
    cout<<"1) Actualizar datos"<<endl;
    cout<<"2) Desplegar cursos"<<endl;
    cout<<"3) Desplegar mis datos"<<endl;
    cout<<"4) Matricular cursos"<<endl;
    cout<<"5) Pagar Creditos"<<endl;
    cout<<"6) Ver Notas"<<endl;
    cout<<"7) Atras"<<endl;
}

void interfazControl::presentacion(){
gotoxy(10,10);cout<<"██████╗ ██╗███████╗███╗   ██╗██╗   ██╗███████╗███╗   ██╗██╗██████╗  ██████╗ "<<endl;
gotoxy(10,11);cout<<"██╔══██╗██║██╔════╝████╗  ██║██║   ██║██╔════╝████╗  ██║██║██╔══██╗██╔═══██╗"<<endl;
gotoxy(10,12);cout<<"██████╔╝██║█████╗  ██╔██╗ ██║██║   ██║█████╗  ██╔██╗ ██║██║██║  ██║██║   ██║"<<endl;
gotoxy(10,13);cout<<"██╔══██╗██║██╔══╝  ██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║██║  ██║██║   ██║"<<endl;
gotoxy(10,14);cout<<"██████╔╝██║███████╗██║ ╚████║ ╚████╔╝ ███████╗██║ ╚████║██║██████╔╝╚██████╔╝"<<endl;
gotoxy(10,15);cout<<"╚═════╝ ╚═╝╚══════╝╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝╚═╝╚═════╝  ╚═════╝ "<<endl;
gotoxy(20,17);cout<<"Sistema de administracion de una universidad"<<endl;
gotoxy(21,18);cout<<"Presione cualquier tecla para continuar"<<endl;
gotoxy(21,19);
}

void interfazControl::salirSeguro(){
        system("cmd /c cls");
        gotoxy(55,20);
        cout<<"CERRANDO APLICACION"; exit(0);
}

bool interfazControl::esNumero(string str){
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]<48 || str[i]>57){
            return false;
	}
    }
    return true;
}

void interfazControl::advertencia(){
    cout<<"DATOS INCORRECTOS"<<endl;cin.get();
}

void interfazControl::listaVacia(){
    cout<<"Lista vacia";
}

string interfazControl::cambiarDireccion(){//pasar a interfaz Universidad
    string aux="";
    cout<<"Digite nueva direccion"<<endl;
    cin.ignore(256,'\n');getline(cin,aux, '\n');cin.ignore(256,'\n');
    return aux;
}

string interfazControl::ingresaCodigo(){
    string aux = "";
    cout<<"INGRESAR CODIGO"<<endl;
    cin>>aux;
    return aux;
}

void interfazControl::exito(){
    cout<<"OPERACION REALIZADA CON EXITO"<<endl;
}

void interfazControl::mayuscula(string& st){
    std::transform(st.begin(), st.end(),st.begin(), ::toupper);
}

string interfazControl::intToString(int n){
    // declaring output string stream
    ostringstream str1;
 
    // Sending a number as a stream into output
    // string
    str1 << n;
 
    // the str() coverts number into string
    string geek = str1.str();
}
