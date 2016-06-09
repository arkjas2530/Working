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
	way = true; // TYMCZASOWO BO TRZEBA DOPISAÄ† FUNKCJE
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
				swap_elem(table[j], table[j + 1]);
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
			/*
			Wybór kierunku
			*/
			switch (flag)
			{
			case '1':
				/*
				Dla nieparzystych(kierunek w shaker) i elemntów zawierających się  tablicy zwiększam porówania
				Dla parzystych(kierunek w shaker) zwiekszam porówania
				*/
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)
				{
					comp++;
				}
				/*
				Zmiana dla przystych
				*/
				if (table[j] > table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					inv++;
				}
				/*
				Zmiana dla nieparzystych
				*/
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
{
	int temp;
	int j = 0;
	int sum;
	int comp = 0;
	int a=0;

	for (int i = 0; i < sizeTable - 1; i++)
	{
		temp = table[i + 1];//zmienna porownywana z posortowana tab
		j = i;
		sum = 0;


		while (j >= 0 && table[j] > temp)
		{
			table[j + 1] = table[j];
			table[j] = temp;
			j--;
			a++;
			sum++;
		}

		if (j == -1) // w momencie w ktorym nie nastapi przestawienie bo while zostanie spelniony trzeba dodac 1
			comp += sum;
		else
			comp = comp + 1 + sum;

	}
	cout << a << std::endl;
	cout << comp << std::endl;
}
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
   
    /*for(int i = 0; i < sizeTable; i++)
        std::cout << table[i] << ", ";*/

	//std::cout << std::endl << "Ilosc porownan elementow: " << sizeTable - 1 << std::endl; 
	//ZAPYTAC JAK TU TO ROBIC CZY WGL GRZESIUUU
	//std::cout << "Ilosc przestawien elementow: " << sizeTable << std::endl; 

	// W wolnej chwili niech ktos zobaczy czy to zliczanie porownan jest dobrze
	// w tym sortowaniu nie nastepuje zadna zamiana miejsc a porownuje sie tylko max i min
	// a ilosc przestawien to po prostu ilosc zapisow do tablicy pomocniczej 
	
}
void CTable::quickSortL(int first, int last, int _way)
{
	if(first < last)
	{
		// Ustawiamy os podzialu na ostatni  element
		int pivot = partitionLomut(first, last, _way);

		// Wywolanie rekurencyjne funkcji 
		quickSortL(first, pivot - 1, _way);
		quickSortL(pivot + 1, last, _way);
	}
}

int CTable::partitionLomut(int first, int last, int _way = true)
{
	// Ustawiamy os podzialu na ostatni  element
	int pivot = table[last];

	// Licznik i ustawiam na pierwszy element 
	int i = first - 1;

	// Przeszukuje od pierwszego do ostatniego elementu, jesli liczba mniejsza zamien!
	// @i - wskazuje na n element
	// @j - wskazuje na (n + 1) element
	if(_way)
	{
		for(int j = first; j < last; j++)
			if(table[j] < pivot)
				std::swap(table[++i], table[j]);
	}
	else
	{
		for(int j = first; j < last; j++)
			if(table[j] > pivot)
				std::swap(table[++i], table[j]);
	}

	std::swap(table[++i], table[last]);

	return i;
}
