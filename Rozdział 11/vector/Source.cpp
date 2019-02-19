#include "pch.h"
#include "vector.h"
#include <iostream>
using namespace std;

int main () {

	Vector temp;
	Vector one = Vector (23, 76);
	Vector two = Vector (1, 2);

	cout << one << endl;

	temp = one + two;
	cout << temp << endl;

	temp = one * 2;
	cout << temp << endl;

	temp = one - two;
	cout << temp << endl;

	temp = 5 * two;
	cout << temp << endl;

}