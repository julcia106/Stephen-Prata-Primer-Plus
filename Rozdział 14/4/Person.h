#pragma once
#include "pch.h"
#include <iostream>
#include <string>

class Person {
public:
	Person ();
	Person ();
	~Person ();
	void Show (); // wy�wietla imie i nazwisko 
private:
	std::string name;
	std::string surname;
};

class Gunslinger: public Person {
public:
	Gunslinger ();
	~Gunslinger ();
	double Draw (); //czas wyci�gania rewolweru przez rewolwerowca
	void Show (); // wy�wietla wszystkie informacje
private:
	int GunIncision; //liczba naci�� na rewolwerze 
};

class PokerPlayer: virtual Person {
public:
	PokerPlayer ();
	~PokerPlayer ();
	int Draw (); //zwraca liczb� losow� mi�dzy 1 a 52, reprezentuj�c� kart�
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
	double Gdraw (); //zwraca czas wyci�gania rewolweru
	int Cdraw (); //zwraca kolejn� wyci�gan� kart�
	void Show ();
private:

};