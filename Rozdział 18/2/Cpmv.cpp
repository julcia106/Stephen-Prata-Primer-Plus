#include "pch.h"
#include "Cpmv.h"

Cpmv::Cpmv () {
	pi= nullptr;
}

Cpmv::Cpmv (std::string q, std::string z) {
	pi = new Info {q,z};
}

Cpmv::Cpmv (const Cpmv & cp) {
	pi = new Info { cp.pi->qcode, cp.pi->zcode };
}

Cpmv::Cpmv (Cpmv && mv) {
	std::cout << "Konstruktor przenoszacy\n";
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv () {
	delete pi;  
}

Cpmv & Cpmv::operator=(const Cpmv & cp) {
	
	if ( this == &cp )
		return *this;

	delete pi;
	pi = new Info { cp.pi->qcode, cp.pi->zcode };
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv) {
	std::cout << "Przenoszacy operator przypisania\n";

	if ( this == &mv )
		return *this;
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const {
	return Cpmv (pi->qcode + obj.pi->qcode, 
				 pi->zcode + obj.pi->zcode);
}

void Cpmv::Display () const {
	std::cout << "qcode: " << pi->qcode << "\n";
	std::cout << "zcode: " << pi->zcode << "\n";
}

