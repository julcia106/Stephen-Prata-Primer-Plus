#include "pch.h"
#include "string.h"
#include <iostream>
using namespace std;

int String::how_many = 0;

//zmienne statyczne- poczytaj.
//416 prata  

String::String (const char*s) {

	len = strlen (s);
	str = new char [len + 1];
	strcpy (str, s);
}

String::String () {

	len = 0;
	str = new char [1];
	str [0] = '\0';
}

String::String (const String& st) {

	len = st.len;
	str = new char [len + 1];
	strcpy (str, st.str);
}

String::~String () {

	delete[] str;
}

String& String::operator=(const String& st) {

	if ( this == &st )
		return *this;
	delete[] str;
	len = st.len;
	str = new char [len + 1];
	strcpy (str, st.str);
	return *this;
}

String& String::operator=(const char* ch) {

	delete[] str;
	len = strlen (ch);
	str = new char [len + 1];
	strcpy (str, ch);
	return *this;
}

char& String::operator [](int i) {

	return str [i];
}

const char& String::operator[](int i) const {

	return str [i];
}

String operator+(const char* ch, const String& st) {

	int len = 0;
	int len2 = 0;

	len = strlen (ch);
	len2 = strlen (st.str);

	char*temp_char = new char [len + len2 + 1];

	strcpy (temp_char, ch);
	strcat (temp_char, st.str);

	return temp_char;
}

String operator+(const String& ls, const String& rs) {

	int len = 0;
	int len2 = 0;

	len = strlen (ls.str);
	len2 = strlen (ls.str);

	char* temp = new char [len + len2 + 1];

	strcpy (temp, ls.str);
	strcat (temp, rs.str);

	return temp;
}

void String::stringlow () {

	int i = 0;
	while ( str [i] ) {
		putchar (tolower (str [i]));
		i++;
	}
}

void String::stringup () {

	int i = 0;
	while ( str [i] ) {
		putchar (toupper (str [i]));
		i++;
	}
}

int String::has (char ch) {

	int i = 0;
	while ( str [i] ) {
		if ( str [i] == ch ) {
			how_many++;
		}
		i++;
	}
	return how_many;
}

ostream& operator<< (ostream& os, const String & st) {
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st) {

	char temp [String::CLINLIM];
	is.get (temp, String::CLINLIM);
	if ( is ) {
		st = temp;
	}
	while ( is && is.get () != '\n' )
		continue;
	return is;
}

bool operator==(const String &st, const String &st2) {
	return (strcmp (st.str, st2.str) == 0);
}

