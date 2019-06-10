/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on 12 de marzo de 2017, 08:27 PM
 */

#include <cstdlib>
#include "librerias.h"
#include "control.h"
#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include "curso.h"

#include "escuela.h"
using namespace std;


int main() {
    sistema* st = new sistema();
    st->empezar();
     return 0;
}

