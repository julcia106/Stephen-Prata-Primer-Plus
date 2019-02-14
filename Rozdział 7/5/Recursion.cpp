#include "pch.h"
#include <iostream>
using namespace std;

int recursion (int n);

int main () {
	int number;

	std::cout << "Podaj liczbe: \n";
	cin >> number;

	for ( int i = number; i < 0; i++ ) {

		int wynik = recursion (number);
		cout <<"Wynik: " << wynik;
	}

	return 0;
}

int recursion (int n) {

	if ( n == 0 )
		return 1;
	else
		return(n * recursion (n - 1));

}