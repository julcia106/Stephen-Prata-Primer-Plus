#include "pch.h"
#include "Sales.h"

namespace SALES {
	Sales::Sales () {
		std::cout << "konstruktor domyslny: " << std::endl;

		m_sales [0] = 0.0;
		m_average = 0.0;
		m_max = 0.0;
		m_min = 0.0;

	}

	Sales::Sales (const double sales[], double average, double max, double min) {
		std::cout << "konstruktor z argumentem: " << std::endl;

		for ( int i = 0; i < 4; i++ )
			m_sales [i] = sales [i];
		m_average = average;
		m_max = max;
		m_min = min;
	}

	void Sales::setSales () {
		std::cout << "uzupelnianie interaktywne tablicy, wpisz 4 liczby: " << std::endl;

		double tab [4];
		for ( int i = 0; i < 4; i++ ) {
			std::cin >> tab [i];
		}

		double min = tab [0];
		for ( int i = 0; i < 4; i++ ) {

			if ( min > tab [i] )
				min = tab [i];
		}

		double temp = 0;
		double ave = 0;
		for ( int i = 0; i < 4; i++ ) {
			temp = temp + tab [i];
		}
		ave = temp / 4;

		double max = tab [0];
		for ( int i = 0; i < 4; i++ ) {
			if ( max < tab [i] )
				max = tab [i];
		}

		*this = Sales (tab, ave, max, min);

	}
	void Sales::showSales ()const {
		std::cout << "srednia: " << m_average << std::endl;
		std::cout << "max: " << m_max << std::endl;
		std::cout << "min: " << m_min << std::endl;
		//std::cout << "sales: " << m_sales << std::endl; // nie wiem jak to zrobić. 
	}
}