#pragma once
#ifndef _List_h_
#define _List_h_
#include <memory>
#include "ListItem.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"
class List{
public:
	List();

	bool Empty();
	int GetSize();
	void Add_Triangle(std::shared_ptr<Triangle> &&triangle);
	void Add_Hexagon(std::shared_ptr<Hexagon> &&hexagon);
	void Add_Octagon(std::shared_ptr<Octagon> &&octagon);
	std::shared_ptr<Triangle> Extract_triangle(int position);
	std::shared_ptr<Hexagon> Extract_hexagon(int position);
	std::shared_ptr<Octagon> Extract_octagon(int position);
	void Remove_triangle(const Triangle& triangle);
	void Remove_hexagon(const Hexagon& hexagon);
	void Remove_octagon(const Octagon& octagon);

	friend std::ostream& operator << (std::ostream& os, const List& list);

	virtual ~List();
private:
	std::shared_ptr<ListItem> head;
	int size;
};

#endif