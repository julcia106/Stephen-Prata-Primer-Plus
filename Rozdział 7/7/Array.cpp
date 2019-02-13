#include "pch.h"
#include <iostream>
const int Max = 5;

int* fill_array (int * begin, int * end);
void show_array (int * begin, int * end);
void revalue (int * begin, int * end, int r);

int main () {
	using namespace std;
	int properties [Max];
	int* end_of_array;
	end_of_array = fill_array (properties, properties + Max);

	int* pt;
	//TODO pt= &stg;

	show_array (properties, properties + Max);
	if ( end_of_array > 0 ) {
		cout << " Podaj czynnik zmiany wartosci: ";
		int factor;
		while ( !(cin >> factor) ) {
			cin.clear ();
			while ( cin.get () != '\n' )
				continue;
			cout << "Niepoprawna wartosc; podaj liczbe: ";
		}
		revalue (properties, properties + Max, factor);
		show_array (properties, end_of_array);
	}
	cout << "Gotowe.\n";

	cin.get ();
	cin.get ();
	return 0;
}
int* fill_array (int * begin, int * end) {
	using namespace std;
	int temp;
	int* pt;
	int i = 0;
	for ( pt = begin; pt != end; pt++ ) {
		cout << "Podaj wartosc nr" << i + 1 << ": "; // wtf
		cin >> *pt;
		if ( !cin ) {
			cin.clear ();
			while ( cin.get () != '\n' )
				continue;
			cout << "Bledne dane, wprowadzanie danych przerwane.\n";
			break;
		}
		else if ( temp < 0 )
			break;
		//*pt=temp;
		i++;
	}
	return pt;
}
void show_array (int * begin, int * end) {
	using namespace std;
	int *pt;
	int i = 0;
	for ( pt = begin; pt != end; pt++ ) {
		cout << " Nieruchomosc nr " << (i + 1) << ": ";
		cout << *pt << endl;
		i++;
	}
}
void revalue (int * begin, int * end, int r) {
	int* pt;
	for ( pt = begin; pt != end; pt++ )
		*pt *= r;

}