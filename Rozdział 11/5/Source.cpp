#include "pch.h"
#include "Stonewt.h"
#include <iostream>
using namespace std;

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

	cout << "Dodawanie (Incognito + 200): " << incognito + 200 << endl;
	cout << "Odejmowanie (prezydent -12): " << taft - 12 << endl;
	cout << "Mnozenie (Detektyw * 2): " << wolfe * 2 << endl;
	cout << "Dodawanie celebryty i prezydenta :" << incognito + taft << endl;
	cout << "Mnozenie (Detektyw * Prezydent): " << wolfe * taft << endl;
	cout << "Odejmowanie (Detektyw - celebryta): " << wolfe - incognito << endl;
}