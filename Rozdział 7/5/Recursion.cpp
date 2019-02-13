#include "pch.h"
#include <iostream>
using namespace std;

int recursion (int n);

int main () {
	int number;
	cin >> number;

	int wynik = recursion (number);
	cout << wynik;
}

int recursion (int n) {

	if ( n == 0 )
		return 1;
	else
		return(n * recursion (n - 1));

}