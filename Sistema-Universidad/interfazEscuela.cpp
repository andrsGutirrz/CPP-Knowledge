/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfazEscuela.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 3 de mayo de 2017, 11:39 PM
 */

#include "interfazEscuela.h"

interfazEscuela::interfazEscuela() {
}

interfazEscuela::~interfazEscuela() {
}

/**PARA CURSO*/
string interfazEscuela::pedirNombreCurso(){
    string aux = " ";
    cout<<"Ingrese nombre del curso"<<endl;getline(cin,aux, '\n');cin.ignore(256,'\n');
    return aux;
}

string interfazEscuela::pedirNRC(){
    string NRC=" ";
    cout<<"Ingrese El NRC del curso "<<endl;cin>>NRC;
    return NRC;
}

string interfazEscuela::imprimeCodigosHeader(){
    stringstream s;
    s<<"----------------------------------------------------------"<<endl;
    s << "Lista de Cursos " << endl<<endl;
    s<<"Nombre  :  SIGLAS    : Escuela "<<endl<<endl;
    return s.str();
}

void interfazEscuela::listaVacia(){
    cout<<"Lista vacia!"<<endl;
}
void interfazEscuela::cursoBorrado(){
    cout<<"Curso borrado!";
}

void interfazEscuela::cursoNoExiste(){
    cout<<"NO EXISTE CURSO";
}

/**PARA PROFESOR*/

string interfazEscuela::pedirId(){
     string aux = " ";
    cout<<"ingresar id"<<endl;
    cin>>aux;
    return aux;
}

void interfazEscuela::noSeEncuentraProfesor(){
    cout<<"Este profesor no se encuentra registrado en nuestra base de datos"<<endl;
}

void interfazEscuela::profeTieneCurso(){
    cout<<"Este curso ya cuenta con profesor asignado"<<endl;
}

int interfazEscuela::pedirCreditos(){
    int creditos = 0;
    cout<<"Digite la cantidad de creditos del curso " <<endl; cin >>creditos ; cin.ignore(256,'\n');
    return creditos;
}

string interfazEscuela::pedirCantidadCursos(){
    string cantidad = " ";
    cout<<"Digite la cantidad de grupos del curso " <<endl; cin >>cantidad ; cin.ignore(256,'\n');
    return cantidad;

}


bool interfazEscuela::esNumero(string str){
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]<48 || str[i]>57){
            return false;
	}
    }
    return true;
}

void interfazEscuela::advertencia(){
    cout<<"DATOS INCORRECTOS"<<endl;cin.get();
}
  

void interfazEscuela::mayuscula(string& st){
    std::transform(st.begin(), st.end(),st.begin(), ::toupper);
}

string interfazEscuela::pedirSiglas(){
    string siglas = " ";
    cout<<"Digite las siglas del curso " <<endl; cin >>siglas ; cin.ignore(256,'\n');
    return siglas;
}
