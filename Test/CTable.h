#include "library.h"

class CTable
{
protected:
	///////////////////////////////////////////////////
	// ZMIENNE
	///////////////////////////////////////////////////
	// Tablica glowna klasy
	int *table; 
	int *heapTable;
	// Rozmiar tablicy 
	int sizeTable; 
	int heapSize;
	// Kierunek sortowania
	// true - rosnaco, false - malejaco
	bool way; 
	
	// Przechowuja dane zwiazane z zadaniem!
	int comparision;	// Liczba porownan
	int inversion;		// Liczba przestawien
	
	///////////////////////////////////////////////////
	// METODY
	///////////////////////////////////////////////////
	void swap_elem(int &a, int &b);
	void build_heap();
	void restore_heap(int i);
public:
	CTable();
	~CTable();
	///////////////////////////////////////////////////
	// METODY
	///////////////////////////////////////////////////
	int size(); // sprawdza rozmiar tablicy, to powinno byc typu size_t, ale trzeba bedzie uwazac na warning

	//	Weronika
	void bubbleSort();		// Sortowanie bąbelkowe
	void selectionSort();	// Sortowanie przez wybieranie
	void quickSortH(int first, int last);		// Sortowanie szybkie Hoare'a
	int partitionHoare(int first, int last);

	//	Arek
	void shakerSort();		// Sortowanie bąbelkowe wariant wahadlowym GOTOWE
	void insertSort();		// Sortowanie przez wstawianie
	void heapSort();		// Sortowanie przez kopcowanie

	//	Dominik
	void bubbleSortCOM();	// Sortowanie bąbelkowe z ciagla kontrla monotonicznosci
	void bucketSort();		// Sortowanie kubełkowe
	void quickSortL(int first, int last);	// Sortowanie szybkie Lomuta
	int partitionLomut(int first, int last);		



};
