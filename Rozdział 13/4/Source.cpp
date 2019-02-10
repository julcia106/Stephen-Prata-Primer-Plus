#include "pch.h"
#include "Port.h"
#include <iostream>
using namespace std;

int main () {

	Port classic = Port ("Gallo", "Lekko brazowy", 20);
	VintagePort vintage = VintagePort ("Portada", 12, "Slodki", 1994);

	Port* ptr = &classic;

	classic.Show ();
	cout << endl;
	vintage.Show ();
	cout << endl;

	cout << "wskaznik: " << endl;
	ptr->Show ();
	ptr = &vintage;
	ptr->Show ();

	vintage.BottleCount ();

}