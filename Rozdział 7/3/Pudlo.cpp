#include "pch.h"
#include <iostream>
using namespace std;

struct pudlo {
	const char producent [40];
	float wysokosc;
	float szerokosc;
	float dlugosc;
	float objetosc;
};

void show (pudlo p);
void volume (pudlo & p);

int main () {
	pudlo mini =
	{
		"marka",
		12,
		5,
		1,
		5
	};
	show (mini);
	volume (mini);
}

void show (pudlo p) {
	cout << "dane: " << endl;
	cout << p.producent << ", " << p.wysokosc << ", " << p.szerokosc;
	cout << ", " << p.dlugosc << ", " << p.objetosc << endl;
}

void volume (pudlo & p) {
	double v;
	v = (p.dlugosc * p.szerokosc * p.wysokosc);
	p.objetosc = v;
	cout << "volume: " << p.objetosc;
}
