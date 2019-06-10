/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfazUniversidad.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 4 de mayo de 2017, 10:11 PM
 */

#include "interfazUniversidad.h"

interfazUniversidad::interfazUniversidad() {
}

interfazUniversidad::~interfazUniversidad() {
}
string interfazUniversidad::pedirNombreEscuela(){
    string nom = " ";
    cout<<"Ingrese nombre de la escuela"<<endl;getline(cin,nom, '\n');cin.ignore(256,'\n');
    return nom;
}

string interfazUniversidad::pedirDireccionEscuela(){
    string dir = " ";
    cout<<"Ingrese direccion de la escuela"<<endl;getline(cin,dir, '\n');cin.ignore(256,'\n');
    return dir;
}

string interfazUniversidad::pedirTelefonoEscuela(){
    string tel = " ";
    cout<<"Ingrese telefono de la escuela"<<endl;getline(cin,tel, '\n');cin.ignore(256,'\n');
    return tel;
}

string interfazUniversidad::pedirCodigoEscuela(){
    string cod = " ";
    cout<<"Ingrese codigo de la escuela"<<endl;getline(cin,cod, '\n');cin.ignore(256,'\n');
    return cod;
}

void interfazUniversidad::escuelaNoExiste(){
    cout<<"LA ESCUELA NO EXISTE"<<endl;
}

void interfazUniversidad::escuelaSinCursos(){
    cout<<"ESCUELA SIN CURSOS"<<endl;
}

string interfazUniversidad::pedirNombre(){
    string nom = " ";
    cout<<"Ingrese nombre"<<endl;cin>>nom;
    return nom;
}

string interfazUniversidad::pedirApellido1(){
    string ape1 = " ";
    cout<<"Ingrese el primer apellido"<<endl;cin>>ape1;
    return ape1;
}

string interfazUniversidad::pedirApellido2(){
    string ape2 = " ";
    cout<<"Ingrese el segundo apellido"<<endl;cin>>ape2;
    return ape2;

}

string interfazUniversidad::pedirCedula(){
    string id = " ";
    cout<<"Ingrese el numero de cedula"<<endl;cin>>id;
    return id;
}

string interfazUniversidad::pedirCarnet(){
    string id = " ";
    cout<<"Ingrese el numero de carnet"<<endl;cin>>id;
    return id;
}

 string interfazUniversidad::pedirNacionalidad(){
    string extranjero = "";
    cout<<"Ingrese 0 (cero) si es nacional o 1 para extranjero"<<endl;cin>>extranjero;
    return extranjero;
 }
 
 float interfazUniversidad::pedirPorcentajeBeca(){
     float porcentajeBeca = 0.0;
    cout<<"Ingrese el porcentaje de beca del estudiante, si no posee, digite 0(cero)"<<endl;cin>> porcentajeBeca;cin.ignore(256,'\n');
    return porcentajeBeca;
 }

void interfazUniversidad::logginPresentacion(){
    cout<<"********************************************"<<endl;
    cout<<"*        INICIAR SESION ESTUDIANTE         *"<<endl;
    cout<<"********************************************"<<endl;
}

 void interfazUniversidad::profesorNoRegistrado(){
     cout<<"Este profesor no se encuentra registrado en nuestra base de datos"<<endl;
 }
