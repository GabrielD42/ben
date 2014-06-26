#ifndef NODE_H
#define NODE_H


/**
 * Node class for linked list. should not be implemented.
 */
class Node {
	public:
		/**
		 * initializes the variables
		 */
		Node();
		/**
		 * set what the node after this one is. the operation will fail if object isn't a valid pointer or if `next` is already set
		 *
		 * @param object the node after this one
		 * @return wether or not this was sucessful
		 */
		bool setNext(Node* object);
		/**
		 * get the address of the next node
		 * @return the address of the next node
		 */
		Node* getNext();
	private:
		Node* next;
	};

#endif