#include "pch.h"
#include "Bank_Account.h"
#include <iostream>


void Bank_Account::person (const std::string& per, const std::string& num, double sal) {
	saldo = sal;
	name = per;
	account_number = num;
}
void Bank_Account::show (void) const {
	using std::cout;
	using std::endl;

	cout << "Name: " << name << endl;
	cout << "Account number: " << account_number << endl;
	cout << "Saldo: " << saldo << endl;
}
void Bank_Account::take (double amount) {
	saldo += amount;
	std::cout << "Saldo after function take: " << saldo << std::endl;
}
void Bank_Account::give (double amount) {
	saldo += amount;
	std::cout << "Saldo after function give: " << saldo << std::endl;
}