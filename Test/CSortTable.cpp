#include "CSortTable.h"
#include"library.h"

using std::cout;
using std::endl;
using std::cin;


CSortTable::CSortTable()
{
	for (;;)
	{
		// Menu glowne
		show_menu();

		// Menu wyboru kierunku sortowania
		chooseWay();

		// Menu wyboru metody sortowania
		menuMethodChoice();

		// Wyswietlenie tablicy
		printTable();
		
		// Koniec z danymi, 
		cout << "Nacisnij Enter aby kontynuowac..." << endl;
		system("pause");
		system("cls");
	}
}

void CSortTable::show_menu()
{
	cout << "--------------MENU GLOWNE--------------" << endl;
	cout << "1. Reczenie uzupelnij tablice" << endl;
	cout << "2. Losuj dane do tablicy " << endl;
	cout << "3. Tworzenie tabeli" << endl;
	cout << "0. Opuszczenie programu" << endl;

	char flag;
	int n;
	cout << " * Opcja: "; cin >> flag;
	cout << endl;

	system("cls");
	switch (flag)
	{
	case '1':

		cout << "Podaj ilosc elementow do wpisania: ";
		while (!(cin >> n))
		{
			cout << "Podaj ilosc elementow do wpisania: "; 
			cin.clear();
			cin.sync();
			cin.ignore();
		}

		table = creatTable(n);
		sizeTable = n;
		menuUserChoice(n);
		break;

	case '2':		
		cout << "Podaj ilosc elementow do losowania: ";
		while (!(cin >> n))
		{
			cout << "Podaj ilosc elementow do losowania: ";
			cin.clear();
			cin.sync();
			cin.ignore();
		}

		table = creatTable(n);
		sizeTable = n;
		menuPseudoChoice(n);
		break;

	case '3':
		menu();
		// TWORZENIE TABELKI Z DANYMI
		break;

	case'0':
		cout << "Koniec dzialania programu. " << endl;
		exit(0);

	default:
		cout << "Brak wyboru w menu.Sprobuj ponownie " << endl;
		show_menu();
	}
	cout << endl;
}
void CSortTable::chooseWay()
{
	cout << "Wybierz kierunek sortowania: " << endl; 
	cout << "1. Sortuja rosnaco " << endl;
	cout << "2. Sortuja malejaco " << endl;

	char flag;
	cin >> flag;
	switch (flag)
	{
	case '1':
		way = true;
		break;
	case '2':
		way = false;
		break;
	default:
		system("cls");
		cout << "Cos poszlo nie tak. Wybierz 1 lub 2" << endl;
		chooseWay();
	}
}
void CSortTable::menuPseudoChoice(int _n)
{
	int a, b;
	// Zabezpieczenie generatora, da sie to jakos zrobiæ na TRY CATCH ??? ~AREK

	cout << "Podaj zakres generacji liczb: ";
	while (!(cin >> a >> b))
	{
		cout << "Podaj zakres generacji liczb : ";
		cin.clear();
		cin.sync();
		cin.ignore();
	}
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
	for (int i = 0; i < _n; i++)
	{
		table[i] = generate(mt);
		cout << table[i] << " ";
	}
}

void CSortTable::menuUserChoice(int _n)
{
	for (int i = 0; i < _n; i++)
	{
		cout << "Podaj " << i + 1 << " element tablicy : ";
		cin >> table[i];
	}
}

void CSortTable::menu()
{

}

void CSortTable::menuMethodChoice()
{
	system("cls");
	cout << "----------------------------" << endl;
	cout << "Wylosowana tablica: " << endl;
	cout << "----------------------------" << endl;

	showTable();

	cout << "--------------METODY--------------" << endl;
	cout << "1. Sortowanie babelkowe" << endl;
	cout << "2. Sortowanie babelkowe(ciagla kontrola monotonicznosci) " << endl;
	cout << "3. Sortowanie babelkowe(wariant wahadlowy)" << endl;
	cout << "4. Sortowanie kubelkowe" << endl;
	cout << "5. Sortowanie przez wybor" << endl;
	cout << "6. Sortowanie przez wstawianie" << endl;
	cout << "7. Sortowanie szybkie(algorytm podzialu Horne'a)" << endl;
	cout << "8. Sortowanie szybkie(algorytm podzialu Lomuta)" << endl;
	cout << "9. Sortowanie przez kopcowanie" << endl;
	cout << "0. Powrot do mentu glwonego" << endl;

	cout << " * Opcja : ";
	char flag; cin >> flag;
	cout << endl;
	switch (flag)
	{
	case'1':

		bubbleSort();
		break;

	case'2':
		bubbleSortCOM();
		break;

	case'3':
		shakerSort();
		break;
	case'4':

		bucketSort();
		break;

	case'5':

		selectionSort();
		break;

	case'6':

		insertSort();
		break;

	case'7':

		quickSortH(0,sizeTable-1);
		break;

	case'8':

		quickSortL(0, sizeTable - 1);
		break;

	case'9':

		heapSort();
		break;

	case '0':
		system("cls");
		CSortTable();
		break;
		
	default:
		cout << "Brak wyboru w menu.Sprobuj ponownie " << endl;
		menuMethodChoice();

	}
}
	
void CSortTable::showTable()
{
	system("cls");
	cout << "----------------------------" << endl;
	cout << "Dane w tablicy:  " << endl;
	cout << "----------------------------" << endl;

	int *wsk = table;
	for(int i = 0; i < sizeTable; i++)
		cout << *wsk++ << ", ";
	cout << endl;

	if(comparision) cout << "Ilosc porownan: " << comparision << endl;
	if(inversion) cout << "Ilosc przestawien: " << inversion << endl;
	cout << endl;
}


// Zobaczcie czy tak to moze byc!!
void CSortTable::saveToFile()
{
	std::string nameFile;
	cout << "Podaj nazwe pliku: "; cin >> nameFile;
	std::ofstream outFile(nameFile + ".txt");
	if(outFile.fail())
	{
		cout << "Cos poszlo nie tak! " << endl;
		exit(0);
	}
	// Zapis tablicy do pliku
	int *wsk = table;
	for(int i = 0; i < sizeTable; i++)
		outFile << *wsk++ << ' ';
	outFile << endl;

	outFile.close();
}

void CSortTable::printTable()
{
	system("cls");
	cout << "Co zrobic z tablica: " << endl; 
	cout << "1. Wyswietlic dane: " << endl;
	cout << "2. Zapisac sorotwane dane do pliku " << endl;
	cout << "3. Wyswietlic i zapisac sortowane dane do pliku" << endl;

	char flag; cin >> flag;

	switch(flag)
	{
	case '1':
		showTable();
		break;
	case '2': 
		saveToFile();
		break;
	case '3':
		showTable();
		saveToFile();
		break;
	default:
		cout << "Cos poszlo nie tak!" << endl;
		printTable();
	}
}
