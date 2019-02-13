#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void small_to_big (string& a);

int main () {
	string small;
	cout << "Podaj lancuch (q aby skonczyc): " << endl;

	while ( small != "Q" ) {
		getline (cin, small);
		small_to_big (small);
		cout << small;
		cout << endl;
		cout << "Podaj lancuch (q aby skonczyc): " << endl;

	}

}

void small_to_big (string& a) {
	for ( int i = 0; i < a.length (); i++ )// moze mi to Jonasz wytlumaczyc?
	{
		a [i] = toupper (a [i]);
	}
}