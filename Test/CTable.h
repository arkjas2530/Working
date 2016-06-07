#include "library.h"
class CTable
{
protected:
	int *table; // tablica ktora bedzie sortowana :D
	int sizeTable; // Rozmiar tablicy 
	void swap_elem(int &a, int &b);

	int iloscPorownan;
	int iloscPrzestawien;
public:
	CTable();
	~CTable();
	///////////////////////////////////////////////////
	// METODY
	///////////////////////////////////////////////////
	int size(); // sprawdza rozmiar tablicy, to powinno byc typu size_t, ale trzeba bedzie uwazac na warning
	int swap(); // zamienia dwie tablice TEGO typu


	//	Weronika
	void bubbleSort();		// Sortowanie bąbelkowe
	void selectionSort();	// Sortowanie przez wybieranie
	void quickSortH();		// Sortowanie szybkie Hoare'a

	//	Arek
	void shakerSort();		// Sortowanie bąbelkowe wariant wahadlowym
	void insertSort();		// Sortowanie przez wstawianie
	void heapSort();		// Sortowanie przez kopcowanie

	//	Dominik
	void bubbleSortCOM();	// Sortowanie bąbelkowe z ciagla kontrla monotonicznosci
	void bucketSort();		// Sortowanie kubełkowe
	void quickSortL(int first, int last);		// Sortowanie szybkie Lomuta
	int partitionLomut(int first, int last);


};
