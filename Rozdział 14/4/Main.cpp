#include "pch.h"
#include "Person.h"
#include <iostream>
#include <cstring>

const int Size = 2;

int main () {


	Person * one [Size];

	for ( int i = 0; i < Size; i++ ) {
		one [i] = new Gunslinger;
		one [i]->Set();
	}
	
	for ( int i = 0; i < Size; i++ ) {
		one [i]->Show ();
	}

	

	return 0;
}