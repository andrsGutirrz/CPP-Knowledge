#pragma once
#include<iostream>
#include<list>
#include<vector>
#include"Tombola.h"
#include"Jugador.h"
#include"Libraries\CTML\CTML.h"

using namespace std;
using namespace CTML;

class HTMLInterface {

public:

	HTMLInterface();
	void styleSheets();
	void serialize(list<Jugador*>, int);
	void write(int);

	Document doc;
	Node td;
};