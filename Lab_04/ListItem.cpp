#include "ListItem.h"
#include <memory>

template <class A,class B,class C> ListItem<A,B,C>::ListItem() {
	//this->ffigure = nullptr;
	//this->octagon = nullptr;
	//this->hexagon = nullptr;
	//this->next = nullptr;
	std::cout << "Null-item created" << std::endl;
}
template <class A,class B,class C> ListItem<A,B,C>::ListItem(const std::shared_ptr<A>& figure) {
	this->ffigure = figure;
	this->sfigure = nullptr;
	this->tfigure = nullptr;
	this->next = nullptr;
	std::cout <<"Figure item created" << std::endl;
}
template <class A,class B,class C> ListItem<A,B,C>::ListItem(const std::shared_ptr<B>& figure) {
	this->ffigure = nullptr;
	this->sfigure = figure;
	this->tfigure = nullptr;
	this->next = nullptr;
	std::cout << "Second item created" << std::endl;
}
template <class A,class B,class C> ListItem<A,B,C>::ListItem(const std::shared_ptr<C>& figure) {
	this->ffigure = nullptr;
	this->sfigure = nullptr;
	this->tfigure = figure;
	this->next = nullptr;
	std::cout << "Third item created" << std::endl;
}

template<class A, class B, class C> void ListItem<A,B,C>::SetNext(std::shared_ptr<ListItem> new_next) {
	std::shared_ptr<ListItem> old = this->next;
	this->next = new_next;
}
template <class A,class B,class C> std::shared_ptr<ListItem<A, B, C>> ListItem<A,B,C>::GetNext() {
	return this->next;
}

template <class A,class B,class C> std::shared_ptr<A> ListItem<A,B,C>::GetFFigure() const {
	return this->ffigure;
}
template <class A,class B,class C> std::shared_ptr<B> ListItem<A,B,C>::GetSFigure() const {
	return this->sfigure;
}
template <class A,class B,class C> std::shared_ptr<C> ListItem<A,B,C>::GetTFigure() const {
	return this->tfigure;
}

template <class D, class E, class F> std::ostream& operator << (std::ostream& os, const ListItem<D, E, F>& item){
	if (item.ffigure != nullptr) {
		os << "{" << *item.ffigure << "}" << std::endl;
		return os;
	}
	if (item.sfigure != nullptr) {
		os << "{" << *item.sfigure << "}" << std::endl;
		return os;
	}
	if (item.tfigure != nullptr) {
		os << "{" << *item.tfigure << "}" << std::endl;
		return os;
	}
	os << "Empty element" << std::endl;
	return os;
}
template <class A,class B,class C> bool ListItem<A,B,C>::operator ==(const ListItem<A, B, C>& right) {
	if ((this->GetFFigure() != nullptr) && (right.GetFFigure() != nullptr)) {
		if (*this->GetFFigure() == *right.GetFFigure()) {
			return true;
		}
		else return false;
	}
	if ((this->GetSFigure() != nullptr) && (right.GetSFigure() != nullptr)) {
		if (*this->GetSFigure() == *right.GetSFigure()) {
			return true;
		}
		else return false;
	}
	if ((this->GetTFigure() != nullptr) && (right.GetTFigure() != nullptr)) {
		if (*this->GetTFigure() == *right.GetTFigure()) {
			return true;
		}
		else return false;
	}
	return false;
}

template <class A,class B,class C> ListItem<A,B,C>::~ListItem() {
	std::cout << "ListItem deleted" << std::endl;
}

template class ListItem<Triangle,Hexagon,Octagon>;
//template class ListItem<Triangle>;
//template class ListItem<Octagon>;
template std::ostream& operator << (std::ostream& os, const ListItem<Triangle,Hexagon,Octagon>& item);
//template std::ostream& operator << (std::ostream& os, const ListItem<Hexagon>& item);
//template std::ostream& operator << (std::ostream& os, const ListItem<Octagon>& item);