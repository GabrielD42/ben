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
		 * adds the argument to the appropriate position in the list based on its comparison operators, as long as it is not already in the list. object must be allocated on heap. takes over control of object, ie DO NOT DELETE OBJECT
		 *
		 * @param object the address of the object to be added to the list
		 *
		 * @return  if it was successful
		 */
		bool add(Node<T>* object);
	};

template <class T>
bool OrderedList<T>::add(Node<T>* object) {
	for(int i = 0; i < length(); i++) {
		if(&object.data == &get(i).data) {
			return false;
			}
		}
	OrderedList::add(object);
	}

#endif