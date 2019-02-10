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

	const double Rad_to_deg = 54.0 / atan (1.0);

	double Vector::magval () const {

		double mag;
		double t_x = get_x ();
		double t_y = get_y ();

		mag = sqrt ((t_x* m_x) + (t_y * m_y)); //m_x* m_x

		return mag;
	}

	double Vector::angval () const {

		double ang;
		double t_x = get_x ();
		double t_y = get_y ();

		if ( t_x == 0.0 && t_y == 0.0 )
			ang = 0.0;
		else
			ang = atan2 (t_y, t_x);

		return ang;
	}

	Vector::Vector () {
		m_x = m_y = 0.0;
		mode = RECT;
	}

	//konstruuje wektor o zadanych współrzędnych biegunowych (w trybie 'p')
	//bądź protokątnych (w domyslnym trybie 'r')
	Vector::Vector (double n1, double n2, Mode form) {


		mode = form;
		if ( form == RECT ) {

			m_x = n1;
			m_y = n2;
		}
		else if ( form == POL ) {

			set_x (n1, n2);
			set_y (n1, n2);

		}
		else {
			cout << "Niepoprawna wartosc trzeciego argumentu Vector ()--";
			cout << "zeruje wektor" << endl;
			m_x = m_y = 0.0;
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

		}
		else if ( form == POL ) {

			set_x (n1, n2);
			set_y (n1, n2);

		}
		else {
			cout << "Niepoprawny trzeci argument set ()--";
			cout << "zeruje wektor" << endl;
			m_x = m_y = 0.0;
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

	Vector Vector::operator+(const Vector& b) const {
		return Vector (m_x + b.m_x, m_y + b.m_y);
	}

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
			os << "(x,y)= (" << v.get_x () << ", " << v.get_y () << ")";
		else if ( v.mode == Vector::POL ) {
			os << "(m,a)=(" << v.magval () << ", "
				<< v.angval ()*Rad_to_deg << ")";
		}
		else
			os << "Niepoprawny tryp reprezentacji obiektu wektora";
		return os;
	}
}


