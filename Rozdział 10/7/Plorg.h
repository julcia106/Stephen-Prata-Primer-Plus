#pragma once
#include "pch.h"
#include <iostream>

class Plorg {
private:
	char m_name [19];
	int m_food;
public:
	Plorg (const char* name = "Plorga", int food = 50);
	void change_food (int food);
	void show ()const;
};