#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std; 

struct stringy {
	char* str;
	int ct;
};
void set (stringy& s,char str[]);
void show (const stringy& s, int n=1);
void show (const char str[], int n=1);

int main () {
	string beany;
	char testing[] = "Rzeczywistosc to juz nie to, co kiedys. ";

	set (beany, testing);
	show (beany);
	show (beany, 2);
	testing [0] = 'D';
	testing [1] = 'u';
	show (testing);
	show (testing, 3);
	show ("Gotowe!");
	return 0;
}

void set (stringy& s, char str[]) {

	int size = strlen (str);
	char* temp = new char [size + 1];
	strcpy(temp, str);

	s.str = temp;
	s.ct = size;

	return;
}

void show (const stringy& s, int n) {

	cout << "Pierwsza funkcja\n";
	for ( int i = 0; i < n; i++ ) {
		cout << s.str << endl;
	}
	return;
}

void show (const char str[], int n) {

	cout << "druga funkcja: ";
	for ( int i = 0; i < n; i++ )
		cout << str << endl;
	return;
}
