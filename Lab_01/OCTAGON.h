#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include <iostream>
#include "FIGURE.h"

class OCTAGON :	public FIGURE{
public:
	OCTAGON(std::istream &is);
	OCTAGON(int a);

	double SQUARE() override;
	void PRINT() override;

	virtual ~OCTAGON();

private:
	int side_a;
};
#endif // !OCTAGON_H
