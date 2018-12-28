#pragma once
#ifndef _Octagon_h_ 
#define _Octagon_h_
#include <iostream>
class Octagon
{
public:
	Octagon();
	Octagon(int a);
	Octagon(const Octagon& orig);

	friend std::ostream& operator << (std::ostream& os, const Octagon& octagon);

	Octagon& operator = (const Octagon& right);
	bool operator == (const Octagon& right);

	virtual ~Octagon();
private:
	int side;
};
#endif