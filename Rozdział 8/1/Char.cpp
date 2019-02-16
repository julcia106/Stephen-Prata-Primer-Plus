#include "pch.h"
#include <iostream>
using namespace std;
const int SLEN = 20; //TODO

void show_char (char tab[], int);

int main () {
	char test[] = "test";
	show_char (test, 1);
	show_char (test, 1);
	show_char (test, 1);
	show_char (test, 1);

}

void show_char (char tab[], int n) {
	
	int temp = 1;
	if ( n == 1 ) {

		for ( int i = 0; i < temp; i++ ) {
			cout << tab << endl;
			cout << "temp= " << temp << endl;
		}
		temp++;
	}
	else if ( n == 0 )
		temp--;

	return;

}