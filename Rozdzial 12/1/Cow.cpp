#include "pch.h"
#include "Cow.h"
#include <iostream>
#include <string>
using namespace std;

int Cow::num_strings = 0;

Cow::Cow () {

	weight = 0;
	len = 4;
	name [0] = 0;
	hobby = new char [4];
	std::strcpy (hobby, "C++"); // ci¹g domyœlny
	num_strings++;
	cout << num_strings << ": \"" << hobby
		<< "\" -obiekt domyslny utworzony.\n";

}

Cow::Cow (const char * nm, const char* ho, double wt) {

	weight = wt;
	std::strcpy (name, nm);
	len = strlen (ho);
	hobby = new char [len + 1];
	strcpy (hobby, ho);
	num_strings++;
	cout << num_strings << ": \"" << hobby
		<< "\"-obiekt utworzony.\n";

}

Cow::Cow (const Cow &c) {

	num_strings++;
	len = c.len;
	hobby = new char [len + 1];
	std::strcpy (hobby, c.hobby);
	cout << num_strings << ": \"" << hobby << "\"- obiekt utworzony.\n";

}

Cow::~Cow () {

	cout << "\"" << hobby << "\"- obiekt usuniety, ";
	num_strings--;
	cout << "sa jeszcze " << num_strings << ".\n";
	delete[] hobby;

}

Cow& Cow::operator= (const Cow& c) {

	if ( this == &c )
		return *this;
	delete[] hobby;
	len = c.len;
	hobby = new char [len + 1];
	std::strcpy (hobby, c.hobby);
	return *this;
}

void Cow::ShowCow () const {
	cout << "hobby: " << hobby << endl;
	cout << "waga: " << weight << endl;
	cout << "imie: " << name << endl;
}