#pragma once
#include "pch.h"
#include <iostream>

namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	private:
		double m_x; //warto�� sk�adowej poziomej
		double m_y; //warto�� sk�adowej pionowej
		double mag; //dlugosc wektora
		double ang; // kierunek wektora  ( w stopniach )
		Mode mode; // RECT lub POL
		//prywatne metody ustawiaj�ce sk�adowe
		void set_mag ();
		void set_ang ();
		void set_x ();
		void set_y ();
	public:
		Vector ();
		Vector (double n1, double n2, Mode form = RECT);
		void reset (double n1, double n2, Mode form = RECT);
		~Vector ();
		double xval () const { return m_x; } // zwraca warto�� sk�adowej x
		double yval () const { return m_y; } // zwraca warto�� sk�adowej y
		double magval () const { return mag; } // zwraca d�ugo��
		double angval () const { return ang; } // zwraca k�t
		void polar_mode (); // ustawia tryb na biegunowy POL
		void rect_mode (); // ustawia tryb na kartezja�ski RECT 
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
