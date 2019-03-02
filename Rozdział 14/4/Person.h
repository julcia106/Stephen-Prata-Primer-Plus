#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Person {
public:
	Person (): name ("brak"), surname ("brak") {}
	Person (std::string n, std::string sn): name (n), surname (sn) {}
	virtual ~Person () = 0; 
	virtual void Show () const; 
private: 
	std::string name;
	std::string surname;
};

class Gunslinger: public Person {
public:
	Gunslinger (int GI = 0, std::string n = "brak", std::string sn = "brak")
		:Person (n, sn) {}
	~Gunslinger () {};
	double Draw (double time) const { return time; }; //TODO czas wyci¹gania rewolweru przez rewolwerowca
	virtual void Show () const; // wyœwietla wszystkie informacje
private:
	int GunIncision; //liczba naciêæ na rewolwerze 
};

class PokerPlayer: virtual public Person {
public:
	PokerPlayer ():Person () {};
	~PokerPlayer () {};
	int Draw () const; //zwraca liczbê losow¹ miêdzy 1 a 52, reprezentuj¹c¹ kartê
	virtual void Show () const; //funkcja klasy Person
};

class Card {
public:
	Card (std::string col = "brak", int num = 0): colour (col), number (num) {}
	~Card () {};
private:
	std::string colour;
	int number;
};

class BadDude:public Gunslinger, public PokerPlayer {
public:
	BadDude (std::string n, std::string sn, int GI)
		:Person (n, sn), Gunslinger(GI),PokerPlayer() {}
	~BadDude () {}; 
	double Gdraw (double t); //zwraca czas wyci¹gania rewolweru
	int Cdraw () const; //zwraca kolejn¹ wyci¹gan¹ kartê
	virtual void Show () const;
};