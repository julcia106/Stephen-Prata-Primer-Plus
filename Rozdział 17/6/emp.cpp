#include "pch.h"
#include "emp.h"
#include <fstream>
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
	std::cin >> fname;
	cout << "Podaj nazwisko: \n";
	std::cin >> lname;
	cout << "Podaj zawod: \n";
	std::cin >> job;
}

void abstr_emp::writeall (std::ofstream & fs) {

	fs << "Imie: " << fname << endl;
	fs << "Nazwisko: " << lname << endl;
	fs << "Zawod: " << job << endl;
	cout << endl;
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

void employee::writeall (std::ofstream& fs) {
	abstr_emp::writeall (fs);
}

manager::manager (const std::string & fn, const std::string & ln, const std::string & j, int ico)
	:abstr_emp (fn, ln, j) {
	inchargeof = ico;
}

manager::manager (const manager & m)
	: abstr_emp (m) {
	inchargeof = m.inchargeof;
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

void manager::writeall (std::ofstream& fs) {
	fs << "Liczba obiektow: " << inchargeof << endl;
	abstr_emp::writeall (fs);
}

fink::fink (const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	:abstr_emp (fn, ln, j) {
	reportsto = rpo;
}

void fink::ShowAll () const {
	abstr_emp::ShowAll ();
	cout << "Osoba do ktorej fink przesyla raport: "
		<< reportsto << endl;
}

void fink::SetAll () {
	cout << "Podaj do kogo fink przesyla raport: \n";
	getline (cin, reportsto);

	abstr_emp::SetAll ();
}

void fink::writeall (std::ofstream& fs) {
	fs << "Raporty przesylane do: " << reportsto << endl;
	abstr_emp::writeall (fs);
}

void highfink::ShowAll () const {
	abstr_emp::ShowAll ();
	cout << "Liczba obiektow: " << InChargeOf () << endl;
	cout << "Raporty przesylane sa do: " << ReportsTo () << endl;
}

void highfink::SetAll () {
	abstr_emp::SetAll ();
	cout << "Wpisz liczbe obiektow: \n";
	cin >> InChargeOf ();
	cout << "Podaj do kogo przesylane sa raporty: \n";
	cin >> ReportsTo ();
}

void highfink::writeall (std::ofstream& fs) {
	abstr_emp::writeall (fs);
}