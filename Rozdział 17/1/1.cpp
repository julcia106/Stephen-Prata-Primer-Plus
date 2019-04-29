#include "pch.h"
#include <iostream>

int main () {

	char ch;
	int numberOfChar = 0;

	while ( std::cin.get(ch) ) {

		if ( ch != '$' ) {
			numberOfChar++;
		}
		else {
			std::cin.putback (ch);
			break;
		}
	}

	if ( !std::cin.eof () ) {
		std::cin.get (ch);
		std::cout << ch << " to nastepny znak wejsciowy. \n";
	}

	std::cout << "Liczba znakow: " << numberOfChar << "\n";

}