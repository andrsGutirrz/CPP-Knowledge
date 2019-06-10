#pragma once
#include <iostream>
#include <sstream>
#include <memory>
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
	shared_ptr<Node> first;
	shared_ptr<Node> current;
	shared_ptr<Node> last;
	int size;
};
