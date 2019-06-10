/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Control.cpp
 * Author: Andrés Gutiérrez
 * 
 * Created on 16 de marzo de 2017, 11:35 AM
 */

#include "sistema.h"


sistema::sistema() {
    uni =  NULL;
    saludo();
    escogerFuente();
    ctrl = new control(uni);
    intfz = new interfazControl();
    
}

void sistema::ingresarDatosU(){
    string nombre=""; 
    string telefono=""; 
    string direccion="";
    cout<<"Digite el nombre de la Universidad"<<endl;getline(cin, nombre, '\n');cin.ignore(256,'\n');
    transform(nombre.begin(), nombre.end(),nombre.begin(), ::toupper);
    cout<<"Digite el numero telefonico de la Universidad"<<endl;getline(cin, telefono, '\n');cin.ignore(256,'\n');
    cout<<"Digite la direccion de la Universidad"<<endl;getline(cin, direccion, '\n');cin.ignore(256,'\n');
    uni = new universidad(nombre, direccion, telefono);
}

sistema::~sistema() {
    delete ctrl;
    delete uni;
}

void sistema::empezar(){
   //uni->iniciarlizarListaEscuelas();
   ctrl->switchInicio();
}

void sistema::saludo(){
    intfz->presentacion();
    cin.get();
    system("cmd /c cls");
}

void sistema::escogerFuente(){
    string op = " ";
    cout<<"ingrese 1 para cargar desde un txt o 2 para continuar manualmente"<<endl;
    cin>>op;
    if(op=="1"){
        string ruta = "";
        cout<<"Ingrese nombre del archivo: ";cin>>ruta;
        stringstream s;
        s<<"Data/"<<ruta;
        ruta = s.str();
        try{
            ifstream entrada(ruta.c_str());
            if(!entrada.good())
                throw -1;
            string a1,a2,a3;
            entrada>>a1;entrada>>a2;entrada>>a3;
            uni = new universidad(a1,a2,a3);
            respaldo::restaurarRespaldo(uni,entrada);
        }catch(int e){
            cerr<<"Error, proceder  manualmente(precionar Enter) o cerrar la app e intentar de nuevo"<<endl;cin.get();cin.get();
            ingresarDatosU();
            uni->iniciarlizarListaEscuelas();
        }
    }else{
        ingresarDatosU();
        uni->iniciarlizarListaEscuelas();
    }
}
