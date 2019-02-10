#pragma once
#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>

class Person {
private:
	static const int LIMIT = 256;
	std::string lname;
	char fname [LIMIT];
public:
	Person ();
	Person (const std::string& ln, const char* fn = "HejTY");
	void Show () const;
	void FormalShow () const;
};