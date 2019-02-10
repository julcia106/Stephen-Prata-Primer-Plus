#include "pch.h"
#include "stock.h"
#include <iostream>
#include <cstring>

const int STKS = 4;

int main () {
	using std::cout;

	Stock stocks [STKS] =
	{
		Stock ("NanoSmart", 12, 20.0),
		Stock ("BurakPol", 200, 2.0),
		Stock ("GruzPOL", 130, 3.25),
		Stock ("FutroPOL", 60, 6.5),
	};

	cout << "Portfel inwestycyjny:\n";

	for ( int i = 0; i < STKS; i++ )
		cout << stocks [i];

	const Stock* top = &stocks [0];
	for ( int i = 0; i < STKS; i++ )
		top = &top->topval (stocks [i]); 

	cout << "Najbardziej wartosciowy pakiet:\n";
	cout << *top;
	return 0;
}