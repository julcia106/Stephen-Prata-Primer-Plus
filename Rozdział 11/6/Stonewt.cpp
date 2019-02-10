#include "pch.h"
#include "Stonewt.h"
#include <iostream>
using namespace std;

Stonewt::Stonewt (double Ibs) {
	stone = int (Ibs) / Lbs_per_stn; // dzielenie całkowite
	pds_left = int (Ibs) % Lbs_per_stn + Ibs - int (Ibs);
	pounds = Ibs;
}

Stonewt::Stonewt (int stn, double Ibs) // konstruuje obiekt Stonewt z liczby kamieni i funtów
{
	stone = stn;
	pds_left = Ibs;
	pounds = stn * Lbs_per_stn + Ibs;
}

Stonewt::Stonewt () { // konstruktor domyślny, zeruje obiekt
	stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt () {}

ostream & operator<<(ostream& os, const Stonewt & st) {
	os << st.pounds << " funtow, ";
	return os;

}

bool operator== (const Stonewt & lhs, const Stonewt& rhs) {
	if ( lhs.pounds == rhs.pounds )
		return true;
	else
		return false;
}

bool operator!= (const Stonewt & lhs, const Stonewt& rhs) {
	if ( lhs.pounds != rhs.pounds )
		return true;
	else
		return false;
}

bool operator> (const Stonewt & lhs, const Stonewt& rhs) {
	if ( lhs.pounds > rhs.pounds )
		return true;
	else
		return false;
}

bool operator< (const Stonewt & lhs, const Stonewt& rhs) {
	if ( lhs.pounds < rhs.pounds )
		return true;
	else
		return false;
}

bool operator>= (const Stonewt & lhs, const Stonewt& rhs) {
	if ( lhs.pounds >= rhs.pounds )
		return true;
	else
		return false;
}

bool operator<= (const Stonewt & lhs, const Stonewt& rhs) {
	if ( lhs.pounds <= rhs.pounds )
		return true;
	else
		return false;
}