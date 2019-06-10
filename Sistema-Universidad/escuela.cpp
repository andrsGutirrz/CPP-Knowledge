/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escuela.cpp
 * Author: User
 * 
 * Created on 12 de marzo de 2017, 08:28 PM
 */

#include "escuela.h"

escuela::escuela(istream& entrada){
    int cantidadCursos = 0;
    entrada>>cantidadCursos;
    entrada>>nombre;
    entrada>>direccion;
    entrada>>numeroTelef;
    entrada>>codigoEscuela;
    listaCursos = new lista<curso>();
    profesores = new lista<profesor>();
    intfz = new interfazEscuela();
    this->director = NULL;
    restaurarCurso(entrada,cantidadCursos);   
}

void escuela::restaurarCurso(istream& entrada, int cantidadCursos){
    int cont = 1;
    curso* cr = NULL;
    while(cont<=cantidadCursos){
        cr = new curso(entrada); 
        listaCursos->agregar(cr);
        cont++;
    }    
}

escuela::escuela(string nom, string direc, string telef,string codig):codigoEscuela(codig),nombre(nom),direccion(direc),numeroTelef(telef)
{
    listaCursos = new lista<curso>();
    profesores = new lista<profesor>();
    intfz = new interfazEscuela();
    this->director = NULL;
}

void escuela::guardarEscuela(ostream& salida){
    salida<<listaCursos->numElementos()<<" "<<nombre<<" "<<direccion<<" "<<numeroTelef<<" "<< codigoEscuela<<"\n";
    iterador<curso>* it = listaCursos->obtenerIterador();
    curso* cr = NULL;
    while(it->masElementos()){
        cr=it->proximoElemento();
        cr->guardarCurso(salida);
    }
    if(!it->masElementos())
    {}
}

escuela::~escuela() {
    delete listaCursos;
    delete profesores;
    delete intfz;
}

 void escuela::establecerDirector(profesor* p){
    director = p;
 }
    
string escuela::getCodigoEscuela(){return this->codigoEscuela;}//quitar
 string escuela::getDireccion() { return direccion;}
void escuela::setDireccion(string direc){this->direccion = direc;}
string escuela::getTelef(){return numeroTelef;}
void escuela::setTelef(string telef){this->numeroTelef = telef;}
string escuela::getNombre() const {return nombre;}
string escuela::obtenerLlave(){return codigoEscuela;}
    
string escuela::toString()
{
    stringstream s;
    s<<"\n\nNombre: \t" << this->getNombre() <<endl;
    s<<"Codigo: \t" << this->getCodigoEscuela() << endl;
    s<<"Direccion: \t" << this->getDireccion() <<endl;
    s<<"Num. Telef: \t" << this->getTelef()<< endl;
    if(director==NULL){s<<"(SIN DIRECTOR)"<<endl;}else{
    s<<"Director: \t"<<director->getNombre()<<" "<<director->getApe1()<<endl;}
    return s.str();
}

bool escuela::estaCurso(string s){
    iterador <curso>*it = listaCursos->obtenerIterador();
    string aux = " ";
    curso* cr = NULL;
    while(it->masElementos()){
        aux = it->proximoElemento()->getCodigoCurso();
        if(aux==s){return true;}
    }
    return false;
}

curso* escuela::retornaCurso(){
    curso* cr = NULL;
    iterador <curso>*it = listaCursos->obtenerIterador();
    if(!it->masElementos()){return NULL;}
    cout<<imprimeCodigoCursos()<<endl;
    string aux = " ";
    aux = intfz->pedirSiglas();
    intfz->mayuscula(aux);  
    coleccionBuscable<curso>* cB = new coleccionBuscable<curso>(listaCursos);
    cr = cB->buscar(aux);
    delete cB;
    return cr;
}

