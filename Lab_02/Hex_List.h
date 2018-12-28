#pragma once
#ifndef  Hex_List_h
#define Hex_List_h
#include "ListItem.h"
#include "Hexagon.h"
#include <iostream>

class Hex_List{
public:
	Hex_List();
	Hex_List(const Hex_List& list);

	bool Empty();
	void Add(Hexagon &&hexagon);
	Hexagon Extract(int position);
	bool Remove(const Hexagon& hexagon);
	int GetSize();

	friend std::ostream& operator << (std::ostream& os, const Hex_List& list);

	virtual ~Hex_List();

private:
	ListItem* head;
	int size;
};

#endif // ! Hex_List_h
