#pragma once
#ifndef ListItem_h
#define ListItem_h
#include <memory>
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"

class ListItem{
public:
	ListItem();
	ListItem(const std::shared_ptr<Triangle>& tri);
	ListItem(const std::shared_ptr<Octagon>& oct);
	ListItem(const std::shared_ptr<Hexagon>& hex);

	std::shared_ptr<ListItem> SetNext(std::shared_ptr<ListItem> new_next);
	std::shared_ptr<ListItem> GetNext();
	std::shared_ptr<Triangle> GetTriangle() const;
	std::shared_ptr<Hexagon> GetHexagon() const;
	std::shared_ptr<Octagon> GetOctagon() const;

	friend std::ostream& operator << (std::ostream& os, const ListItem& item);
	virtual ~ListItem();
private:
	std::shared_ptr<Triangle> triangle;
	std::shared_ptr<Hexagon> hexagon;
	std::shared_ptr<Octagon> octagon;
	std::shared_ptr<ListItem> next;
};

#endif