#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Lotto (int Liczbapol, int Liczbanumerow);

int main () {

	std::vector<int>winners;
	winners = Lotto (51, 6);

	std::cout << winners [0];
}

std::vector<int> Lotto (int Liczbapol, int Liczbanumerow) {

	std::vector<int>numbers= 
	{ 1, 2, 3, 4, 6, 6, 7, 8, 9, 10, 12, 13,
	14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,28,30,
	31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
	49,50,51};

	random_shuffle (numbers.begin (), numbers.end ());

	for ( int i = 1; i <Liczbanumerow; i++ )
		std::cout << numbers[i] << " ";

	return numbers;
}
