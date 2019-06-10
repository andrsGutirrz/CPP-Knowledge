#pragma once
#include <iostream>
#include <algorithm>    // std::shuffle
#include <vector>
#include <chrono>
#include <random> 
#include <stack>

using namespace std;

class Tombola {
public:
	Tombola();
	bool vacio();
	int sacar(); //Saca una bolita.
	int tope();

	vector<int> shuffle(); //Genera arreglo desordenado del 1 al 75.

private:
	stack<int> bolitas;
};