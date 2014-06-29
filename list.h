#ifndef LIST_H
#define LIST_H

#include "node.h"

/**
 * The list class is a generic, extremely lightweight linked list. it should be used by overriding the node class and adding child objects using the add() method
 */
template <class T>
class List {
	public:
		/**
		 * Default constructer, simply initializes all variables
		 */
		List() {
			size = 0;
			first = 0;
			}
		/**
		 * adds the argument to the end of the list. object must be allocated on heap. takes over control of object, ie DO NOT DELETE OBJECT
		 * @param object the address of the object to be added to the list
		 */
		void add(Node<T>* object) {
			if(length() == 0) {
				first = object;
				}
			else {
				get(length() - 1)->setNext(object);
				}
			size++;
			}
		/**
		 * the current length of the list
		 * @return the list length
		 */
		int length() {
			return size;
			}
		/**
		 * accessor function to get the nth member of the list
		 *
		 * @param position the 0-indexed position of the wanted object
		 * @return pointer to object, or 0 if position to large or small
		 */
		Node<T>* get(int position) {
			if(position < length() && position >= 0) {
				Node<T>* returnValue = first;
				for(int i = 0; i < position; i++) {
					returnValue = returnValue->getNext();
					}
				return returnValue;
				}
			return 0;
			}
		/**
		 * delete all elements in list
		 */
		~List() {
			Node<T>* nextValue = first;
			while(nextValue) {
				Node<T>* deleteThis = nextValue;
				nextValue = deleteThis->getNext();
				delete deleteThis;
				}
			}
	private:
		int size;
		Node<T>* first;
	};

#endif