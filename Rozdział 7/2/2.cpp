#include "pch.h"
#include <iostream>
using namespace std;

const int Limit = 10;

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
	cout << " wprowadz dane, q konczy : " << endl;
	double number;
	for ( int i = 0; i < Limit; i++ ) {
		if ( cin != "q" ) //TODO

			cin >> ar [i];
	}
}
void show_ar (double ar[], int n) {
	for ( int i = 0; i < Limit; i++ ) {
		cout << ar [i] << " , ";
	}
}
void average (double ar[]) {
	double av;
	int a = 0;
	for ( int i = 0; i < Limit; i++ ) {
		av = av + ar [i];
		a++;
	}
	cout << "srenia: " << av / a;
}