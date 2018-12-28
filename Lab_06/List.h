#pragma once
#ifndef _List_h_
#define _List_h_
#include <memory>
#include "ListItem.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"
#include "ListIterator.h"

template <template <class, class, class> class T, class A, class B, class C> class List {
public:
	List();

	bool Empty();
	int GetSize();
	void Add_figure(std::shared_ptr <T<A, B, C>> &&figure);
	std::shared_ptr<A> Extract_ffigure(int position);
	std::shared_ptr<B> Extract_sfigure(int position);
	std::shared_ptr<C> Extract_tfigure(int position);
	void Remove_figure(const T<A, B, C>& triangle);

	ListIterator<T, A, B, C> begin();
	ListIterator<T, A, B, C> end();

	template <template <class, class, class> class D, class E, class F, class G> friend std::ostream& operator << (std::ostream& os, const List<D, E, F, G>& list);

	virtual ~List();
private:
	std::shared_ptr <T<A, B, C>> head;
	int size;
};

#endif
