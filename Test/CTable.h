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
	
	// Kierunek sortowania
	// true - rosnaco, false - malejaco
	bool way; 
	
	// Przechowuja dane zwiazane z zadaniem!
	int iloscPorownan;
	int iloscPrzestawien;
	
	///////////////////////////////////////////////////
	// METODY
	///////////////////////////////////////////////////
	void swap_elem(int &a, int &b);
	int *create_root();
	void build_heap(int elem, int k);
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
	void quickSortH(int first, int last, int _way = true);		// Sortowanie szybkie Hoare'a

	//	Arek
	void shakerSort();		// Sortowanie bąbelkowe wariant wahadlowym GOTOWE
	void insertSort();		// Sortowanie przez wstawianie
	void heapSort();		// Sortowanie przez kopcowanie

	//	Dominik
	void bubbleSortCOM();	// Sortowanie bąbelkowe z ciagla kontrla monotonicznosci
	void bucketSort();		// Sortowanie kubełkowe
	void quickSortL(int first, int last);	// Sortowanie szybkie Lomuta
	int partitionLomut(int first, int last);		
	int partitionHoare(int first, int last, int _way);


};
