#include "pch.h"
#include "Stonewt.h"
#include <iostream>
using namespace std;

Stonewt Stonewt::operator*(double n) const {
	Stonewt temp;
	double total = pounds * n;
	temp.pounds = total;
	temp.stone = int (total) / 14;
	temp.pds_left = int (total) % Lbs_per_stn;
	return temp;
}

Stonewt operator*(const Stonewt & a, const Stonewt & b) {
	Stonewt temp;
	double total = a.pounds * b.pounds;
	temp.pounds = total;
	temp.stone = int (total) / 14;
	temp.pds_left = int (total) % Stonewt::Lbs_per_stn;
	return temp;
}

Stonewt operator+(const Stonewt & a, const Stonewt & b){
	Stonewt temp;
	double total = a.pounds + b.pounds;
	temp.pounds = total;
	temp.stone = int (total) / 14;
	temp.pds_left = int (total) % Stonewt::Lbs_per_stn;
	return temp;
}

Stonewt operator-(const Stonewt & a, const Stonewt & b) {
	Stonewt temp;
	double total = a.pounds - b.pounds;
	temp.pounds = total;
	temp.stone = int (total) / 14;
	temp.pds_left = int (total) % Stonewt::Lbs_per_stn;;
	return temp;
}

Stonewt::Stonewt (double Ibs, Mode form) {
	if ( form == STONE ) { // kamienie
		stone = int (Ibs) / Lbs_per_stn;
		pds_left = stone % Lbs_per_stn;
		pounds = Ibs;
	}

	else if ( form == PDS ) { // bez czesci ulamkowej
		stone = int (Ibs) / Lbs_per_stn;
		pds_left = int (Ibs) % Lbs_per_stn;
		pounds = Ibs;
	}

	else if ( form == PDSL ) { // z czescia ulamkowa
		stone = int (Ibs) / Lbs_per_stn;
		pounds = Ibs;
		pds_left = int (Ibs) % Lbs_per_stn;
	}
	else
		cout << "blad";
}

Stonewt::Stonewt () { // konstruktor domyślny, zeruje obiekt
	stone = 0;
	pounds = pds_left = 0.0;
}
Stonewt::~Stonewt () {}

ostream & operator<<(ostream& os, const Stonewt & st) {
	os << st.stone << " kamieni, " << st.pds_left << " funtow." << endl;
	os << st.pounds << " samych funtow." << endl;
	return os;

}