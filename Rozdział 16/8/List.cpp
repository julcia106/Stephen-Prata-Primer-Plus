#include "pch.h"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>


int main () {

	std::list<std::string> Bolek = { "Kasia Kowalska","Julia Rutkowska", "Ola Michalska", "Anna Kot"}; // kontener z imionami Bolka
	std::list<std::string> Lolek = { "Tomek Bobek", "Julia Rutkowska", "Tomasz Kot" }; // kontener z imionami Lolka

	Bolek.sort ();
	Lolek.sort ();

	Bolek.merge (Lolek);
	Bolek.unique ();

	std::list<std::string>::iterator pd;
	for ( pd = Bolek.begin (); pd != Bolek.end (); ++pd )
		std::cout << *pd << std::endl;

	return 0;
}