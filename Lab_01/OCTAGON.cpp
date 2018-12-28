#include <iostream>
#include <cmath>
#include "OCTAGON.h"

OCTAGON::OCTAGON(std::istream &is)
{
	is >> side_a;
}

OCTAGON::OCTAGON(int a) {
	side_a = a;
}

double OCTAGON::SQUARE() {
	return 2 * (1 + sqrt(2))*side_a*side_a;
}

void OCTAGON::PRINT() {
	std::cout << "FIGURE - Regular octagon" << std::endl << "side=" << side_a << std::endl;
}

OCTAGON::~OCTAGON()
{
	std::cout << "Regular octagon deleted" << std::endl;
}
