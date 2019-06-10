#include "Node.h"
#include <memory>

Node::Node(int _data,shared_ptr<Node> _sig):next(_sig),data(_data){
}

Node::~Node(){
	//cout<< "Deleted node" <<endl;
}

void Node::setNext(shared_ptr<Node> _data){
	this->next = _data;
}

shared_ptr<Node> Node::getNext() const {
	return this->next;
}

string Node::toString() {
	stringstream s;
	s << "data: " << this->data << "\n";
	return s.str();
}
