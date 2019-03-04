#include "pch.h"
#include "Person.h"
#include <iostream>
#include <cstring>

const int SIZE = 2;

int main () {
	
	using std::strchr;

	Person* gang [SIZE];
	for (int i = 0; i < SIZE; i++ ) {
		char choice;
		std::cout << "Wybierz jedna osobe: \n"
			<< "z: zwykla osoba g: gunslinger   "
			<< "p: PokerPlayer  b: badDude      "
			<< "w: wyjscie  \n";
		std::cin >> choice;
		while ( strchr ("zgpbw", choice) == NULL ) {
			std::cout << "Wypisz z, g, p, b lub w: ";
			std::cin >> choice;
		}
		if ( choice == 'w' )
			break;
		switch ( choice ) {
		case 'z': gang [i] = new Person;
			break;
		case 'g': gang [i] = new Gunslinger;
			break;
		case 'p': gang [i] = new PokerPlayer;
			break;
		case 'b': gang [i] = new BadDude;
			break;
		}
		std::cin.get ();
		gang [i]->Set ();
	}
	std::cout << std::endl;
	std::cout << "Lista gangu: \n";
	for ( int i = 0; i < SIZE; i++ ) {
		std::cout << std::endl;
		gang [i]->Show ();
	}

	for ( int i = 0; i < SIZE; i++ )
		delete gang [i];
	std::cout << std::endl;
	std::cout << "Koniec.\n";

	return 0;
}