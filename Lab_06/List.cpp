#include "List.h"
#include <iostream>

template <template <class, class, class> class T, class A, class B, class C> List<T, A, B, C>::List() {
	head = nullptr;
	size = 0;
}

template <template <class, class, class> class T, class A, class B, class C> bool List<T, A, B, C>::Empty() {
	return (size == 0);
}

template <template <class, class, class> class T, class A, class B, class C> int List<T, A, B, C>::GetSize() {
	return size;
}

template <template <class, class, class> class T, class A, class B, class C> void List<T, A, B, C>::Add_figure(std::shared_ptr <T<A, B, C>> &&figure) {
	std::shared_ptr <T<A, B, C>> item = figure;
	item->SetNext(this->head);
	this->head = item;
	this->size++;
}


template <template <class, class, class> class T, class A, class B, class C> std::shared_ptr<A> List<T, A, B, C>::Extract_ffigure(int position) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<T<A, B, C>> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	return iter->GetFFigure();
}

template <template <class, class, class> class T, class A, class B, class C> std::shared_ptr<B> List<T, A, B, C>::Extract_sfigure(int position) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<T<A, B, C>> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	return iter->GetSFigure();
}

template <template <class, class, class> class T, class A, class B, class C> std::shared_ptr<C> List<T, A, B, C>::Extract_tfigure(int position) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<T<A, B, C>> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	return iter->GetTFigure();
}

template <template <class, class, class> class T, class A, class B, class C> void List<T, A, B, C>::Remove_figure(const T<A, B, C>& fig) {
	std::shared_ptr<T<A, B, C>> prev = this->head;
	std::shared_ptr<T<A, B, C>> iter = this->head;
	while (iter != nullptr) {
		if (*iter == fig) {
			if (iter == this->head) {
				this->head = iter->GetNext();
			}
			else {
				prev->SetNext(iter->GetNext());
			}
			iter->SetNext(nullptr);
			iter->~ListItem();
			std::cout << "Element deleted" << std::endl;
			this->size--;
			return;
		}
		prev = iter;
		iter = iter->GetNext();
	}
	std::cout << "No element to delete" << std::endl;
}

template <template <class, class, class> class T, class A, class B, class C> ListIterator<T, A, B, C> List<T, A, B, C>::begin() {
	return ListIterator<T, A, B, C>(head);
}

template <template <class, class, class> class T, class A, class B, class C> ListIterator<T, A, B, C> List<T, A, B, C>::end() {
	return ListIterator<T, A, B, C>(nullptr);
}

template <template <class, class, class> class T, class A, class B, class C> std::ostream& operator << (std::ostream& os, const List<T, A, B, C>& list) {
	std::shared_ptr<ListItem<A, B, C>> iter = list.head;
	os << "Printing list: |";
	while (iter != nullptr) {
		if (iter->GetFFigure() != nullptr) {
			os << *iter->GetFFigure();
		}
		if (iter->GetSFigure() != nullptr) {
			os << *iter->GetSFigure();
		}
		if (iter->GetTFigure() != nullptr) {
			os << *iter->GetTFigure();
		}
		iter = iter->GetNext();
	}
	os << "|." << std::endl;
	return os;
}

template <template <class, class, class> class T, class A, class B, class C>  List<T, A, B, C>::~List() {
	std::cout << "List deleted" << std::endl;
}

template class List<ListItem, Triangle, Hexagon, Octagon>;
template std::ostream& operator << (std::ostream& os, const List<ListItem, Triangle, Hexagon, Octagon>& list);