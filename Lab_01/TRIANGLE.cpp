#include <iostream>
#include <cmath>
#include "TRIANGLE.h"

TRIANGLE::TRIANGLE(std::istream &is)
{
	is >> side_a;
	is >> side_b;
	is >> side_c;
}

TRIANGLE::TRIANGLE(int a, int b, int c) {
	side_a = a;
	side_b = b;
	side_c = c;
}

double TRIANGLE::SQUARE() {
	double p = double(side_a + side_b + side_c) / 2;
	if (sqrt(p*(p - side_a)*(p - side_b)*(p - side_c)) > 0) {
		return sqrt(p*(p - side_a)*(p - side_b)*(p - side_c));
	}
	else {
		return 0;
	}
}

void TRIANGLE::PRINT() {
	std::cout << "FIGURE - Triangle" << std::endl << "a=" << side_a << std::endl << "b=" << side_b << std::endl << "c=" << side_c << std::endl;
}
TRIANGLE::~TRIANGLE()
{
	std::cout << "Triangle deleted" << std::endl;
}
