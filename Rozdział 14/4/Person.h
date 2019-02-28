#pragma once
#include "pch.h"
#include <iostream>
#include <string>

class Person {
public:
	Person ();
	Person ();
	~Person ();
	void Show (); // wyœwietla imie i nazwisko 
private:
	std::string name;
	std::string surname;
};

class Gunslinger: public Person {
public:
	Gunslinger ();
	~Gunslinger ();
	double Draw (); //czas wyci¹gania rewolweru przez rewolwerowca
	void Show (); // wyœwietla wszystkie informacje
private:
	int GunIncision; //liczba naciêæ na rewolwerze 
};

class PokerPlayer: virtual Person {
public:
	PokerPlayer ();
	~PokerPlayer ();
	int Draw (); //zwraca liczbê losow¹ miêdzy 1 a 52, reprezentuj¹c¹ kartê
	void Show (); //funkcja klasy Person
private:
};

class Card {
public:
	Card ();
	~Card ();
private:
	void colour();
	void number ();
};

class BadDude:Gunslinger, PokerPlayer {
public:
	BadDude ();
	~BadDude ();
	double Gdraw (); //zwraca czas wyci¹gania rewolweru
	int Cdraw (); //zwraca kolejn¹ wyci¹gan¹ kartê
	void Show ();
private:

};