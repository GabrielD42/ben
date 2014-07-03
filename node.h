#ifndef NODE_H
#define NODE_H

/**
 * Node class for linked list. should not be implemented.
 */
template <class T>
class No+de {
	public:
		/**
		 * initializes the variables
		 */
		Node(T* tempData);
		/**
		 * set what the node after this one is. the operation will fail if object isn't a valid pointer or if `next` is already set
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
	private:
		Node<T>* next;
		T* data;
	};

Node<T>::Node(T* tempData) {
	next = 0;
	data = tempData;
	}
bool Node<T>::setNext(Node<T>* object) {
	if(next == 0 && object != 0) {
		next = object;
		return true;
		}
	return false;
	}
Node<T>* Node<T>::getNext() {
	return next;
	}
T* Node<T>::getData() {
	return data;
	}

#endif