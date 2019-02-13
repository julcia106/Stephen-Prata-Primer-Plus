#include "pch.h"
#include "List.h"
#include <iostream>

using namespace std;

int main () {
	List one;
	one.add (1, 44);
	one.add (2, 1);
	one.add (3, 123);
	one.add (4, 5);
	one.add (5, 9);
	one.remove (1);
	one.size ();

	one.show ();

}