#include "pch.h"
#include "Person.h"
#include <iostream>

void Person::Set () {
	std::cout << "Podaj imie i nazwisko: ";
	std::getline (std::cin, fullname);
}

Gunslinger::Gunslinger (int GI,double t, std::string fn)
	: Person(fn) 
{
	GunIncision = GI;
	time = t;
}

void Gunslinger::Set () {
	Person::Set ();	
	std::cout << "Wprowadz liczbe naciec: \n";
	std::cin >> GunIncision;
	std::cout << "Wprowadz czas wyciagania rewolerwu: \n";
	std::cin >> time;
}

void Gunslinger::Show () const { 
	Person::Show ();
	std::cout << "Liczba naciec na rewolerze: " << GunIncision << std::endl;
	std::cout << "Czas wyciagania rewoleru: " << time << std::endl;
}

int PokerPlayer::Draw () const {
	srand (time (NULL));
	return rand () & 52 + 1;
}

void PokerPlayer::Set () {
	Person::Set ();
}

void PokerPlayer::Show () const {
	Person::Show ();
	std::cout << "Numer karty: " << Draw () << std::endl;
}

double BadDude::Gdraw ()const {

	return Gunslinger::Draw ();
}

int BadDude::Cdraw () const {

	return PokerPlayer::Draw ();
}

void BadDude::Set () {
	Gunslinger::Set ();
}

void BadDude::Show () const {

	Person::Show ();
	std::cout << "Czas wyciagania rewolweru: " << Gdraw () << std::endl;
	std::cout << "Numer karty: " << Cdraw () << std::endl;
	
}
