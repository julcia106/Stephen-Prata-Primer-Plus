#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <iterator>

using namespace std;

void is_open (ifstream& file, string fileName);
void is_open (ofstream& file, string fileName);

int main () {

	ifstream bolek;
	ifstream lolek;

	bolek.open ("bolek.txt");
	lolek.open ("lolek.txt");

	is_open (bolek, "bolek");
	is_open (lolek, "lolek");

	string temp;
	list <string> lista_bolka;
	list <string> lista_lolka;

	while ( !bolek.eof () ) {
		getline (bolek, temp);
		lista_bolka.push_back (temp);
	}
	
	lista_bolka.sort ();

	while ( !lolek.eof () ) {
		getline (lolek, temp);
		lista_lolka.push_back (temp);
	}

	lista_lolka.sort ();
	lista_lolka.merge (lista_bolka);
	lista_lolka.unique ();

	ofstream party;
	party.open ("balilol.txt");
	is_open (party, "balilol");

	list<string>::iterator pd;
	for ( pd = lista_lolka.begin (); pd != lista_lolka.end (); pd++ ) {
		party << *pd << endl;
	}

	cout << "Gotowe.\n";
	bolek.close ();
	lolek.close ();
	party.close ();
	return 0;
}

void is_open (ifstream& file, string file_name) {

	if ( !file.is_open () ) {
		cerr << "Nie mozna otworzyc pliku " << file_name << "\n";
		exit (EXIT_FAILURE);
	}
}

void is_open (ofstream& file, string file_name) {

	if ( !file.is_open () ) {
		cerr << "Nie mozna otworzyc pliku " << file_name << ".txt\n";
		exit (EXIT_FAILURE);
	}
}