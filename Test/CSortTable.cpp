#include "CSortTable.h"
#include <cstdlib>
#include <random>
#include"library.h"

using std::cout;
using std::endl;
using std::cin;

CSortTable::CSortTable()
{
	for (;;)
	{
		show_menu();
		choice();
		show_menuMethod();
		menuMethodChoice();
		cout << "Nacisnij Enter aby kontynuowac..." << endl;
		system("pause");
		system("cls");
	}
}

void CSortTable::choice()
{
	int n;
	cin >> sign;

	switch (sign)
	{
	case '1':
		cout << "Podaj ilosc elementow do tablicy: ";
		cin >> n;
		table = creatTable(n);
		sizeTable = n;
		menuUserChoice(n);
		break;

	case '2':
		cout << "Podaj ilosc elementow do losowania: " << endl;
		cin >> n;
		table = creatTable(n);
		sizeTable = n;
		menuPseudoChoice(n);
		break;
	case '3':
		menu();
		// TWORZENIE TABELKI Z DANYMI
		break;
	case'0':
		exit(0);
	default:
		cout << "Brak wyboru w menu.Sprobuj ponownie " << endl;

	}
}

void CSortTable::menuPseudoChoice(int _n)
{
	int a, b;
	// Zabezpieczenie generatora, da sie to jakos zrobiæ na TRY CATCH ??? ~AREK
	cout << "Podaj zakres z ktorego maja byc generowane liczby" << endl;
	cin >> a >> b;
	while (a >= b)
	{
		cout << "Poczatek zakresu jest wiekszy lub rowny koncu. Sprobuj jeszcze raz" << endl;
		cin >> a >> b;
	}
	// Stworzenie generatora liczb pseudolosowych u¿ywaj¹cego algorytmu mt19937
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> generate(a, b);

	// Przypisanie nowo wygenerowanej liczby pseudolosowej:
	for (int i = 0; i < _n;i++)
	{
		table[i] = generate(mt);
		cout << table[i] << " ";
	}
}
void CSortTable::menuUserChoice(int _n)
{
	for (int i = 0; i < _n;i++)
	{
		cout << "Podaj " << i + 1 << " element tablicy : " ;
		cin >> table[i];
	}
	//nie wiem czy zostawiæ obczajcie to ! ~AREK
	//system("cls");
}
void CSortTable::menu()
{

}
void CSortTable::show_menu()
{
	cout << "Menu Glowne" << endl;
	cout << "1. Realizacja algorytmow przy pomocy recznie uzupelnionej tablicy" << endl;
	cout << "2. Realizacja algorytmow przy pomocy tablicy uzupelnionej liczbami losowymi" << endl;
	cout << "3. Ilustracja dzialania programow sortujacych " << endl;
	cout << "0. Opuszczenie programu" << endl;
}
void CSortTable::show_menuMethod()
{
	cout << endl;
	cout << "Wybor metody" << endl;
	cout << "1. Sortowanie babelkowe " << endl;
	cout << "8. Sortowanie kubelkowe " << endl;
}
void CSortTable::menuMethodChoice()
{
	cout << "Wybrana opcja : ";
	cin >> sign;

	switch (sign)
	{
	case'1':
		bubbleSort();
		break;
		
	case'2':	
		selectionSort();
		break;
	
	case'3':
		quickSortH();
		break;
		
	case'4':
	
		shakerSort();
		break;
	
	case'5':
		insertSort();
		break;
	
	case'6':
		heapSort();
		break;
	
	case'7':
		bubbleSortCOM();
		break;
	
	case'8':
		bucketSort();
		break;

	case'9':
		quickSortL();
		break;
	
	default:
		cout << "Brak wyboru w menu.Sprobuj ponownie " << endl;

	}
}
