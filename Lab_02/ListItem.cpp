#include "ListItem.h"
#include "Hexagon.h"



ListItem::ListItem() {
	this->hex = Hexagon();
	this->next = nullptr;
}

ListItem::ListItem(const Hexagon& hexagon){
	this->hex = hexagon;
	this->next = nullptr;
	//std::cout << "ListItem created." << std::endl;
}

ListItem::ListItem(const ListItem& item) {
	this->hex = item.hex;
	this->next = item.next;
	//std::cout << "ListItem copied." << std::endl;
}

ListItem* ListItem::SetNext(ListItem* new_next) {
	ListItem* old = this->next;
	this->next = new_next;
	return old;
}

ListItem* ListItem::GetNext() {
	return this->next;
}

Hexagon ListItem::GetHex() const{
	return this->hex;
}

std::ostream& operator << (std::ostream& os, const ListItem& item) {
	os <<"[" << item.hex << "]";
	return os;
}

ListItem::~ListItem(){
	std::cout << "ListItem deleted." << std::endl;
	if (next != nullptr) {
		delete next;
	}
}
