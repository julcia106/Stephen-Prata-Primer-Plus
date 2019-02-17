#include "pch.h"
#include <iostream>
#include <cstring>
#include <new>

struct chaff { 
	char dross [20];
	int slag;
};

char buffer1 [50];
char buffer2 [500];

int main () {
	using namespace std;

	chaff* p1 = new (buffer1) chaff;
	char* p2 = new (buffer2) char [1];

	for ( int i = 0; i < 2; i++ ) {

		cout << "Imie: " << endl;
		cin >> p2;
		strcpy (p1->dross, p2);

		cout << "Liczba: " << endl;
		cin >> p1[i].slag;
	}

	for ( int i = 0; i < 2; i++ ) {
		cout << "Imie:" << p1[i].dross << endl;
		cout << "Liczba: " << p1[i].slag << endl;
	}

}
