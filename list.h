#ifndef LIST_H
#define LIST_H

#include "node.h"

/**
 * The list class is a generic, extremely lightweight linked list. it should be used by overriding the node class and adding child objects using the add() method
 */
class List {
	public:
		/**
		 * Default constructer, simply initializes all variables
		 */
		List();
		/**
		 * adds the argument to the end of the list
		 * @param object the address of the object to be added to the list
		 */
		void add(Node* object);
		/**
		 * the current length of the list
		 * @return the list length
		 */
		int length();
		/**
		 * accessor function to get the nth member of the list
		 *
		 * @param position the 0-indexed position of the wanted object
		 * @return pointer to object, or 0 if position to large or small
		 */
		Node* get(int position);
	private:
		int size;
		Node* first;
	};

#endif