#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main () {
	
	std::cout << "Podaj nazwe pliku: \n";
	std::string plikName;
	std::cin >> plikName;

	std::fstream plik;
	plik.open (plikName.c_str(),std::ios::out | std::ios::app); // out -> tworzy nowy plik | app-> dopisuje do pliku dane | in -> wprowadź do programu(odczyt)

	if (!plik.is_open()) {	
		std::cerr << "Nie mozna otworzyc pliku " << plikName << " do zapisu.\n";
		exit (EXIT_FAILURE);
	}

	std::cout << "Prosze podac dane (znak '$' konczy): \n";
	std::string dane;
	while ( std::getline (std::cin, dane) && dane != "$" )
		plik << dane;
	
	plik.close ();

	return 0;
}