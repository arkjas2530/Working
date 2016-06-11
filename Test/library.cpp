#include"library.h"

int *creatTable(int _n)
{
	int *table;
	table = nullptr;

	try
	{
		table = new int[_n];
	}
	
	catch(std::bad_alloc &e)
	{
		std::cout << &e << std::endl;
	}

	return table;
}

void mixingTable(int *arr, int first, int last)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> generate(first, last);
	for (int i = last - first; i >= 0; i--)
	{
		int x = generate(mt);
		int y = generate(mt);
		std::swap(x, y);
	}
}
