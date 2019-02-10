#pragma once
#include "pch.h"
#include <iostream>
#include <cstring>

class Cow {
private:
	char name [20];
	char* hobby;
	double weight;
	int len;
	static int num_strings;
public:
	Cow ();
	Cow (const char * nm, const char* ho, double wt);
	Cow (const Cow &c); //konstruktor kopiujacy  
	~Cow ();
	Cow& operator= (const Cow& c); //operator przypisania
	void ShowCow () const; //wyœwietla wszystkie dane obiektu
};