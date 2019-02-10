#include "pch.h"
#include "Double_queue.h"
#include <iostream>
#include <cstdlib> //rand() i srand()
#include <ctime> //time()
const int MIN_PER_HR = 60;
bool newcustomer (double x); // czy dotar³ ju¿ nastêpny klient?

int main () {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand (std::time (0));
	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
	cout << "Podaj maksymalna dlugosc kolejki: ";
	int qs;
	cin >> qs;
	Queue line (qs); // w kolejce mo¿e stan¹æ do klientów
	Queue line2 (qs);

	cout << "Podaj symulowany czas (w godzinach): ";
	int hours;
	cin >> hours;
	//symulacja z jednominutow¹ rozdzielczoœci¹ 
	long cyclelimit = MIN_PER_HR * hours; // liczba cykli

	cout << "Podaj srednia liczbe klientow na godzine: ";

	double perhour; //srednia liczba nowych klientow na godzine
	cin >> perhour;

	double min_per_cust; //œredni odstêp czasowy pomiêdzy klientami
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for ( int cycle = 0; cycle < cyclelimit; cycle++ ) {

		if ( newcustomer (min_per_cust) ) {

			if ( line2.isfull () || line.isfull () )
				turnaways++;
			else {
				customers++;
				temp.set (cycle);
				cout << "dolaczam do pierwszej kolejki: " << endl;
				line.enqueue (temp);

				if ( line.isfull () ) {
					customers++;
					temp.set (cycle);
					cout << "dolaczam do drugiej kolejki: " << endl;
					line2.enqueue (temp);
				}
			}
		}
		if ( wait_time <= 0 && !line.isempty () ) {//?

			line.dequeue (temp);

			if ( wait_time <= 0 && !line2.isempty () )
				line2.dequeue (temp);

			wait_time = temp.ptime ();
			line_wait += cycle - temp.when ();
			served++;
		}
		if ( wait_time > 0 )
			wait_time--;
		sum_line += line.queuecount () + line2.queuecount ();
	}


	if ( customers > 0 ) {

		cout << " liczba klientow przyjetych: " << customers << endl;
		cout << " liczba klientow obsluzonych: " << served << endl;
		cout << " liczba klientow odeslanych: " << turnaways << endl;
		cout << "  srednia dlugosc kolejki: ";
		cout.precision (2);
		cout.setf (ios_base::fixed, ios_base::floatfield);
		cout.setf (ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "  sredni czas oczekiwania: "
			<< (double)line_wait / served << "minut\n";
	}
	else
		cout << "Brak klientow!\n";
	cout << " Gotowe!\n";
	return 0;
}

// x= œredni odstêp czasowy (w minutach) pomiêdzy potencjalnymi klientami
// jeœli wartoœæ zwracana to true, w danej minucie pojawi siê klient

bool newcustomer (double x) {
	return (std::rand () * x / RAND_MAX < 1);
}

