#include "pch.h"
#include "Plorg.h"

Plorg::Plorg (const char* name, int food) {
	strcpy (m_name, name);
	m_food = food;
}

void Plorg::change_food (int food) {
	m_food = food;
}

void Plorg::show ()const {
	std::cout << "Imie: " << m_name << std::endl;
	std::cout << "Wspolczynnik sytosci: " << m_food << std::endl;
}