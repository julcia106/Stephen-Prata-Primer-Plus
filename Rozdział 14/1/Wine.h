#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <valarray> 
#include "Pair.h"

class Wine {
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	std::string label;
	PairArray data;
	int years;

public:
	Wine ();
	Wine (const char* l, int y, const int yr[], const int bot[]);
	Wine (const char* l, int y);
	void GetBottles ();
	const std::string Label () const { return label; }
	int   sum () const;
	void show () const;
};


