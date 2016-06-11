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

/*
Buduje forme kopca na bazie Tabeli
*/
void CTable::build_heap()
{
	heapSize = sizeTable;
	/*
	ustawia indeks na węźle,który ma połączenie z ostatnim, 
	lisciem w drzewie. 
	*/
	for (int i = sizeTable / 2;i >= 0;i--)
	{
		restore_heap(i);
	}
}
/*
Przywrca wartości kopca, tzn sprzwdza czy synowie i-tego węzła
nie mają większych wartości od niego
*/
void CTable::restore_heap(int i)
{
	//ustawia indeksy synow
	int left = 2 * i, right = (2 * i) + 1, largest;
	
	/*
	Poniższe warunki sprawdzają kto jest większy lewy syn, prawy syn, 
	czy ojciec
	*/
	if (left < heapSize && table[left] > table[i])
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	if (right < heapSize && table[right] > table[largest])
	{
		largest = right;
	}
	/*
	W sytuacji jeśli któryś z synów jest większy od ojca, 
	następuje rekurencyjne wywołanie restore_heap, gdzie sprawdza się dla
	węzła w którym znaleziono większą wartość, nie zaburzony został kopiec.
	*/
	if (largest != i)
	{
		//zamienia wiekszego syna z ojcem
		swap_elem(table[i], table[largest]);
		restore_heap(largest);
	}
}

CTable::CTable()
{
	iloscPorownan = 0;
	iloscPrzestawien = 0;
	heapSize = sizeTable;
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
//zmienna przechowujaca wartosc tab

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
	//zmienna wskazujaca na element do zmiany(najmniejszy lub największy znaleziony)
	int element_to_swap;
	iloscPorownan = 0;	iloscPrzestawien = 0;
	for (int i = 0;i < sizeTable - 1;i++)
	{
		//Ustalam pierwszy znaleziony element jako element do zmiany
		element_to_swap = i;
		for (int j = i + 1;j < sizeTable;j++)
		{
			iloscPorownan;
			//Jesli znajduje element mniejszy to wskazuje na niego
			if (table[element_to_swap] > table[j])
			{
				element_to_swap = j;
			}
		}
		//Jesli element do zmiany jest rozny od elementu na pozycji poczatkowej to zamieniam je
		if (element_to_swap != i)
		{
			iloscPrzestawien;
			swap_elem(table[i], table[element_to_swap]);
		}
	}
	 
}
void CTable::quickSortH(int first,int last,int _way)
{
	if (first < last)
	{
		// Ustawiamy os podzialu na ostatni  element
		int pivot = partitionHoare(first, last, _way);

		// Wywolanie rekurencyjne funkcji 
		quickSortH(first, pivot - 1, _way);
		quickSortH(pivot + 1, last, _way);
	}
}
void CTable::shakerSort()
{
	cout << "1. Sortowanie Rosnace" << std::endl;
	cout << "2. Sortowanie Malejace" << std::endl;

	int sum = 0;
	iloscPorownan = 0; iloscPrzestawien = 0;
	for (int i = 0; i < sizeTable-1;i++)
	{
		for (int j = 0, k = sizeTable - 1;j < sizeTable-1;j++,k--)
		{
			/*
			Wybór kierunku
			*/
			switch (way)
			{
			case true:
				/*
				Dla nieparzystych(kierunek w shaker) i elemntów zawierających się  tablicy zwiększam porówania
				Dla parzystych(kierunek w shaker) zwiekszam porówania
				*/
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)
				{
					iloscPorownan++;
				}
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
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)
				{
					iloscPorownan++;
				}
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
			}

		}
		if (sum == 0)	break;
		sum = 0;
	}
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
{
	build_heap();
	/*
	Zamienia korzeń z najmłodszym lisciem, wyrzuca zamieniony element, poza
	kopiec i przywraca wartość kopca w korzeniu, tak dopóki w kopcu
	nie zostanie 1 element
	*/
	for (int i = sizeTable - 1;i >= 1;i--)
	{
		swap_elem(table[0], table[i]);
		heapSize--;
		restore_heap(0);
	}
}					
void CTable::bubbleSortCOM()
{
	;
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
}
void CTable::quickSortL(int first, int last)
{
	if(first < last)
	{
		// Ustawiamy os podzialu na ostatni  element
		int pivot = partitionLomut(first, last);

		// Wywolanie rekurencyjne funkcji 
		quickSortL(first, pivot - 1);
		quickSortL(pivot + 1, last);
	}
}

int CTable::partitionLomut(int first, int last)
{
	// Ustawiamy os podzialu na ostatni  element
	int pivot = table[last];

	// Licznik i ustawiam na pierwszy element 
	int i = first - 1;

	// Przeszukuje od pierwszego do ostatniego elementu, jesli liczba mniejsza zamien!
	// @i - wskazuje na n element
	// @j - wskazuje na (n + 1) element
	if(way)
	{	// Sortowanie rosnaco
		for(int j = first; j < last; j++)
			if(table[j] < pivot)
				std::swap(table[++i], table[j]);
	}
	else
	{	// Sortowanie malejaco
		for(int j = first; j < last; j++)
			if(table[j] > pivot)
				std::swap(table[++i], table[j]);
	}

	std::swap(table[++i], table[last]);

	return i;
}
int CTable::partitionHoare(int first, int last, int _way)
{
	
		int x;// element rozdzielajacy 
		int i, j;
		int p = first;
		int r = last;

		x = table[p];
		i = p - 1;
		j = r + 1;

		while (i<j)
		{
			do
			{
				j--;


			} while (table[j - 1] > x);

			do {

				i++;

			} while (table[i] < x);

			if (i < j)
			{
				swap_elem(table[i], table[j - 1]);
			
			}
			else
				return j;
		}


	}

