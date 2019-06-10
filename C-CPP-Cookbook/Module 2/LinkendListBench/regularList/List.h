#pragma once
#include <iostream>
#include <sstream>
#include "Node.h"
using namespace std;

class List {
public:
	List();
	~List();
	void addFirst(int);
	void addLast(int);
	string toString();
	int getSize() const;
private:
	Node* first;
	Node* current;
	Node* last;
	int size;
};
