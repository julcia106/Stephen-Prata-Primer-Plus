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
	struct Node { Item item; struct Node* next; };

private:
	enum { Q_SIZE = 10 };
	Node*front;
	Node *rear;
	int items;
	const int qsize; //

public:
	Queue (int qs = Q_SIZE);
	~Queue ();
	Queue (const Queue & q); //
	Queue & operator= (const Queue & q);//
	bool isempty () const;
	bool isfull () const;
	int queuecount () const;
	bool enqueue (const Item& item);
	bool dequeue (Item & item);
};
