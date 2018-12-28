#pragma once
#ifndef _ListArray_h_
#define _ListArray_h_

#include <iostream>
#include <memory>
#include "ListItem.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"


template<template<class,class,class> class T,class A,class B,class C> class ListArray{
public:
	ListArray();

	void Add(std::shared_ptr<T<A, B, C>> Newitem);

	std::shared_ptr<A> Extract_ffigure(int position2);
	std::shared_ptr<B> Extract_sfigure(int position2);
	std::shared_ptr<C> Extract_tfigure(int position2);

	int GetFreeSpace();
	void SetNext(std::shared_ptr<ListArray> newNext);
	std::shared_ptr<ListArray> GetNext();
	void Sort();

	bool Remove_figure(const T<A, B, C>& triangle);
	void Remove_all();
	void Remove_by_square(int mode, double square);
	void Remove_by_type(int type);

	template <template<class, class, class> class H, class E, class F, class G> friend std::ostream& operator << (std::ostream& os, const ListArray<H, E, F, G>& arr);

	~ListArray();
private:
	std::shared_ptr<T<A,B,C>> data[5];
	int freeSpace;
	std::shared_ptr<ListArray> next;
};

#endif