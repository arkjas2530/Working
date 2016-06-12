#include "CSortTable.h"
#include"library.h"

using std::cout;
using std::endl;
using std::cin;

CSortTable::CSortTable()
{
	for (;;)
	{
		show_menu();
		menuMethodChoice();

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
	cout << "0. Opuszczenie programu" << endl;

	
	int n;
	cout << " * Opcja: ";
	char choice;
	cin >> choice;
	cout << endl;

	system("cls");
	
	switch (choice)
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
		// Menu wpisywania danych przez usera
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

		// Menu losowania danych
		menuPseudoChoice(n);
		break;

	case'0':

		cout << "Koniec dzialania programu. " << endl;
		file.close();
		exit(0);

	default:
		cout << "Brak wyboru w menu.Sprobuj ponownie " << endl;
		show_menu();
	}
	cout << endl;
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


void CSortTable::menuMethodChoice()
{
	std::string name, ntable;
	way = true; // na poczatku zawsze ma sortowac rosnaco
	double temp= ceil(static_cast<double>(sizeTable / 10.));// zmienna liczaca 10% z tablicy
	system("cls");

	cout << "----------------------------" << endl;
	cout << "Wylosowana tablica: " << endl;
	cout << "----------------------------" << endl;
	int *wsk = table;

	for (int i = 0; i < sizeTable; i++)
		cout << *wsk++ << ", ";
	cout << endl;

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
	cout << "0. Powrot do mentu glownego" << endl;

	cout << " * Opcja : ";
	char choice;
	cin >> choice;
	cout << endl;
	/*
	Decyduje czy metoda należy do tych od 0 - 7
	Potrzebne do wyswietlania porow. i inv
	*/
	if (choice == '7' || choice == '8'|| choice == '9') simple_method = false;
	else simple_method = true;

	printTable();
	if(flag == '2' || flag == '3')	openToSave();
	
	switch (choice)
	{
	case'1':
		name = "Sortowanie babelkowe(kontrola monotonicznosci): ";
		bubbleSort(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		bubbleSort();	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table,0,static_cast<int> (temp)); //10% zmiana elementow posortowanej tablicyy
		bubbleSort(); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		bubbleSort(); //sortowanie tablicy posortowanej malejaco
		way = true;
		bubbleSort();//sortowanie tablicy posortowanej niemalejaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'2':
		name = "Sortowanie babelkowe(kontrola monotonicznosci): ";
		bubbleSortCOM(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		bubbleSortCOM();	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		bubbleSortCOM(); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		bubbleSortCOM(); //sortowanie tablicy posortowanej malejaco
		way = true;
		bubbleSortCOM();//sortowanie tablicy posortowanej niemalejaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'3':
		name = "Sortowanie babelkowe z wariantem wahadlowym : ";
		shakerSort(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		shakerSort();	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);

		mixingTable(table, 0, static_cast<int> (temp));;
		shakerSort(); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		shakerSort(); //sortowanie tablicy posortowanej malejaco
		way = true;
		shakerSort();//sortowanie tablicy posortowanej niemalejaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;
	case'4':
		name = "Sortowanie kubelkowe : ";
		bucketSort(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		bucketSort();	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		bucketSort(); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		bucketSort(); //sortowanie tablicy posortowanej malejaco
		way = true;
		bucketSort();//sortowanie tablicy posortowanej niemalejaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'5':
		selectionSort(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		selectionSort(); //sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		selectionSort();  //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		selectionSort(); //sortowanie tablicy posortowanej malejaco
		way = true;
		selectionSort();//sortowanie tablicy posortowanej niemalejaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'6':
		name = "Sortowanie przez wstawianie ";
		insertSort(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		insertSort();	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		insertSort(); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		insertSort(); //sortowanie tablicy posortowanej malejaco
		way = true;
		insertSort();//sortowanie tablicy posortowanej niemalejaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'7':
		name = " Sortowanie szybkie Hoarne";

		quickSortH(0, sizeTable - 1); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		quickSortH(0, sizeTable - 1);	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		quickSortH(0, sizeTable - 1); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		quickSortH(0, sizeTable-1); //sortowanie tablicy posortowanej malejaco

		way = true;
		quickSortH(0, sizeTable-1); //sortowanie tablicy posortowanej rosnaco 
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'8':
		name = "Sortowanie szybkie Lomuta";

		quickSortL(0, sizeTable - 1); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		quickSortL(0, sizeTable - 1);	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		quickSortL(0, sizeTable - 1); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		quickSortL(0, sizeTable - 1); //sortowanie tablicy posortowanej malejaco
		way = true;
		quickSortL(0, sizeTable - 1);
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case'9':

		name = "Sortowanie (kopcowanie)";

		heapSort(); //sortowanie tablicy losowej
		ntable = "tablica z wartosciami losowymi";
		showOrSave(name, ntable);

		heapSort();	//sortowanie tablicy posortowanej
		ntable = "tablica posortowana rosnaco ";
		showOrSave(name, ntable);


		mixingTable(table, 0, static_cast<int> (temp));
		heapSort(); //sortowanie tablicy czesciowo posortowanej
		ntable = "tablica czesciowo posortowana";
		showOrSave(name, ntable);

		way = false;
		heapSort(); //sortowanie tablicy posortowanej malejaco
		way = true;
		heapSort();
		ntable = "tablica posortowana malejaco";
		showOrSave(name, ntable);
		file << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		break;

	case '0':
		system("cls");
		CSortTable();
		break;

	default:
		cout << "Brak wyboru w menu.Sprobuj ponownie " << endl;

	}
}
void CSortTable::printTable()
{
	flag = '0';
	system("cls");
	cout << "Co zrobic z tablica: " << endl;
	cout << "1. Wyswietlic dane: " << endl;
	cout << "2. Zapisac sorotwane dane do pliku " << endl;
	cout << "3. Wyswietlic i zapisac sortowane dane do pliku" << endl;
	//zmienna okreslajaca pozniejsze wyswietlanie

	cin >> flag;

	if (flag != '1' && flag != '2' && flag != '3') // ??? Dziwne zmien to
		cout << "Cos poszlo nie tak!" << endl;


}
void CSortTable::showTable(std::string name, std::string ntable)
{

	cout << "----------------------------" << endl;
	cout << "Metoda : " << name << endl;
	cout << "Jaka tablica zostala poddana sortowaniu : " << ntable << endl;
	cout << "Dane w tablicy:  " << endl;


	int *wsk = table;
	for (int i = 0; i < sizeTable; i++)
	cout << *wsk++ << ", ";
	cout << endl;
	
	if (simple_method == true)
	{
		cout << "* Ilosc porownan: " << comparision << endl;
		cout << "* Ilosc przestawien: " << inversion << endl;
		cout << endl;
	}

}

void CSortTable::showOrSave(std::string name, std::string ntable)
{
	switch (flag)
	{
	case '1':
		showTable(name, ntable);
		break;
	case '2':
		saveFile(name, ntable);
		break;
	case '3':
		showTable(name, ntable);
		saveFile(name, ntable);
		break;
	}

}

void CSortTable::saveFile(std::string name, std::string ntable)
{

	file << "----------------------------" << endl;
	file << "Metoda : " << name << endl;
	file << "Jaka tablica zostala poddana sortowaniu : " << ntable << endl;
	file << "Dane w tablicy:  " << endl;


	int *wsk = table;
	for (int i = 0; i < sizeTable; i++)
		file << *wsk++ << ", ";
	file << endl;

	file << "* Ilosc porownan: " << comparision << endl;
	file << "* Ilosc przestawien: " << inversion << endl;
	file << endl;

}

