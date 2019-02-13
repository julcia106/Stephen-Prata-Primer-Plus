#include "pch.h"
#include <iostream>

using namespace std;

void harmoniczna (int x, int y);

int main () {
	int a, b;

	while ( a != 0 && b != 0 ) {
		cin >> a >> b; //TODO
		harmoniczna (a, b);
	}
}

void harmoniczna (int x, int y) {
	double srednia;

	srednia = ((2.0 * x * y) / (x + y));
	cout << srednia << endl;

}