#include "pch.h"
#include "emp.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const char* file = "emp.txt";

int main (void) {

	const int MAX = 2;
	char ch;

	//poka¿ pocz¹tkow¹ zawartoœæ
	ifstream fin;
	fin.open (file);

	if ( fin.is_open () ) {
		cout << "Oto aktualna zawartosc pliku "
			<< file << ":\n";
		while ( fin.get (ch) )
			cout << ch;
		fin.close ();
	}

	//dodaj nowe osoby
	ofstream fout (file, ios_base::out | ios_base::app);
	if ( !fout.is_open () ) {
		cerr << "Nie mozna otworzyc pliku " << file << " do zapisu.\n";
		exit (EXIT_FAILURE);
	}

	abstr_emp* pc [MAX];

	int ct;
	for ( ct = 0; ct < MAX; ++ct ) { 
		char choice;
		cout << "Prosze wybrac obiekt do utworzenia: \n"
			<< "e: employee  m: manager \n"
			<< "f: fink      h: highfink\n"
			<< "w: wyjscie\n";
		cin >> choice;

		while ( strchr ("emfhw", choice) == NULL ) {
				cout << "Wpisz e,m,f,h lub w: ";
				cin >> choice;
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
		cin.get ();
		pc [ct]->SetAll ();
		pc [ct]->writeall (fout);
	}
	int i;
	cout << "\nLista pracownikow:\n";
	for ( i = 0; i < ct; ++i ) {
		cout << endl;
		pc [i]->ShowAll ();
	}
	for ( i = 0; i < ct; ++i ) 
		delete pc [i];

	//wyœwietl zmieniony plik
	fin.clear ();
	fin.open (file);
	if ( fin.is_open () ) {
		cout << "\nOto nowa zawartosc pliku "
			<< file << ":\n";
		while ( fin.get (ch) )
			cout << ch;
		fin.close ();
	}

	fout.close ();
	cout << "\nGotowe.\n";
	return 0;
}



	//cout << "Podaj imiona i nazwiska gosci(aby, zakonczyc, wprowadz pusty wiersz):\n";
	//string name;
	//while ( getline (cin, name) && name.size () > 0 ) {
	//	fout << name << endl;
	//}
	//fout.close ();
