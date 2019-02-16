#include "pch.h"
#include <iostream>
const int Max = 5;

int* fill_array (int * ar, int limit);
void show_array (const int * ar, int * end);
void revalue (int * ar, int * end, int r);

int main () {

	using namespace std;
	int properties [Max];
	int* end_of_array = fill_array (properties, Max);
	show_array (properties, end_of_array);

	cout << " Podaj czynnik zmiany wartosci: ";
	int factor;
	cin >> factor;
	
	revalue (properties, end_of_array, factor);
	show_array (properties, end_of_array);
	cout << "Gotowe.\n";

	return 0;
}

int* fill_array (int * ar, int limit) {

	using namespace std;
	double temp;
	int i;
	for (i = 0; i<limit; i++ ) {
		cout << "Podaj wartosc nr" << i + 1 << ": ";
		cin >> temp;

		if ( !cin ) {
			cin.clear ();
			while ( cin.get () != '\n' )
				continue;
			cout << "Bledne dane, wprowadzanie danych przerwane.\n";
			break;
		}
		else if ( temp < 0 )
			break;
		*(ar + i) = temp;
	}
	return (ar+i);
}
void show_array (const int * ar, int * end) {

	using namespace std;
	const int *pt = ar;

	for ( int i = 0; pt < end; i++, pt++ ) {
		cout << " Nieruchomosc nr " << (i + 1) << ": ";
		cout << *pt << endl;
	}
}
void revalue (int * ar, int * end, int r) {

	int* pt = ar;
	for (int i = 0; pt< end; i++, pt++ )
		*pt *= r;

}