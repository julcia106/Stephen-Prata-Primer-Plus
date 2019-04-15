#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int NUM = 1000000;
int getRandom () { return rand () % 100 + 1; }
double sortVI (std::vector<int> &v);
double sortLI (std::list<int> &l);
double sortLII (std::list<int> &l, std::vector<int> &v);


int main () {

	std::srand (std::time (0));

	std::vector<int> vi0 (NUM);
	std::generate (vi0.begin (), vi0.end (), getRandom);

	std::vector<int> vi(vi0);
	std::list<int>li (vi.begin (), vi.end ());

	double sortvi= sortVI(vi);
	double sortli = sortLI (li);

	std::copy (vi0.begin (), vi0.end (), li.begin ()); //przywrócenie nieuporządkowanej sekwencji
	double sortlii = sortLII (li,vi);

	std::cout << "Czas sortowania wektora vi: " << sortvi << " sekund.\n";
	std::cout << "Czas sortowania listy li: " << sortli << " sekund.\n";
	std::cout << "Czas sortowania listy przez skopiowanie do wektora: " << sortlii << " sekund.\n";

	return 0;
}

double sortVI (std::vector<int> &v) {

	clock_t start = clock ();
	std::sort (v.begin (), v.end ());
	clock_t end = clock ();

	return (double)(end - start) / CLOCKS_PER_SEC;
}

double sortLI (std::list<int> &l) {

	clock_t start = clock ();
	l.sort ();
	clock_t end = clock ();

	return (double)(end - start) / CLOCKS_PER_SEC;
}

double sortLII (std::list<int> &li, std::vector<int> &vi) {

	clock_t start = clock ();
	std::copy (li.begin (), li.end (), vi.begin ()); // li do vi
	std::sort (vi.begin (), vi.end ()); 
	std::copy (vi.begin (), vi.end (), li.begin ()); //vi do li
	clock_t end = clock ();

	return (double)(end - start) / CLOCKS_PER_SEC;
	

}