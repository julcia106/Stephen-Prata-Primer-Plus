#include "pch.h"
#include "Wine.h"
#include "Pair.h"
#include <iostream>
#include <valarray>
#include <string>
using namespace std;

Wine::Wine ()
	: std::string ("brak"), years (0), PairArray (ArrayInt (0), ArrayInt (0)) {

}

Wine::Wine (const char* l, int y, const int yr[], const int bot[])
	: std::string (l), years (y), PairArray (ArrayInt (yr, y), ArrayInt (bot, y)) {

}

Wine::Wine (const char* l, int y)
	: std::string (l), years (y), PairArray (ArrayInt (y), ArrayInt (y)) {

}


void Wine::GetBottles () {

	for ( int i = 0; i < years; i++ ) {
		cout << "Podaj rocznik wina " << (string&)*this << endl;
		cin >> PairArray::first () [i];
		cout << "Podaj liczbe butelek: " << endl;
		cin >> PairArray::second () [i];
	}
}

int Wine::sum () const {
	return PairArray::second ().sum (); // d. prywatne
}


void Wine::show () const {

	cout << "Wino: " << (string&)*this << endl;
	cout << "Rocznik: " << years << endl;

	for ( int i = 0; i < years; i++ ) {
		cout << PairArray::first () [i] << "    ";
		cout << PairArray::second () [i] << endl;

	}
}

