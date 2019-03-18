#pragma once
#include "pch.h"
#include <iostream>
#include <stdexcept>

class basic_mean:public std::logic_error {
public:
	basic_mean (double a, double b, const std::string& what_arg):
		std::logic_error (what_arg), m_a(a), m_b(b) {}
	const char * what () { return std::logic_error::what (); }
	~basic_mean () = 0 {}
	virtual void show ()const { std::cout << "zle wartosci: " << m_a << " oraz " << m_b << std::endl; }

private:
	double m_a;
	double m_b;
};

class bad_hmean: public basic_mean {
public:
	bad_hmean (double a, double b, const std::string& what_arg):basic_mean (a,b,what_arg){}
	void show () const;
};

class bad_gmean: public basic_mean {
public:
	bad_gmean (double a, double b, const std::string& what_arg):basic_mean (a,b,what_arg) {}
	void show () const;
};

