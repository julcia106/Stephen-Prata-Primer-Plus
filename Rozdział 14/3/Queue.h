#pragma once
#include "pch.h"
#include <iostream>

template <typename T1>
class QueueTp {

private:
	enum { SIZE = 5 };

	struct Node {
		T1 data;
		Node* next;

		Node (T1 value) {
			data = value;
			next = nullptr;
		}
	};
	Node* head;
	Node* tail;
	int items;
	const int qsize;
public:
	QueueTp (int qs = SIZE):qsize (qs) { head = nullptr, tail = nullptr, items = 0; }
	~QueueTp ();
	bool enqueue (const T1&item);
	bool dequeue (const T1& item);
	void FistElement () { std::cout << head->data; }
	bool isEmpty () const { return head == nullptr; }
	bool isFull () const { return items == qsize; }
	int count () const { return items; }

};

template<typename T1>
QueueTp<T1>::~QueueTp () {
	Node* temp = nullptr;
	while ( head != nullptr ) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T1>
bool QueueTp<T1>::enqueue (const T1& item) {

	if ( isFull () )
		return false;

	Node* temp = new Node (item);
	if ( head == nullptr ) {
		head = temp;
		tail = temp;
	}
	else {
		head->next = nullptr;
		tail->next = temp;
		tail = temp;
	}
	items++;

	return true;
}

template <typename T1>
bool QueueTp<T1>::dequeue (const T1& item) {
	Node* s = new Node (item);


	if ( isEmpty () )
		return false;

	s = head;
	Node* temp = head;
	head = head->next;
	delete temp;
	items--;
	return true;
}