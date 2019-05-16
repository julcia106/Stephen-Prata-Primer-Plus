#include "pch.h"
#include <iostream>
#include <initializer_list>

template<typename T>
T average_list (const std::initializer_list<T> il);

int main () {
	using namespace std;

	//lista wartości typu double wydedukowana na podstawie zawartości
	auto q = average_list ({ 15.4,10.7,9.0 });
	cout << q << endl;

	//lista wartośći typu int, wydedukowana na bazie zawartości
	cout << average_list ({ 20,30,19,17,45,38 }) << endl;

	//wymuszona lista wartości typu double
	auto ad = average_list<double> ({ 'A', 70, 65.33 });
	cout << ad << endl;

	cout << "Gotowe.\n";
	return 0;
}

template<typename T>
T average_list (const std::initializer_list<T> il) {
		
	T temp = 0;

	for ( auto iter = il.begin (); iter != il.end (); ++iter )
		temp += *iter;

	return temp / il.size ();
}