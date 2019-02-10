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
	enum Mode { STONE, PDS, PDSL };
	Stonewt (double Ibs, Mode form = STONE);
	Stonewt ();
	~Stonewt ();
	Stonewt operator+(double n) const;
	Stonewt operator-(double n) const;
	Stonewt operator*(double n) const;
	friend ostream& operator<<(ostream& os, const Stonewt & st);
};