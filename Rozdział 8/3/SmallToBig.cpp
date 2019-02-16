#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>

void small_to_big (std::string& a);

int main () {
	std::string small;
	std::cout << "Podaj lancuch (q aby skonczyc): \n";

	while ( small != "Q" ) {
		std::getline (std::cin, small);
		small_to_big (small);
		std::cout << small;
		std::cout << std::endl;
		std::cout << "Podaj lancuch (q aby skonczyc): \n";

	}

}

void small_to_big (std::string& a) {
	for ( int i = 0; i < a.length (); i++ )
	{
		a [i] = toupper (a [i]);
	}
}