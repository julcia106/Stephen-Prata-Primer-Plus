#include "pch.h"
#include <iostream>
#include <cstdlib>

int silnia (int liczba);

int main () {

	int s;

	std::cout << "podaj liczbe, '00' konczy. \n";
	std::cin >> s;
	
	while ( s != 00 ) {

		std::cout << s <<"!= " << silnia (s) << std::endl;
		std::cout << "Wprowadz kolejna liczbe('00' konczy): \n";
		std::cin >> s;

	}
	return 0;
}

int silnia (int liczba) {

	if ( liczba == 0 )
		return 1;
	else if ( liczba < 2 )
		return liczba;
	else
		return liczba * silnia (liczba - 1);
	return 0;
}