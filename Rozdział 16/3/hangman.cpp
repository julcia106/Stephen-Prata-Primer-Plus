// hangman.cpp -- wybrane metody klasy string
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
const int NUM = 26;

int main () {

	using namespace std;
	std::srand (std::time (0));

	ifstream fin;
	fin.open ("Text.txt");

	if ( fin ) {
		cout << "Udalo sie otworzyc plik!\n";
	}
	else {
		cout << "Nie udalo sie odczytac pliku\n";
		exit (EXIT_FAILURE);
	}

	vector <string> lista;
	string linia;
	int count = 0;

	fin >> linia;
	while ( fin ) {
		++count;
		cout <<count << ": " <<  linia << endl;
		lista.push_back (linia); 
		fin >> linia;
	}
	cout << "Wielkosc listy wektor: " << lista.size () << endl;

	char play;
	cout << "Czy chcesz zagrac w gre slowna? <t/n> ";
	cin >> play;
	play = tolower (play);

		while ( play == 't' ) {

			string secret_word= lista[std::rand () % lista.size()];

			cout << "Ukryte slowo dla sprawdzenia: " << secret_word << ". Jego wielkosc: "
				<< secret_word.size () << endl;

			int length = secret_word.size ();

			string attempt (length, '-');
			string badchars;
			int guesses = 6;
			cout << "Zgadnij moje sekretne slowo. Ma ono " << length
				<< " liter. Mozesz zgadywac\n"
				<< "po jednej literze naraz. Mozesz pomylic sie " << guesses
				<< " razy.\n";
			cout << "Twoje slowo: " << attempt << endl;
			while ( guesses > 0 && attempt != secret_word ) {
				char letter;
				cout << "Zgadnij litere: ";
				cin >> letter;
				if ( badchars.find (letter) != string::npos
					|| attempt.find (letter) != string::npos ) {
					cout << "Ta litera juz byla. Sprobuj innej.\n";
					continue;
				}
				int loc = secret_word.find (letter);
				if ( loc == string::npos ) {
					cout << "Nie ma takiej litery!\n";
					--guesses;
					badchars += letter; // dodaje do ciągu
				}
				else {
					cout << "Poprawna litera!\n";
					attempt [loc] = letter;
					// sprawdza, czy litera nie pojawia się ponownie w innym miejscu
					loc = secret_word.find (letter, loc + 1);
					while ( loc != string::npos ) {
						attempt [loc] = letter;
						loc = secret_word.find (letter, loc + 1);
					}
				}
				cout << "Twoje slowo: " << attempt << endl;
				if ( attempt != secret_word ) {
					if ( badchars.length () > 0 )
						cout << "Niepoprawne litery: " << badchars << endl;
					cout << "Mozesz pomylic sie jeszcze " << guesses << " razy\n ";
				}
			}
			if ( guesses > 0 )
				cout << "To juz cale slowo!\n";
			else
				cout << "Niestety, to slowo to " << secret_word << ".\n";

			cout << "Czy chcesz zagrac jeszcze raz? <t/n> ";
			cin >> play;
			play = tolower (play);
		}

	cout << "Koniec\n";
	fin.close ();
	return 0;
}

