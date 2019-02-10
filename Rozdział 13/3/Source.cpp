#include "pch.h"
#include "Dma.h"
#include <iostream>
#include <string>


int main () {

	using std::cout;
	using std::cin;
	using std::endl;

	abstractDMA * ptr [4];
	char tempLabel [40];
	int tempR;
	int number;

	for ( int i = 0; i < 2; i++ ) {
		cout << "Podaj nazwe: " << endl;
		cin.get (tempLabel, 40).get ();
		cout << "Podaj liczbe: " << endl;
		cin >> tempR;
		cout << "Wpisz 1 dla baseDMA, 2 dla lackDMA i 3 dla hasDMA: " << endl;

		while ( cin >> number && (number != 1 && number != 2 && number != 3) ) {
			cout << " Wpisz 1, 2 lub 3: " << endl;
		}
		cin.get ();
		if ( number == 1 )
			ptr [i] = new baseDMA (tempLabel, tempR);
		else if ( number == 2 ) {
			char tempColor [40];
			std::cout << "Podaj kolor: " << endl;
			cin.get (tempColor, 40);
			ptr [i] = new lacksDMA (tempColor, tempLabel, tempR);
		}
		else {
			char tempStyle [40];
			cout << "Podaj styl: " << endl;
			cin.get (tempStyle, 40);
			ptr [i] = new hasDMA (tempStyle, tempLabel, tempR);
		}

		while ( cin.get () != '\n' )
			continue;
	}
	cout << endl;
	for ( int i = 0; i < 2; i++ ) {
		ptr [i]->viewDMA ();
		cout << endl;
	}
	for ( int i = 0; i < 2; i++ ) {
		delete ptr [i];
	}

	//baseDMA shirt ("Portabelly", 8);
	//lacksDMA  balloon ("czerwony", "Blimpo", 4);
	//hasDMA map ("Merkator", "Buffalo Keys", 5);
	//cout << "Wypisywanie obiektu baseDMA:\n";
	//shirt.viewDMA ();
	//cout << "Wypisywanie obiektu lackDMA:\n";
	//balloon.viewDMA ();
	//cout << "Wypisywanie obiektu hasDMA:\n";
	//map.viewDMA ();
	//lacksDMA balloon2 (balloon);
	//cout << "Wynik kopiowania lacksDMA: \n";
	//balloon2.viewDMA ();
	//hasDMA map2;
	//map2 = map;
	//cout << "Wynik przypisania hasDMA:\n";
	//map2.viewDMA ();
}