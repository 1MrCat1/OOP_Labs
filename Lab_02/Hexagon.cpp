#include "Hexagon.h"
#include <iostream>
#include <cmath>


Hexagon::Hexagon(){
	this->side = 0;
}

Hexagon::Hexagon(int a) {
	if (a <= 0) {
		std::cout << "Side less then 0. Set to 0." << std::endl;
		this->side = 0;
	}
	else {
		this->side = a;
	}
}

Hexagon::Hexagon(const Hexagon& hex) {
	side = hex.side;
	//std::cout << "Hex copy created." << std::endl;
}

double Hexagon::Square() {
	return 3 * sqrt(3)*pow(side, 2) / 2;
}

std::ostream& operator << (std::ostream& os, const Hexagon& hex) {
	os << "Side=" << hex.side ;
	return os;
}

std::istream& operator >> (std::istream& is, Hexagon& hex) {
	is >> hex.side;
	return is;
}

Hexagon& Hexagon::operator = (const Hexagon& hex) {
	if (this == &hex) {
		return *this;
	}
	//std::cout << "Hex copy created by equality." << std::endl;
	side = hex.side;
	return *this;
}

bool Hexagon::operator== (const Hexagon& hex) {
	if (side == hex.side) {
		return true;
	}
	else return false;
}


Hexagon::~Hexagon()
{
}
