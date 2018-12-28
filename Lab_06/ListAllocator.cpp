#include "ListAllocator.h"



ListAllocator::ListAllocator(size_t size, size_t count){
	used_blocks = (char*)malloc(size*count);
	free_blocks = new Array(count);
	for (size_t i = 0; i < count; i++) {
		free_blocks->Add(used_blocks + i * size);
	}
	std::cout << "Memory allocation initialized" << std::endl;
}

void* ListAllocator::allocate() {
	void* memory = nullptr;
	if (free_blocks->Index()<=0){
		std::cout << "No memory left. Returning nullptr" << std::endl;
	}
	else {
		memory = free_blocks->Get();
		free_blocks->Remove();
		std::cout << "Memory allocated, memory left = " << free_blocks->Index() << std::endl;
	}
	return memory;
}

void ListAllocator::deallocate(void* p) {
	free_blocks->Add(p);
	std::cout << "Memory freed, memory left = " << free_blocks->Index() << std::endl;
}

bool ListAllocator::Full() {
	return free_blocks->Index() < 0;
}

ListAllocator::~ListAllocator(){
	delete used_blocks;
	delete free_blocks;
}
