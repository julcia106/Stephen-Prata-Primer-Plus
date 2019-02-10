#include "pch.h"
#include "Worker.h"
#include "Queue.h"
#include <iostream>
#include <cstring>
using namespace std;

int main () {
	using std::strchr;

	QueueTp<Worker> queue (3);

	Worker one ("Julia Rutkowska", 1221);
	queue.enqueue (one);

	Worker two ("Jonasz Romanowski", 131);
	queue.enqueue (two);

	one.Show ();
	two.Show ();
	Worker three;
	three.Set ();
	three.Show ();
	if ( queue.isFull () )
		cout << "Kolejka pelna" << endl;
	else
		cout << " Jest jeszcze miejsce w kolejce" << endl;

	Worker temp;
	queue.dequeue (temp);
	temp.Show ();



}
