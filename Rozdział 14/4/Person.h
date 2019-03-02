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
	double Draw (double time) const { return time; }; //TODO czas wyci�gania rewolweru przez rewolwerowca
	virtual void Show () const; // wy�wietla wszystkie informacje
private:
	int GunIncision; //liczba naci�� na rewolwerze 
};

class PokerPlayer: virtual public Person {
public:
	PokerPlayer ():Person () {};
	~PokerPlayer () {};
	int Draw () const; //zwraca liczb� losow� mi�dzy 1 a 52, reprezentuj�c� kart�
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
	double Gdraw (double t); //zwraca czas wyci�gania rewolweru
	int Cdraw () const; //zwraca kolejn� wyci�gan� kart�
	virtual void Show () const;
};