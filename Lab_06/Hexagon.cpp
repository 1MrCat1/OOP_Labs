#include "Hexagon.h"


Hexagon::Hexagon() {
	side = 0;
	std::cout << "Created def. Hexagon" << std::endl;
}

Hexagon::Hexagon(int a) {
	side = a;
}

Hexagon::Hexagon(const Hexagon& orig) {
	side = orig.side;
	std::cout << "Hexagon copied" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Hexagon& hex) {
	os << "[Hexagon.Side=" << hex.side << "]";
	return os;
}

Hexagon& Hexagon::operator= (const Hexagon& right) {
	if (this == &right) {
		return *this;
	}
	this->side = right.side;
	return *this;
}

bool Hexagon::operator == (const Hexagon& right) {
	if (side == right.side) {
		return true;
	}
	return false;
}

Hexagon::~Hexagon() {
	std::cout << "Hexagon deleted." << std::endl;
}

