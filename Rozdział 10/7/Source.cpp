#include "pch.h"
#include "Plorg.h"
#include <iostream>


int main () {
	Plorg one = Plorg ("Plorg Betelgeski", 24);
	one.show ();

	Plorg two;
	two.show ();

	Plorg three;
	three.change_food (2);
	three.show ();
}