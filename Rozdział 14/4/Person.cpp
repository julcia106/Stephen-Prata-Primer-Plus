#include "pch.h"
#include "Person.h"
#include <iostream>

Person::~Person () {}

void Person::Get () {
	std::cout << "Podaj imie i nazwisko: ";
	std::getline (std::cin, fullname);
}

void Person::Data () const {
	std::cout << "Imie i nazwisko: " << fullname << std::endl;
}

Gunslinger::Gunslinger (int GI,double t, std::string fn)
	: Person(fn) 
{
	GunIncision = GI;
	time = t;
}

void Gunslinger::Set () {
	std::cout << "Set z Person(): \n";
	Person::Get ();	
	Get ();
}

void Gunslinger::Data () const {
	std::cout << "Liczba naciec na rewolwerze: " << GunIncision << std::endl;
	std::cout << "Czas wyciagania rewolweru: " << Draw () << std::endl;
}

void Gunslinger::Get () {
	std::cout << "Podaj liczbe naciec w rewolwerze: \n";
	std::cin >> GunIncision;
	std::cout << "Podaj czas wyciagania rewolerwu: \n";
	std::cin >> time;
}

void Gunslinger::Show () const { 
	std::cout << "Show z Person(): \n";
	Person::Data ();
	Data ();

}


int PokerPlayer::Draw () const {

	srand (time (NULL));
	
	int min = 1;
	int max = 52;
	int number = ((rand () % ((max - min) + 1)) + min);
	
	return number;
}

void PokerPlayer::Set () {
	std::cout << "Set z Person: \n";
	Person::Set ();
}

void PokerPlayer::Show () const {
	std::cout << "Show z Person(): \n";
	Person::Data ();
	Data ();
}

void PokerPlayer::Data () const {
	std::cout << "Liczba losowa miedzy 1 a 52: " << Draw () << std::endl;
}

double BadDude::Gdraw ()const {

	return Gunslinger::Draw ();
}

int BadDude::Cdraw () const {

	return PokerPlayer::Draw ();
}

void BadDude::Set () {
	Person::Get ();
	Get ();
}

void BadDude::Data () const {
	Gunslinger::Data ();
	PokerPlayer::Data ();

	std::cout << "Nowe dane: \n";
	std::cout << "Numer kolejnej wyciagnietej karty: " << Cdraw () << std::endl;
	std::cout << "Czas wyciagania rewolweru: " << Gdraw () << std::endl;
}

void BadDude::Get () {
	Gunslinger::Get ();
	PokerPlayer::Get ();
}

void BadDude::Show () const {

	std::cout<<"Show z Person(): \n";
	Person::Data ();
	Data ();
}
