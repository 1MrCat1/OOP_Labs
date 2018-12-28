#ifndef HEXAGON_H
#define HEXAGON_H

#include <cstdlib>
#include <iostream>
#include "FIGURE.h"

class HEXAGON : public FIGURE {
public:
	HEXAGON(std::istream &is);
	HEXAGON(int a);

	double SQUARE() override;
	void PRINT() override;

	~HEXAGON();

private:
	int side_a;
};

#endif

