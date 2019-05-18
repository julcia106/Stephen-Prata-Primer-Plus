#include "pch.h"
#include <iostream>

long double sum = 0;

//definicja dla pustej liczby argumentów- wywołanie kończące rekurencję
void sum_values () {}

//definicja dla jednego bądź wielu parametrów
template <typename T, typename...Args>
void sum_values (T value, Args...args) {

	std::cout << value << std::endl;
	sum += value;
	sum_values (args...);

}

int main () {

	sum_values (34, 88.5, 2);

	std::cout << "suma: " << sum << std::endl;

	std::cout << "Gotowe.\n";
	return 0;
}