#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <random>

#include "CTable.h"

class CSortTable:public CTable
{
	// Kierunek sortowania
	// true - rosnaco, false - malejaco
	void chooseWay();
	
	// Wyswietla i obsluguje menu glowne
	void show_menu();

	// Pobieranie od usera danych do tablicy
	void menuUserChoice(int _n);

	// Losuje dane do tablicy
	void menuPseudoChoice(int _n);

	// Wyswietla tabelke
	void menu();

	// Wyswietla i obsluguje metody sortujace
	void menuMethodChoice();

	// Odpowiada za drukowanie danych w pliku i konsoli 
	void printTable();

	// Wyswietlanie zawartosci tablicy
	void showTable();	

	// Zapisz zawrtosc tablicy do pliku 
	void saveToFile();	
	
public:
	///////////////////////////////////////////////////
	// KONSTRUKTOR
	///////////////////////////////////////////////////
	// Odpowiada za wywolanie programu w pliku glownym
	CSortTable();
};
