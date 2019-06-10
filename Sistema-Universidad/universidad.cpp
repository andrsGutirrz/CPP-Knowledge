/* 
 * File:   Universidad.cpp
 * Author: User
 * 
 * Created on 14 de marzo de 2017, 07:53 PM
 */

#include "universidad.h"
#include "lista.h"
#include "profesor.h"
#include "interfazUniversidad.h"

universidad::universidad(istream& entrada ){
    entrada>>nombre;
    entrada>>direccion;
    entrada>>telefono;
    if (!entrada.good()) {
        throw -1;
    }
    listaProf = new lista <profesor> ();
    listaEstu = new lista <estudiante>();
    listaEsc = new lista <escuela> ();
    intfz = new interfazControl();
    inter = new interfazUniversidad();
}


universidad::universidad(string nomb ,string direcc,string telef):nombre(nomb),direccion(direcc),telefono(telef)
{
    listaProf = new lista <profesor> ();
    listaEstu = new lista <estudiante>();
    listaEsc = new lista <escuela> ();
    intfz = new interfazControl();
    inter = new interfazUniversidad();
}   

void universidad::respaldarEscuelas(ostream& salida){
    salida<<listaEsc->numElementos()<<"\n";
    iterador<escuela>* it = listaEsc->obtenerIterador();
    while(it->masElementos()){
        it->proximoElemento()->guardarEscuela(salida);    
    }
}

void universidad::restaurarEscuela(istream& entrada){
    int cont = 1;
    int cantidadEscuelas = 0;
    entrada>>cantidadEscuelas;
    escuela* ec = NULL;
    while(cont<=cantidadEscuelas){
        ec = new escuela(entrada);
        listaEsc->agregar(ec);
        cont++;
    }
}

void universidad::restaurarEstudiante(istream& lectura){
    int cont = 1;
    int cantidadEstudiantes = 0;
    lectura>>cantidadEstudiantes;
    estudiante* ec = NULL;
    while(cont<=cantidadEstudiantes){
        ec = new estudiante(lectura);
        listaEstu->agregar(ec);
        cont++;
    }
    
}

void universidad::restaurarProfesor(istream& lectura){\
    int cont = 1;
    int cantidadProfesores = 0;
    lectura>>cantidadProfesores;
    profesor* pf = NULL;
    while(cont<=cantidadProfesores){
        pf = new profesor(lectura);
        listaProf->agregar(pf);
        cont++;
    }
}



universidad::~universidad(){
    delete listaEsc;
    delete intfz;
    delete inter;
    delete listaEstu;
    delete listaProf;
}

void universidad::iniciarlizarListaEscuelas(){
    escuela* escuela1 = new escuela("INFORMATICA","LAGUNILLA","61688613","INF01");
    escuela* escuela2 = new escuela("BIOPROCESOS","HEREDIA","61688613","BIOQUI01");
    listaEsc->agregar(escuela1);
    listaEsc->agregar(escuela2);   
}

void universidad::setDireccion(string direcc) {this->direccion = direcc;}
void universidad::setTelefono(string telef) {this->telefono = telef;}

string universidad::getDireccion(){return direccion;}
string universidad::getTelefono() {return telefono;}
string universidad::getNombre() {return nombre;}

string universidad::toString()
{
   stringstream s;
   s<<"Nombre : " << getNombre() << endl;
   s <<"Direccion: " << getDireccion() <<endl;
   s<<"Telefono: " << getTelefono() <<endl;
   return s.str();
}

void universidad::cambiarNumero(){
    string aux="";
    cout<<"Digite nuevo numero"<<endl;
    cin>>aux;
    if (intfz->esNumero(aux)){
        setTelefono(aux);
    }else{
        intfz->advertencia();
        this->cambiarNumero();
    }
    // El metodo debe ser recursivo debido a que si elusuario digita una letra, los saca del metodo, la idea es que salga del metodo 
    //hasta que se digite correctamente el numero de telefono. 
}

void universidad::cambiarDireccion(){
    setDireccion(intfz->cambiarDireccion());
}

