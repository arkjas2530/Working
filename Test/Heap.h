#pragma once
#include "Ctable.h"
class Heap:public CTable
{
	int val;
	int *B;
public:
	Heap();
	int *create_root();
	void build(int elem, int k);
	~Heap();
};

