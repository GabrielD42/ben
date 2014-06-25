#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
	public:
		List();
		void add(Node* object);
		int length();
		Node* get(int position);
	private:
		int size;
		Node* first;
	};

#endif