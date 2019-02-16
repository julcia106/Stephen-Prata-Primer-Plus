#include "pch.h"
#include <iostream>
using namespace std;
const int SLEN = 20; 

void show_char (const char* test, int n=0);

int main () {

	std::cout << "Wprowadz slowo: \n";
	char test [SLEN];
	cin.getline (test, SLEN);

	show_char (test);
	show_char (test, 1);
	show_char (test);
	show_char (test, 1);

}

void show_char (const char* test, int n) {
	
	static int count = 0;
	count++;

	if ( n == 1 ) {
		cout << test << endl;
		return;
	}
	else {
		for ( int i = 0; i < count; i++ )
			cout << test << endl;
	}

	return;

}