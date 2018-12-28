#pragma once
#ifndef _ListItem_h_
#define _ListItem_h_
#include <memory>
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"

template <class A,class B,class C> class ListItem {
public:
	ListItem();
	ListItem(const std::shared_ptr<A>& figure);
	ListItem(const std::shared_ptr<B>& oct);
	ListItem(const std::shared_ptr<C>& hex);

	void SetNext(std::shared_ptr<ListItem> new_next);
	std::shared_ptr<ListItem<A, B, C>> GetNext();
	std::shared_ptr<A> GetFFigure() const;
	std::shared_ptr<B> GetSFigure() const;
	std::shared_ptr<C> GetTFigure() const;

	template <class D,class E,class F> friend std::ostream& operator << (std::ostream& os, const ListItem<D,E,F>& item);
	bool operator == (const ListItem<A, B, C> &right);
	virtual ~ListItem();
private:
	std::shared_ptr<A> ffigure;
	std::shared_ptr<B> sfigure;
	std::shared_ptr<C> tfigure;
	std::shared_ptr<ListItem> next;
};

#endif