#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

/**
 * Node class for linked list. should not be implemented.
 */
template <class T>
class Node {
	public:
		/**
		 * initializes the variables
		 */
		Node(T* tempData) {
			next = 0;
			data = tempData;
			}
		/**
		 * set what the node after this one is. the operation will fail if object isn't a valid pointer or if `next` is already set
		 *
		 * @param object the node after this one
		 * @return wether or not this was sucessful
		 */
		bool setNext(Node<T>* object) {
			cout << "in Node<T>*::setNext()" << endl;
			cout << "setting next to " << object << endl;
			if(next != 0 && object != 0) {
				next = object;
				return true;
				}
			return false;
			}
		/**
		 * get the address of the next node
		 * @return the address of the next node
		 */
		Node<T>* getNext() {
			cout << "in Node<T>*::getNext()" << endl;
			cout << "returning " << next << endl;
			return next;
			}
		/**
		 * Returns a pointer to the data stored in this Node
		 * @return address of data
		 */
		T* getData() {
			return data;
			}
	private:
		Node<T>* next;
		T* data;
	};

#endif