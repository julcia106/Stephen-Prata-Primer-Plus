#pragma once
#include "pch.h"
#include <iostream>
using std::ostream;

class Stonewt {
private:
	enum { Lbs_per_stn = 14 }; // liczba funtów na kamien
	int stone; // masa w calych kamieniach
	double pds_left; // reszta w funtach
	double pounds; // masa w funtach
public:
	Stonewt (double Ibs); // konstruktor dla funtów
	Stonewt (int stn, double Ibs); // konstruktor dla kamieni i funtów 
	Stonewt ();
	~Stonewt ();
	friend ostream & operator<<(ostream& os, const Stonewt & st);
	friend bool operator==(const Stonewt & lhs, const Stonewt& rhs);
	friend bool operator!=(const Stonewt & lhs, const Stonewt& rhs);
	friend bool operator> (const Stonewt & lhs, const Stonewt& rhs);
	friend bool operator< (const Stonewt & lhs, const Stonewt& rhs);
	friend bool operator>= (const Stonewt & lhs, const Stonewt& rhs);
	friend bool operator<= (const Stonewt & lhs, const Stonewt& rhs);

};
