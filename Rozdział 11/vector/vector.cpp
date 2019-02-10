#include "pch.h"
#include "vector.h"
#include <iostream>

Vector::Vector (double m_x, double m_y) {
	x = m_x;
	y = m_y;
}
void Vector::scalar () { //TODO

}

Vector Vector::operator+ (const Vector& v) const {

	return Vector (x + v.x, y + v.y);
}


Vector Vector::operator- (const Vector& v) const {

	return Vector (x - v.x, y - v.y);
}

Vector Vector::operator*(double n) const {

	return Vector (x * n, y * n);
}

std::ostream & operator<< (std::ostream &os, const Vector& v) {

	os << v.x << " = x, " << v.y << " = y"; // wyswietlanie wartosci obiektu
	return os;

}