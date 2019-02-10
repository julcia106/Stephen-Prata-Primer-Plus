#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <valarray> 
#include "Pair.h"

class Wine: private std::string, private std::valarray<int>,
	private Pair<std::valarray<int>, std::valarray<int>> {
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	int years;

public:
	Wine ();
	Wine (const char* l, int y, const int yr[], const int bot[]);
	Wine (const char* l, int y);
	void GetBottles ();
	const std::string Label () const { return (const std::string&)*this; }
	int   sum () const;
	void show () const;
};



