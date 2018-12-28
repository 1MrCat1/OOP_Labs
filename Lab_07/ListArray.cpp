#include "ListArray.h"



template<template<class, class, class> class T, class A, class B, class C> ListArray<T,A,B,C>::ListArray(){
	//data = (std::shared_ptr<T<A,B,C>>*) malloc(sizeof(std::shared_ptr<T<A, B, C>>) * 5);
	freeSpace = 5;
	next = nullptr;
}

template<template<class, class, class> class T, class A, class B, class C> void ListArray<T, A, B, C>::Add(std::shared_ptr<T<A, B, C>> Newitem) {
	data[5 - freeSpace] = Newitem;
	freeSpace--;
	Sort();
}

template<template<class, class, class> class T, class A, class B, class C> std::shared_ptr<A> ListArray<T, A, B, C>::Extract_ffigure(int position2) {
	return data[position2]->GetFFigure();
}

template<template<class, class, class> class T, class A, class B, class C> std::shared_ptr<B> ListArray<T, A, B, C>::Extract_sfigure(int position2) {
	return data[position2]->GetSFigure();
}

template<template<class, class, class> class T, class A, class B, class C> std::shared_ptr<C> ListArray<T, A, B, C>::Extract_tfigure(int position2) {
	return data[position2]->GetTFigure();
}

template<template<class, class, class> class T, class A, class B, class C> int ListArray<T, A, B, C>::GetFreeSpace() {
	return freeSpace;
}

template<template<class, class, class> class T, class A, class B, class C> void ListArray<T, A, B, C>::SetNext(std::shared_ptr<ListArray<T, A, B, C>> newNext) {
	next = newNext;
}

template<template<class, class, class> class T, class A, class B, class C> std::shared_ptr<ListArray<T,A,B,C>> ListArray<T, A, B, C>::GetNext() {
	return next;
}

template<template<class, class, class> class T, class A, class B, class C> void ListArray<T, A, B, C>::Sort() {
	for (int j = 1; j < 5 - freeSpace; j++) {
		for (int i = 0; i < 4 - freeSpace; ++i) {
			if (data[i]->GetSquare() > data[i + 1]->GetSquare()) {
				std::swap(data[i], data[i + 1]);
			}
		}
	}
}

template<template<class, class, class> class T, class A, class B, class C> bool ListArray<T, A, B, C>::Remove_figure(const T<A, B, C>& figure) {
	for (int i = 0; i < 5 - freeSpace; i++) {
		if (*data[i] == figure) {
			data[i]->~ListItem();
			for (int j = i; j < 4 - freeSpace; j++) {
				std::swap(data[j],data[j + 1]);
			}
			freeSpace++;
			return true;
		}
	}
	return false;
}

template<template<class, class, class> class T, class A, class B, class C> void ListArray<T, A, B, C>::Remove_all() {
	for (int i = 0; i < 5 - freeSpace; i++) {
		data[i]->~ListItem();
	}
	freeSpace = 5;
}

template<template<class, class, class> class T, class A, class B, class C> void ListArray<T, A, B, C>::Remove_by_square(int mode, double square) {
	switch (mode) {
	case(1):
		for (int i = 0; i < 5 - freeSpace; i++) {
			if (data[i]->GetSquare() > square) {
				data[i]->~ListItem();
				for (int j = i; j < 4 - freeSpace; j++) {
					std::swap(data[j], data[j + 1]);
				}
				freeSpace++;
			}
		}
		break;
	case(2):
		for (int i = 0; i < 5 - freeSpace; i++) {
			if (data[i]->GetSquare() < square) {
				data[i]->~ListItem();
				for (int j = i; j < 4 - freeSpace; j++) {
					std::swap(data[j], data[j + 1]);
				}
				freeSpace++;
			}
		}
		break;
	default:
		std::cout << "Wrong mode" << std::endl;
		break;
	}
}

template<template<class, class, class> class T, class A, class B, class C> void ListArray<T, A, B, C>::Remove_by_type(int type) {
	switch (type){
	case(1):
		for (int i = 0; i < 5 - freeSpace; i++) {
			if (data[i]->GetFFigure() != nullptr) {
				data[i]->~ListItem();
				for (int j = i; j < 4 - freeSpace; j++) {
					std::swap(data[j], data[j + 1]);
				}
				freeSpace++;
			}
		}
		break;
	case(2):
		for (int i = 0; i < 5 - freeSpace; i++) {
			if (data[i]->GetSFigure() != nullptr) {
				data[i]->~ListItem();
				for (int j = i; j < 4 - freeSpace; j++) {
					std::swap(data[j], data[j + 1]);
				}
				freeSpace++;
			}
		}
		break;
	case(3):
		for (int i = 0; i < 5 - freeSpace; i++) {
			if (data[i]->GetTFigure() != nullptr) {
				data[i]->~ListItem();
				for (int j = i; j < 4 - freeSpace; j++) {
					std::swap(data[j], data[j + 1]);
				}
				freeSpace++;
			}
		}
		break;
	default:
		break;
	}
}

template<template<class, class, class> class L, class A, class B, class C> std::ostream& operator << (std::ostream& os, const ListArray<L, A, B, C>& arr) {
	for (int i = 0; i < 5 - arr.freeSpace; i++) {
		os << "|" << i << "=" << *arr.data[i]<<"|";
	}
	return os;
}

template<template<class, class, class> class T, class A, class B, class C> ListArray<T, A, B, C>::~ListArray(){
}

template class ListArray<ListItem, Triangle, Hexagon, Octagon>;
template std::ostream& operator << (std::ostream& os, const ListArray<ListItem, Triangle, Hexagon, Octagon>& item);