void universidad::registrarEscuela(){
    system("cmd /c cls");
    string nom,dir,tel,cod = " ";
    cin.ignore(256,'\n');
    nom = inter->pedirNombreEscuela();intfz->mayuscula(nom);
    dir = inter->pedirDireccionEscuela();intfz->mayuscula(dir);
    tel = inter->pedirTelefonoEscuela();intfz->mayuscula(tel);
    cod = inter->pedirCodigoEscuela();intfz->mayuscula(cod);
    escuela* aux = new escuela(nom, dir, tel, cod);
    listaEsc->agregar(aux);
}

string universidad::imprimeCodigoEscuela(){
    stringstream s;
    iterador<escuela>* it = listaEsc->obtenerIterador();
    s<<"---------------------------------------------------"<<endl;
    s <<"  Lista de Escuelas " << endl<<endl;
    s<<"Codigo    :    Nombre"<<endl<<endl;
    s<<"'''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
    while(it->masElementos())
    {
        escuela* ec = it->proximoElemento();
        s<<ec->getCodigoEscuela()<<" : "<<ec->getNombre()<<endl;//se castea a Escuela
    }
    s<<"---------------------------------------------------"<<endl;
    return s.str();
    
}

escuela* universidad::retornaEscuela(){
    system("cmd /c cls"); 
    cout<<imprimeCodigoEscuela()<<endl;
    string aux = intfz->ingresaCodigo();
    intfz->mayuscula(aux);
    coleccionBuscable<escuela>* cB = new coleccionBuscable<escuela>(listaEsc);
    escuela* ec = cB->buscar(aux);
    delete cB;
    return ec;
}

void universidad::consultarEscuela()
{
    escuela* esc = this->retornaEscuela();
    if(esc==NULL){return;}
    cout<<esc->toString()<<endl;
}

string universidad::imprimirTodasEscuelas(){
    return listaEsc->toString();
}


void universidad::insertarCurso(){
    int aux5 = 0;
    escuela* esc = this->retornaEscuela();//almacena la escuela
    if(esc == NULL){cout<<"NO EXISTE ESCUELA";cin.get();return;}
    esc->registrarCurso();
   
}

void universidad::imprimirCursosEscuela(){
    this->retornaEscuela()->imprimirCursos();
}

void universidad::cambiarNombreCurso(){
    escuela* ec = this->retornaEscuela();
    if(ec == NULL){cout<<"NO HAY ESCUELA"<<endl;return;}
    ec->cambiarNombreCurso();
}

void universidad::imprimirTodosCursos(){/** imprime organizados por escuelas*/
    iterador<escuela> * i = listaEsc->obtenerIterador();
    escuela* ec;
    while (i->masElementos()) {
        ec = i->proximoElemento(); //OPERADOR SOBRECARGADO
         cout<<"*"<<ec->getNombre()<<endl;
         cout<<ec->imprimeNombresCursos();
    }      
}

 void universidad::eliminarCurso(){
    string aux= "";
    escuela * temp = this->retornaEscuela();
    if(temp == NULL){inter->escuelaNoExiste();cin.get();return;}
    if(temp->listaEscVacia()){inter->escuelaSinCursos();cin.get();cin.get();return;}
    curso* cr = temp->retornaCurso();
    if(cr!=NULL){
       cout<< cr->toString();
       temp->eliminarCurso(cr);
    }
 }
 
 void universidad::registrarProfesores(){
    system("cmd /c cls");
    string nom,id,ape1,ape2,opcion = " ";
    cin.ignore(256,'\n');
    cout<<"ESCOGER LA ESCUELA"<<endl;cin.get();
    escuela *esc = this->retornaEscuela();
    if(esc==NULL){inter->escuelaNoExiste();cin.get();return;}
    cout<<"Establecer como director si=1,no=0";cin>>opcion;
    id = inter->pedirCedula();intfz->mayuscula(id);
    nom = inter->pedirNombre();intfz->mayuscula(nom);
    ape1 = inter->pedirApellido1();intfz->mayuscula(ape1);
    ape2 = inter->pedirApellido2();intfz->mayuscula(ape2);
    if(!validadorID(id)){
        profesor* profe = new profesor(id,nom,ape1,ape2);
        listaProf->agregar(profe);
        profesor* p = (profesor*)profe;
        if(p->getTengoEscuela()){cout<<"El profesor ya se encuentra registrado en una escuela"<<"( "<<p->getNombreEscuela()<<" )"<<endl;cin.get();return;}
        esc->insertarProfesor(profe);
        p->setMiEscuela(esc->getNombre());//a profesor le pasa el nombre de la escuela a la cual pertenece
        if(opcion=="1"){p->setDirector(true);esc->establecerDirector(p);}
    }else {
        cout<< "El ID ingresada ya esta registrada " <<endl;cin.get();
        registrarProfesores();
    }
  }
 
  
