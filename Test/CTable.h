#include "library.h"
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>

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

	// sprawdza czy metoda od 0 - 7 czy nie
	bool simple_method;
	
	// Przechowuja dane zwiazane z zadaniem!
	// Liczba porownan
	unsigned long long comparision;

	// Liczba przestawien
	unsigned long long inversion;
	
	// Czas wykonywania algorytmu
	clock_t czas; 
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
	int partitionHoare(int first, int last); // funkcja sortujaca w miejscu tablice

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
