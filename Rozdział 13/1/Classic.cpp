#include "pch.h"
#include "classic.h"
#include <iostream>
using namespace std;


//Cd::Cd(const Cd& d) {
//
//}
//
//
//Classic::Classic (char * m_s) {
//
//}
// 
//


void Cd::Report () const {

	cout << "wykonawcy: " << performers << endl;
	cout << "nazwa: " << label << endl;
	cout << "liczba utworow: " << selections << endl;
	cout << "dlugosc plyty w minutach: " << playtime << endl;
}

Cd::Cd (const char *s1, const char *s2, int n, double x) {

	strcpy (performers, s1);
	strcpy (label, s2);
	selections = n;
	playtime = x;
}

Classic::Classic (const char *s1, const char *s2, const char *s3, int i, double x): Cd::Cd (s1, s2, i, x) {
	//lista inicjalizacyjna reszta konstruktora

	strcpy (main_song, s3);
}

