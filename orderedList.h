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
		 * adds the argument to the appropriate position in the list based on its comparison operators
		 *
		 * @param the piece of data to be added to the list
		 */
		void add(T data);
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
void OrderedList<T>::add(T data) {
	T newData = new T(data);
	Node<T> newNode = new Node<T>(&newData);
	for(int i = 0; i < List<T>::length(); i++) {
		if(*(newNode->getData()) <= *(List<T>::get(i)->getData())) {
			insert(i, newNode);
			return;
			}
		}
	insert(List<T>::length(), newNode);
	}
template <class T>
void OrderedList<T>::insert(int position, Node<T>* object) {
	if(List<T>::length() != 0 && position < List<T>::length() && position >= 0) {
		Node<T>* previous = List<T>::get(position - 1);
		Node<T>* next = List<T>::get(position);
		if(previous) {
			previous->setNext(object);
			}
		else {
			// we must be adding to the beginning of the list, so we need to reassign first
			this->first = object;
			}
		if(next) {
			object->setNext(next);
			}
		(this->size)++;
		}
	else {
		List<T>::add(object); // will increment size
		}
	}

#endif