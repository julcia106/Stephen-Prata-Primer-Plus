#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <iterator>

int main () {
	using namespace std;

	ifstream bolek;
	ifstream lolek;

	bolek.open ("bolek.txt");
	if ( !bolek.is_open () ) {
		cout << "Nie mozna otworzyc pliku bolek.txt\n";
		exit (EXIT_FAILURE);
	}

	string temp_bolek;
	list <string> lista_bolka;
	while ( !bolek.eof () ) {
		getline (bolek, temp_bolek);
		lista_bolka.push_back (temp_bolek);
	}
	
	lista_bolka.sort ();
	list<string>::iterator pd;
	for ( pd = lista_bolka.begin (); pd != lista_bolka.end (); pd++ )
		cout << *pd << " ";
	cout << endl;

	lolek.open ("lolek.txt");
	if ( !lolek.is_open () ) {
		cout << "Nie mozna otworzyc pliku lolek.txt\n";
		exit (EXIT_FAILURE);
	}

	string temp_lolek;
	list<string> lista_lolka;
	while ( !lolek.eof () ) {
		getline (lolek, temp_lolek);
		lista_lolka.push_back (temp_lolek);
	}

	lista_lolka.sort ();
	list<string>::iterator pt;
	for ( pt = lista_lolka.begin (); pt != lista_lolka.end (); pt++ )
		cout << *pt << " ";
	cout << endl;

	lista_lolka.merge (lista_bolka);
	lista_lolka.unique ();

	for ( pt = lista_lolka.begin (); pt != lista_lolka.end (); pt++ )
		cout << *pt << " ";
	cout << endl;

	ofstream balilol;
	balilol.open ("balilol.txt");
	if ( !balilol.is_open () ) {
		cout << "Nie mozna otworzyc pliku balilol.txt\n";
		exit (EXIT_FAILURE);
	}

	for ( pt = lista_lolka.begin (); pt != lista_lolka.end (); pt++ ) {
		balilol << *pt << endl;
	}

	cout << "Gotowe.\n";
	bolek.close ();
	lolek.close ();
	balilol.close ();
	return 0;
}