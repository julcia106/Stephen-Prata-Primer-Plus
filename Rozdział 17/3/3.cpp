#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main () {

	using namespace std;
	char ch;

	cout << "Podaj nazwe pliku do ktorego chcesz skopiowac dane: \n";
	string FileName;
	cin >> FileName;

	ifstream fin ("Text.txt", ios_base::in);
	ofstream fout (FileName.c_str (), ios_base::out | ios_base::app);

	string temp;
	if ( !fin.is_open () && !fout.is_open() ) {
		cerr << "Nie mozna otworzyc pliku do skopiowania!\n";
		exit (EXIT_FAILURE);
	}
	else {

		cout << "Kopiuje tekst\n";
		while ( getline (fin, temp) ) {
			fout << temp;
			fout << endl;
		}
	}

	cout << "Gotowe.\n";
	fin.close ();
	return 0;
}