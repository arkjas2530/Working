#include "library.h"
#include <fstream>
#include<string>

class CTable
{
protected:
	///////////////////////////////////////////////////
	// ZMIENNE
	///////////////////////////////////////////////////
	// Tablica glowna klasy
	int *table; 

	char flag; //zmienna decydujaca o sposobie zilustrowania danych

	std::ofstream file;//uchwyt do pliku

	// Rozmiar tablicy 
	int sizeTable; 

	// Rozmiar kopca
	int heapSize;

	// Kierunek sortowania
	// true - rosnaco, false - malejaco
	bool way; 
	// zmienna zapamietująca zapis do pliku(żeby nie powtarzać w pętli 4 razy)
	bool save;
	// Przechowuja dane zwiazane z zadaniem!
	// Liczba porownan
	int comparision;	

	// Liczba przestawien
	int inversion;		
	
	///////////////////////////////////////////////////
	// METODY
	///////////////////////////////////////////////////
	// Zamienia miejscami elementy podane w parametrach
	void swap_elem(int &a, int &b);

	/*
	Buduje forme kopca na bazie Tabeli
	*/
	void build_heap();

	/*
	Przywrca wartości kopca, tzn sprzwdza czy synowie i-tego węzła
	nie mają większych wartości od niego
	*/
	void restore_heap(int i);

	// Zwraca rozmiar tablicy
	size_t size(); 

	void openToSave();//zapis tabelki do pliku

public:
	///////////////////////////////////////////////////
	// KONSTRUKTORY
	///////////////////////////////////////////////////
	CTable();

	~CTable();

	///////////////////////////////////////////////////
	// METODY
	///////////////////////////////////////////////////
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
