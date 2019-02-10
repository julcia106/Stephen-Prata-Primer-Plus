#include "pch.h"
#include "Stonewt.h"
#include <iostream>
using namespace std;

void display (const Stonewt& st, int n);
int main () {
	Stonewt incognito = 275; // inicjalizacja konstruktorem
	Stonewt wolfe (285.7); // równowa¿enie instrukcji: Stonewt wolfe= 285.7;
	Stonewt taft = 20;

	cout << "Celebryta wazyl " << incognito << endl;
	cout << "Detektyw wazyl " << wolfe << endl;
	cout << "Prezydent wazyl: " << taft << endl;
	incognito = 276.8; // konwersja konstruktorem
	taft = 325; // równowa¿enie intrukcji: teft= Stonewt(325);
	cout << "Po obiedzie celebryta wazy: " << incognito << endl;
	cout << "Po obiedzie prezydent wazy: " << taft << endl;

	Stonewt temp;
	temp = incognito + 200;
	cout << "Dodawanie: " << temp << endl;
	temp = taft - 12;
	cout << "Odejmowanie: " << temp << endl;
	temp = wolfe * 2;
	cout << "Mnozenie: " << temp << endl;
}