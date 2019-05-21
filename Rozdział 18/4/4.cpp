#include "pch.h"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

//void outint (int n) { std::cout << n << " "; }
auto outint = [](int n) {std::cout << n << " "; };

int main () {
	using namespace std;
	list<int> one (5, 2); // lista pięciu wartości 2
	int stuff [5] = { 1, 2, 4, 8, 6 };
	list<int> two;
	two.insert (two.begin (), stuff, stuff + 5);
	int more [6] = { 6, 4, 2, 4, 6, 5 };
	list<int> three (two);

	three.insert (three.end (), more, more + 6);
	cout << "Lista one: ";
	for_each (one.begin (), one.end (), outint);

	cout << endl << "Lista two: ";
	for_each (two.begin (), two.end (), outint);

	cout << endl << "Lista three: ";
	for_each (three.begin (), three.end (), outint);
	//three.remove (2);
	std::remove_if (three.begin (), three.end (), [](int x) {return x == 2; });
	cout << endl << "Lista three bez dwojek: ";
	for_each (three.begin (), three.end (), outint);

	three.splice (three.begin (), one);
	cout << endl << "Lista three po uzyciu funkcji splice: ";
	for_each (three.begin (), three.end (), outint);

	cout << endl << "Lista one: ";
	for_each (one.begin (), one.end (), outint);

	three.unique ();
	cout << endl << "Lista three po uzyciu funkcji unique: ";
	for_each (three.begin (), three.end (), outint);

	three.sort ();
	three.unique ();
	cout << endl << "Lista three po uzyciu funkcji sort oraz unique: ";
	for_each (three.begin (), three.end (), outint);

	two.sort ();
	three.merge (two);
	cout << endl << "Posortowana lista two wklejona w liste three: ";
	for_each (three.begin (), three.end (), outint);
	cout << endl;

	return 0;
}

