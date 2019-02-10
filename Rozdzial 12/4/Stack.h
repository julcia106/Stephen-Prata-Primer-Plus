#pragma once
#include "pch.h"
#include <iostream>
#include <cstring>

typedef unsigned long Item;

class Stack {
private:
	enum { MAX = 10 };
	Item * pitems;
	int size;
	int top;
public:
	Stack (int n = MAX);
	Stack (const Stack & st); // k.kopiujacy
	~Stack ();
	void show () const;
	bool isempty () const;
	bool isfull () const;
	bool push (const Item & item);
	bool pop (Item & item);
	Stack & operator= (const Stack & st);  // op. przypisania

};