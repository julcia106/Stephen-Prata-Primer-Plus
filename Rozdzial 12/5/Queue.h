#pragma once
#include "pch.h"
#include <iostream>

class Customer {
	long arrive;
	int processtime;
public:
	Customer () { arrive = processtime = 0; }
	void set (long when);
	long when () const { return arrive; }
	int ptime () const { return processtime; }
};

typedef Customer Item;
class Queue {
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node*front; // czo�o
	Node *rear; // ogon
	int items; //bierz�ca liczba element�w kolejki
	const int qsize; //maksymalna liczba element�w kolejki

	// definicje blokuj�ce publiczny dost�p do operacji kopiowania 
	Queue (const Queue & q): qsize (0) {}
	Queue & operator= (const Queue & q) { return *this; }
public:
	Queue (int qs = Q_SIZE); // tworzy kolejk� o pojemno�ci qs
	~Queue ();
	bool isempty () const;
	bool isfull () const;
	int queuecount () const;
	bool enqueue (const Item& item); // dodaje element na koniec kolejki
	bool dequeue (Item & item); // wyci�ga element z czo�a kolejki 
};
