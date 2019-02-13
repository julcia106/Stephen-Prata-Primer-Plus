#pragma once
#include "pch.h"
#include <iostream>

class List {
private:
	static const int MaxSize = 5;
	int arr [MaxSize];
	int size_of_ar; // aktualna wielkosc 
public:
	List ();
	void add (int Index, const int& newItem); // dodaje Item na listê w pozycji index	
	void remove (int index);
	void size ()const;
	void show () const;
};