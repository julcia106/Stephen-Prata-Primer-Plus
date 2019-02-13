#include "pch.h"
#include <iostream>
using namespace std;

double add (double, double);
double multi (double, double);

double calculate (double, double, double (*pf)(double, double), double (*ps)(double, double));

int main () {
	double x = 2.2;
	double y = 4.8;

	double q = calculate (x, y, add, multi);
	cout << "dodane dwie funkcje: " << q;
}

double add (double a, double b) {
	return a + b;
}
double multi (double x, double y) {
	return x * y;
}
double calculate (double x, double y, double (*pf)(double, double), double (*ps)(double, double)) {
	add (x, y);
	multi (x, y);
	cout << "dodawanie:" << (*pf)(x, y) << endl;
	cout << "mnozenie: " << (*ps)(x, y) << endl;

	return add (x, y) + multi (x, y);

}