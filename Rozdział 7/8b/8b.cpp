#include <iostream>
#include <string>

const int Seasons = 4;
const char* Snames [Seasons] = { "Wiosna", "Lato", "Jesien", "Zima" };
struct expenses {
	double tab [Seasons];
};

void fill_array (expenses* exp);
void show_array (expenses* exp);

int main () {
	expenses year;

	fill_array (&year);
	show_array (&year);
	return 0;
}
void fill_array (struct expenses* exp) {
	using namespace std;
	for ( int i = 0; i < Seasons; i++ ) {
		cout << "Podaj wydatki za okres>> " << Snames [i] << " <<: ";
		cin >> (exp->tab) [i];

	}
}
void show_array (expenses* exp) {
	using namespace std;
	double total = 0.0;
	cout << "\nWYDATKI\n";
	for ( int i = 0; i < Seasons; i++ ) {
		cout << Snames [i] << ": " << (exp->tab) [i] << "zl" << endl;
		total += (exp->tab) [i];
	}
	cout << "Laczne wydatki roczne: " << total << "zl" << endl;
}