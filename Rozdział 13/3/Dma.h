#pragma once
#include "pch.h"
#include <iostream>

class abstractDMA {
public:
	char *label;
	int rating;
public:
	abstractDMA (const char*l = "brak", int r = 0);
	abstractDMA (const abstractDMA &rs);
	abstractDMA& operator= (const abstractDMA &rs);

	virtual void viewDMA () const = 0;
	virtual ~abstractDMA () {}
};

class baseDMA:public abstractDMA {

public:
	baseDMA (const char* l = "brak", int r = 0): abstractDMA (l, r) {}
	baseDMA (const baseDMA &rs): abstractDMA (rs) {}
	virtual ~baseDMA ();
	baseDMA & operator= (const baseDMA & rs);

	virtual void viewDMA () const {
		abstractDMA::viewDMA ();
	}
};

class lacksDMA:public abstractDMA {
private:
	enum { COL_LEN = 40 };
	char color [COL_LEN];
public:
	lacksDMA (const char* c = "brak", const char * l = "brak", int r = 0);
	lacksDMA (const char* c, const baseDMA & rs);

	virtual void viewDMA () const {
		abstractDMA::viewDMA ();
		std::cout << "Kolor: " << color << std::endl;
	}

};

class hasDMA: public abstractDMA {
private:
	char* style;
public:
	hasDMA (const char * s = "brak", const char* l = "brak", int r = 0);
	hasDMA (const char* s, const baseDMA &rs);
	hasDMA (const hasDMA &hs);
	~hasDMA ();
	hasDMA&operator=(const hasDMA& rs);

	virtual void viewDMA () const {
		abstractDMA::viewDMA ();
		std::cout << "Styl: " << style << std::endl;
	}
};
