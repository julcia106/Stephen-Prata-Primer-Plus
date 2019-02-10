#include "pch.h"
#include "Double_queue.h"
#include <iostream>
#include <cstdlib> // funkcja rand()

Queue::Queue (int qs): qsize (qs) {

	front = rear = nullptr;
	items = 0;
}

Queue::~Queue () { 

	Node* temp;
	while ( front != nullptr ) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

Queue::Queue (const Queue & q): qsize (Q_SIZE) {

	items = 0;
	front = rear = nullptr;

	Node* temp = q.front;
	while ( temp != nullptr )
		enqueue (temp->item);
	temp = temp->next;

}

Queue & Queue::operator= (const Queue & q) {

	if ( this == &q )
		return *this;
	delete[]front;
	delete[]rear;

	items = 0;
	front = rear = nullptr;

	Node* temp = q.front;
	while ( temp != nullptr )
		enqueue (temp->item);
	temp = temp->next;
	return *this;
}

bool Queue::isempty () const {

	if ( items == 0 )
		return true;
	else
		return false;
}

bool Queue::isfull () const {
	if ( items == qsize )
		return true;
	else
		return false;
}

int Queue::queuecount () const {
	return items;
}

bool Queue::enqueue (const Item& item) {

	if ( isfull () )
		return false;

	Node* temp = new Node;
	temp->item = item;
	temp->next = nullptr;
	items++;
	if ( front == nullptr )
		front = temp;
	else
		rear->next = temp;
	rear = temp;
	return true;
}

bool Queue::dequeue (Item & item) {

	if ( front == nullptr )
		return false;
	item = front->item;
	items--;
	Node *temp = front;
	front = front->next;
	delete temp;
	if ( items == 0 )
		rear = nullptr;
	return true;
}

//kiedy klient trafia do kolejki, zapamiêtywany jest bie¿¹cy czas systemowy, losowany jest te¿
//czas obs³ugi klienta (z zakresu od 1 do 3)
void Customer::set (long when) {

	processtime = std::rand () % 3 + 1;
	arrive = when;
}
