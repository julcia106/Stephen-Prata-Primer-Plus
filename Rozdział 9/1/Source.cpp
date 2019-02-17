#include "pch.h"
#include "golf.h"
#include<cstring>
#include<iostream>

void setgolf (golf & g, const char * name, int hc) {
	std::strcpy (g.fullname, name);
	g.handicap = hc;
	return;
}

int setgolf (golf & g) {

	std::cout << "Wprowadz imie: ";
	std::cin.get (g.fullname, Len);
	if ( (g.fullname) [0] == '\0' ) {
		std::cin.clear ();  
		std::cin.get ();
		return 0;
	}
	else {
		while ( std::cin.get () != '\n' )
			continue;
		std::cout << "Wprowadz handicap: ";
		std::cin >> g.handicap;
		std::cin.get (); 	
		return 1;
	}
}

void handicap (golf & g, int hc) {
	g.handicap = hc;
	return;
}

void showgolf (const golf & g) {

	std::cout << "Imie: " << g.fullname << std::endl;
	std::cout << "handicap: " << g.handicap << std::endl;
	return;
}
