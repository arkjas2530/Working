#include"library.h"
#include<iostream>

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
