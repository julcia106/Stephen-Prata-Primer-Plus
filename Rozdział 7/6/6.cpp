#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

void fill_array (double ar[], int n);
void show_array (double ar[], int n);
double reverse_array (double ar[], int n);

int main () {
	int size;
	cout << "wielkosc: " << endl;
	cin >> size;

	double tab [size]; //TODO
	cout << "wartosci: " << endl;

	fill_array (tab, size);
	show_array (tab, size);
	reverse_array (tab, size);



}
void fill_array (double ar[], int n) {
	for ( int i = 0; i < n; i++ ) {
		cin >> ar [i];
	}
}

void show_array (double ar[], int n) {
	for ( int i = 0; i < n; i++ )
		cout << ar [i] << endl;
}
double reverse_array (double ar[], int n) {
	cout << "odwrocone: ";

	for ( int i = (n - 1); i >= 0; i-- ) {
		cout << ar [i];
	}


}