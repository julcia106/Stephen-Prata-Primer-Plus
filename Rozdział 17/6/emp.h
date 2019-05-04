#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <string>

class abstr_emp {
public:
	abstr_emp ()
		: fname (""), lname (""), job ("") {};
	abstr_emp (const std::string & fn, const std::string & ln,
			   const std::string & j);
	virtual void ShowAll () const; //opisuje i wyœwietla wszystkie dane
	virtual void SetAll (); //prosi u¿ytkownika o podanie wartoœci
	virtual void writeall (std::ofstream& fs);
	friend std::ostream & operator<<(std::ostream&os, const abstr_emp& e);
	// tylko wyœwietla imie i nazwisko
	virtual ~abstr_emp () = 0 {}; //wirtualna klasa bazowa
private:
	std::string fname; //imiê obiektu abstr_emp
	std::string lname; //nazwisko obiektu abstr_emp
	std::string job; //zawód obiektu abstr_emp
};

class employee: public abstr_emp {
public:
	employee ():abstr_emp () {};
	employee (const std::string& fn, const std::string& ln,
			  const std::string & j)
		:abstr_emp (fn, ln, j) {}
	virtual void ShowAll () const;
	virtual void SetAll ();
	virtual void writeall (std::ofstream& fs);
};

class manager: virtual public abstr_emp {
public:
	manager ()
		:abstr_emp () {}
	manager (const std::string& fn, const std::string& ln,
			 const std::string & j, int ico = 0);
	manager (const abstr_emp& e, int ico)
		: abstr_emp (e), inchargeof (ico) {}
	manager (const manager& m);
	virtual void ShowAll () const;
	virtual void SetAll ();
	virtual void writeall (std::ofstream& fs);
protected:
	int InChargeOf () const { return inchargeof; } //wyjœcie
	int& InChargeOf () { return inchargeof; } //wejœcie
private:
	int inchargeof; //liczba obiektów abstr_emps, którymi zarz¹dza 
};

class fink: virtual public abstr_emp {
public:
	fink (): abstr_emp () {}
	fink (const std::string& fn, const std::string& ln,
		  const std::string & j, const std::string& rpo);
	fink (const abstr_emp & e, const std::string & rpo)
		:abstr_emp (e), reportsto (rpo) {}
	fink (const fink & e)
		:abstr_emp (e), reportsto (e.reportsto) {}
	virtual void ShowAll () const;
	virtual void SetAll ();
	virtual void writeall (std::ofstream& fs);
protected:
	const std::string ReportsTo ()const { return reportsto; }
	std::string&ReportsTo () { return reportsto; }
private:
	std::string reportsto; // do kogo fink(donosiciel) przesy³a raport
};

class highfink: public manager, public fink  // g³ówny donosiciel
{
public:
	highfink ():abstr_emp (), manager (), fink () {}
	highfink (const std::string& fn, const std::string& ln,
			  const std::string & j, const std::string & rpo, int ico)
		:abstr_emp (fn, ln, j), fink (fn, ln, j, rpo), manager (fn, ln, j, ico) {}
	highfink (const abstr_emp & e, const std::string & rpo, int ico)
		:abstr_emp (e), manager (e, ico), fink (e, rpo) {}
	highfink (const fink & f, int ico)
		: abstr_emp (f), manager (f, ico), fink (f) {}
	highfink (const manager & m, const std::string & rpo)
		:abstr_emp (m), manager (m), fink (m, rpo) {}

	highfink (const highfink & h)
		:abstr_emp (h), manager (h), fink (h) {}
	virtual void ShowAll () const;
	virtual void SetAll ();
	virtual void writeall (std::ofstream& fs);
};