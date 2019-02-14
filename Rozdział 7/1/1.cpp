#include "pch.h"
#include <iostream>

double harmoniczna (int x, int y);

int main () {
	int a, b;
	std::cout << "Podaj dwie liczby, 0 konczy\n";
	std::cin >> a >> b; 

	while ( a!=0 && b!=0 ) {

		std::cout << "Srednia harmoniczna: " << harmoniczna (a, b) << std::endl;
		std::cout << "Podaj dwie kolejne liczby: \n";
		std::cin >> a >> b;


	}
}
double harmoniczna (int x, int y) {
	double srednia;

	srednia = ((2.0 * x * y) / (x + y));
	return srednia;
}