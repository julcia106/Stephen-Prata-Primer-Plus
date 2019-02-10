#include "pch.h"
#include "Person.h"
#include <iostream>

int main () {
	using std::cout;
	using std::endl;

	Person one;
	Person two ("Staszek");
	Person three ("Jacek", "Placek");

	one.Show ();
	cout << endl;
	one.FormalShow ();
	cout << endl;

	two.Show ();
	cout << endl;
	two.FormalShow ();
	cout << endl;

	three.Show ();
	cout << endl;
	three.FormalShow ();
	cout << endl;

}