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
	way = true; // TYMCZASOWO BO TRZEBA DOPISAĂ„â€  FUNKCJE
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
	//zmienna wskazujaca na element do zmiany(najmniejszy lub największy znaleziony)
	int element_to_swap;
	iloscPorownan = 0;	iloscPrzestawien = 0;

	for (int i = 0;i < sizeTable - 2;i++)
	{
		//Ustalam pierwszy znaleziony element jako element do zmiany
		element_to_swap = i;
		for (int j = i + 1;j < sizeTable;j++)
		{
			iloscPorownan++;
			//Jesli znajduje element mniejszy to wskazuje na niego
			if (table[element_to_swap] > table[j])
			{
				element_to_swap = j;
			}
		}
		//Jesli element do zmiany jest rozny od elementu na pozycji poczatkowej to zamieniam je
		if (element_to_swap != i)
		{
			iloscPrzestawien++;
			swap_elem(table[i], table[element_to_swap]);
		}
	}

}
void CTable::quickSortH()
{}
void CTable::shakerSort()
{

	int sum = 0;
	iloscPorownan = 0;	iloscPrzestawien = 0;
	
	for (int i = 0; i < sizeTable-1;i++)
	{
		for (int j = 0, k = sizeTable - 1;j < sizeTable-1;j++,k--)
		{
			/*
			WybĂłr kierunku
			*/
			switch (way)
			{
			case true:
				/*
				Dla nieparzystych(kierunek w shaker) i elementow nie wykraczajacych poza tablice zwiekszam porownania
				Dla parzystych(kierunek w shaker) zwiekszam porownania
				*/
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)	iloscPorownan++;
				/*
				Zmiana dla przystych
				*/
				if (table[j] > table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					iloscPrzestawien++;
				}
				/*
				Zmiana dla nieparzystych
				*/
				else if (table[k - 1] < table[k - 2] && i % 2 != 0 && k - 2 >= 0)
				{
					swap_elem(table[k - 1], table[k - 2]);
					sum++;
					iloscPrzestawien++;
				}
				break;
			case false:
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)	iloscPorownan++;
				
				if (table[j] < table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					iloscPrzestawien++;
				}
				
				else if (table[k - 1] > table[k - 2] && i % 2 != 0 && k - 2 >= 0)
				{
					swap_elem(table[k - 1], table[k - 2]);
					sum++;
					iloscPrzestawien++;
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
	cout << "ilosc inversji " << iloscPrzestawien << endl;
	cout << "ilosc porownan " << iloscPorownan << endl;
	for (int i = 0; i < sizeTable; i++)
		cout << table[i] << " ";
}
void CTable::insertSort()
{
	using std::cout;
	int temp;
	int j = 0;
	int sum;
	int comp = 0;
	int a=0;

	for (int i = 0; i < sizeTable - 1; i++)
	{
		temp = table[i + 1];//zmienna porÄ‚Ĺ‚wnywana z posortowana tab
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

void CTable::bubbleSortCOM(bool _way)
{
	// Liczniki 
	// @i - wskazuje do ktorego elementu tablica jest posortowana 
	// @j - przechodzi przez elementy petli FOR od konca
	int i = -1, j;

	// Flaga sterujaca petla WHILE
	bool isMonotonicity; 
	do
	{
		// Ustaw wartosc flagi sterujacej na false
		isMonotonicity = false;

		// Przechodz i sprawdzaj tablice od konca
		// Po przejsciu calej tablicy ZAWSZE pierwszy element znajduje na swoim miejscu, 
		// dlatego nie sprawdzana cala tablica
		for(j = sizeTable - 1, i++, iloscPorownan++; i < j; j--)
		{
	
			if(_way)
			{	// Sortuj rosnaco
				if(table[j] < table[j - 1])
				{
					// Zamiana elementow 
					std::swap(table[j], table[j - 1]);

					// Jesli nastapi przestawienie ustaw flage na true
					isMonotonicity = true;

					// Zliczanie ilosci zamian elementow
					iloscPrzestawien++;
				}
			}
			else
			{	// Sortuj malejaco
				if(table[j] > table[j - 1])
				{
					// Zamiana elementow 
					std::swap(table[j], table[j - 1]);

					// Jesli nastapi przestawienie ustaw flage na true
					isMonotonicity = true;

					// Zliczanie ilosci zamian elementow
					iloscPrzestawien++;
				}
			}

		}

	// Jesli nie nastapi przestawienie zakoncz petle
	} while(isMonotonicity);
}

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