void escuela::registrarCurso(){
    string canCur = " ";
    string aux2=" ";//es para el nombre
    string aux3=" ";//es la el nrc
    string aux4=" ";//pertence
    string aux6 = " ";//siglas del curso
    int aux5 = 0;
    system("cmd /c cls"); 
    cout<<"Insertar curso1"<<endl;
    cout<<"---- "<<this->getNombre()<<" ----"<<endl;
    canCur = intfz->pedirCantidadCursos();
    if(!intfz->esNumero(canCur)){cout<<"NO DIGITO UN NUMERO ";cin.get();return;}
    int b = atoi(canCur.c_str());//convierto el string en entero
    aux2 = intfz->pedirNombreCurso();
    aux6 = intfz->pedirSiglas();intfz->mayuscula(aux6);
    aux3 = intfz->pedirNRC(); 
    aux5 = intfz->pedirCreditos();
    aux4 = this->getNombre();//Nombre de la escuela
    intfz->mayuscula(aux3);intfz->mayuscula(aux2);intfz->mayuscula(aux4);
    if(!this->validadorCodigo(aux3)){//si no esta, entonces si cree el curso
        curso* ob = new curso(aux2,aux6,aux4,aux5);
        this->insertarCurso(ob);//insercion del curso
        string p=aux3;
        for(int i=1;i<=b;i++){
            stringstream s;
            s<<p<<i;
            aux3 = s.str();
            grupo* obj = new grupo(aux2,aux3,aux5);//nombre, NRC, pertenece URGENTE VALIDAR NRC, QUE NO ESTE REPETIDO
            ob->insetarGrupo(obj);
        }
    }else{intfz->advertencia();return;}  
}
    
    
string escuela::imprimeCodigoCursos(){
    stringstream s;
    iterador<curso> *it = listaCursos->obtenerIterador();
    s <<intfz->imprimeCodigosHeader();
    if(!it->masElementos()){intfz->listaVacia();cin.get();}
    while(it->masElementos()){
        curso* c = it->proximoElemento();
        s<<c->getNombre()<<"    : "<<c->getCodigoCurso()<<" : "<<c->getPertenece()<<endl;
        s<<"----------------------------------------------------------"<<endl;
    }
    return s.str();
}
     
void escuela::consultarCursos(){
    curso* cr = this->retornaCurso();
    cout<<cr->toString();
 }

void escuela::insertarCurso(curso* cr){//relacion de agregacion
    listaCursos->agregar(cr);
}
  
 void escuela::imprimirCursos(){
     cout<<listaCursos->toString();
 }
 
 void escuela::eliminarCurso(curso* ob){
     iterador<curso>* it = listaCursos->obtenerIterador();
     curso *cr = NULL;
     while(it->masElementos()){
         cr = it->proximoElemento();
         if( cr == ob){
            //listaCursos->eliminarNodo(ob);//elimina el nodo donde se encuentra el objeto a eliminar (en teoria)
         }
     }
     delete cr;//ELIMINA EL CONTENIDO
 }
 
 void escuela::cambiarNombreCurso(){
    string aux = " ";
    iterador<curso>* it = listaCursos->obtenerIterador();
    if(!it->masElementos()){intfz->listaVacia();return;}
    curso* temp = this->retornaCurso();
    if(temp == NULL){return;}
    aux = intfz->pedirNombreCurso();
    temp->setNombre(aux);
 }
 
 escuela& escuela::operator=(const escuela& e){
     this->codigoEscuela = e.codigoEscuela;
     this->direccion = e.direccion;
     this->nombre = e.nombre;
     this->numeroTelef = e.numeroTelef;
     this->listaCursos = e.listaCursos;
     return *this;
 }
 
 bool escuela::validadorCodigo(string str){
     return this->estaCurso(str);
 }
   
  string escuela::imprimeNombresCursos(){
    stringstream s;
    iterador<curso>* it = listaCursos->obtenerIterador();
    if(it->masElementos()){
        while(it->masElementos()){
            curso* cs = it->proximoElemento();
            s<<"    "<<cs->getNombre()<<cs->recuperarProfesoresCurso()<<endl;
        }
    }
    s<<"    "<<"(vacio)"<<endl;    
    return s.str();
  }
  
