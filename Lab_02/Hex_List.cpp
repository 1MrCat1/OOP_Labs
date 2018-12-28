#include "Hex_List.h"



Hex_List::Hex_List(){
	this->head = new ListItem();
	this->head->SetNext(nullptr);
	this->size = 0;
	std::cout << "List created." << std::endl;
}

Hex_List::Hex_List(const Hex_List& list) {
	this->head = list.head;
	this->size = list.size;
	std::cout << "List copy created." << std::endl;
}

bool Hex_List::Empty() {
	if (this->size == 0) {
		return true;
	}
	else return false;
}

void Hex_List::Add(Hexagon &&hexagon) {
	ListItem* new_item = new ListItem(hexagon);
	new_item->SetNext(this->head->GetNext());
	this->head->SetNext(new_item);
	this->size++;
}

Hexagon Hex_List::Extract(int position) {
	ListItem* iterator = head->GetNext();
	if (position > this->size) {
		std::cout << "Wrong item position in list. Returning zero-hex." << std::endl;
		return Hexagon();
	}
	for (int i = 1; i < position; i++) {
		iterator = iterator->GetNext();
	}
	return iterator->GetHex();
}

bool Hex_List::Remove(const Hexagon& hex) {
	ListItem* prev = head;
	ListItem* iterator = head->GetNext();
	while (iterator != nullptr) {
		if (iterator->GetHex() == hex) {
			prev->SetNext(iterator->GetNext());
			iterator->SetNext(nullptr);
			delete iterator;
			//std::cout << "Element deleted." << std::endl;
			return true;
		}
		prev = iterator;
		iterator = iterator->GetNext();
	}
	//std::cout << "Element not found." << std::endl;
	return false;
}

int Hex_List::GetSize() {
	return this->size;
}

std::ostream& operator << (std::ostream& os, const Hex_List& list) {
	ListItem* iterator = list.head->GetNext();
	os << "Printing list: {";
	while (iterator != nullptr) {
		os << *iterator;
		iterator = iterator->GetNext();
	}
	os << "}." << std::endl;
	return os;
}
Hex_List::~Hex_List(){
	delete head;
}
