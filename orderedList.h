#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include "list.h"
#include "node.h"

/**
 * This type of list keeps all its members ordered, from smallest to largest, using the data's comparision operators
 *
 * @tparam T the type of data to be stored in the list
 */
template <class T>
class OrderedList : public List<T> {
	public:
		/**
		 * adds the argument to the appropriate position in the list based on its comparison operators. object must be allocated on heap. takes over control of object, ie DO NOT DELETE OBJECT
		 *
		 * @param object the address of the object to be added to the list
		 */
		void add(Node<T>* object);
	protected:
		/**
		 * inserts the argument into list at position specified
		 *
		 * @param position where to insert the new Node
		 * @param object the address of the object to be added to the list
		 */
		void insert(int position, Node<T>* object);
	};

template <class T>
void OrderedList<T>::add(Node<T>* object) {
	for(int i = 0; i < List<T>::length(); i++) {
		if(object->getData() <= List<T>::get(i)->getData) {
			insert(i, object);
			return;
			}
		}
	insert(List<T>::length(), object);
	}
template <class T>
void OrderedList<T>::insert(int position, Node<T>* object) {
	if(List<T>::length() != 0 && position < List<T>::length() && position >= 0) {
		Node<T>* previous = List<T>::get(position);
		Node<T>* next = List<T>::get(position + 1);
		previous->setNext(object);
		if(next) {
			object->setNext(next);
			}
		}
	else {
		List<T>::add(object);
		}
	}

#endif