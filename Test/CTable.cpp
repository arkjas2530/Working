#include "CTable.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void CTable::swap_elem(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

CTable::CTable()
{
	iloscPorownan = 0;
	iloscPrzestawien = 0;
	table = nullptr;
}

CTable::~CTable()
{
	// delete[] table;
}

int CTable::size()
{
	return sizeTable;
}

void CTable::bubbleSort()
{
	
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
	cout <<endl;
	cout << a << endl;
	cout << comp << endl;

}
void CTable::selectionSort()
{
}
void CTable::quickSortH()
{}
void CTable::shakerSort()
{
	cout << "1. Sortowanie Rosnace" << std::endl;
	cout << "2. Sortowanie Malejace" << std::endl;
	
	char flag;
	cin >> flag;

	int sum = 0, inv = 0, comp = 0;
	
	for (int i = 0; i < sizeTable-1;i++)
	{
		for (int j = 0, k = sizeTable - 1;j < sizeTable-1;j++,k--)
		{
			switch (flag)
			{
			case '1':
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)
				{
					comp++;
				}
				if (table[j] > table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					inv++;
				}
				else if (table[k - 1] < table[k - 2] && i % 2 != 0 && k - 2 >= 0)
				{
					swap_elem(table[k - 1], table[k - 2]);
					sum++;
					inv++;
				}
				break;
			case '2':
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)
				{
					comp++;
				}
				if (table[j] < table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					inv++;
				}
				else if (table[k - 1] > table[k - 2] && i % 2 != 0 && k - 2 >= 0)
				{
					swap_elem(table[k - 1], table[k - 2]);
					sum++;
					inv++;
				}
				break;
			default:
				cout << "BLEDNY WYBOR. Po nacisnieciu ENTER program zakonczy dzialanie" << endl;
				system("pause");
				exit(0);
			}

		}
		if (sum == 0)	break;
		sum = 0;
	}
	cout << "ilosc inversji " << inv << endl;
	cout << "ilosc porownan " << comp << endl;
	for (int i = 0; i < sizeTable; i++)
		cout << table[i] << " ";
}
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
    int *tableHelper = creatTable(sizeTableHelper);
   
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
