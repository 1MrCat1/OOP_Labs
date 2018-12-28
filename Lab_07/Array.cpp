#include "Array.h"

Array::Array(int size) {
	data = (void**)malloc(sizeof(void*)*size);
	this->size = size;
	this->index = 0;
}

int Array::Size() {
	return this->size;
}

int Array::Index() {
	return this->index;
}

/*void Array::SetIndex(int new_index) {
	this->index = new_index;
}*/

bool Array::Add(void* pointer) {
	if (index + 1 == size) {
		//std::cout << "Array.Error. Memory is full" << std::endl;
		return false;
	}
	else {
		data[index + 1] = pointer;
		this->index++;
		return true;
	}
}

void* Array::Get() {
	if (index < 0) {
		//std::cout << "Array.Error. No memory left" << std::endl;
		return nullptr;
	}
	else {
		return this->data[index];
	}
}

void Array::Remove() {
	this->index--;
	data[index + 1] = nullptr;
}

Array::~Array() {
	free(data);
}
