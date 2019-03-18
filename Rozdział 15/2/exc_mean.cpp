#include "pch.h"
#include <iostream>
#include <stdexcept>

class bad_hmean: public std::logic_error {
public:
	bad_hmean (const std::string& what_arg): std::logic_error (what_arg) {}
	//const char * what () { return std::logic_error::what(); }
};

class bad_gmean: public std::logic_error{
public:
	bad_gmean (const std::string& what_arg): std::logic_error (what_arg) {}
	const char * what () { return std::logic_error::what (); }
};

