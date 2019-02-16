#include "pch.h"
#include <iostream>
#include <string>

const int Seasons = 4;
const char* Snames [Seasons] = { "Wiosna", "Lato", "Jesien", "Zima" };
struct expenses {
	double tab [Seasons];
};

void fill_array (expenses* exp);
void show_array (expenses* exp);

int main () {
	expenses year;

	fill_array (&year);
	show_array (&year);
	return 0;
}
void fill_array (struct expenses* exp) {

	for ( int i = 0; i < Seasons; i++ ) {
		std::cout << "Podaj wydatki za okres>> " << Snames [i] << " <<: ";
		std::cin >> (exp->tab) [i];

	}
}
void show_array (expenses* exp) {

	double total = 0.0;
	std::cout << "\nWYDATKI\n";
	for ( int i = 0; i < Seasons; i++ ) {
		std::cout << Snames [i] << ": " << (exp->tab) [i] << "zl\n";
		total += (exp->tab) [i];
	}
	std::cout << "Laczne wydatki roczne: " << total << "zl\n";
}