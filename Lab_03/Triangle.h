#pragma once
#ifndef _Triangle_h_ 
#define _Triangle_h_
#include <iostream>
class Triangle
{
public:
	Triangle();
	Triangle(int a,int b,int c);
	Triangle(const Triangle& orig);

	friend std::ostream& operator << (std::ostream& os, const Triangle& triangle);

	Triangle& operator = (const Triangle& right);
	bool operator == (const Triangle& right);

	virtual ~Triangle();
private:
	int side_a;
	int side_b;
	int side_c;
};

#endif