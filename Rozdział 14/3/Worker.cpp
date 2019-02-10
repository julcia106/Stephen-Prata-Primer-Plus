#include "pch.h"
#include "Worker.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Worker::Set () {
	cout << "Podaj imie i nazwisko: " << endl;
	getline (cin, fullname);
	cout << "Podaj numer identyfikacyjny: " << endl;
	cin >> id;
}

void Worker::Show () const {

	cout << "Imie i nazwisko: " << fullname << endl;
	cout << "Numer identyfikacyjny: " << id << endl;
}
