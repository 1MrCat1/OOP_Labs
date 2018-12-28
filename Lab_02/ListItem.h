#pragma once
#ifndef ListItem_h
#define ListItem_h
#include "Hexagon.h"
#include <iostream>

class ListItem{
public:
	ListItem();
	ListItem(const Hexagon& hexagon);
	ListItem(const ListItem& item);

	ListItem* SetNext(ListItem* new_next);
	ListItem* GetNext();
	Hexagon GetHex() const;

	friend std::ostream& operator << (std::ostream& os, const ListItem& item);

	virtual ~ListItem();
private:
	ListItem* next;
	Hexagon hex;
};
#endif

