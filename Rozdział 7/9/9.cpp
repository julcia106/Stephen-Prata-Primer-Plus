#include "pch.h"
#include <iostream>

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
	std::cout << "Podaj wielkosc grupy: ";
	int class_size;
	std::cin >> class_size;
	while ( std::cin.get () != '\n' )
		continue;
	student* ptr_stu = new student [class_size];
	int entered = getinfo (ptr_stu, class_size);
	for ( int i = 0; i < entered; i++ ) {
		display1 (ptr_stu [i]);
		display2 (&ptr_stu [i]);
	}
	display3 (ptr_stu, entered);
	delete[]ptr_stu;
	std::cout << "Gotowe\n";
	return 0;
}

int getinfo (student pa[], int n) {
	std::cout << "Wpisz dane studentow: \n";
	int i = 0;

	for ( int i = 0; i < n; i++ ) {
		std::cout << "Imie: ";
		std::cin >> pa [i].fullname;
		std::cout << "Hobby: ";
		std::cin >> pa [i].hobby;
		std::cout << "Liczba: ";
		std::cin >> pa [i].ooplevel;
	}
	return n;
}
void display1 (student st) {

	std::cout << "Pobrana struktura: \n";
	std::cout << "Imie: " << st.fullname;
	std::cout << " Hobby: " << st.hobby;
	std::cout << " Poziom: " << st.ooplevel;
	std::cout << std::endl;

}
void display2 (const student * ps) {

	std::cout << "Pobiera adres struktury: \n";
	std::cout << "Imie: " << ps->fullname;
	std::cout << " Hobby: " << ps->hobby;
	std::cout << " Poziom: " << ps->ooplevel;
	std::cout << std::endl;
}
void display3 (const student pa[], int n) {

	std::cout << "Pobiera adres pierwszego elementu tablicy ze strukturami student: \n";

	for ( int i = 0; i < n; i++ ) {
		std::cout << "Imie: " << pa [i].fullname;
		std::cout << " Hobby: " << pa [i].hobby;
		std::cout << " Poziom: " << pa [i].ooplevel;
		std::cout << std::endl;
	}
}