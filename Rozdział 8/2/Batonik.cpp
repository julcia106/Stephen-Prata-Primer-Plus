#include "pch.h"
#include <iostream>
using namespace std;

struct Batonik {
	const char* name;
	double weigh;
	int calories;
};

void fill_arr (Batonik &data, const char* pt, double a, int b);
void show_arr (Batonik &data);

int main () {
	Batonik milky;

	const char* _name = "Muller Munich";
	double _weigh = 2.45;
	int _calories = 123;


	fill_arr (milky, _name, _weigh, _calories);
	show_arr (milky);
}

void fill_arr (Batonik &data, const char* pt, double a, int b) {
	data.name = pt;
	data.weigh = a;
	data.calories = b;
}

void show_arr (Batonik &data) {
	cout << data.name << endl;
	cout << data.weigh << endl;
	cout << data.calories << endl;
}