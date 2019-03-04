#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Person {
public:
	Person ():fullname("brak") {}
	Person (const std::string& fn)
		: fullname (fn) {}
	virtual ~Person () {}
	virtual void Show () const { std::cout << "Imie i nazwisko: " << fullname << std::endl; }
	virtual void Set ();
private: 
	std::string fullname;
};

class Gunslinger: virtual public Person {
public:
	Gunslinger ()
		:Person () {}
	Gunslinger (int GI, double t, std::string fn);
	Gunslinger (const Person& p, double t, int GI)
		:Person (p), time (t), GunIncision (GI) {}
	virtual ~Gunslinger () {};
	double Draw () const { return time; };
	virtual void Show () const;
	virtual void Set ();
private:
	int GunIncision; //liczba naci�� na rewolwerze 
	double time; //czas wyciagania rewolweru przez rewolwerowca
};

class PokerPlayer: virtual public Person {
public:
	PokerPlayer () {}
	PokerPlayer (std::string fn)
		:Person (fn) {};
	PokerPlayer (const Person& p)
		: Person (p) {}
	virtual ~PokerPlayer () {};

	int Draw () const; //zwraca liczb� losow� mi�dzy 1 a 52, reprezentuj�c� kart�
	virtual void Show () const; 
	virtual void Set ();
};

class BadDude:public Gunslinger,public PokerPlayer {
public:
	BadDude ()
		:Person(),Gunslinger(),PokerPlayer() {}
	BadDude (const Person& fn,double t, int GI)
		:Person (fn), Gunslinger(fn,t,GI),PokerPlayer() {}
	virtual ~BadDude () {}; 
	double Gdraw () const; //zwraca czas wyci�gania rewolweru
	int Cdraw () const; //zwraca kolejn� wyci�gan� kart�
	virtual void Show () const;
	virtual void Set ();
}; 