#pragma once
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

class Node {
public:
	Node(int, shared_ptr<Node>);
	~Node();
	void setNext(shared_ptr<Node>);
	shared_ptr<Node> getNext()const;
	string toString();
private:
	shared_ptr<Node> next;
	int data;
};
