#include "pch.h"
#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>


int main () {
	using namespace std;
	using VECTOR::Vector;
	srand (time (0));
	double direction;
	Vector wektor;
	Vector result (0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	while ( cin >> target ) {

		cout << "Podaj dlugosc kroku: ";
		if ( !(cin >> dstep) )
			break;

		while ( result.magval () < target ) {
			direction = rand () % 360;
			wektor.reset (dstep, direction, Vector::POL);
			result = result + wektor;
			steps++;
		}
		cout << "Po " << steps << " krokach delikwent"
			"osiagnal polozenie" << endl;
		cout << result << endl;
		result.polar_mode ();
		cout << "Czyli" << result << endl;
		cout << "Srednia dlugosc kroku pozornego= "
			<< result.magval () / steps << endl;
		steps = 0;
		result.reset (0.0, 0.0);
		cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	}
	cout << "Koniec!" << endl;
	cin.clear ();
	while ( cin.get () != '\n' )
		continue;
	return 0;
}