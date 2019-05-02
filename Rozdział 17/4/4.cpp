#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main () {

	std::ifstream one;
	std::ifstream two;
	std::ofstream three;

	one.open ("one.txt");
	two.open ("two.txt");
	three.open ("three.txt");

	if (!one.is_open ()) {
		std::cout << "Nie mozna otworzyc pliku one.\n ";
		exit (EXIT_FAILURE);
	}
	
	if (!two.is_open()) {
		std::cout << "Nie mozna otworzyc pliku two.\n ";
		exit (EXIT_FAILURE);
	}

	if (!three.is_open ()) {
		std::cout << "Nie mozna otworzyc pliku three.\n";
		exit (EXIT_FAILURE);
	}

	std::string temp_one;
	std::string temp_two;

	while ( !one.eof () && !two.eof () ) {
		std::getline (one, temp_one);
		std::getline (two, temp_two);
		three << temp_one << " " << temp_two << "\n";
	}
	if ( one.eof () && !two.eof() ) {
		getline (two, temp_two);
		three << temp_two << "\n";
	}
	else if ( two.eof () && !one.eof () ) {
		getline (one, temp_one);
		three << temp_one << "\n";
	}

	std::cout << "Gotowe.";
	one.close ();
	two.close ();
	three.close ();

	return 0;
}