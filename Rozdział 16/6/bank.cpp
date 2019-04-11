#include "pch.h"
#include "bank.h"
#include <iostream>
#include "bank.h"

void Customer::set (long when) {
	processtime = std::rand () % 3 + 1;
	arrive = when;
}
