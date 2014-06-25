#include "list.h"
#include "node.h"

List::List() {
	size = 0;
	first = 0;
	}

int List::length() {
	return size;
	}

void List::add(Node* object) {
	if(length() == 0) {
		first = object;
		}
	else {
		get(length() - 1)->next = object;
		}
	size++;
	}

Node* List::get(int position) {
	if(position < length()) {
		Node* returnValue = first;
		for(int i = 0; i < position; i++) {
			returnValue = returnValue->next;
			}
		return returnValue;
		}
	return 0;
	}