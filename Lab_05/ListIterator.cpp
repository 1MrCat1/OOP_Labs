/*#include "ListIterator.h"
template <template <class, class, class> class T, class A, class B, class C> ListIterator<T, A, B, C>::ListIterator(std::shared_ptr <T<A, B, C>> new_node){
 node = new_node;
}

template <template <class, class, class> class T, class A, class B, class C> std::shared_ptr<T<A, B, C>> ListIterator<T,A,B,C>::operator *() {
	return *node;
}

template <template <class, class, class> class T, class A, class B, class C> std::shared_ptr<T<A, B, C>> ListIterator<T, A, B, C>::operator ->() {
	return *node;
}


template <template <class, class, class> class T, class A, class B, class C> void ListIterator<T, A, B, C>::operator ++ () {
	return node->GetNext();
}
template <template <class, class, class> class T, class A, class B, class C> ListIterator<T,A,B,C> ListIterator<T, A, B, C>::operator ++ (int a) {
	ListIterator iter(*this);
	++(*this);
	return iter;
}

template <template <class, class, class> class T, class A, class B, class C> bool ListIterator<T, A, B, C>::operator == (const ListIterator<T,A,B,C> &right) {
	return node == right.node;
}
template <template <class, class, class> class T, class A, class B, class C> bool ListIterator<T, A, B, C>::operator != (const ListIterator<T, A, B, C> &right) {
	return !(this == right);
}*/