bool escuela::listaEscVacia(){//investigar su uso
    iterador<curso>* it = listaCursos->obtenerIterador();
    return !it->masElementos(); //masElementos returna true si hay elementos, queremos el true cuando no haya elementos, por eso se niega
}


 
 void escuela::imprimirProfes(){
     cout<<this->profesores->toString();
 }
  
 bool escuela::hayProfes(){
    iterador<profesor>* it = profesores->obtenerIterador();
    return it->masElementos();
 }
 
bool escuela::validadorID(string str){//si esta true
   iterador<profesor>* it = profesores->obtenerIterador();
   while(it->masElementos()){
       profesor* pf = it->proximoElemento();
       if(pf->getId()==str)
           return true;
   }
   return false;
}
 
void escuela::insertarProfesor(profesor* profe){
    profesores->agregar(profe);
}
   
profesor* escuela::retornaProfesor(string _id){
    coleccionBuscable<profesor>* cB = new coleccionBuscable<profesor>(profesores);
    profesor* pf = cB->buscar(_id);
    delete cB;
    return pf;
}
void escuela::asignarProfeCurso(){
    string aux = " ";
    // 1) escoger profesor y guardar en puntero
    profesor* pf = NULL;
    imprimirProfes();
    aux = intfz->pedirId();
    if(!validadorID(aux)){intfz->noSeEncuentraProfesor();cin.get();return;}
    pf = this->retornaProfesor(aux);
    if(pf->esDirector()){cout<<"El profesor es director, no puede ser profesor";cin.get();return;}
    grupo *g = this->retornaGrupo();
    //grupo* gr = (grupo*)g;
    if(g==NULL){cout<<"sin grupo";return;}
    if(g->getProfesor() != NULL){intfz->profeTieneCurso();cin.get();return;}
    if(pf->yaTengoEseCurso(g)){cout<<"Este curso ya lo tiene este profe"<<endl;cin.get();cin.get();return;}//valida lo mismo jaja
    pf->insertarCursoProf(g);//se inserta el grupo en la lista de grupos del profesor
    g->setMiProfe(pf);//al grupo se le guarda el profesor que va a impoartir las clases
}


void escuela::consultaProfes(){
    stringstream s;
    s<<"Profesores: \n";
    string n = " ";
    this->imprimeNombresCursos();
    n = intfz->pedirNombreCurso();
    iterador<curso>* it = listaCursos->obtenerIterador();
    profesor * pf;
    while(it->masElementos()){
        curso* cs = it->proximoElemento();
        if(cs->getNombre() == n){
            pf = cs->getMisProfes();
            if(pf!=NULL){
                s<<pf->nombreCompleto()<<endl;
            }
        }
    }
    cout<<s.str()<<endl;
}


 /**PARA GRUPOS*/


grupo* escuela::retornaGrupo(){
   string aux = " ";
   curso* cr =  this->retornaCurso();
   if(cr==NULL){cout<<"SIN CURSO ";cin.get();return NULL;}
   cout<<cr->verGrupos()<<endl;
   aux = intfz->pedirNRC();
   intfz->mayuscula(aux);
   if(cr->estaGrupo(aux)){return cr->retornarGrupo(aux);}
   else{intfz->advertencia();return NULL;}
}

grupo* escuela::retornaGrupo(string nombreCurso,string nrc){
    iterador<curso>*it = listaCursos->obtenerIterador();
    while(it->masElementos()){
        curso* cr = it->proximoElemento();
        if(cr->getNombre() == nombreCurso)
            return cr->retornarGrupo(nrc);         
    }
}

void escuela::verGrupos(){
   curso* cr =  this->retornaCurso();
   if(cr==NULL){cout<<"SIN CURSO ";cin.get();return;}
   cout<<cr->verGrupos();
}

void escuela::reporteGrupos(ostream& salida){
    iterador<curso>* it = listaCursos->obtenerIterador();
    while(it->masElementos()){
        it->proximoElemento()->reporteNotas(salida);
    }
    
}


void escuela::relacionarEstudiante(estudiante* estu){
    iterador<curso>* it = listaCursos->obtenerIterador();
    while(it->masElementos()){
        it->proximoElemento()->relacionarEstudiante(estu);
    }
}