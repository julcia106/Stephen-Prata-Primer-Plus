#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	private:
		double m_x; //wartość składowej poziomej
		double m_y; //wartość składowej pionowej
		double mag; //dlugosc wektora
		double ang; // kierunek wektora  ( w stopniach )
		Mode mode; // RECT lub POL
		//prywatne metody ustawiające składowe
		void set_mag ();
		void set_ang ();
		void set_x ();
		void set_y ();
	public:
		Vector ();
		Vector (double n1, double n2, Mode form = RECT);
		void reset (double n1, double n2, Mode form = RECT);
		~Vector ();
		double xval () const { return m_x; } // zwraca wartość składowej x
		double yval () const { return m_y; } // zwraca wartość składowej y
		double magval () const { return mag; } // zwraca długość
		double angval () const { return ang; } // zwraca kąt
		void polar_mode (); // ustawia tryb na biegunowy POL
		void rect_mode (); // ustawia tryb na kartezjański RECT 
		//metody przeciazajace operatory
		Vector operator+(const Vector& b) const;
		Vector operator- (const Vector& b) const;
		Vector operator- () const;
		Vector operator* (double n) const;
		//funkcje zaprzyjaznione
		friend Vector operator* (double n, const Vector& a);
		friend std::ostream&
			operator <<(std::ostream& os, const Vector& v);
	};
}
