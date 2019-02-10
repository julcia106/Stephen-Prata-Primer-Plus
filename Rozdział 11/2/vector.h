#pragma once
#pragma once
#include "pch.h"
#include <iostream>

namespace VECTOR {

	class Vector {
	public:
		enum Mode { RECT, POL };

	private:
		double m_x;
		double m_y;
		Mode mode; // RECT lub POL

		//prywatne metody ustawiaj¹ce sk³adowe
		void set_x (double mag, double ang) { m_x = (mag * cos (ang)); }
		void set_y (double mag, double ang) { m_y = (mag * sin (ang)); }
		double get_x () const { return m_x; }
		double get_y () const { return m_y; }

	public:
		Vector ();
		Vector (double mag, double ang, Mode form = RECT);
		void reset (double mag, double ang, Mode form = RECT);
		~Vector ();
		double magval () const; // zwraca d³ugoœæ
		double angval () const; // zwraca k¹t
		void polar_mode (); // ustawia tryb na biegunowy POL
		void rect_mode (); // ustawia tryb na kartezjañski RECT

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
