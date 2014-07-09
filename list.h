#ifndef LIST_H
#define LIST_H

#include "node.h"

/**
 * The list class is a generic, extremely lightweight linked list. it has the option to either take control of data stored in it or passively store it
 *
 * @tparam T the type of data to be stored in the list
 */
template <class T>
class List {
	public:
		/**
		 * Constructer initializes all variables. if tempControlData is true, then List will delete all data upon destruction
		 *
		 * @param tempControlData wether or not this class should control the data stored in it
		 */
		List(bool tempControlData);
		/**
		 * adds the argument to the end of the list
		 *
		 * @param a pointer to the piece of data to be added to the list
		 */
		void add(T* data);
		/**
		 * the current length of the list
		 *
		 * @return the list length
		 */
		int length();
		/**
		 * accessor function to get the nth piece of data in the list
		 *
		 * @param position the 0-indexed position of the wanted object
		 *
		 * @return pointer to the data at position specified, or 0 if position to large or small
		 */
		T* get(int position);
		/**
		 * delete all elements in list
		 */
		virtual ~List();
	protected:
		/**
		 * accessor function to get the nth node of the list
		 *
		 * @param position the 0-indexed position of the wanted object
		 *
		 * @return pointer to the node at position specified, or 0 if position to large or small
		 */
		Node<T>* getNode(int position);
		Node<T>* first;
		int size;
		const bool controlData;
	};

template <class T>
List<T>::List(bool tempControlData) : controlData(tempControlData) {
	size = 0;
	first = 0;
	}
template <class T>
void List<T>::add(T* data) {
	Node<T>* newNode = new Node<T>(data, controlData);
	if(length() == 0) {
		first = newNode;
		}
	else {
		get(length() - 1)->setNext(newNode);
		}
	size++;
	}
template <class T>
int List<T>::length() {
	return size;
	}
template <class T>
T* List<T>::get(int position) {
	return getNode(position)->getData();
	}
template <class T>
Node<T>* List<T>::getNode(int position) {
	if(position < length() && position >= 0) {
		Node<T>* returnValue = first;
		for(int i = 0; i < position; i++) {
			returnValue = returnValue->getNext();
			}
		return returnValue;
		}
	return 0;
	}
template <class T>
List<T>::~List() {
	Node<T>* nextValue = first;
	while(nextValue) {
		Node<T>* deleteThis = nextValue;
		nextValue = deleteThis->getNext();
		delete deleteThis;
		}
	}

#endif