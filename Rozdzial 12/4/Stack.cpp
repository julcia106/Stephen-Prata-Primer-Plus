#include "pch.h"
#include "Stack.h"
#include <iostream>
#include <cstring>

Stack::Stack (int n) {

	top = 0;
	size = 0;

	pitems = new Item [n];
	pitems [0] = '\0';
}

Stack::Stack (const Stack & st) {

	size = st.size;
	pitems = new Item [size];
	pitems = st.pitems;

	top = st.top;
}

Stack::~Stack () {

	delete[] pitems;
	std::cout << "Destruktor dziala" << std::endl;
}

bool Stack::isempty () const {

	if ( top == 0 )
		return true;
	else
		return false;
}

bool Stack::isfull () const {

	if ( top == MAX )
		return true;
	else
		return false;
}

bool Stack::push (const Item & item) {

	if ( top == MAX )
		return false;
	else {

		pitems [top++] = item;
		size++;
		return true;
	}
}

bool Stack::pop (Item & item) {

	if ( top == 0 )
		return false;
	else {

		item = pitems [top--];
		size--;
		return true;
	}
}

Stack & Stack::operator= (const Stack & st) {

	if ( this == &st ) //1
		return *this;
	delete[]pitems; //2

	size = st.size; //3. jak w k.kopiujacym
	pitems = new Item [size]; // +1?
	pitems = st.pitems;
	top = st.top;

	return *this;
}

void Stack::show () const {
	using std::cout;
	using std::endl;

	cout << "Poczatek stosu ";
	for ( int i = 0; i < top; i++ ) {

		cout << pitems [i] << ", ";
	}
	cout << " koniec stosu. " << endl;
}