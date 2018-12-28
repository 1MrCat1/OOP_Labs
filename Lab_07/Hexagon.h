#pragma once
#ifndef _Hexagon_h_ 
#define _Hexagon_h_
#include <iostream>

class Hexagon
{
public:
	Hexagon();
	Hexagon(int a);
	Hexagon(const Hexagon& orig);

	double Square();

	friend std::ostream& operator << (std::ostream& os, const Hexagon& hexagon);

	Hexagon& operator = (const Hexagon& right);
	bool operator == (const Hexagon& right);

	virtual ~Hexagon();
private:
	int side;
};
#endif