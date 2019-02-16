#include "pch.h"
#include <iostream>
#include <string>

using namespace std; //TODO
#include <cstring>

struct stringy {
	char* str;
	int ct;
};
void set (stringy& s, const char* str);
void show (stringy s);
void show (stringy s, int n);

int main () {
	string beany;
	char testing[] = "Rzeczywistosc to juz nie to, co kiedys. ";

	set (beany, testing);
	show (beany);
	show (beany, 2)
		testing [0] = 'D';
	testing [1] = 'u';
	show (testing);
	show (testing, 3);
	show ("Gotowe!");
	return 0;
}
void set (stringy& s, const char* str) {

	str = new char [strlen (s.str) + 1];
	strcpy(s.str, str);
	

}
void show (stringy s) {
	cout << "pierwsza funkcja: ";
	cout << s.str << endl;
}
void show (stringy s, int n) {
	cout << "druga funkcja: ";
	for ( int i = 0; i < n; i++ )
		cout << s.str << endl;
}
