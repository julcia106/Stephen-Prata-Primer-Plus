#pragma once
#include "pch.h"
#include <iostream>
#include <cstring>

const int Len = 40;

class Golf {
private:
	char fullname [Len];
	int handicap;
public:
	Golf ();
	Golf (const char* name, int hc);
	void Showgolf () const;
	void Setgolf ();
};