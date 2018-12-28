#pragma once
#ifndef HEXAGON_H
#define HEXAGON_H
#include <iostream>

class Hexagon{
public:
	Hexagon();
	Hexagon(int a);
	Hexagon(const Hexagon& orig);

	double Square();

	friend std::ostream& operator << (std::ostream& os, const Hexagon& hex);
	friend std::istream& operator >> (std::istream& is, Hexagon& hex);

	Hexagon& operator = (const Hexagon& hex);
	bool operator == (const Hexagon& hex);

	~Hexagon();
private:
	int side;
};

#endif