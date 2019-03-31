#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool palindrom (string & str);

int main () {

	string word;

	cout << "Prosze podac slowo: " << endl;
	getline (cin, word);
	cout << "Oto Twoje slowo: " << word << endl;

	if ( palindrom (word) )
		cout << "Twoje slowo jest palindromem. " << endl;
	else
		cout << "Twoje slowo nie jest palindromem. " << endl;

}
 
bool palindrom (string & str) {

	string temp = str;

	reverse (str.begin (), str.end ());

	if ( temp.string::compare (str) == 0 )
		return true;
	else
		return false;

}
