#pragma once
#include "pch.h"
#include <iostream>

class Customer {
private:
	long arrive;     // czas do��czenia klienta do kolejki
	int processtime; // czas obs�ugi klienta
public:
	Customer () { arrive = processtime = 0; }
	void set (long when);
	long when () const { return arrive; }
	int ptime () const { return processtime; }
};