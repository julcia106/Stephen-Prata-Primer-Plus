#include "pch.h"
#include "Port.h"
#include <iostream>
#include <string>

Port::Port (const char*br, const char*st, int b) {
	brand = new char [strlen (br) + 1];
	strcpy (brand, br);

	strcpy (style, st);
	bottles = b;
	Port::operator+=(1);
}

Port::Port (const Port& p) {

	brand = new char [strlen (p.brand) + 1];
	strcpy (brand, p.brand);

	strcpy (style, p.style);
	bottles = p.bottles;
	Port::operator+=(1);
}

Port& Port::operator= (const Port & p) {

	if ( this == &p )
		return*this;
	delete[] brand;
	brand = new char [strlen (p.brand) + 1];
	strcpy (brand, p.brand);

	strcpy (style, p.style);
	bottles = p.bottles;
	return *this;
	Port::operator+=(1);
}
Port& Port::operator+=(int b) { // dodaje b do bottles

	Port temp;
	temp.bottles = bottles + b;
	return temp;
}

Port& Port::operator-=(int b) {// odejmuje b od bottles, jeśli operacja ta jest możliwa

	Port temp;
	if ( bottles >= b )
		temp.bottles = bottles - b;
	else
		std::cout << " nie wykonac operacji. " << std::endl;
	return temp;
}

void Port::Show () const {
	std::cout << "Marka: " << brand << std::endl;
	std::cout << "Rodzaj: " << style << std::endl;
	std::cout << "Butelek: " << bottles << std::endl;
}

std::ostream& operator << (std::ostream& os, const Port& p) {

	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort ()
	:Port () {

	nickname = new char [4];
	strcpy (nickname, "brak");
	year = 0;

}

VintagePort::VintagePort (const char* br, int b, const char * nn, int y):Port (br, nn, b) {

	nickname = new char [strlen (nn) + 1];
	strcpy (nickname, nn);
	year = y;
}

VintagePort::VintagePort (const VintagePort& vp):Port (vp) {

	nickname = new char [strlen (vp.nickname) + 1];
	strcpy (nickname, vp.nickname);
	year = vp.year;
}
VintagePort& VintagePort::operator= (const VintagePort& vp) {
	if ( this == &vp )
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char [strlen (vp.nickname) + 1];
	strcpy (nickname, vp.nickname);
	year = vp.year;
	return *this;
}
void VintagePort::Show () const {
	Port::Show ();
	std::cout << "Nick: " << nickname << std::endl;
	std::cout << "Rok winobrania: " << year << std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& vp) {

	os << vp.nickname << ", " << vp.year;
	return os;
}