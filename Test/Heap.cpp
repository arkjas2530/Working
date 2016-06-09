#include "Heap.h"



Heap::Heap()
{
	B = create_root();
}

int *Heap::create_root()
{
	B = new int[sizeTable];
	B[0] = table[0];
	return B;
}

void Heap::build(int elem,int k)
{
	int *B = nullptr;
	
	int j = (k - 1) / 2;

	while (k > 0 && B[j] < elem)
	{
		B[k] = B[j];
		k = j;
		j = (k - 1) / 2;
	}
	B[k] = elem;
}


Heap::~Heap()
{
	table = B;
}
