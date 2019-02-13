#include "pch.h"
#include <iostream>
#include <cstring>
#include <new>

struct chaff { //TODO
	char dross [20];
	int slag;
};

char buffer1 [50];
char buffer2 [500];

int main () {
	using namespace std;

	char temp [20];

	chaff* p1 = new (buffer1) chaff;
	char* p2 = new (buffer2) char [3];

	for ( int i = 0; i < 2; i++ ) {
		cout << "imie: " << endl;
		cin.get (temp, 20).get ();
		p2 = temp;
		strcpy (p1->dross, p2);


		cout << "liczba: " << endl;
		cin >> p1 [i].slag;
	}

	for ( int i = 0; i < 2; i++ ) {
		cout << "imie:" << p1 [i].dross << endl;
		cout << "liczba: " << p1 [i].slag << endl;
	}

}
