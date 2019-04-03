#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool is_palindrom (string & str);

int main () {

	string word;

	cout << "Prosze podac slowo: " << endl;
	getline (cin, word);

	if(is_palindrom (word))
		cout << "Twoje slowo jest palindromem. " << endl;
	else
		cout << "Twoje slowo nie jest palindromem. " << endl;
}
 
bool is_palindrom (string & str) {

	string palindrome;

	for ( unsigned int i = 0; i < str.size (); i++ )
		if ( isalpha (str [i]) )
			palindrome.push_back (tolower (str [i]));

	for ( int i = 0, j = palindrome.size () - 1; i < j; i++, j-- )
		if ( palindrome [i] != palindrome [j] )
			return false;
		else
			return true;

}
