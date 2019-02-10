#include "pch.h"
#include "Wine.h"
#include "Pair.h"
#include <iostream>
#include <valarray>
#include <string>
using namespace std;

Wine::Wine ()
	: label ("brak"), years (0), data (ArrayInt (0), ArrayInt (0)) {

}

Wine::Wine (const char* l, int y, const int yr[], const int bot[])
	: label (l), years (y), data (ArrayInt (yr, y), ArrayInt (bot, y)) {

}

Wine::Wine (const char* l, int y)
	: label (l), years (y), data (ArrayInt (y), ArrayInt (y)) {

}

void Wine::GetBottles () {

	for ( int i = 0; i < years; i++ ) {
		cout << "Podaj rocznik wina " << label << endl;
		cin >> data.first () [i];
		cout << "Podaj liczbe butelek: " << endl;
		cin >> data.second () [i];
	}
}

int Wine::sum () const {
	return data.second ().sum ();
}


void Wine::show () const {

	cout << "Wino: " << label << endl;
	cout << "Rocznik: " << years << endl;

	for ( int i = 0; i < years; i++ ) {
		cout << data.first () [i] << "     ";
		cout << data.second () [i] << endl;

	}
}

