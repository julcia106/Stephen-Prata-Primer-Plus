#include "pch.h"
#include "Stonewt.h"
#include <iostream>
using namespace std;

void display (const Stonewt& st, int n);

int main () {
	Stonewt incognito = 275; // inicjalizacja konstruktorem
	Stonewt wolfe (285.7); // równowa¿ne instrukcji: Stonewt wolfe= 285.7;
	Stonewt taft = 20;

	cout << "Celebryta wazyl " << incognito << endl;
	cout << "Detektyw wazyl " << wolfe << endl;
	cout << "Prezydent wazyl: " << taft << endl;
	incognito = 276.8; // konwersja konstruktorem
	taft = 325; // równowa¿enie intrukcji: teft= Stonewt(325);
	cout << "Po obiedzie celebryta wazy: " << incognito << endl;
	cout << "Po obiedzie prezydent wazy: " << taft << endl;

	cout << "Dodawanie: " << incognito + 200 << endl;
	//cout << "Dodawanie incognito i taft (275+20) :" << incognito + taft << endl;
	cout << "Odejmowanie: " << taft- 12 << endl;

	cout << "Mnozenie: " << wolfe *2 << endl;
}