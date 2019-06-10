#include "List.h"

List::List():first(NULL),current(NULL),last(NULL),size(0) {
}

List::~List() {
	cout<<"Elimina List"<<endl;
	current = first;
	while (current != NULL) {
		Node * temp = current;
		current = current->getNext();
		delete temp;
	}
}

void List::addFirst(int _data) {
	if (!first) {
		first = new Node(_data, NULL);
		size++;
	}
	else {
		first = new Node(_data, first);
		size++;
	}
}

void List::addLast(int _data) {
	if (!first) {
		first = new Node(_data, NULL);
		size++;
		last = first;
	}
	else {
		last->setNext(new Node(_data, NULL));
		last = last->getNext();
	}
}

string List::toString() {
	stringstream s;
	s << "\t" <<"List"<<"\n";
	s << "=================================" << "\n";
	current = first;
	while (current != NULL) {
		s<<current->toString() << "\n";
		current = current->getNext();
	}
	s << "=================================" << "\n";
	return s.str();
}

int List::getSize() const {
	return this->size;
}
