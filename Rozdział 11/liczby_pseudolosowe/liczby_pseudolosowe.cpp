﻿#include "pch.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main () {

	srand (time (NULL));

	int min, max;

	max = 10;
	min = 9;
	int number = ((rand () % ((max - min) + 1)) + min);

	cout << number;

	return 0;


}