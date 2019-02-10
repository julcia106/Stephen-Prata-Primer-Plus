#pragma once
#include "pch.h"
#include <iostream>
#include <cctype>
#include <string.h>
using std::ostream;
using std::istream;

class String {

private:
	char* str;
	int len;
	static int how_many;
	static const int CLINLIM = 80; //limit d�ugo�ci ci�gu na wej�ciu
public:
	String (const char*s);//konstruktor
	String (); // konstruktor domy�lny 
	String (const String&); //konstruktor kopiujacy
	~String ();
	int length () const { return len; }
	void stringlow (); // konwertuje wszystkie wyst�puj�ce w ci�gu litery na litery ma�e int tolower(int ch);
	void stringup (); // konwertuje wszystkie wyst�puj�ce w ci�gu litery na wielkie int toupper (int ch);
	int has (char ch); //przyjmuje argumenty typu char i zwraca liczb� wyst�pie� tak zadanego znaku w ci�gu danego obiektu

	String& operator=(const String&); //przypisywanie obiektu klasy string do innego obiektu tej klasy 
	String& operator=(const char*); //przypisywanie ci�gu C do obiektu klasy String

	friend String operator+(const char*, const String&); //��czy dwa ci�gi w jeden 
	friend String operator+(const String&, const String&); //��czy dwa ci�gi w jeden 
	friend ostream& operator<< (ostream& os, const String & st);
	friend istream& operator>>(istream& is, String& st);
	friend bool operator==(const String &st, const String &st2);

	char& operator [](int i);
	const char& operator [](int i) const;
	//friend bool operator<(const String& st, const String& st2);
	//friend bool operator>(const String &st1, const String &st2);
	////metoda statyczna
	//static int HowMany ();
};