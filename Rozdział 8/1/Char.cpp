#include "pch.h"
#include <iostream>
using namespace std;
const int SLEN = 20;

void show_char (char tab[], int);

int main () {
	char test[] = "test";

	int n;
	cout << "podaj liczbe: " << endl;
	cin >> n;

	show_char (test, n);

}

void show_char (char tab[], int n) {
	if ( n > 0 ) {
		for ( int i = 0; i <= n; i++ ) {
			cout << "wyswietlam wyraz po raz:  " << i + 1 << endl;
			cout << tab << endl;
		}
	}

}