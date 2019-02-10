#pragma once
#include "pch.h"
#include <iostream>

class Cd {
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd (const char *s1, const char *s2, int n, double x);
	Cd ();
	Cd (const Cd& d);
	Cd& operator=(const Cd& d);
	~Cd ();
	virtual void Report () const;
};

class Classic: public Cd {

private:
	char* main_song;
public:
	Classic ();
	~Classic ();
	Classic (const Classic& cl);
	Classic& operator=(const Classic& cl);
	Classic (const char *s1, const char *s2, const char *s3, int i, double x);

	virtual void Report () const {
		Cd::Report (); //!!! w c++ musi byæ w javie nie!
		std::cout << "glowny utwor na plycie: " << main_song;
	};

};
