#pragma once
#ifndef _List_h_
#define _List_h_
#include <memory>
#include "ListArray.h"
#include "ListItem.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"
#include "ListIterator.h"

template <template <template <class,class,class> class, class, class, class> class T,template <class,class,class> class L, class A, class B, class C> class List {
public:
	List();

	bool Empty();
	int GetSize();
	void Add_figure(std::shared_ptr<L<A, B, C >> Newitem);
	std::shared_ptr<A> Extract_ffigure(int position1,int position2);
	std::shared_ptr<B> Extract_sfigure(int position1, int position2);
	std::shared_ptr<C> Extract_tfigure(int position1, int position2);
	void Remove_figure(const L<A, B, C>& triangle);
	void Remove_all();
	void Remove_by_square(int mode, double criteria);
	void Remove_by_type(int type);

	ListIterator<T,L ,A, B, C> begin();
	ListIterator<T,L ,A, B, C> end();

	template <template < template<class, class, class> class,class, class, class> class D,template<class,class,class> class H, class E, class F, class G> friend std::ostream& operator << (std::ostream& os, const List<D, H, E, F, G>& list);

	virtual ~List();
private:
	std::shared_ptr <T<L,A, B, C>> head;
	int size;
};

#endif