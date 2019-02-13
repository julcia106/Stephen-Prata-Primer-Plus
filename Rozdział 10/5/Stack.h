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
	enum { MAX = 10 }; //sta³a zasiêgu klasy
	Item items [MAX]; // przechowuje element stosu
	int top; //indeks szczytowego elementu stosu
public:
	Stack ();
	bool isempty () const;
	bool isfull () const;
	//push() zwraca false, jeœli stos jest juz pe³en(true w pozosta³ych przypadkach)
	bool push (const Item& item); // odk³ada element na stos
	//pop() zwraca false, jeœli stos jest juz pusty 9true w pozosta³ych przypadkach)
	bool pop (Item& item); // zdejmuje element ze stosu
};