#include "pch.h"
#include "Golf.h"
#include <iostream>

using namespace std;

Golf::Golf () {
	fullname [0] = '\0';
	handicap = 0;
	std::cout << "konstruktor domyslny" << std::endl;
}

Golf::Golf (const char* name, int hc) {

	strcpy (fullname, name);
	handicap = hc;
	std::cout << "konstruktor z argumentem" << std::endl;
}

void Golf::Setgolf () {
	char name [Len];
	int n;

	cout << "wprowadz imie: " << endl;
	cin.get (name, Len);

	cout << "wprowadz liczbe: " << endl;
	cin >> n;

	*this = Golf (name, n);
}

void Golf::Showgolf () const {
	cout << "imie: " << fullname << endl;
	cout << "liczba: " << handicap << endl;
}