#include "pch.h"
#include "vector.h"
#include <iostream>
#include <cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;

namespace VECTOR {
	// przelicznik radianow na stopnie
	const double Rad_to_deg = 54.0 / atan (1.0);
	// powinno wyjsc ok 57.2

	//metody prywatne
	//oblicza dlugość wektora ze składowych x i y
	void Vector::set_mag () {
		mag = sqrt (m_x* m_x + m_y * m_y);
	}

	void Vector::set_ang () {
		if ( m_x == 0.0 && m_y == 0.0 )
			ang = 0.0;
		else
			ang = atan2 (m_y, m_x);
	}

	//oblicza składową x ze współrzędnych biegunowych
	void Vector::set_x () {
		m_x = mag * cos (ang);
	}

	//oblicza składową  y ze współrzędnych biegunowych
	void Vector::set_y () {
		m_y = mag * sin (ang);
	}

	//metody publiczne
	Vector::Vector () { // konstruktor domyslny 
		m_x = m_y = mag = ang = 0.0;
		mode = RECT;
	}

	//konstruuje wektor o zadanych współrzędnych biegunowych (w trybie 'p')
	//bądź protokątnych (w domyslnym trybie 'r')
	Vector::Vector (double n1, double n2, Mode form) {
		mode = form;
		if ( form == RECT ) {
			m_x = n1;
			m_y = n2;
			set_mag ();
			set_ang ();
		}
		else if ( form == POL ) {
			mag = n1;
			ang = n2;
			set_x ();
			set_y ();
		}
		else {
			cout << "Niepoprawna wartosc trzeciego argumentu Vector ()--";
			cout << "zeruje wektor" << endl;
			m_x = m_y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	//zerowanie wartości wektora dla zadanych współrzędnych kartezjańskich ( dla RECT)
	// albo dla zadanych współrzędnych biegunowych (POL)
	void Vector::reset (double n1, double n2, Mode form) {
		mode = form;
		if ( form == RECT ) {
			m_x = n1;
			m_y = n2;
			set_mag ();
			set_ang ();
		}
		else if ( form == POL ) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x ();
			set_y ();
		}
		else {
			cout << "Niepoprawny trzeci argument set ()--";
			cout << "zeruje wektor" << endl;
			m_x = m_y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector () {

	}
	void Vector::polar_mode () { // przyłącza do reprezentacji biegunowej
		mode = POL;
	}
	void Vector::rect_mode () { // przyłącza do reprezentacji kartezjańskiej
		mode = RECT;
	}

	//przeciążone operatory dodawanie dwóch wektorów
	Vector Vector::operator+(const Vector& b) const {
		return Vector (m_x + b.m_x, m_y + b.m_y);
	}

	// odejmowanie wektora b od wektora a
	Vector Vector::operator-(const Vector& b) const {
		return Vector (m_x - b.m_x, m_y - b.m_y);
	}

	// zmienia znak wektora 
	Vector Vector::operator-() const {
		return Vector (-m_x, -m_y);
	}

	// mnoży wektor wywołujący przez n
	Vector Vector::operator*(double n) const {
		return Vector (n* m_x, n*m_y);
	}

	//funkcje zaprzyjaźnione mnoży n przez wektor a
	Vector operator* (double n, const Vector &a) {
		return a * n;
	}

	// wyswietla współrzedne wektora (prostokątne w trybie RECT, biegunowe w trybie POL)
	std::ostream & operator << (std::ostream & os, const Vector &v) {
		if ( v.mode == Vector::RECT )
			os << "(x,y)= (" << v.m_x << ", " << v.m_y << ")";
		else if ( v.mode == Vector::POL ) {
			os << "(m,a)=(" << v.mag << ", "
				<< v.ang*Rad_to_deg << ")";
		}
		else
			os << "Niepoprawny tryp reprezentacji obiektu wektora";
		return os;
	}
}


