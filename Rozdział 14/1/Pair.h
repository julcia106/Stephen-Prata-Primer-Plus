#pragma once
#include "pch.h"
#include <iostream> 

template <class T1, class T2>

class Pair {
private:
	T1 a;
	T2 b;
public:
	T1& first ();
	T2& second ();
	T1 first () const { return a; }
	T2 second () const { return b; }
	Pair (const T1 & aval, const T2 & bval): a (aval), b (bval) {}
	Pair () {}
	Pair (const Pair <T1, T2> &p);
};

template<typename T1, typename T2>
Pair <T1, T2>::Pair (const Pair<T1, T2> &p) {
	a = p.a;
	b = p.b;
}

template <class T1, class T2>
T1& Pair<T1, T2>::first () {
	return a;
}

template<class T1, class T2>
T2& Pair <T1, T2>::second () {
	return b;
}