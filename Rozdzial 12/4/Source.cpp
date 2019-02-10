#include "pch.h"
#include "Stack.h"
#include <iostream>
#include <cstring>

using namespace std;

int main () {

	Stack one;
	Item* temp = new Item [10];
	unsigned long value;

	for ( int i = 0; i < 10; i++ ) {
		cout << "wprowadz wartosc numer " << i + 1 << ": ";
		cin >> temp [i];
		one.push (temp [i]);
	}

	one.show ();

	if ( one.isempty () )
		cout << "stos pusty" << endl;
	else
		cout << "cos znajduje sie na stosie" << endl;

	if ( one.isempty () )
		cout << " stos pusty, nie mozna nic zdjac. " << endl;
	else {
		one.pop (value);
	}

	one.show ();

}