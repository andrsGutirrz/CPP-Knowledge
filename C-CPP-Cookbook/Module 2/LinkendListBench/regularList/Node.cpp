#include "Node.h"

Node::Node(int _data,Node* _next):next(_next),data(_data){
}

Node::~Node(){
	cout<<"Deleted node"<<endl;
}

void Node::setNext(Node* _node){
	this->next = _node;
}

Node* Node::getNext() const {
	return this->next;
}

string Node::toString() {
	stringstream s;
	s << "Data: " << this->data << "\n";
	return s.str();
}
