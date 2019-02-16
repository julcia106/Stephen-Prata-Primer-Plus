#include "pch.h"
#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const std::array<std::string, Seasons> Snames =
{ "Wiosna", "Lato", "Jesien", "Zima" };

void fill (std::array<double, Seasons> *pa);
void show (std::array<double, Seasons> da);

int main () {
	std::array<double, Seasons> expenses;
	fill (&expenses);
	show (expenses);
	return 0;
}
void fill (std::array<double, Seasons> * pa) {

	for ( int i = 0; i < Seasons; i++ ) {
		std::cout << "Podaj wydatki za okres>> " << Snames [i] << " <<: ";
		std::cin >> (*pa) [i];
	}
}
void show (std::array<double, Seasons> da) {

	double total = 0.0;
	std::cout << "\nWYDATKI\n";
	for ( int i = 0; i < Seasons; i++ ) {
		std::cout << Snames [i] << ": " << da [i] << "zl\n";
		total += da [i];
	}
	std::cout << "Laczne wydatki roczne: " << total << "zl\n";
}