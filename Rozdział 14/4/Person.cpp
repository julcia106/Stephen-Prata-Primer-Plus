#include "pch.h"
#include "Person.h"
#include <iostream>

Gunslinger::Gunslinger (int GI, std::string n, std::string sn)
	: Person(n, sn) 
{
	GunIncision = GI;
}

void Gunslinger::Show () const {
	std::cout << "Liczba naciec na rewolwerze: " << GunIncision << std::endl;
	std::cout << "Czas wyciagania rewolweru: " << Draw() << std::endl; //TODO

}

Person::Person (std::string n, std::string sn) {
	name = n;
	surname = sn;
}

void Person::Show () const {
	std::cout << "Imie: " << name << std::endl;
	std::cout << "Nazwisko: " << surname << std::endl;
}

int PokerPlayer::Draw () const {

	srand (time (NULL));
	
	int min = 1;
	int max = 52;
	int number = ((rand () % ((max - min) + 1)) + min);
	
	return number;
}

void PokerPlayer::Show () const {
	
	std::cout << "Liczba losowa miedzy 1 a 52: " << Draw () << std::endl;
}

double BadDude::Gdraw (double t) {

	return Gunslinger::Draw (t);
}

int BadDude::Cdraw () const {

	return PokerPlayer::Draw ();
}

void BadDude::Show () const {

	std::cout << "Numer kolejnej wyciagnietej karty: " << Cdraw () << std::endl;
	std::cout << "Czas wyciagania rewolweru: " << Gdraw () << std::endl; //TODO
}
