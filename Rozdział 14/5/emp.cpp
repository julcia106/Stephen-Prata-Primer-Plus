#include "pch.h"
#include "emp.h"
#include <iostream>
using namespace std;

abstr_emp::abstr_emp (const std::string & fn, const std::string & ln, const std::string & j) {
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::ShowAll () const {
	cout << "Imie: " << fname << endl;
	cout << "Nazwisko: " << lname << endl;
	cout << "Zawod: " << job << endl;
}

void abstr_emp::SetAll () {
	cout << "Podaj imie: \n";
	getline (cin, fname);
	cout << "Podaj nazwisko: \n";
	getline (cin, lname);
	cout << "Podaj zawod: \n";
	getline (cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
	os << "Imie: " << e.fname << endl;
	os << "Nazwisko: " << e.lname << endl;
	return os;
}

void employee::ShowAll () const {
	abstr_emp::ShowAll ();
}

void employee::SetAll () {
	abstr_emp::SetAll ();
}

manager::manager (const std::string & fn, const std::string & ln, const std::string & j, int ico)
	:abstr_emp(fn,ln,j)
{
	inchargeof = ico;
}

void manager::ShowAll () const {
	abstr_emp::ShowAll ();
	cout << "Liczba obiektow: " << inchargeof << endl;
}

void manager::SetAll () {
	abstr_emp::SetAll ();
	cout << "Podaj liczbe obiektow: \n";
	cin >> inchargeof;
}

fink::fink (const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	:abstr_emp(fn,ln,j)
{
	reportsto = rpo;
}

void fink::ShowAll () const {
	abstr_emp::ShowAll ();
	cout << "Osoba do ktorej fink przesyla raport: "
		<< reportsto << endl;
}

void fink::SetAll () {
	abstr_emp::SetAll ();
	cout << "Podaj do kogo fink przesyla raport: \n";
	getline (cin, reportsto);
}

highfink::highfink (const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	:abstr_emp(fn,ln,j), fink(fn,ln,j,rpo), manager(fn,ln,j,ico) 
{}

void highfink::ShowAll () const {
	manager::ShowAll ();
	fink::ShowAll ();
}

void highfink::SetAll () {
	manager::SetAll ();
	fink::SetAll ();
}
