#include "pch.h"
#include "emp.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


const char* file = "emp.txt";
int main (void) {

	const int MAX = 2;
	char ch;

	//poka¿ pocz¹tkow¹ zawartoœæ
	std::ifstream fin;
	fin.open (file);

	if ( fin.is_open () ) {
		std::cout << "Oto aktualna zawartosc pliku "
			<< file << ":\n";
		while ( fin.get (ch) )
			std::cout << ch;
		fin.close ();
	}

	//dodaj nowe osoby
	std::ofstream fout (file, std::ios_base::out | std::ios_base::app);
	if ( !fout.is_open () ) {
		std::cerr << "Nie mozna otworzyc pliku " << file << " do zapisu.\n";
		exit (EXIT_FAILURE);
	}

	abstr_emp* pc [MAX];

	int ct;
	for ( ct = 0; ct < MAX; ++ct ) { 
		char choice;
		std::cout << "Prosze wybrac obiekt do utworzenia: \n"
			<< "e: employee  m: manager \n"
			<< "f: fink      h: highfink\n"
			<< "w: wyjscie\n";
		std::cin >> choice;

		while ( strchr ("emfhw", choice) == NULL ) {
				std::cout << "Wpisz e,m,f,h lub w: ";
				std::cin >> choice;
			}
		if ( choice == 'w' )
			break;
		switch ( choice ) {
			case 'e': pc [ct] = new employee;
				break;
			case 'm': pc [ct] = new manager;
				break;
			case 'f':pc [ct] = new fink;
				break;
			case 'h': pc [ct] = new highfink;
				break;
		}
		std::cin.get ();
		pc [ct]->SetAll ();
		pc [ct]->writeall (fout);
	}
	int i;
	std::cout << "\nLista pracownikow:\n";
	for ( i = 0; i < ct; ++i ) {
		std::cout << std::endl;
		pc [i]->ShowAll ();
	}
	for ( i = 0; i < ct; ++i ) 
		delete pc [i];

	//wyœwietl zmieniony plik
	fin.clear ();
	fin.open (file);
	if ( fin.is_open () ) {
		std::cout << "\nOto nowa zawartosc pliku "
			<< file << ":\n";
		while ( fin.get (ch) )
			std::cout << ch;
		fin.close ();
	}

	fout.close ();
	std::cout << "\nGotowe.\n";
	return 0;
}
