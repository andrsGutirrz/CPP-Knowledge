/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matricula.cpp
 * Author: Elmer MB
 * 
 * Created on 9 de mayo de 2017, 23:44
 */

#include "matricula.h"

matricula::matricula(){
}


matricula::~matricula() {
}


void matricula::matricular(universidad* u,estudiante* es){
  //estudiante* est = (estudiante*)es;
//ocupamos saber cual es la escuela
    escuela* esc = u->retornaEscuela();
    if(esc == NULL){cout<<"NO HAY ESCUELA"<<endl;return;}
    //buscar en la lista de grupos de el curso capturado
    //ya existe un retorna grupo
    grupo* grup = esc->retornaGrupo();
    if(grup == NULL){cout<<"NO HAY GRUPO"<<endl;return;}
    es->insetarCurso(grup);
    try{
       //grupo* gr = ((grupo*)grup);
        if(grup->getCantidad()>35){
            throw -1;
        }else{
            grup->insertarEstudianteGrupo(es);
        }
    }catch(int e){
        cout<<"EL GRUPO ESTA LLENO"<<endl;cin.get();return;        
    }
    
}

void matricula::montoPagarCreditos(estudiante* estu){
    system("cmd /c cls");
    double montoTotalPagar = 0;
    int cantDeCreditos = estu->getNumCreditos();
    double subTotal = 0;
    double subTotalExtranjero = 0;
    double descuento = 0;
    if(estu->getNumeroDeCursos() == 0){cout<<"No posee cursos matriculados"<<endl;return;}
    subTotal = (cantDeCreditos * costoPorCredito) + gastosAdministrativos;
    if(estu->getExtranjero()){
        subTotalExtranjero = (subTotal * 40) / 100;
        montoTotalPagar = subTotal + subTotalExtranjero;
    }
    else{
        descuento = subTotal * (estu->getPorcentajeBeca() / 100);   
        montoTotalPagar = subTotal - descuento;
    }
  
    desglosePagoCreditos(estu, subTotalExtranjero, descuento);
    cout<<"El monto total de creditos a pagar es de " <<montoTotalPagar<<" colones"<<endl;   
}


void matricula::desglosePagoCreditos(estudiante * estu, double recargoExtranjero, double descuentoBeca){
    cout<<"---------------------------------DESGLOSE---------------------------------"<<endl;
    cout<<"Creditos matriculados : "<< estu->getNumCreditos()<<endl;
    cout<<"Monto por creditos : "<< costoPorCredito<<endl;
    cout<<"Costos administrativos : "<< gastosAdministrativos<<endl;
    cout<<"Recargo por extranjero : "<< recargoExtranjero<<endl;
    cout<<"Descuento por beca : "<<descuentoBeca<<endl;
}


const int matricula::gastosAdministrativos = 15000;
const int matricula::costoPorCredito = 10000;