#include "pch.h"
#include <iostream>
#include <string>


void strcount (std::string str);

int main () {
	using namespace std;
	string input;
	string next;

	cout << "Wprowadz wiersz: " << endl;
	while ( cin >> input && input != "q" ) {
		strcount (input);
		cout << " Wprowadz nastepny wiersz(wiersz pusty konczy wprowadzenie): " << endl;
		cin >> input;
		strcount (input);
		cout << " Wprowadz nastepny wiersz(wiersz pusty konczy wprowadzenie): " << endl;
	}
	cout << "Koniec" << endl;
	return 0;
}

void strcount (std::string str) {
	using namespace std;
	static int total = 0;
	int count = 0;
	int size = str.size ();

	cout << "\"" << str << "\" zawiera ";

	while ( count != size )
		count++;
	total += count;
	cout << count << " znakow. " << endl;
	cout << "lacznie " << total << " znakow" << endl;
}