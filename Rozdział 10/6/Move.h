#pragma once
#include "pch.h"
#include <iostream>

class Move {
private:
	double x;
	double y;
public:
	Move (double a = 0, double b = 0); // ustawia x na a, y na b

	void showmove () const; // wyswietla bierz¹ce wartoœci x i y

	Move add (const Move& m) const;
	//Powy¿sza metoda sumuje x obiektu m i x obiektu wywo³uj¹cego,
	// y obiektu m i y obiektu wywo³uj¹cego, tworzy nowy obiekt, inicjalizuje 
	// go obliczonymi sumami x i y i zwraca tak zainicjalizowany obiekt

	void reset (double a = 0, double b = 0); // ustawia x na a, y a b


};