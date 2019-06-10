#include "List.h"
#include <memory>

List::List():first(nullptr),current(nullptr),last(nullptr),size(0) {
}

List::~List() {
	cout<< "List start to delete" <<endl;
}

void List::addFirst(int _data) {
	if (!first) {
		first = make_shared<Node>(_data, nullptr);
		size++;
	}
	else {
		first = make_shared<Node>(_data,first);
		size++;
	}
}

void List::addLast(int _data) {
	if (!first) {
		first = make_shared<Node>(_data, nullptr);
		size++;
		last = first;
	}
	else {
		last->setNext(make_shared<Node>(_data, nullptr));
		last = last->getNext();
	}
}

string List::toString() {
	stringstream s;
	s << "\t" <<"List"<<"\n";
	s << "=================================" << "\n";
	current = first;
	while (current != nullptr) {
		s<<current->toString() << "\n";
		current = current->getNext();
	}
	s << "=================================" << "\n";
	return s.str();
}

int List::getSize() const {
	return this->size;
}
