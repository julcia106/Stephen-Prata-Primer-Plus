#include "pch.h"
#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void ShowStr (const string & str);
void GetStrs (std::ifstream & fs, vector<string>& str);

int main () {

	vector <string> vostr;
	string temp;

	//pobierz łańcuchy
	cout << "Podaj lancuchy (aby zakonczyc, wprowadz pusty wiersz):\n";
	while ( getline (cin, temp) && temp [0] != '\0' )
		vostr.push_back (temp);
	cout << "Oto twoje dane wejsciowe.\n";
	for_each (vostr.begin (), vostr.end (), ShowStr);

	//zapisz w pliku
	ofstream fout ("lancuchy.dat", ios_base::out | ios_base::binary);
	for_each (vostr.begin (), vostr.end (), Store (fout));
	fout.close ();

	//odczytaj zawartość pliku 
	vector <string> vistr;
	ifstream fin ("lancuchy.dat", ios_base::in | ios_base::binary);
	if ( !fin.is_open () ) {
		cerr << "Nie mozna otworzyc pliku do oczytu.\n";
		exit (EXIT_FAILURE);
	}	

	GetStrs (fin, vistr);
	cout << "\nOto lancuchy odczytane z pliku:\n";
	for_each (vistr.begin (), vistr.end (), ShowStr);

	cout << "Gotowe.\n";
	return 0;
}

void ShowStr (const std::string & str) {
	
	cout << str << endl;
}
 
void GetStrs (std::ifstream & fs, vector<string>& str) { //odczytuje dane z pliku

	string temp;
	char ch;
	size_t len;


	while ( fs.read ((char*)&len, sizeof (size_t))){

		for ( int i = 0; i < len; ++i ) {
			fs.read ((char*)&ch, sizeof (char));
			temp.push_back (ch);
		}

		str.push_back (temp);
		temp.clear ();

	}
}