bool universidad::validadorID(string str){//si esta true
    iterador<profesor>* it = listaProf->obtenerIterador();
    while(it->masElementos()){
        profesor* pf = it->proximoElemento();
        if(pf->getId()==str)
            return true;
    }
    return false;
}

void universidad::imprimirProfes(){
    cout<<this->listaProf->toString()<<endl;
} 

profesor* universidad::retornaProfesor(string _id){
    coleccionBuscable<profesor>* cB = new coleccionBuscable<profesor>(listaProf);
    profesor* p = cB->buscar(_id);
    delete cB;
    return p;
}


void universidad::buscarProfeEspecifico(){//pide al usuario id, valida e imprime
    system("cmd /c cls");
    if(listaProf->numElementos()== 0){cout<<"lista vacia1"<<endl;cin.get();return;}
    string aux = inter->pedirCedula();
    if(!validadorID(aux)){
        inter->profesorNoRegistrado();cin.get();return;
    }else{
        cout<<retornaProfesor(aux)->toString();
    }
}

void universidad::eliminarProfesor(){/*SE DEBE CAMBIAR*///se debe revisar
    system("cmd /c cls");
    if(listaProf->numElementos()== 0){cout<<"lista vacia"<<endl;cin.get();return;}
    this->imprimirProfes();
    string aux = inter->pedirCedula();
    if(!validadorID(aux)){
        cout<<"El profesor no se encuentra registrado en nuestra base de datos"<<endl;cin.get();return;
    }
    iterador <profesor>*it = listaProf->obtenerIterador();
    profesor* profeBase = NULL;
    while(it->masElementos()){
        profeBase = it->proximoElemento();
        profesor* profe = profeBase;
        if(profe->getId() == aux){
            //listaProf->eliminarNodo(profeBase);
        }
    }
    delete profeBase;
}

void universidad::modificarDatosProfe(){
    system("cmd /c cls"); 
    if(listaProf->numElementos()== 0){cout<<"lista vacia"<<endl;cin.get();return;}
    string aux1 = inter->pedirCedula();
    if(!validadorID(aux1)){
        cout<<"El profesor no se encuentra registrado en nuestra base de datos"<<endl;cin.get();return;
    }else{
        system("cmd /c cls");
        string nom,ape1,ape2 = " ";
        nom = inter->pedirNombre();intfz->mayuscula(nom);
        ape1 = inter->pedirApellido1();intfz->mayuscula(ape1);
        ape2 = inter->pedirApellido2();intfz->mayuscula(ape2);
        profesor* pf = retornaProfesor(aux1);
        pf->setNombre(nom);//revisar
        pf->setApe1(ape1);
        pf->setApe2(ape2);
    }  
}

void universidad::asignarProfeCursoU(){
    escuela* ec = this->retornaEscuela();
    if(ec == NULL){ cout<<"La escuela no esta"<<endl;cin.get();return;}
    if(!ec->hayProfes()){intfz->listaVacia();return;}
    ec->asignarProfeCurso();
}

void universidad::imprimirCargaAcademica(){
    escuela* ec = this->retornaEscuela();
    if(ec == NULL){ cout<<"La escuela no esta"<<endl;cin.get();return;}
    if(!ec->hayProfes()){intfz->listaVacia();return;}
    ec->imprimirProfes();
    string aux = inter->pedirCedula();
    profesor* pf = ec->retornaProfesor(aux);
    if(pf==NULL){intfz->listaVacia();return;}
    cout<<pf->imprimirMisCursos()<<endl;    
}

void universidad::imporimirProfesEscuela(){
    escuela* ec = this->retornaEscuela();
    if(ec == NULL){ cout<<"La escuela no esta"<<endl;cin.get();return;}
    ec->imprimirProfes();
}

