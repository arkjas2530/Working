#include "CTable.h"
#include<iostream>

CTable::CTable()
{
	table = nullptr;
}

CTable::~CTable()
{
	delete[] table;
}

int CTable::size()
{
	return sizeTable;
}

void CTable::bubbleSort()
{
	
	using std::cout;
	int sum;
	int a=0;
	int comp=0;//liczba porownan
	int temp;//zmienna przechowujaca wartosc tab

	for (int i = 0; i <  sizeTable- 1; i++)
	{
		sum = 0;

		for (int j = 0; j < sizeTable - 1-i; j++)
		{
			if (table[j] > table[j + 1])
			{
				temp = table[j];
				table[j] = table[j + 1];
				table[j + 1] = temp;
				a++;
				sum++;
			}
			comp++;
		}

		if (sum == 0)
			break;
	}

	for (int i = 0; i < sizeTable; i++)
		cout << table[i] << " ";
	cout <<std::endl;
	cout << a << std::endl;
	cout << comp << std::endl;

}
void CTable::selectionSort()
{
}
void CTable::quickSortH()
{}
void CTable::shakerSort()
{}
void CTable::insertSort()
{}
void CTable::heapSort()
{}					
void CTable::bubbleSortCOM()
{}
void CTable::bucketSort()
{}
void CTable::quickSortL()
{}