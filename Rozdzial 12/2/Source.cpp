#include "pch.h"
#include "string.h"
#include <iostream>
using namespace std;

int main () {

	String s1 (" i ucze sie C++.");
	String s2 = "Podaj swoje imie: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "Mam na imie " + s3;
	cout << s2 << endl;
	s2 = s2 + s1;
	cout << s2 << endl;
	s2.stringup ();
	cout << endl;
	cout << "Powyzszy ciag zawiera " << s2.has ('a') << " litery A" << endl;

	s1 = "czerwona"; // String(const char*)
	//a potem String & operator = (const String&)
	String rgb [3] = { String (s1), String ("zielona"), String ("niebieska") };
	cout << "Podaj nazwe barwy podstawowej: ";
	String ans;
	bool success = false;

	while ( cin >> ans ) {
		ans.stringlow (); //zamiana liter w ciagu na ma³e
		for ( int i = 0; i < 3; i++ ) {
			if ( ans == rgb [i] ) { //przeci¹¿ony operator ==
				cout << ". Prawidlowo!\n";
				success = true;
				break;
			}
		}
		if ( success )
			break;
		else
			cout << ". Sprobuj ponownie! \n";

	}
	cout << "Zegnam\n";
	return 0;
}