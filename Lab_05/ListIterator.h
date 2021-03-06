#pragma once
#ifndef _ListIterator_h_
#define _ListIterator_h_
#include <memory>
#include "ListItem.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"

template <template <class, class, class> class T,class A,class B,class C> class ListIterator
{
public:
	ListIterator(std::shared_ptr <T<A, B, C>> new_node) {
		node = new_node;
	}

	std::shared_ptr<T<A, B, C>> operator *() {
		return node;
	}

	std::shared_ptr<T<A, B, C>> operator ->() {
		return node;
	}

	void operator ++ () {
		node = node->GetNext();
	}

	ListIterator<T, A, B, C> operator ++ (int a) {
		ListIterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator == (const ListIterator<T, A, B, C> &right) {
		return node == right.node;
	}

	bool operator != (const ListIterator<T, A, B, C> &right) {
		return !(*this == right);
	}

	//virtual ~ListIterator();
private:
	std::shared_ptr<T<A, B, C>> node;
};


#endif // !_ListIterator_h_
