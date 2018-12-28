#pragma once
#ifndef _Array_h_
#define _Array_h_
#include <iostream>
#include <cstdlib>

class Array
{
public:
	Array(int size);
	int Size();
	int Index();
	//void SetIndex(int i);
	bool Add(void* pointer);
	void* Get();
	void Remove();
	~Array();
private:
	void** data;
	int size;
	int index;
};


#endif // !_Array_h_
