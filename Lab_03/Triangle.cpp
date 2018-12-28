#include "Triangle.h"
#include <iostream>


Triangle::Triangle(){
	side_a = 0;
	side_b = 0;
	side_c = 0;
	std::cout << "Created def. Triangle" << std::endl;
}

Triangle::Triangle(int a, int b, int c) {
	side_a = a;
	side_b = b;
	side_c = c;
}

Triangle::Triangle(const Triangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
	std::cout << "Triangle copied" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Triangle& tri) {
	os << "[Triangle.a=" << tri.side_a << " b=" << tri.side_b << " c=" << tri.side_c << "]";
	return os;
}

Triangle& Triangle::operator= (const Triangle& right) {
	if (this == &right) {
		return *this;
	}
	this->side_a = right.side_a;
	this->side_b = right.side_b;
	this->side_c = right.side_c;
	return *this;
}

bool Triangle::operator== (const Triangle& right) {
	if ((side_a == right.side_a) && (side_b == right.side_b) && (side_c == right.side_c)) {
		return true;
	}
	return false;
}

Triangle::~Triangle(){
	std::cout << "Triangle deleted." << std::endl;
}
