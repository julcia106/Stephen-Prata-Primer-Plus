#include "pch.h"
#include <iostream>
#include <cstring>

void fill_array (double ar[], int n);
void show_array (double ar[], int n);
void reverse_array (double ar[], int n);

int main () {

	const int size = 5;

	double tab [size]; 
	std::cout << "Podaj " << size << " wartosci: \n";
	fill_array (tab, size);
	show_array (tab, size);
	reverse_array (tab, size);

	return 0;	
}

void fill_array (double ar[], int n) {

	for ( int i = 0; i < n; i++ ) {
		std::cin >> ar [i];
	}
	return;
}

void show_array (double ar[], int n) {

	std::cout << "Wartosci tablicy: ";
	for ( int i = 0; i < n; i++ )
		std::cout << ar [i];
	std::cout << std::endl;
	return;
}

void reverse_array (double ar[], int n) {
	std::cout << "Wartosci odwrocone: ";

	for ( int i = (n - 1); i >= 0; i-- ) {
		std::cout << ar [i];
	}
	return;

}