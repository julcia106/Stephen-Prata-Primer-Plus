#include "pch.h"
#include "golf.h"
#include <iostream>
const int size = 5;

int main () {

	std::cout << "Wprowadz dane " << size << " graczy.\n";
	int players = 0;
	golf list [size];
	while ( players < size&& setgolf (list [players]) ) {
		players++;
	}

	std::cout << "Dane graczy : \n";
	if ( players > 0 ) {
		for ( int i = 0; i < players; i++ )
			showgolf (list [i]);

		std::cout << "Wprowadz numer: \n";
		int newHandicap;
		std::cin.clear ();

		while ( !(std::cin >> newHandicap) ) {

			std::cin.clear ();
			while (std::cin.get () != '\n' )
				continue;
			std::cout << "Sporoboj ponownie: ";
		}

		std::cout << "Wprowadzone dane graczy: \n";
		for ( int i = 0; i < players; i++ ) {
			handicap (list [i], newHandicap);
			showgolf (list [i]);
		}
	}
	else {
		std::cout << "Brak graczy. \n";
	}

	return 0;
}

