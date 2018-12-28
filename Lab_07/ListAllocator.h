#pragma once
#ifndef _ListAllocator_h_
#define _ListAllocator_h_
#include <cstdlib>
#include <iostream>
#include "Array.h"
class ListAllocator {
public:
	ListAllocator(size_t size, size_t count);
	void* allocate();
	void deallocate(void* pointer);
	bool Full();


	virtual ~ListAllocator();
private:
	size_t size;
	size_t count;

	char* used_blocks;
	Array* free_blocks;
};


#endif // !_ListAllocator_h_
