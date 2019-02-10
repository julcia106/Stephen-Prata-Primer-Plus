#pragma once
#include "pch.h"
#include <iostream>
#include "complex_number.h"
using namespace std;

using std::ostream;
using std::istream;

class Complex {
public:
	Complex ();
	~Complex () {}
	Complex (double, double);

	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator*(int n);
	Complex operator~();

	/*friend Complex operator-(const Complex &, const Complex &);
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator*(const Complex &, const Complex &);
	friend Complex operator*(int, const Complex &);
	friend Complex operator~(const Complex &);*/

	friend ostream & operator << (ostream &, const Complex &);
	friend istream & operator >> (istream &, Complex &);



private:
	double real;
	double imaginary;
};