#include "pch.h"
#include "Golf.h"
#include <iostream>

int main () {
	using std::cout;
	using std::endl;

	Golf frania;
	frania.Setgolf ();
	frania.Showgolf ();

	Golf ann ("Ania Wieczorek", 24);
	ann.Showgolf ();

	Golf juzia;
	juzia.Showgolf ();

}