#include "pch.h"
#include "Golf.h"
#include <iostream>

int main () {
	using std::cout;
	using std::endl;

	Golf frania;
	frania.Showgolf ();

	Golf ann ("Ania Wieczorek", 24);
	ann.Setgolf ();
	ann.Showgolf ();

	Golf juzia;
	juzia.Showgolf ();

}