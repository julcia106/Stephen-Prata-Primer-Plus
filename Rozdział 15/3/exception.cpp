#include "pch.h"
#include <iostream>
#include <stdexcept>
#include "exception.h"

void bad_hmean::show () const {
	std::cout << "Metoda hmean(): " << std::endl;
	basic_mean::show ();
}

void bad_gmean::show () const {
	std::cout << "Metoda gmean(): " << std::endl;
	basic_mean::show ();
}

