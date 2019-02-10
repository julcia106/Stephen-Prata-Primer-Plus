#include "pch.h"
#include "Queue.h"
#include <iostream>
#include <cstdlib> //rand() i srand()
#include <ctime> //time()
const int MIN_PER_HR = 60;
bool newcustomer (double x); // czy dotar� ju� nast�pny klient?

int main () {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	//przygotowani symulacji
	std::srand (std::time (0)); // inicjalizacja generatora liczb losowych
	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
	cout << "Podaj maksymalna dlugosc kolejki: ";
	int qs;
	cin >> qs;
	Queue line (qs); // w kolejce mo�e stan�� do klient�w

	cout << "Podaj symulowany czas (w godzinach): ";
	int hours;
	cin >> hours;
	//symulacja z jednominutow� rozdzielczo�ci� 
	long cyclelimit = MIN_PER_HR * hours; // liczba cykli

	cout << "Podaj srednia liczbe klientow na godzine: ";
	//zadanie! warto�� �redniej liczby klient�w na godzin�,
	double perhour; //srednia liczba nowych klientow na godzine
	cin >> perhour;
	double min_per_cust; //�redni odst�p czasowy pomi�dzy klientami
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

			if ( line.isfull () )
				turnaways++;
			else {

				customers++;
				temp.set (cycle);
				line.enqueue (temp);
			}
		}
		if ( wait_time <= 0 && !line.isempty () ) {

			line.dequeue (temp);
			wait_time = temp.ptime ();
			line_wait += cycle - temp.when ();
			served++;
		}
		if ( wait_time > 0 )
			wait_time--;
		sum_line += line.queuecount ();
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

// x= �redni odst�p czasowy (w minutach) pomi�dzy potencjalnymi klientami
// je�li warto�� zwracana to true, w danej minucie pojawi si� klient

bool newcustomer (double x) {
	return (std::rand () * x / RAND_MAX < 1);
}

