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


	void saveFile(std::string name, std::string ntable);
	//zapis do pliku
	
	// zapisz zawrtosc tablicy do pliku 
	void showTable(std::string name, std::string ntable);
	
	//zapisywanie lub pokazywanie danych wszystkich czterech posortowanych 
	void showOrSave(std::string name, std::string ntable);
	void changeTable();
	void printTable();
public:
	///////////////////////////////////////////////////
	// KONSTRUKTOR
	///////////////////////////////////////////////////
	// Odpowiada za wywolanie programu w pliku glownym
	CSortTable();
};
