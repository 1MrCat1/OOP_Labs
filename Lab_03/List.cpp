#include "List.h"


List::List(){
	//std::shared_ptr<ListItem> item(new ListItem());
	this->head = nullptr;
	this->size = 0;
}

bool List::Empty() {
	return this->size;
}

int List::GetSize() {
	return this->size;
}

void List::Add_Triangle(std::shared_ptr<Triangle> &&triangle){
	std::shared_ptr<ListItem> item(new ListItem(triangle));
	item->SetNext(this->head);
	this->head = item;
	this->size++;
}

void List::Add_Hexagon(std::shared_ptr<Hexagon> &&hexagon) {
	std::shared_ptr<ListItem> item(new ListItem(hexagon));
	item->SetNext(this->head);
	this->head=item;
	this->size++;
}

void List::Add_Octagon(std::shared_ptr<Octagon> &&octagon) {
	std::shared_ptr<ListItem> item(new ListItem(octagon));
	item->SetNext(this->head);
	this->head=item;
	this->size++;
}

std::shared_ptr<Triangle> List::Extract_triangle(int position) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<ListItem> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	return iter->GetTriangle();
}

std::shared_ptr<Hexagon> List::Extract_hexagon(int position) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<ListItem> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	return iter->GetHexagon();
}

std::shared_ptr<Octagon> List::Extract_octagon(int position) {
	if (position > this->size) {
		std::cout << "Wrong position of element. Returning nullptr" << std::endl;
		return nullptr;
	}
	std::shared_ptr<ListItem> iter = this->head;
	for (int i = 1; i < position; i++) {
		iter = iter->GetNext();
	}
	return iter->GetOctagon();
}

void List::Remove_triangle(const Triangle& triangle) {
	std::shared_ptr<ListItem> prev = this->head;
	std::shared_ptr<ListItem> iter = this->head;
	while (iter != nullptr) {
		if (iter->GetTriangle() != nullptr) {
			if (*iter->GetTriangle() == triangle) {
				if (iter == this->head) {
					this->head = iter->GetNext();
					iter->SetNext(nullptr);
					iter->~ListItem();
					std::cout << "Element deleted" << std::endl;
					this->size--;
					return;
				}
				else {
					prev->SetNext(iter->GetNext());
					iter->SetNext(nullptr);
					iter->~ListItem();
					std::cout << "Element deleted" << std::endl;
					this->size--;
					return;
				}
			}
		}
		prev = iter;
		iter = iter->GetNext();
	}
	std::cout << "No element to delete" << std::endl;
}

void List::Remove_hexagon(const Hexagon& hexagon) {
	std::shared_ptr<ListItem> prev = this->head;
	std::shared_ptr<ListItem> iter = this->head;
	while (iter != nullptr) {
		if (iter->GetHexagon() != nullptr) {
			if (*iter->GetHexagon() == hexagon) {
				if (iter == this->head) {
					this->head = iter->GetNext();
					iter->SetNext(nullptr);
					iter->~ListItem();
					std::cout << "Element deleted" << std::endl;
					this->size--;
					return;
				}
				else {
					prev->SetNext(iter->GetNext());
					iter->SetNext(nullptr);
					iter->~ListItem();
					std::cout << "Element deleted" << std::endl;
					this->size--;
					return;
				}
			}
		}
		prev = iter;
		iter = iter->GetNext();
	}
	std::cout << "No element to delete" << std::endl;
}

void List::Remove_octagon(const Octagon& octagon) {
	std::shared_ptr<ListItem> prev = this->head;
	std::shared_ptr<ListItem> iter = this->head;
	while (iter != nullptr) {
		if (iter->GetOctagon() != nullptr) {
			if (*iter->GetOctagon() == octagon) {
				if (iter == this->head) {
					this->head = iter->GetNext();
					iter->SetNext(nullptr);
					iter->~ListItem();
					std::cout << "Element deleted" << std::endl;
					this->size--;
					return;
				}
				else {
					prev->SetNext(iter->GetNext());
					iter->SetNext(nullptr);
					iter->~ListItem();
					std::cout << "Element deleted" << std::endl;
					this->size--;
					return;
				}
			}
		}
		prev = iter;
		iter = iter->GetNext();
	}
	std::cout << "No element to delete" << std::endl;
}

std::ostream& operator << (std::ostream& os, const List& list) {
	std::shared_ptr<ListItem> iter = list.head;
	os << "Printing list: |";
	while (iter != nullptr) {
		if (iter->GetTriangle() != nullptr) {
			os << *iter->GetTriangle();
		}
		if (iter->GetHexagon() != nullptr) {
			os << *iter->GetHexagon();
		}
		if (iter->GetOctagon() != nullptr) {
			os << *iter->GetOctagon();
		}
		iter=iter->GetNext();
	}
	os << "|." << std::endl;
	return os;
}

List::~List(){
	std::cout << "List deleted" << std::endl;
}