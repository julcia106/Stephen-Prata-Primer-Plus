#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
	char fullname [SLEN];
	char hobby [SLEN];
	int ooplevel;
};

int getinfo (student pa[], int n);
void display1 (student st);
void display2 (const student * ps);
void display3 (const student pa[], int n);

int main () {
	cout << "Podaj wielkosc grupy: ";
	int class_size;
	cin >> class_size;
	while ( cin.get () != '\n' )
		continue;
	student* ptr_stu = new student [class_size];
	int entered = getinfo (ptr_stu, class_size);
	for ( int i = 0; i < entered; i++ ) {
		display1 (ptr_stu [i]);
		display2 (&ptr_stu [i]);
	}
	display3 (ptr_stu, entered);
	delete[]ptr_stu;
	cout << "Gotowe\n";
	return 0;
}

int getinfo (student pa[], int n) {
	cout << "Wpisac dane studentow: " << endl;
	for ( int i = 0; i < n; i++ ) {
		cout << "imie: ";
		cin >> pa [i].fullname;

		if ( !(cin >> pa [i].fullname) ) {
			break;
		}
		else {
			cout << "hobby: ";
			cin >> pa [i].hobby;
			cout << endl;
			cout << "poziom/ liczba: ";
			cin >> pa [i].ooplevel;
			cout << endl;
		}
	}
}
void display1 (student st) {
	cout << "display1: " << endl;
	cout << "imie: " << st.fullname << endl;
	cout << "hobby: " << st.hobby << endl;
	cout << "poziom: " << st.ooplevel << endl;

}
void display2 (const student * ps) {
	cout << "display2: " << endl;
	cout << "imie: " << ps->fullname << endl;
	cout << "hobby: " << ps->hobby << endl;
	cout << "poziom: " << ps->ooplevel << endl;
}
void display3 (const student pa[], int n) {
	for ( int i = 0; i < n; i++ ) {
		cout << "display3:  " << endl;
		cout << "imie: " << pa->fullname << endl;
		cout << "hobby: " << pa->hobby << endl;
		cout << "poziom: " << pa->ooplevel << endl;
	}
}