#include "pch.h"
#include "complex_number.h"
#include <iostream>
using namespace std;

int main () {
	Complex a (3.0, 4.0);
	Complex c;

	cout << "Podaj liczbe zespolona (k, aby zakonczyc):\n";
	cout << endl;
	while ( cin >> c ) {
		cout << "c to " << c << '\n';
		cout << "sprzezona z c to " << c.operator~() << endl;
		cout << " a to " << a << endl;
		cout << " a + c wynosi " << a.operator+(c) << endl;
		cout << " a - c wynosi " << a.operator-(c) << endl;
		cout << " a * c wynosi " << a.operator*(c) << endl;
		cout << " 2 * c wynosi " << c.operator*(2) << endl;
		cout << "Podaj liczbe zespolona (k, aby zakonczyc)" << endl;
	}
	cout << "Gotowe" << endl;
	return 0;
}