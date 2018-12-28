#include "Octagon.h"
#include <cmath>

Octagon::Octagon() {
	side = 0;
	std::cout << "Created def. Octagon" << std::endl;
}

Octagon::Octagon(int a) {
	side = a;
}

Octagon::Octagon(const Octagon& orig) {
	side = orig.side;
	std::cout << "Octagon copied" << std::endl;
}

double Octagon::Square() {
	return 2 * (1 + sqrt(2))*side*side;
}

std::ostream& operator << (std::ostream& os, const Octagon& oct) {
	os << "[Octagon.Side=" << oct.side << "]";
	return os;
}

Octagon& Octagon::operator= (const Octagon& right) {
	if (this == &right) {
		return *this;
	}
	this->side = right.side;
	return *this;
}

bool Octagon::operator == (const Octagon& right) {
	if (side == right.side) {
		return true;
	}
	return false;
}

Octagon::~Octagon() {
	std::cout << "Octagon deleted." << std::endl;
}
