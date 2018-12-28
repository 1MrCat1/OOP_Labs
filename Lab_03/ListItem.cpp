#include "ListItem.h"
#include <memory>

ListItem::ListItem() {
	this->triangle = nullptr;
	this->octagon = nullptr;
	this->hexagon = nullptr;
	this->next = nullptr;
	std::cout << "Null-item created" << std::endl;
}
ListItem::ListItem(const std::shared_ptr<Triangle>& tri) {
	this->triangle = tri;
	this->octagon = nullptr;
	this->hexagon = nullptr;
	this->next = nullptr;
	std::cout << "Triangle item created" << std::endl;
}
ListItem::ListItem(const std::shared_ptr<Octagon>& oct) {
	this->triangle = nullptr;
	this->octagon = oct;
	this->hexagon = nullptr;
	this->next = nullptr;
	std::cout << "Octagon item created" << std::endl;
}
ListItem::ListItem(const std::shared_ptr<Hexagon>& hex) {
	this->triangle = nullptr;
	this->octagon = nullptr;
	this->hexagon = hex;
	this->next = nullptr;
	std::cout << "Hexagon item created" << std::endl;
}

std::shared_ptr<ListItem> ListItem::SetNext(std::shared_ptr<ListItem> new_next) {
	std::shared_ptr<ListItem> old = this->next;
	this->next = new_next;
	return old;
}
std::shared_ptr<ListItem> ListItem::GetNext() {
	return this->next;
}
std::shared_ptr<Triangle> ListItem::GetTriangle() const {
	return this->triangle;
}
std::shared_ptr<Hexagon> ListItem::GetHexagon() const {
	return this->hexagon;
}
std::shared_ptr<Octagon> ListItem::GetOctagon() const {
	return this->octagon;
}

std::ostream& operator << (std::ostream& os, const ListItem& item) {
	if (item.triangle != nullptr) {
		os << "{" << *item.triangle << "}" << std::endl;
		return os;
	}
	if (item.hexagon != nullptr) {
		os << "{" << *item.hexagon << "}" << std::endl;
		return os;
	}
	if (item.octagon != nullptr) {
		os << "{" << *item.octagon << "}" << std::endl;
		return os;
	}
	os << "Empty element" << std::endl;
	return os;
}

ListItem::~ListItem() {
	std::cout << "ListItem deleted" << std::endl;
}