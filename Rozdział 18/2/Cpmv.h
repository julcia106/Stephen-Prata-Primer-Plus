#pragma once
#include "pch.h"
#include <iostream>
#include <string>

class Cpmv {
public:
	struct Info {
		std::string qcode;
		std::string zcode;
	};
private:
	Info *pi;
public:
	Cpmv ();
	Cpmv (std::string q, std::string z);
	Cpmv (const Cpmv & cp); // zwyk³y k. kopiuj¹cy
	Cpmv (Cpmv && mv); //k.przenosz¹cy
	~Cpmv ();
	Cpmv& operator=(const Cpmv& cp); // operator przypisania
	Cpmv& operator= (Cpmv && mv); // przenosz¹cy operator przypisania
	Cpmv operator+(const Cpmv& obj) const;
	void Display () const;
};
