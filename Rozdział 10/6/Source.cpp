#include "pch.h"
#include "Move.h"
#include <iostream>


int main () {
	using namespace std;

	Move one = Move (2, 3);

	Move two = Move (2, 2);

	Move three;
	three = one.add (two);

	three.showmove ();




}