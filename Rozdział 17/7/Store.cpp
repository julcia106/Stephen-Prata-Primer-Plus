#include "pch.h"
#include "Store.h"
#include <iostream>

Store::Store (std::ofstream & fout) {
	os = &fout;
}

void Store::operator ()(const std::string & s) {

	size_t len = s.size ();
	os->write ((char*)& len, sizeof (std::size_t));
	os->write ((char*)s.data (), len);
}