void universidad::relacionarProfesor(){
    iterador<profesor>*it = listaProf->obtenerIterador();
    profesor* pf = NULL;
    while(it->masElementos()){
        pf = it->proximoElemento();
        iterador<escuela>*itE = listaEsc->obtenerIterador();
        while(itE->masElementos()){
            escuela* ec = itE->proximoElemento();
            if(ec->getNombre() == pf->getNombreEscuela())
                ec->insertarProfesor(pf);
        }
    }
}

void universidad::consultarProfesSegunCurso(){
    escuela* ec = this->retornaEscuela();
    if(ec == NULL){ cout<<"La escuela no esta"<<endl;cin.get();return;}
    curso* cr = ec->retornaCurso();
    if(cr == NULL){ cout<<"El curso no esta"<<endl;cin.get();return;}
    cout<<cr->recuperarProfesoresCurso()<<endl;
}
//------------------------------------------------------------------------------Estudiante------------------------------------------------------------------------------
void universidad::registrarEstudiante(){
    system("cmd /c cls");
    string nom, id, ape1, ape2, carnet = " ";
    string extranjero = "";
    float porcentajeBeca = 0;
    cin.ignore(256,'\n');
    id = inter->pedirCedula();intfz->mayuscula(id);
    nom = inter->pedirNombre();intfz->mayuscula(nom);
    ape1 = inter->pedirApellido1();intfz->mayuscula(ape1);
    ape2 = inter->pedirApellido2();intfz->mayuscula(ape2);
    carnet = inter->pedirCarnet();intfz->mayuscula(carnet);
    extranjero = inter->pedirNacionalidad();
    bool esEx = esExtranjero(extranjero);
    if(!esEx){
        try{
            porcentajeBeca = inter->pedirPorcentajeBeca();
            if(porcentajeBeca>100 || porcentajeBeca < 0){throw -1;}
        }catch(int e){
            cout<<"Porcentaje introducido no es valido"<<endl;cin.get();return;
        }
    }
    
    if(!validarIDCarnet(id) && !validarIDCarnet(carnet)){
        estudiante* aux = new estudiante(nom, id, ape1, ape2, carnet, esEx,porcentajeBeca);
        listaEstu->agregar(aux);
    }else {
        cout<< "El ID o numero de carnet ingresadas ya esta registrada " <<endl;cin.get();
        registrarEstudiante();
    }
}

bool universidad::esExtranjero(string x){
    string aux = "";
    if(x == "0")
        return false;
    
    if(x == "1")
        return true; 
    if(x!="1" || x!="0"){
        aux = inter->pedirNacionalidad();
        esExtranjero(aux);
    }
}

bool universidad::validarIDCarnet(string str){//si esta true
    iterador<estudiante>* it = listaEstu->obtenerIterador();
    while(it->masElementos()){
        estudiante* pf = it->proximoElemento();
        if(pf->getId() == str)
            return true;
    }
    return false;
}

 void universidad::desplegarEstudiantes(){
     cout<<listaEstu->toString()<<endl;
 }
 
 estudiante* universidad::retornaEstudiante(string _id){// busca por cedula o por numero de carnet
    iterador<estudiante>* it = listaEstu->obtenerIterador();
    while(it->masElementos()){
        estudiante* pf = it->proximoElemento();
        if(pf->getId() == _id || pf->getNumCarnet() == _id)
            return pf;
    }
    return NULL; //NO ENCONTRO ESTUDIANTE
 }
 
 void universidad::verCursosEstudiante(){
     string aux = " ";
     cout<<"ingrese id o carnet"<<endl;
     cin>>aux;
     estudiante* es = this->retornaEstudiante(aux);
     if(es==NULL){cout<<"no se encontro estudiante";cin.get();return;}
     es->verMisCursos();
 }

 estudiante* universidad::log(){
     system("cmd /c cls");
     inter->logginPresentacion();
     string aux = inter->pedirCedula();
     estudiante* es = this->retornaEstudiante(aux);
     return es;
 }
 
 
 void universidad::actualizarDatosEstudiante(estudiante* est){
    system("cmd /c cls");
    if(listaEstu->numElementos() == 0){cout<<"lista vacia"<<endl;cin.get();return;}
    system("cmd /c cls");
    string nom,ape1,ape2 = " ";
    nom = inter->pedirNombre();intfz->mayuscula(nom);
    ape1 = inter->pedirApellido1();intfz->mayuscula(ape1);
    ape2 = inter->pedirApellido2();intfz->mayuscula(ape2);
    est->setNombre(nom);
    est->setApe1(ape1);
    est->setApe2(ape2);
     
}
 
