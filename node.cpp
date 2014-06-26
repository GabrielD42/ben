#include "node.h"

Node::Node() {
	next = 0;
	}

bool Node::setNext(Node* object) {
	if(next != 0 && object != 0) {
		next = object;
		return true;
		}
	return false;
	}

Node* Node::getNext() {
	return next;
	}