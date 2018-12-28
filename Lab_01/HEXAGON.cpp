#include <iostream>
#include <cmath>
#include "HEXAGON.h"

HEXAGON::HEXAGON(std::istream &is)
{
	is >> side_a;
}

HEXAGON::HEXAGON(int a) {
	side_a = a;
}

double HEXAGON::SQUARE() {
	return 3*sqrt(3)*pow(side_a,2)/2;
}

void HEXAGON::PRINT() {
	std::cout << "FIGURE - Regular hexagon" << std::endl << "side=" << side_a << std::endl;
}

HEXAGON::~HEXAGON()
{
	std::cout << "Regular hexagon deleted" << std::endl;
}