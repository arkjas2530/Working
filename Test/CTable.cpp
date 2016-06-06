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
{
    // Ustawienie poczatkowych wartosci dla max i min
    int min = table[0], max = table[0];
   
    // Szukanie minimum oraz maksimum
    for(int i = 1; i < sizeTable; i++)
    {
        if(min > table[i]) min = table[i];
        if(max < table[i]) max = table[i];
    }
    // Wielkosc tablicy pomocniczej
    int sizeTableHelper = max - min + 1;
   
    // Tworzenie tablicy pomocniczej
    int *tableHelper = new int[sizeTableHelper];
   
    // Zerowanie licznikow tablicy
    for(int i = 0; i < sizeTableHelper; i++)
        tableHelper[i] = 0;   

    // Zliczanie licznikow
    for(int i = 0; i < sizeTable; i++)
        tableHelper[table[i] - min]++;
 
   
    // Wartosci niezerowych licznikow zapisz do table
    // tyle razy ile wystepuja w tabe
    for(int i = 0, j = 0; i < sizeTableHelper; i++)
        while(tableHelper[i]--)
			table[j++] = i + min;
   
    for(int i = 0; i < sizeTable; i++)
        std::cout << table[i] << ", ";

	std::cout << std::endl << "Ilosc porownan elementow: " << sizeTable - 1 << std::endl; 
	//ZAPYTAC JAK TU TO ROBIC CZY WGL GRZESIUUU
	//std::cout << "Ilosc przestawien elementow: " << sizeTable << std::endl; 

	// W wolnej chwili niech ktos zobaczy czy to zliczanie porownan jest dobrze
	// w tym sortowaniu nie nastepuje zadna zamiana miejsc a porownuje sie tylko max i min
	// a ilosc przestawien to po prostu ilosc zapisow do tablicy pomocniczej 
	
}
void CTable::quickSortL()
{}
