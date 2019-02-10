#include "pch.h" 
#include "Dynamic_cd.h"
#include <iostream>

using namespace std;

void Bravo (const Cd& disk);

int main () {

	Cd c1 ("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic ("Sonata fortepianowa B-dur, Fantazja C-moll",
						  "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1; //!mogê ustawiæ ten wskaŸnik na ka¿dy inny obiekt np. &c2

	cout << endl;
	cout << "Bezposrednie uzycie obiektu:\n";
	c1.Report ();
	c2.Report ();

	cout << endl << endl;
	cout << "Uzycie wskaznika na typ Cd:\n";
	pcd->Report (); // u¿ywa metody klasy Cd dla obiektu tej klasy 
	pcd = &c2; // wskaŸnik bazowa= adres pochodna
	pcd->Report (); //u¿ywa metody klasy Classic dla obiektu tej klasy

	cout << endl << endl;
	cout << "Wywolanie funkcji z argumentem w postaci referencji do typu cd:\n";
	Bravo (c1);
	Bravo (c2);

	cout << endl << endl;
	cout << "Test przypisania: ";
	Classic copy;
	copy = c2; // pochodna= pochodna
	copy.Report ();

	return 0;
}

void Bravo (const Cd & disk) {
	disk.Report ();
}

