#pragma once
#include "pch.h"
#include <iostream>

class Remote;

class Tv {
public:
	friend class Remote;

	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv (int s = Off, int mc = 125): state (s), volume (5),
		maxchannel (mc), channel (2), mode (Cable), input (TV) {}
	void onoff ();
	bool ison () const;
	bool volup ();
	bool voldown ();
	void chanup ();
	void chandown ();
	void set_mode ();
	void set_input ();
	void settings () const; // wyœwietla wszystkie ustawienia
	void change_remote (Remote& r); 

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

	enum { basic, interactive };

	Remote (int m = Tv::TV, int r = basic): mode (m), remote_mode (r) {}
	bool volup (Tv& t) { return t.volup (); }
	bool voldown (Tv & t) { return t.voldown (); }
	void onoff (Tv &t) { t.onoff (); }
	void chanup (Tv & t) { t.chanup (); }
	void chandown (Tv&t) { t.chandown (); }
	void set_chan (Tv& t, int c) { t.channel = c; }
	void set_mode (Tv& t) { t.set_mode (); }
	void set_input (Tv& t) { t.set_input (); }
	void set_remote ();
	void show () const; 
private:
	int mode;
	int remote_mode; 
};



inline void Tv::change_remote (Remote& r) { r.set_remote (); }
inline void Tv::set_mode () { mode = (mode == Antenna) ? Cable : Antenna; }
inline void Tv::set_input () { input = (input == TV) ? DVD : TV; }
inline void Tv::onoff () { state = (state == On) ? Off : On; }
inline bool Tv::ison () const { return state == On; }

