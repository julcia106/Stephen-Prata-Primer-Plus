#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Person {
public:
	Person (): fullname ("brak") {}
	Person (std::string fn): fullname (fn){}
	virtual ~Person () = 0; 
	virtual void Set () = 0;
	virtual void Show () const=0; 
protected:
	virtual void Data () const;
	virtual void Get ();
private: 
	std::string fullname;
};

class Gunslinger: virtual public Person {
public:
	Gunslinger (int GI = 0, double t = 0.0, std::string fn = "brak");
	~Gunslinger () {};
	double Draw () const { return time; };
	virtual void Show () const;
	virtual void Set ();
protected:
	virtual void Data () const;
	virtual void Get ();
private:
	int GunIncision; //liczba naci�� na rewolwerze 
	double time; //czas wyciagania rewolweru przez rewolwerowca
};

class PokerPlayer: virtual public Person {
public:
	PokerPlayer ():Person () {}; //TODO ???
	PokerPlayer (std::string fn):Person (fn) {};
	~PokerPlayer () {};
	int Draw () const; //zwraca liczb� losow� mi�dzy 1 a 52, reprezentuj�c� kart�
	virtual void Show () const; 
	virtual void Set ();
protected:
	virtual void Data () const;
};

class Card {
public:
	Card (std::string col = "brak", int num = 0): colour (col), number (num) {}
	~Card () {}; 
private:
	std::string colour;
	int number;
	//TODO u�y� typu Card jako warto�ci zwracanej przez metod� Draw()
};

class BadDude:public Gunslinger,public PokerPlayer {
public:
	BadDude (const Person& fn, int GI=0)
		:Person (fn), Gunslinger(GI),PokerPlayer() {}
	~BadDude () {}; 
	double Gdraw () const; //zwraca czas wyci�gania rewolweru
	int Cdraw () const; //zwraca kolejn� wyci�gan� kart�
	virtual void Show () const;
	virtual void Set ();
protected:
	virtual void Data () const;
	virtual void Get ();
}; 