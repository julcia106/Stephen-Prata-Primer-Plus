#include "pch.h"
#include "Person.h"
#include <iostream>

Person::Person () {
	lname = " ";
	fname [0] = '\0';
}

Person::Person (const std::string& ln, const char* fn) {
	lname = ln;
	strcpy (fname, fn);

}

void Person::Show () const {
	using std::cout;
	using std::endl;


	cout << "first name: " << fname << endl;
	cout << "last name: " << lname << endl;


}
void Person::FormalShow () const {
	using std::cout;
	using std::endl;

	cout << "last name: " << lname << endl;
	cout << "first name: " << fname << endl;
}