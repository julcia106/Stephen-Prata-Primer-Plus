#include "pch.h"
#include <iostream>
#include "tv.h"

bool Tv::volup () {
	if ( volume < MaxVal ) {
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown () {
	if ( volume > MinVal ) {
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup () {
	if ( channel < maxchannel )
		channel++;
	else
		channel = 1;
}

void Tv::chandown () {
	if ( channel > 1 )
		channel--;
	else
		channel = maxchannel;
}


void Tv::settings () const {
	std::cout << "Telewizor jest " << (state == Off ? "Wylaczony" : "Wlaczony") << std::endl;
	if ( state == On ) {
		std::cout << "Glosnosc: " << volume << std::endl;
		std::cout << "Program: " << channel << std::endl;
		std::cout << "Tryb: "
			<< (mode == Antenna ? "Antena" : "Kabel") << std::endl;
		std::cout << "Wejscie: "
			<< (input == TV ? "TV" : "DVD") << std::endl;
	}
}

void Remote::set_remote () {
	remote_mode = (remote_mode == basic) ? interactive : basic;
}

void Remote::show () const {
	std::cout << "Tryb pracy pilota: "
		<< (remote_mode == basic ? "podstawowy" : "interaktywny") << std::endl;
	return;
}
