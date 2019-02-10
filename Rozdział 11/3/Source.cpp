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
	int target;
	int dstep;
	int N;
	double average = 0.0;

	cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	while ( cin >> target ) {

		cout << "Podaj dlugosc kroku: ";
		if ( !(cin >> dstep) )
			break;

		cout << "Podaj liczbe prob (N): ";
		if ( !(cin >> N) )
			break;

		int min = INT_MAX;
		int max = 0;

		for ( int i = 0; i < N; i++ ) {

			while ( result.magval () < target ) {
				direction = rand () % 360;
				step.reset (dstep, direction, Vector::POL);
				result = result + step;
				//cout << result << endl;
				steps++;
			}

			cout << "kroki dla proby: " << steps << endl;

			if ( min > steps )
				min = steps;

			if ( max < steps )
				max = steps;

			average = (target / dstep) * (target / dstep);

			cout << endl;
			cout << "Srednia liczba krokow: " << average << endl;
			cout << "Minimalna liczba krokow: " << min << endl;
			cout << "Maksymalna liczba krokow: " << max << endl;
			cout << endl;

			cout << "Po " << steps << " krokach delikwent "
				"osiagnal polozenie" << endl;
			cout << result << endl;
			result.polar_mode ();
			cout << "Czyli" << result << endl;
			cout << "Srednia dlugosc kroku pozornego= "
				<< result.magval () / steps << endl;
			steps = 0;
			result.reset (0.0, 0.0);

		}

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