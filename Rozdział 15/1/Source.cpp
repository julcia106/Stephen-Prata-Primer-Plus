#include "pch.h"
#include "tv.h"
#include <iostream>

int main () {
	Tv s42 (Tv::On);
	std::cout << "UWAGA Poczatkowe ustawienia telewizora 42\":\n";
	s42.settings ();
	s42.onoff ();
	s42.chanup ();
	std::cout << "\nNowe ustawienia telewizora 42\":\n";
	s42.settings ();


	Remote grey;
	grey.set_chan (s42, 10);
	grey.volup (s42);
	grey.volup (s42);
	std::cout << "\nUstawienia telewizora 42\" po uzyciu pilota:\n";
	s42.settings ();
	s42.change_remote (grey);
	grey.show ();


	Tv s58 (Tv::On, Remote::interactive);
	s58.set_mode ();
	grey.set_chan (s58, 28);
	std::cout << "\nUstawienia telewizora 58\"\n";
	s58.settings ();
	std::cout << std::endl;
	std::cout << "Remote: " << std::endl;
	s58.change_remote (grey);
	s58.change_remote (grey);
	s58.change_remote (grey);
	grey.show ();
	std::cout << std::endl;

	return 0;
}