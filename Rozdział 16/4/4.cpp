#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
const int NUM = 15;

int reduce (long ar[], int n);
void show (long ar[], int n);

int main () {

	long arr [NUM] = { 4,2,6,10,15,22,9,90,1,22,67, 4, 2, 76, 1 };
	
	int temp= reduce (arr, NUM);

	cout << "Lista: ";
	show (arr, temp);
}

int reduce (long ar[], int n) {
	std::sort (ar, ar + NUM);
	long*pt = std::unique (ar, ar + NUM);

	return pt - ar;
}

void show (long ar[], int n) {

	for ( int i = 0; i < n; i++ ) {
		cout << ar [i] << ", ";
	}
}