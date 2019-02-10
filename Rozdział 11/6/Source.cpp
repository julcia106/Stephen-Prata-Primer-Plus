#include "pch.h"
#include "Stonewt.h"
#include <iostream>
using namespace std;

void display (const Stonewt& st, int n); //TODO 

int main () {

	Stonewt temp = 11;

	Stonewt tab [6] =
	{
		Stonewt (2),
		Stonewt (21),
		Stonewt (61),
		Stonewt (11),
		Stonewt (1),
		Stonewt (3),
	};


	Stonewt min = tab [0];
	cout << " najmniejszy element:" << endl;
	for ( int i = 0; i <= 6; i++ ) {
		if ( min > tab [i] )
			min = tab [i];
	}
	cout << min;
	cout << endl;

	Stonewt max = tab [0];
	cout << "najwiekszy element: " << endl;
	for ( int i = 0; i <= 6; i++ ) {
		if ( max < tab [i] )
			max = tab [i];
	}
	cout << max;
	cout << endl;


	cout << "wieksze od temp:" << endl;
	for ( int i = 0; i <= 6; i++ ) {
		cout << (tab [i] > temp ? tab [i] : 0);

	}cout << endl;

	cout << "mniejsze od temp:" << endl;
	for ( int i = 0; i <= 6; i++ ) {
		cout << (tab [i] < temp ? tab [i] : 0);

	}cout << endl;

	cout << "rownej temp: " << endl;
	for ( int i = 0; i <= 6; i++ ) {

		cout << (tab [i] == temp ? tab [i] : 0);


	}cout << endl;
};