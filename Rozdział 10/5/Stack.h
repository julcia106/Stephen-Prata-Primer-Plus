#pragma once
#include "pch.h"
#include <iostream>

struct customer {
	char fullname [35];
	double payment;
};

typedef customer Item;

class Stack {
private:
	enum { MAX = 10 }; //sta�a zasi�gu klasy
	Item items [MAX]; // przechowuje element stosu
	int top; //indeks szczytowego elementu stosu
public:
	Stack ();
	bool isempty () const;
	bool isfull () const;
	//push() zwraca false, je�li stos jest juz pe�en(true w pozosta�ych przypadkach)
	bool push (const Item& item); // odk�ada element na stos
	//pop() zwraca false, je�li stos jest juz pusty 9true w pozosta�ych przypadkach)
	bool pop (Item& item); // zdejmuje element ze stosu
};