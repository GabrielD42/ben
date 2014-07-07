#ifndef UNIQUE_LIST_H
#define UNIQUE_LIST_H

#include "orderedList.h"
#include "list.h"
#include "node.h"

/**
 * This type of list ensures that each piece of data can only be stored in the list once. to do this it keeps all its members ordered, from smallest to largest, using the data's comparision operators
 *
 * @tparam T the type of data to be stored in the list
 */
template <class T>
class UniqueList : public OrderedList<T> {
	public:
		/**
		 * adds the argument to the appropriate position in the list based on its comparison operators, as long as it is not already in the list
		 *
		 * @param the piece of data to be added to the list
		 */
		void add(T data);
	};

template <class T>
void UniqueList<T>::add(T data) {
	for(int i = 0; i < List<T>::length(); i++) {
		if(data == *(List<T>::get(i)->getData())) {
			return;
			}
		}
	T newData = new T(data);
	Node<T> newNode = new Node<T>(&newData);
	OrderedList<T>::add(newNode);
	}

#endif