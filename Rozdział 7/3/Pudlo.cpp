#include "pch.h"
#include <iostream>

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
		"SuperPudlo200",
		12,
		5,
		1,
		5
	};
	show (mini);
	volume (mini);

	return 0;
}

void show (pudlo p) {
	std::cout << "Dane: \n";
	std::cout << "Nazwa: " << p.producent << "\n";
	std::cout << "Wysokosc: " << p.wysokosc << "\n";
	std::cout << "Szerokosc: " << p.szerokosc << "\n";
	std::cout << "Dlugosc: " << p.dlugosc << "\n";

	return;
}

void volume (pudlo & p) {
	double v;
	v = (p.dlugosc * p.szerokosc * p.wysokosc);
	p.objetosc = v;
	std::cout << "Objetosc: " << p.objetosc << "\n";

	return;
}
