#include "CTable.h"

using std::cout;
using std::cin;
using std::endl;

void CTable::openToSave()
{
	std::string nameFile;
	cout << "Podaj nazwe pliku do zapisu: ";
	cin >> nameFile;

	size_t pos = nameFile.rfind(".txt");

	if (pos == std::string::npos)//nie znaleziono na zadnej pozycji txt
		file.open(nameFile + ".txt", std::ofstream::out | std::ofstream::app);
	else
		file.open(nameFile, std::ofstream::out | std::ofstream::app);


}

void CTable::swap_elem(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

CTable::CTable()
{
	czas = 0;
	comparision = 0;
	inversion = 0;
	heapSize = sizeTable;
	table = nullptr;
}

CTable::~CTable()
{
	
}

size_t CTable::size()
{
	return sizeTable;
}

void CTable::bubbleSort()
{
	clock_t start = clock();
	inversion = 0;
	comparision = 0;

	if (way)
	{
		for (int i = 0; i < sizeTable - 1; i++)//porownanie jednego elementu z reszta tablicy
		{
			for (int j = 0; j < sizeTable - 2 ; j++)
			{
				if (table[j] > table[j + 1])
				{
					swap_elem(table[j], table[j + 1]); 
					inversion++;

				}
				comparision++;
			}

		}
	}
	else
	{
		for (int i = 0; i < sizeTable - 1; i++)
		{


			for (int j = 0; j < sizeTable - 1; j++)
			{
				if (table[j] < table[j + 1])
				{
					swap_elem(table[j], table[j + 1]);
					inversion++;

				}
				comparision++;
			}

		}
	}

	
	
	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;

}
void CTable::selectionSort()
{
	clock_t start = clock();
	//zmienna wskazujaca na element do zmiany(najmniejszy lub największy znaleziony)
	int element_to_swap;
	comparision = 0;	inversion = 0;
	
	for (int i = 0;i < sizeTable - 1;i++)
	{
		//Ustalam pierwszy znaleziony element jako element do zmiany
		element_to_swap = i;
		if (way)
		{
			for (int j = i + 1;j < sizeTable;j++)
			{
				comparision++;
				//Jesli znajduje element mniejszy to wskazuje na niego
				if (table[element_to_swap] > table[j])
				{
					element_to_swap = j;
				}
			}
			//Jesli element do zmiany jest rozny od elementu na pozycji poczatkowej to zamieniam je
			if (element_to_swap != i)
			{
				inversion++;
				swap_elem(table[i], table[element_to_swap]);
			}
		}
		else
		{
			for (int j = i + 1;j < sizeTable;j++)
			{
				comparision++;
				//Jesli znajduje element wiekszy to wskazuje na niego
				if (table[element_to_swap] < table[j])
				{
					element_to_swap = j;
				}
			}
			//Jesli element do zmiany jest rozny od elementu na pozycji poczatkowej to zamieniam je
			if (element_to_swap != i)
			{
				inversion++;
				swap_elem(table[i], table[element_to_swap]);
			}
		}
	}

	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;
	 
}
void CTable::quickSortH(int first,int last)
{
	clock_t start = clock();
	if (first < last)
	{
		// Ustawiamy os podzialu na ostatni  element
		int pivot = partitionHoare(first, last);

		// Wywolanie rekurencyjne funkcji 
		quickSortH(first, pivot-1);
		quickSortH(pivot + 1, last);
	}

	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;
}
void CTable::shakerSort()
{
	clock_t start = clock();
	int sum = 0;
	comparision = 0; inversion = 0;
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
					comparision++;
				}
				/*
				Zmiana dla przystych
				*/
				if (table[j] > table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					inversion++;
				}
				/*
				Zmiana dla nieparzystych
				*/
				else if (table[k - 1] < table[k - 2] && i % 2 != 0 && k - 2 >= 0)
				{
					swap_elem(table[k - 1], table[k - 2]);
					sum++;
					inversion++;
				}
				break;
			case false:
				if ((k - 2 >= 0 && i % 2 != 0) || i % 2 == 0)
				{
					comparision++;
				}
				if (table[j] < table[j + 1] && i % 2 == 0)
				{
					swap_elem(table[j], table[j + 1]);
					sum++;
					inversion++;
				}
				else if (table[k - 1] > table[k - 2] && i % 2 != 0 && k - 2 >= 0)
				{
					swap_elem(table[k - 1], table[k - 2]);
					sum++;
					inversion++;
				}
				break;
			}

		}
		if (sum == 0)	break;
		sum = 0;
	}
	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;

}
void CTable::insertSort()
{
	clock_t start = clock();
	int temp;
	int j = 0;
	int sum;
	comparision = 0;
	inversion = 0;
	
	if (way)
	{
		for (int i = 0; i < sizeTable - 1; i++)
		{
			temp = table[i + 1];//zmienna porownywana z posortowana tab
			j = i;
			sum = 0;


			while (j >= 0 && table[j] > temp) //zamiana dopoki liczba po prawej bedzie wieksza od wszystkich po lewej
			{
				table[j + 1] = table[j];
				table[j] = temp;
				j--;
				inversion++;
				sum++;
			}

			if (j == -1) // w momencie w ktorym nie nastapi przestawienie bo while zostanie spelniony trzeba dodac 1
				comparision += sum;
			else
				comparision += 1 + sum;

		}
	}
	else
	{
		for (int i = 0; i < sizeTable - 1; i++)
		{
			temp = table[i + 1];//zmienna porownywana z posortowana tab
			j = i;
			sum = 0;


			while (j >= 0 && table[j] < temp)
			{
				table[j + 1] = table[j];
				table[j] = temp;
				j--;			
			}

		}


	}
	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;

}
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
	}\
}
void CTable::restore_heap(int i)
{
	//ustawia indeksy synow
	int left = 2 * i, right = (2 * i) + 1, largest;

	/*
	Poniższe warunki sprawdzają kto jest większy lewy syn, prawy syn,
	czy ojciec
	*/
	if (way)
	{
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
	}
	else
	{
		if (left < heapSize && table[left] < table[i])
		{
			largest = left;
		}
		else
		{
			largest = i;
		}
		if (right < heapSize && table[right] < table[largest])
		{
			largest = right;
		}
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
void CTable::heapSort()
{
	clock_t start = clock();
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

	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;
}

					
void CTable::bubbleSortCOM()
{
	clock_t start = clock();
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
		for (j = sizeTable - 1, i++; i < j; j--)
		{
			comparision++;
			if (way)
			{	// Sortuj rosnaco
				if (table[j] < table[j - 1])
				{
					// Zamiana elementow 
					std::swap(table[j], table[j - 1]);

					// Jesli nastapi przestawienie ustaw flage na true
					isMonotonicity = true;

					// Zliczanie ilosci zamian elementow
					inversion++;
				}
			}
			else
			{	// Sortuj malejaco
				if (table[j] > table[j - 1])
				{
					// Zamiana elementow 
					std::swap(table[j], table[j - 1]);

					// Jesli nastapi przestawienie ustaw flage na true
					isMonotonicity = true;

					// Zliczanie ilosci zamian elementow
					inversion++;
				}
			}
		}

		// Jesli nie nastapi przestawienie zakoncz petle
	} while (isMonotonicity);
	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;

}
void CTable::bucketSort()
{
	clock_t start = clock();
    // Ustawienie poczatkowych wartosci dla max i min
    int min = table[0], max = table[0];
	inversion = 0;
    // Szukanie minimum oraz maksimum
    for(int i = 1; i < sizeTable; i++)
    {
        if(min > table[i]) min = table[i];
        if(max < table[i]) max = table[i];
		inversion++;
    }
    // Wielkosc tablicy pomocniczej
    int sizeTableHelper = max - min + 1;
   
    // Tworzenie tablicy pomocniczej
    int *tableHelper = creatTable(sizeTableHelper);
	comparision = 0; 

    // Zerowanie licznikow tablicy
    for(int i = 0; i < sizeTableHelper; i++)
        tableHelper[i] = 0;   

    // Zliczanie licznikow
	for (int i = 0; i < sizeTable; i++)
	{
		tableHelper[table[i] - min]++;
		comparision++;
	}
   
    // Wartosci niezerowych licznikow zapisz do table
    // tyle razy ile wystepuja w tabe
	if(way)
	{
		for (int i = 0, j = 0; i < sizeTableHelper; i++)
			while (tableHelper[i]--)
				table[j++] = i + min;
	}
	else
	{
		for (int i = sizeTableHelper - 1, j = 0; i >= 0 ; i--)
			while (tableHelper[i]--)
			{
				table[j++] = i + min;
				inversion++;
			}
	}

	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;
}
void CTable::quickSortL(int first, int last)
{
	clock_t start = clock();
	if(first < last)
	{
		// Ustawiamy os podzialu na ostatni  element
		int pivot = partitionLomut(first, last);

		// Wywolanie rekurencyjne funkcji 
		quickSortL(first, pivot - 1);
		quickSortL(pivot + 1, last);
	}

	clock_t stop = clock();
	czas = (stop - start) / CLOCKS_PER_SEC;
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
int CTable::partitionHoare(int first, int last) 
{
	
		int x;
		int i, j;
	

		x = table[first]; //element rozdzielajacy na poczatku tablicy
		i = first - 1;  //na poczatku wskazuje przed tablice
		j = last + 1;//-||-

		if (way)
		{
			while (true)
			{
				do
				{
					j--; //dekrementacja az znajdzie element miejszy od x

				} while (table[j] > x);

				do {

					i++; //inkrementacja az znajdzie elemnent wiekszy od x

				} while (table[i] < x);

				if (i < j)
				{
					swap_elem(table[i], table[j]);

				}
				else 
					break;
			}
		}
		else
		{
			while (true)
			{
				do
				{
					j--;

				} while (table[j] < x);

				do {

					i++;

				} while (table[i] > x);

				if (i < j)
				{
					swap_elem(table[i], table[j]);

				}
				else
					break;
			}
		}

		return j; 
	}

