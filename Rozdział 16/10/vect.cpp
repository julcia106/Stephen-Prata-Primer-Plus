// vect3.cpp -- użycie funkcji biblioteki STL
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
	std::string title;
	int rating;
	double price;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool increasing_rating (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool decreasing_rating (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool increasing_price (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool decreasing_price (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview (std::shared_ptr<Review> & rr);
void ShowReview (const std::shared_ptr<Review> & rr);
void Show_menu ();

int main () {
	using namespace std;

	vector<shared_ptr<Review>> books;

	shared_ptr<Review> temp (new Review);

	while ( FillReview (temp) ) {
		books.push_back (temp);
		temp = std::shared_ptr<Review> (new Review);
	}

	if ( books.size () > 0 ) {
		cout << "Dziekuje. Podales "
			<< books.size () << " ocen ksiazek:\n";

		for_each (books.begin (), books.end (), ShowReview);

		std::cout << "W jaki sposob mam wyswietlic ksiazki?\n";

			Show_menu ();
			int choice;
			cin >> choice;

			while ( choice != 7 ) {
				switch ( choice ) {
				case 1: 
					for_each (books.begin (), books.end (), ShowReview);
					break;
				case 2:
					sort (books.begin (), books.end ());
					for_each (books.begin (), books.end (), ShowReview);
					break;
				case 3:
					sort (books.begin (), books.end (), increasing_rating);
					for_each (books.begin (), books.end (), ShowReview);
					break;
				case 4:
					sort (books.begin (), books.end (), decreasing_rating);
					for_each (books.begin (), books.end (), ShowReview);
					break;
				case 5:
					sort (books.begin (), books.end (), increasing_price);
					for_each (books.begin (), books.end (), ShowReview);
					break;
				case 6:
					sort (books.begin (), books.end (), decreasing_price);
					for_each (books.begin (), books.end (), ShowReview);
					break;
				}
				Show_menu ();
				cin >> choice;
			}

	}
	else
		cout << "Brak danych. ";
	cout << "Koniec.\n";
	return 0;
}

void Show_menu () {

	using std::cout;
	using std::endl;

	cout << "1. Kolejnosc wprowadzania\n";
	cout << "2. Kolejnosc alfabetyczna\n";
	cout << "3. Ocena rosnaco\n";
	cout << "4. Ocena malejaco\n";
	cout << "5. Cena rosnaco\n";
	cout << "6. Cena malejaco\n";
	cout << "7. Wyjscie\n";

}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
	if ( r1->title < r2->title )
		return true;
	else if ( r1->title == r2->title && r1->rating < r2->rating )
		return true;
	else
		return false;
}

bool increasing_rating (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
	if ( r1->rating < r2->rating )
		return true;
	else
		return false;
}

bool decreasing_rating (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
	if ( r1->rating > r2->rating )
		return true;
	else
		return false;
}

bool increasing_price (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
	if ( r1->price < r2->price )
		return true;
	else
		return false;
}

bool decreasing_price (const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
	if ( r1->price > r2->price )
		return true;
	else
		return false;
}

bool FillReview (std::shared_ptr<Review> & rr) { 
	std::cout << " Wpisz tytul ksiazki (koniec, aby zakonczyc): ";
	std::getline (std::cin, rr->title);
	if ( rr->title == "koniec" )
		return false;
	std::cout << "Wpisz ocene: ";
	std::cin >> rr->rating;
	if ( !std::cin )
		return false;
	std::cout << "Wpisz cene ksiazki: ";
	std::cin >> rr->price;
	if ( !std::cin )
		return false;
	// pozbycie się reszty danych wejściowych
	while ( std::cin.get () != '\n' )
		continue;

	return true;
}

void ShowReview (const std::shared_ptr<Review> & rr) {
	std::cout <<"Tytul: " <<  rr->title << ",  Ocena: " << rr->rating << ",  Cena: " << rr->price << "zl. "<< std::endl;
}

