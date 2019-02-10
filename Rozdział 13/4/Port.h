#pragma once
#include "pch.h"
#include <iostream>

class Port {
private:
	char*brand;
	char style [20];
	int bottles;
public:
	Port (const char*br = "Brak", const char*st = "Brak", int b = 0);
	Port (const Port& p); //k. kopiuj¹cy
	virtual ~Port () { delete[] brand; Port::operator-=(1); }
	Port& operator= (const Port & p);
	Port& operator+=(int b); // dodaje b do bottles
	Port& operator-=(int b);// odejmuje b od bottles, jeœli operacja ta jest mo¿liwa
	int BottleCount ()const { return bottles; }
	virtual void Show () const;
	friend std::ostream& operator << (std::ostream& os, const Port& p);
};

class VintagePort: public Port {
	char* nickname; //np. "szlachetny" "aksamitny"
	int year; // rok winobrania
public:
	VintagePort ();
	VintagePort (const char* br, int b, const char * nn, int y);
	VintagePort (const VintagePort& vp);
	~VintagePort () { delete[]nickname; Port::operator-=(1); }
	VintagePort& operator= (const VintagePort& vp);
	void Show () const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);


};
