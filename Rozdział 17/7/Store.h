#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

class Store {
public:
	Store (std::ofstream & fout);
	void operator ()(const std::string & s);
private:
	std::ofstream* os;
};