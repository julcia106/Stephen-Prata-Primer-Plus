#pragma once
#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>

class Bank_Account {
private:
	std::string name; 
	std::string account_number;
	double saldo;
public:
	void person (const std::string& per, const std::string& num, double sal = 0.0); 
	void show (void) const;
	void take (double amount);
	void give (double amount);
};