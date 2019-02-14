#include "pch.h"
#include <iostream>

const int Limit = 5;

void fill_ar (double ar[], int n);
void show_ar (double ar[], int n);
void average (double ar[]);

int main () {

	double golf [Limit];

	fill_ar (golf, Limit);
	show_ar (golf, Limit);
	average (golf);


}

void fill_ar (double ar[], int n) {

	std::cout << " Wprowadz " << Limit << " wynikow golfowych: \n";

	for ( int i = 0; i < Limit; i++ ) {
			std::cin >> ar [i];
	}
}
void show_ar (double ar[], int n) {

	std::cout << "Wprowadzone wyniki: \n";
	for ( int i = 0; i < Limit; i++ ) {
		std::cout <<  ar [i] << " ,";
	}
}
void average (double ar[]) {
	double av = 0;
	int a = 0;
	for ( int i = 0; i < Limit; i++ ) {
		av = av + ar [i];
		a++;
	}
	std::cout << "Srenia: " << av / a;
}