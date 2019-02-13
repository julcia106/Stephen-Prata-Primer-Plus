#include "pch.h"
#include "Stack.h"
#include <iostream>
#include <cctype>


int main () {
	using namespace std;
	Stack st;
	char ch;
	int temp = 0;
	customer person;

	cout << "Nacisnij D, aby wprowadzic deklaracje, " << endl;
	cout << "P, aby przetworzyc deklaracjê , lub K, aby zakonczyc" << endl;
	while ( cin >> ch && toupper (ch) != 'K' ) {
		while ( cin.get () != '\n' )
			continue;
		if ( !isalpha (ch) ) {
			cout << '\a';
			continue;
		}
		switch ( ch ) {
		case 'D':
		case'd': cout << "Podaj imie:" << endl;
			cin.get (person.fullname, 35);
			cout << "Podaj platnosc: " << endl;
			cin >> person.payment;
			if ( st.isfull () )
				cout << "stos pelen!" << endl;
			else {
				st.push (person);
				temp += person.payment;
			}


			break;
		case'P':
		case 'p':
			if ( st.isempty () )
				cout << "Stos pusty" << endl;
			else {
				st.pop (person);
				cout << "person zdjete: " << endl;
				cout << "imie: " << person.fullname << endl;
				cout << "liczba: " << person.payment << endl;
				cout << "calosc: " << temp << endl;
			}
			break;

		}
		cout << "nacisnij D, aby wprowadzic deklaracje, " << endl;
		cout << "P, aby przetworzyc deklaracje, lub K, aby zakonczyc" << endl;

	}
	cout << "koniec.";
	return 0;


}