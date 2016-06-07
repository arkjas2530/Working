#include <iostream>
#include "CTable.h"

class CSortTable:public CTable
{
private:
/* Losuje liczby do tablicy
Arg: @n - wielkosc tablicy*/
	void menuPseudoChoice(int _n);
	/*
	Pokazuje menu glowne
	*/
	void show_menu();
	/*
	Algorytm do wprowadzania elentów do tablicy z klawiatury
	*/
	void menuUserChoice(int _n);
	/*wpisywanie liczb wybranych przez uzytkownika*/
	void menu();
	/*
	Menu glowne
	*/
	void choice();
	void show_menuMethod();
	/*pokazuje menu z wyborem metody sortowania */
	void menuMethodChoice();
	/*umozliwia wybor metody sortowania*/
	
	// odpowiada za drukowanie danych w pliku i konsoli 
	void printTable();
	// wyswietla zawartosc tablicy
	void showTable();	
	// zapisz zawrtosc tablicy do pliku 
	void saveToFile();	
	
	
public:
	CSortTable();
};
