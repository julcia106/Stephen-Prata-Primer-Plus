#include "pch.h"
#include "Bank_Account.h"
#include <iostream>

int main () {
	Bank_Account person1;
	person1.person ("Julia Rutkowska", "2345123", 12.0);
	person1.show ();
	person1.take (2.0);
	person1.give (2.0);
	person1.show ();

}