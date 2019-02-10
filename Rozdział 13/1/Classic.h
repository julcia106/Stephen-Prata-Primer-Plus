#pragma once
#include "pch.h"
#include <iostream>

class Cd {
private:
	char performers [50];
	char label [20];
	int selections;
	double playtime;
public:
	Cd (const char *s1, const char *s2, int n, double x);
	//Cd (const Cd& d);
	Cd () {};
	~Cd () {};
	virtual void Report () const;
	//Cd& operator=(const Cd& d); nie trzeba jezeli nie ma new
};

class Classic: public Cd {

private:
	char main_song [50];
public:
	Classic () {};
	~Classic () {};
	//Classic (char * m_s);
	Classic (const char *s1, const char *s2, const char *s3, int i, double x);

	virtual void Report () const {
		Cd::Report (); //!!! w c++ musi byæ w javie nie!
		std::cout << "glowny utwor na plycie: " << main_song;
	};

};
