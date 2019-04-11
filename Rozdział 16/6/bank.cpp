#include "pch.h"
#include "bank.h"
#include <iostream>
#include "bank.h"

// metody klasy Customer

// kiedy klient trafia do kolejki, zapamiêtywany jest bie¿¹cy
// czas systemowy, losowany jest te¿ czas obs³ugi klienta
// (z zakresu od 1 do 3)
void Customer::set (long when) {
	processtime = std::rand () % 3 + 1;
	arrive = when;
}
