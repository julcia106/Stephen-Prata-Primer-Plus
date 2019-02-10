#pragma once
#include "pch.h"
#include <iostream>
#include <math.h>

class Vector {

private:
	double x;
	double y;

public:
	Vector () { x = 0.0; y = 0.0; };
	Vector (double, double);
	void scalar ();
	Vector operator+ (const Vector& v) const;
	Vector operator- (const Vector& v) const;
	Vector operator*(double n) const;
	friend Vector operator*(double n, const Vector& v) { return v * n; }
	friend std::ostream & operator<< (std::ostream &os, const Vector& v);

};