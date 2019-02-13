#include "pch.h"
#include "Sales.h"
#include <iostream>


int main () {
	using namespace SALES;
	Sales one;
	double array [4] = { 1,2,3,4 };

	setSales (one, array, 4);

	Sales two;

	std::cout << "uzupelnianie tablicy interaktywnie (wpisz liczby): " << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		std::cin >> two.sales [i];
	}
	setSales (two);

	std::cout << "tablica nieinteraktywna: " << std::endl;
	showSales (one);
	std::cout << "tablica interaktywna: " << std::endl;
	showSales (two);




};