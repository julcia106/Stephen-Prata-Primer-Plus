#include "pch.h"
#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>


int main () {
	using namespace std;
	using VECTOR::Vector;
	srand (time (0)); //inicjalizacji liczb pseudolosowych
	double direction;
	Vector step;
	Vector result (0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream fout;

	cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	while ( cin >> target ) {

		cout << "Podaj dlugosc kroku: ";
		if ( !(cin >> dstep) )
			break;

		fout.open ("marsz.txt");
		fout << "Dystans do przejscia: " << target << ", dlugosc kroku: " << dstep << endl;

		while ( result.magval () < target ) {
			direction = rand () % 360;
			step.reset (dstep, direction, Vector::POL);
			result = result + step;
			cout << steps << ": " << result << endl;

			fout << steps << ": " << result << endl;

			result.magval ();
			steps++;
		}


		fout << "Po " << steps << " krokach delikwent"
			"osiagnal polozenie" << endl;
		fout << result << endl;

		result.polar_mode ();
		fout << "Czyli" << result << endl;
		fout << "Srednia dlugosc kroku pozornego= "
			<< result.magval () / steps << endl;
		steps = 0;
		result.reset (0.0, 0.0);
		cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	}

	fout.close ();
	cout << "Koniec!" << endl;
	cin.clear ();
	while ( cin.get () != '\n' )
		continue;
	return 0;
}