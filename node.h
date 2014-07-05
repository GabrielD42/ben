#ifndef NODE_H
#define NODE_H

/**
 * Node class for linked list. should not be implemented.
 */
template <class T>
class Node {
	public:
		/**
		 * initializes the variables. will take over control of tempData, so it must be allocated dynamically
		 */
		Node(T* tempData);
		/**
		 * set what the node after this one is. the operation will fail if object isn't a valid pointer
		 *
		 * @param object the node after this one
		 * @return wether or not this was sucessful
		 */
		bool setNext(Node<T>* object);
		/**
		 * get the address of the next node
		 * @return the address of the next node
		 */
		Node<T>* getNext();
		/**
		 * Returns a pointer to the data stored in this Node
		 * @return address of data
		 */
		T* getData();
		~Node();
	private:
		Node<T>* next;
		T* data;
	};

template <class T>
Node<T>::Node(T* tempData) {
	next = 0;
	data = tempData;
	}
template <class T>
bool Node<T>::setNext(Node<T>* object) {
	if(object != 0) {
		next = object;
		return true;
		}
	return false;
	}
template <class T>
Node<T>* Node<T>::getNext() {
	return next;
	}
template <class T>
T* Node<T>::getData() {
	return data;
	}
template <class T>
Node<T>::~Node() {
	delete data;
	}

#endif