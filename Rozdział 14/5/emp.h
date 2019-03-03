#pragma once
#include <iostream>
#include <string>

class abstr_emp {
public:
	abstr_emp (): fname("brak"), lname("brak"), job("brak"){};
	abstr_emp (const std::string & fn, const std::string & ln,
			   const std::string & j);
	virtual void ShowAll () const; //opisuje i wy�wietla wszystkie dane
	virtual void SetAll (); //prosi u�ytkownika o podanie warto�ci
	friend std::ostream & operator<<(std::ostream&os, const abstr_emp& e);
	// tylko wy�wietla imie i nazwisko
	virtual ~abstr_emp () = 0; //wirtualna klasa bazowa
private:
	std::string fname; //imi� obiektu abstr_emp
	std::string lname; //nazwisko obiektu abstr_emp
	std::string job; //zaw�d obiektu abstr_emp
};

class employee: public abstr_emp {
public:
	employee () {};
	employee (const std::string& fn, const std::string& ln,
			  const std::string & j):abstr_emp (fn, ln, j) {}
	virtual void ShowAll () const;
	virtual void SetAll ();
};

class manager: virtual public abstr_emp {
public:
	manager ();
	manager (const std::string& fn, const std::string& ln,
			 const std::string & j, int ico = 0);
	manager (const abstr_emp& e, int ico); //TODO 
	manager (const manager& m); //TODO
	virtual void ShowAll () const;
	virtual void SetAll (); 
protected:
	int InChargeOf () const { return inchargeof; } //wyj�cie
	int& InChargeOf () { return inchargeof; } //wej�cie
private:
	int inchargeof; //liczba obiekt�w abstr_emps, kt�rymi zarz�dza 
};

class fink:virtual public abstr_emp {
public:
	fink ();
	fink (const std::string& fn, const std::string& ln,
		  const std::string & j, const std::string& rpo);
	fink (const abstr_emp & e, const std::string & rpo); //TODO
	fink (const fink & e); //TODO
	virtual void ShowAll () const;
	virtual void SetAll ();
protected:
	const std::string ReportsTo ()const { return reportsto; }
	std::string&ReportsTo () { return reportsto; }
private:
	std::string reportsto; // do kogo fink(donosiciel) przesy�a raport
};

class highfink: public manager, public fink  // g��wny donosiciel
{
public:
	highfink ();
	highfink (const std::string& fn, const std::string& ln,
			  const std::string & j, const std::string & rpo, int ico);
	highfink (const abstr_emp & e, const std::string & rpo, int ico);
	highfink (const fink & f, int ico);
	highfink (const manager & m, const std::string & rpo);
	highfink (const highfink & h);
	virtual void ShowAll () const; //TODO
	virtual void SetAll (); //TODO
};