void universidad::respaldarEstudiantes(ostream& salida){
    salida<<"\n"<<listaEstu->numElementos()<<" ";
    iterador<estudiante>* it = listaEstu->obtenerIterador();
    estudiante* est = NULL;
    while(it->masElementos()){
        est = it->proximoElemento();
        est->guardarEstudiante(salida);
    }
}

void universidad::respaldarProfesores(ostream& salida){
    salida<<"\n"<<listaProf->numElementos()<<" ";
    iterador<profesor>* it = listaProf->obtenerIterador();
    profesor* pf = NULL;
    while(it->masElementos()){
        pf = it->proximoElemento();
        pf->guardarProfesor(salida);
    }
}


void universidad::relacionarEstudiante(){
    iterador<estudiante>*it = listaEstu->obtenerIterador();
    
    estudiante* _estudiante = NULL;
    while(it->masElementos()){
        iterador<escuela>* itEscuela = listaEsc->obtenerIterador();
        _estudiante = it->proximoElemento();
        //recorer escuelas para acceder a cursos, luego grupos y comparar
        while(itEscuela->masElementos()){
            itEscuela->proximoElemento()->relacionarEstudiante(_estudiante);
        } 
        delete itEscuela;
    }
}

void universidad::reportePorGrupos(ostream& salida){
    salida<<"\n-----------------REPORTE NOTAS POR GRUPO-----------------\n";
    iterador<escuela>* it = listaEsc->obtenerIterador();
    while(it->masElementos()){
        it->proximoElemento()->reporteGrupos(salida);
    }
    salida<<"--------------------FIN REPORTE NOTAS GRUPO-----------------------\n";
}

void universidad::reportePorEstudiantes(ostream& salida){
    salida<<"\n-----------------REPORTE NOTAS POR ESTUDIANTE-----------------\n";
    iterador<estudiante>*it = listaEstu->obtenerIterador();
    estudiante* est = NULL;
    while(it->masElementos()){
        est = it->proximoElemento();
        salida<<est->getNombre()<<" "<<est->getApe1()<<" "<<est->getApe2()<<"\n";
        salida<<est->verMiNotas()<<"\n";
    }
    salida<<"--------------------FIN REPORTE NOTAS ESTUDIANTE-----------------------\n";
}

void universidad::matricularCursos(estudiante* est){
    //ocupamos saber cual es la escuela
    escuela* esc = this->retornaEscuela();
    if(esc == NULL){cout<<"NO HAY ESCUELA"<<endl;return;}
    //ocupamos saber cual es el curso
    grupo* gr = esc->retornaGrupo();
    if(gr == NULL){cout<<"NO HAY GRUPO"<<endl;return;}
    //meter el curso en la lista de cursos
    est->insetarCurso(gr);
}

/**PARA GRUPOS*/
void universidad::verGrupos(){
    escuela* esc = this->retornaEscuela();
    if(esc == NULL){cout<<"NO HAY ESCUELA"<<endl;return;}
    curso* cr = esc->retornaCurso();
    if(cr==NULL){cout<<"NO HAY CURSO"<<endl;return;}
    cout<<cr->verGrupos()<<endl;
}

void universidad::verEstudiantesMatriculados(){
    escuela* esc = this->retornaEscuela();
    if(esc == NULL){cout<<"NO HAY ESCUELA"<<endl;return;}
    grupo* gr = esc->retornaGrupo();
    if(gr==NULL){cout<<"NO HAY GRUPO"<<endl;return;}
    gr->verEstudiantesMatriculados();
}

void universidad::fijarNotas(){
    //ocupamos saber cual es la escuela
    escuela* esc = this->retornaEscuela();
    if(esc == NULL){cout<<"NO HAY ESCUELA"<<endl;return;}
    //ocupamos saber cual es el curso
    grupo* gr = esc->retornaGrupo();
    if(gr == NULL){cout<<"NO HAY GRUPO"<<endl;return;}
    //meter el curso en la lista de cursos
    gr->asignarNotas();
}

void universidad::verNotasEstudiante(estudiante* est){
    cout<<est->verMiNotas()<<endl;
}
