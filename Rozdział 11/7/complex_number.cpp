#include "pch.h"
#include "complex_number.h"
#include <iostream>
using namespace std;

Complex::Complex () {
	imaginary = real = 0.0;
}

Complex::Complex (double m_real, double m_imaginary) {
	real = m_real;
	imaginary = m_imaginary;
}

ostream & operator << (ostream & os, const Complex & st) {
	os << "( " << st.real << ", " << st.imaginary << "i) " << endl;
	return os;
}

istream & operator >> (istream & wejscie, Complex & nt) {
	cout << "skladowa rzeczywista: ";
	wejscie >> nt.real;
	cout << endl;
	cout << "skladowa urojona: ";
	wejscie >> nt.imaginary;
	cout << endl;
	return wejscie;
}


Complex Complex::operator+(const Complex& n) {

	Complex temp;


	temp.real = n.real + real;
	temp.imaginary = n.imaginary + imaginary;

	return temp;
}

Complex Complex::operator-(const Complex& n) {

	Complex temp;
	temp.real = n.real - real;
	temp.imaginary = n.imaginary - imaginary;
	return temp;
}

Complex Complex::operator*(const Complex& n) {

	Complex temp;
	temp.real = n.real *real - n.imaginary * imaginary;
	temp.imaginary = n.real * imaginary + n.imaginary * real;
	return temp;

}

Complex Complex::operator*(int n) {

	Complex temp;
	temp.real = n * real;
	temp.imaginary = n * imaginary;
	return temp;
}

Complex Complex::operator~() {

	Complex temp;
	temp.real = real;
	temp.imaginary = -imaginary;
	return temp;
}

//Complex operator+(const Complex & a, const Complex & b) {
//
//	Complex temp;
//
//	temp.real = a.real + b.real;
//	temp.imaginary= a.imaginary + b.imaginary;
//
//	return temp;
//}

//Complex operator-(const Complex & a, const Complex & b) {
//	Complex temp;
//
//	temp.real = a.real - b.real;
//	temp.imaginary= a.imaginary - b.imaginary;
//	return temp;
//}
//
//Complex operator*(const Complex & a, const Complex & b) {
//	Complex temp;
//
//	temp.real = a.real * b.real - a.imaginary * b.imaginary;
//	temp.imaginary = a.real * b.imaginary + a.imaginary* b.real;
//	return temp;
//}

//Complex operator*(int a, const Complex & b) {
//	Complex temp;
//
//	temp.real = a * b.real;
//	temp.imaginary= a * b.imaginary;
//	return temp;
//}
//
//Complex operator~(const Complex & a) {
//	Complex temp;
//
//	temp.real = a.real;
//	temp.imaginary= -a.imaginary;
//	return temp;
//}
