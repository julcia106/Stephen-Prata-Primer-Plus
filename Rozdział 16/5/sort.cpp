#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int NUM = 15;

template <class T>
int reduce (T ar[], int n);

template <class T>
void show (T ar[], int n);

int main () {

	long arr [NUM] = { 4,2,6,10,15,22,9,90,1,22,67, 4, 2, 76, 1 };

	int temp = reduce(arr, NUM);

	show(arr, temp);
}

template <class T>
int reduce (T ar[], int n) {

	std::sort (ar, ar + NUM);
	T *pt = std::unique (ar, ar + NUM);

	return pt - ar;
}

template <class T>
void show (T ar[], int n) {

	cout << "Lista: ";
	for ( int i = 0; i < n; i++ ) {
		cout << ar [i] << ", ";
	}
}