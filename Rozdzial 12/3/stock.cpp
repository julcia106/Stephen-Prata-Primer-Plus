#include "pch.h"
#include "stock.h"
#include <iostream>
#include <cstring>

Stock::Stock () {

	len = 4;//
	company = new char [1];//
	company [0] = '\0';//

	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock (const char* co, long n, double pr) {

	len = strlen (co);//
	company = new char [len + 1];//
	strcpy (company, co);//

	if ( n < 0 ) {
		std::cout << "Liczba udzialow nie moze byc ujemna: "
			<< "ustalam liczbe udzialow w " << company << "na 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot ();
}

Stock::~Stock () {
	if ( !company )return; // ?dlaczego u praty nie ma tej linijki?
	delete[] company; //
}

Stock::Stock (const Stock& inny) { // 

	len = inny.len;
	company = new char [len + 1];
	strcpy (company, inny.company);

	shares = inny.shares;
	share_val = inny.share_val;
	total_val = inny.total_val;
}

Stock& Stock::operator=(const Stock& wzor) { //

	if ( this == &wzor ) { //prata
		return *this;
	}
	delete[]company;
	//delete shares, delete share_val, delete total_val ?

	shares = wzor.shares;
	share_val = wzor.share_val;
	total_val = wzor.total_val;

	len = wzor.len;
	company = new char [len + 1];
	strcpy (company, wzor.company);
	return *this;

}

void Stock::buy (long num, double price) {

	if ( num < 0 ) {
		std::cout << "Liczba nabywanych udzialow nie moze byc ujemna. "
			<< "Transakcja przerwana.\n";
	}
	else {
		shares += num;
		share_val = price;
		set_tot ();
	}
}

void Stock::sell (long num, double price) {

	using std::cout;
	if ( num > 0 ) {
		cout << "liczba sprzedawanaych udzialow nie moze byc ujemna. "
			<< "Transakcja przerwana.\n";
	}
	else if ( num > shares ) {
		cout << "Nie mozesz sprzedac wiecej udzialow, niz posiadasz!"
			<< "Transakcja przerwana.\n";
	}
	else {
		shares -= num;
		share_val = price;
		set_tot ();
	}
}

void Stock::update (double price) {
	share_val = price;
	set_tot ();
}


ostream&operator<<(ostream& ekran, const Stock& st) {

	ekran << "Spoloka: " << st.company << std::endl;
	ekran << " Liczba udzialow: " << st.shares << std::endl;
	ekran << " Cena udzialu: " << st.share_val << " zl " << std::endl;
	ekran << "Laczna wartosc udzialow : " << st.total_val << " zl " << std::endl;
	return ekran;
}

const Stock& Stock::topval (const Stock& s) const {

	if ( s.total_val > total_val )
		return s;
	else
		return *this;
}

