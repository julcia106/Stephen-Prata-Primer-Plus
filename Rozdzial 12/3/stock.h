#pragma once
#include "pch.h"
#include <string>
using std::ostream;

class Stock {
private:
	char* company; //
	int len; //
	int shares;
	double share_val;
	double total_val;
	void set_tot () { total_val = shares * share_val; }
public:
	Stock ();
	Stock (const char* co, long n = 0, double pr = 0.0); //
	Stock (const Stock& inny); // k. kopiujacy
	Stock& operator=(const Stock& wzor); //kopiujacy op. przypisania
	~Stock ();
	void buy (long num, double price);
	void sell (long num, double price);
	void update (double price);
	const Stock& topval (const Stock& s) const;

	friend ostream & operator <<(ostream& ekran, const Stock & st); //
};