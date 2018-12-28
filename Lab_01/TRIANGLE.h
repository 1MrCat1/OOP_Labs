#ifndef TRIANGLE_H
#define	TRIANGLE_H
#include <cstdlib>
#include <iostream>
#include "FIGURE.h"

class TRIANGLE : public FIGURE {
public:
	TRIANGLE(std::istream &is);
	TRIANGLE(int a, int b, int c);

	double SQUARE() override;
	void PRINT() override;

	virtual ~TRIANGLE();
private:
	int side_a;
	int side_b;
	int side_c;
};
#endif