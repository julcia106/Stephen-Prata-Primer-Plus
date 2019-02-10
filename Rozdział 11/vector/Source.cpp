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




	/*((cout  << one) << two) << endl;
	one.operator*(5); == one * 5
		cout << 5 * one;
	one * 5; = metoda
	5 * one; = metoda zaprzyjazniona
	operator*(vector a, int b)
		operator*(int b, vector a)*/
}