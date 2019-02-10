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
	static const int CLINLIM = 80; //limit d³ugoœci ci¹gu na wejœciu
public:
	String (const char*s);//konstruktor
	String (); // konstruktor domyœlny 
	String (const String&); //konstruktor kopiujacy
	~String ();
	int length () const { return len; }
	void stringlow (); // konwertuje wszystkie wystêpuj¹ce w ci¹gu litery na litery ma³e int tolower(int ch);
	void stringup (); // konwertuje wszystkie wystêpuj¹ce w ci¹gu litery na wielkie int toupper (int ch);
	int has (char ch); //przyjmuje argumenty typu char i zwraca liczbê wyst¹pieñ tak zadanego znaku w ci¹gu danego obiektu

	String& operator=(const String&); //przypisywanie obiektu klasy string do innego obiektu tej klasy 
	String& operator=(const char*); //przypisywanie ci¹gu C do obiektu klasy String

	friend String operator+(const char*, const String&); //³¹czy dwa ci¹gi w jeden 
	friend String operator+(const String&, const String&); //³¹czy dwa ci¹gi w jeden 
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