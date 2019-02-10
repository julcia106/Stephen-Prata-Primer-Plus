#include "pch.h"
#include "Dma.h"
#include <iostream>

abstractDMA::abstractDMA (const char * l, int r) {

	label = new char [std::strlen (l) + 1];
	std::strcpy (label, l);
	rating = r;
}

abstractDMA::abstractDMA (const abstractDMA &rs) {

	label = new char [std::strlen (rs.label) + 1];
	std::strcpy (label, rs.label);
	rating = rs.rating;
}

abstractDMA& abstractDMA::operator= (const abstractDMA &rs) {

	if ( this == &rs )
		return *this;
	delete[]label;
	label = new char [std::strlen (rs.label) + 1];
	std::strcpy (label, rs.label);
	rating = rs.rating;
	return *this;
}

void abstractDMA::viewDMA () const {

	using std::cout;
	using std::endl;

	cout << "Etykieta: " << label << endl;
	cout << "Klasa: " << rating << endl;
}

baseDMA::~baseDMA () {
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA &rs) {
	if ( this == &rs )
		return *this;
	abstractDMA::operator=(rs);
	delete[] label;
	label = new char [std::strlen (rs.label) + 1];
	std::strcpy (label, rs.label);
	rating = rs.rating;
	return *this;
}

lacksDMA::lacksDMA (const char* c, const char * l, int r)
	:abstractDMA (l, r) {
	std::strncpy (color, c, 39);
	color [39] = '\0';

}

lacksDMA::lacksDMA (const char* c, const baseDMA & rs)
	:abstractDMA (rs) {
	std::strncpy (color, c, COL_LEN - 1);
	color [COL_LEN - 1] = '\0';
}

hasDMA::hasDMA (const char * s, const char* l, int r)
	: abstractDMA (l, r) {
	style = new char [std::strlen (s) + 1];
	strcpy (style, s);
}

hasDMA::hasDMA (const char* s, const baseDMA &rs)
	: abstractDMA (rs) {
	style = new char [std::strlen (s) + 1];
	strcpy (style, s);
}

hasDMA::hasDMA (const hasDMA &hs)
	: abstractDMA (hs) {
	style = new char [std::strlen (hs.style) + 1];
	strcpy (style, hs.style);
}

hasDMA::~hasDMA () {
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& rs) {

	if ( this == &rs )
		return *this;
	abstractDMA::operator=(rs);
	delete[]style;
	style = new char [std::strlen (rs.style) + 1];
	strcpy (style, rs.style);
	return *this;
}



