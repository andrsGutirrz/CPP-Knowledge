#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Node {
public:
	Node(int, Node*);
	~Node();
	void setNext(Node*);
	Node* getNext()const;
	string toString();
private:
	Node* next;
	int data;
};
