#include "pch.h"
#include "Dynamic_cd.h"
#include <iostream>
using namespace std;

Cd::Cd () {

	cout << "konstruktor domyslny: " << endl;
	performers = new char [1];
	performers [0] = '\0';

	label = new char [1];
	label [0] = '\0';

	selections = 0;
	playtime = 0.0;

}

Cd::Cd (const char *s1, const char *s2, int n, double x) {

	performers = new char [strlen (s1) + 1];
	strcpy (performers, s1);

	label = new char [strlen (s2) + 1];
	strcpy (label, s2);

	selections = n;
	playtime = x;
}

Cd::Cd (const Cd& p) {

	performers = new char [strlen (p.performers) + 1];
	strcpy (performers, p.performers);

	label = new char [strlen (p.label) + 1];
	strcpy (label, p.label);

	selections = p.selections;
	playtime = p.playtime;
}

Cd& Cd::operator=(const Cd& d) {

	if ( this == &d )
		return *this;

	delete[] performers;
	delete[] label;

	performers = new char [strlen (d.performers) + 1];
	strcpy (performers, d.performers);

	label = new char [strlen (d.label) + 1];
	strcpy (label, d.label);

	selections = d.selections;
	playtime = d.playtime;

	return *this;

}

Cd::~Cd () {

	cout << "uzywam destruktora dla cd: " << endl;
	delete[] performers;
	delete[] label;
}


void Cd::Report () const {

	cout << "wykonawcy: " << performers << endl;
	cout << "nazwa: " << label << endl;
	cout << "liczba utworow: " << selections << endl;
	cout << "dlugosc plyty w minutach: " << playtime << endl;
}


Classic::Classic () {

	cout << "konstruktor domyslny" << endl;
	main_song = new char [1];
	main_song [0] = '\0';
}

Classic::Classic (const char *s1, const char *s2, const char *s3, int i, double x)
	: Cd::Cd (s1, s2, i, x) {
	//lista inicjalizacyjna reszta konstruktora

	main_song = new char [strlen (s3) + 1];
	strcpy (main_song, s3);
}

Classic::~Classic () {

	cout << "uzywam destruktora dla classic: " << endl;
	delete[] main_song;
}

Classic::Classic (const Classic& cl)
	: Cd (cl) { //!

	main_song = new char [strlen (cl.main_song) + 1];
	strcpy (main_song, cl.main_song);
}

Classic& Classic::operator=(const Classic& cl) {

	if ( this == &cl )
		return *this;
	Cd::operator=(cl);//!
	delete[] main_song;
	main_song = new char [strlen (cl.main_song) + 1];
	strcpy (main_song, cl.main_song);

	return *this;

}


