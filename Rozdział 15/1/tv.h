#pragma once
#include "pch.h"
#include <iostream>

class Tv {
public:
	friend class Remote; // klasa Remote ma dostêp do prywatnych danych Tv
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	enum { basic, interactive };

	Tv (int s = Off, int mc = 125): state (s), volume (5),
		maxchannel (mc), channel (2), mode (Cable), input (TV) {}
	void onoff () { state = (state == On) ? Off : On; }
	bool ison () const { return state == On; }
	bool volup ();
	bool voldown ();
	void chanup ();
	void chandown ();
	void set_mode () { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input () { input = (input == TV) ? DVD : TV; }
	void settings () const; // wyœwietla wszystkie ustawienia
	friend void set_remote (Remote& r) { r.remote_mode (); }

private:
	int state; //w³¹czony lub wy³¹czony
	int volume; //zk³adamy, ¿e mo¿na g³oœnoœæ wyraziæ liczb¹
	int maxchannel; //maksymalna liczba kana³ów
	int channel; //aktualnie w³¹czony program
	int mode; //antena lub telewizja kablowa
	int input; //telewizja lub DVD
};

class Remote {
public:
	friend class Tv;

	enum {basic, interactive};

	Remote (int m = Tv::TV, int r= Tv::basic): mode (m), remote_mode(r) {}
	void set_remote () { remote_mode = (remote_mode == basic) ? interactive : basic; } //
	bool volup (Tv& t) { return t.volup (); }
	bool voldown (Tv & t) { return t.voldown (); }
	void onoff (Tv &t) { t.onoff (); }
	void chanup (Tv & t) { t.chanup (); }
	void chandown (Tv&t) { t.chandown (); }
	void set_chan (Tv& t, int c) { t.channel = c; }
	void set_mode (Tv& t) { t.set_mode (); }
	void set_input (Tv& t) { t.set_input (); }
	void show () const; //
private:
	int mode; //kontroluje TV lub DVD
	int remote_mode; // sk³adowa, kt okreœla czy pilot dzia³a w trybie zwyk³ym czy interaktywnym
};