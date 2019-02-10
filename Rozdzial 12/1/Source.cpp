#include "pch.h"
#include "Cow.h"
#include <iostream>

int main () {

	Cow one ("Kasia", "skakanie", 20.00);
	one.ShowCow ();

	Cow two ("tomek", "bieganie", 21.00);
	two.ShowCow ();

	Cow three = Cow ();
	three.ShowCow ();
}