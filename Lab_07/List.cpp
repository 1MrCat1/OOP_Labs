#include "List.h"
#include <iostream>

template <template <template <class, class, class> class, class, class, class> class T, template <class, class, class> class L, class A, class B, class C>  List<T, L, A, B, C>::List() {
	//std::shared_ptr<ListItem<NULL>> item(new ListItem<NULL>());
	head = nullptr;
	size = 0;
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> bool List<T, L, A, B, C>::Empty() {
	return (size == 0);
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> int List<T, L, A, B, C>::GetSize() {
	return size;
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> void List<T, L, A, B, C>::Add_figure(std::shared_ptr<L<A, B, C>> Newitem) {
	if (this->head == nullptr) {
		std::shared_ptr<T<L, A, B, C>> newArray(new T<L,A,B,C>);
		newArray->Add(Newitem);
		this->head = newArray;
		this->size++;
	}
	else {
		std::shared_ptr<T<L, A, B, C>> iter = this->head;
		while (1) {
			if (iter->GetFreeSpace() != 0) {
				iter->Add(Newitem);
				return;
			}
			if (iter->GetNext() != nullptr) {
				iter = iter->GetNext();
			}
			else {
				std::shared_ptr<T<L, A, B, C>> newArray(new T<L, A, B, C>);
				newArray->Add(Newitem);
				iter->SetNext(newArray);
				this->size++;
				return;
			}
		}
	}
}


template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> std::shared_ptr<A> List<T, L, A, B, C>::Extract_ffigure(int position,int position2) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	if (position2 < (5 - iter->GetFreeSpace())) {
		return iter->Extract_ffigure(position2);
	}
	else {
		std::cout << "Wrong position of element" << std::endl;
		return nullptr;
	}
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> std::shared_ptr<B> List<T, L, A, B, C>::Extract_sfigure(int position, int position2) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	if (position2 < (5 - iter->GetFreeSpace())) {
		return iter->Extract_sfigure(position2);
	}
	else {
		std::cout << "Wrong position of element" << std::endl;
		return nullptr;
	}
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> std::shared_ptr<C> List<T, L, A, B, C>::Extract_tfigure(int position, int position2) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	if (position2 < (5 - iter->GetFreeSpace())) {
		return iter->Extract_tfigure(position2);
	}
	else {
		std::cout << "Wrong position of element" << std::endl;
		return nullptr;
	}
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> void List<T, L, A, B, C>::Remove_figure(const L<A, B, C>& fig) {
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	while (iter != nullptr) {
		if (iter->Remove_figure(fig)) {
			return;
		}
		iter = iter->GetNext();
	}
	std::cout << "No element to delete" << std::endl;
}

template <template <template <class, class, class> class, class, class, class> class T, template <class, class, class> class L, class A, class B, class C> void List<T, L, A, B, C>::Remove_all() {
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	std::shared_ptr<T<L, A, B, C>> prev = this->head;
	while (iter != nullptr) {
		iter->Remove_all();
		iter = iter->GetNext();
		prev->~ListArray();
		prev = iter;
	}
	this->head = nullptr;
	this->size = 0;
}

template <template <template <class, class, class> class, class, class, class> class T, template <class, class, class> class L, class A, class B, class C> void List<T, L, A, B, C>::Remove_by_square(int mode, double square) {
	std::shared_ptr<T<L, A, B, C>> prev = this->head;
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	while (iter != nullptr) {
		iter->Remove_by_square(mode, square);
		if (iter->GetFreeSpace() == 5) {
			if (iter == this->head) {
				this->head = iter->GetNext();
			}
			else {
				prev->SetNext(iter->GetNext());
			}
			iter->~ListArray();
		}
		if (iter != this->head) {
			prev = iter;
		}
		iter = iter->GetNext();
	}
}

template <template <template <class, class, class> class, class, class, class> class T, template <class, class, class> class L, class A, class B, class C> void List<T, L, A, B, C>::Remove_by_type(int type) {
	std::shared_ptr<T<L, A, B, C>> prev = this->head; 
	std::shared_ptr<T<L, A, B, C>> iter = this->head;
	while (iter != nullptr) {
		iter->Remove_by_type(type);
		if (iter->GetFreeSpace() == 5) {
			if (iter == this->head) {
				this->head = iter->GetNext();
			}
			else {
				prev->SetNext(iter->GetNext());
			}
			iter->~ListArray();
		}
		if (iter != this->head) {
			prev = iter;
		}
		iter = iter->GetNext();
	}
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> ListIterator<T, L, A, B, C> List<T, L, A, B, C>::begin() {
	return ListIterator<T, L, A, B, C>(head);
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> ListIterator<T, L, A, B, C> List<T, L, A, B, C>::end() {
	return ListIterator<T, L, A, B, C>(nullptr);
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> std::ostream& operator << (std::ostream& os, const List<T, L, A, B, C>& list) {
	std::shared_ptr<T<L,A, B, C>> iter = list.head;
	os << "Printing list: |";
	while (iter != nullptr) {
		os << *iter << std::endl;
		iter = iter->GetNext();
	}
	os << "|." << std::endl;
	return os;
}

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C>  List<T, L, A, B, C>::~List() {
	std::cout << "List deleted" << std::endl;
}

template class List<ListArray, ListItem, Triangle, Hexagon, Octagon>;
template std::ostream& operator << (std::ostream& os, const List<ListArray,ListItem, Triangle, Hexagon, Octagon>& list);