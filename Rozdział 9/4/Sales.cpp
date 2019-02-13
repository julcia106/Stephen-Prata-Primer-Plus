#include "pch.h"
#include "Sales.h"

namespace SALES {
	void setSales (Sales& s, const double ar[], int n) {

		double min = ar [0];
		for ( int i = 0; i < n; i++ ) {

			if ( min > ar [i] )
				min = ar [i];
			s.min = min;
		}


		double ave = 0;
		for ( int i = 0; i < n; i++ ) {
			ave = ave + ar [i];
			s.average = ave / n;
		}

		double max = ar [0];
		for ( int i = 0; i < n; i++ ) {
			if ( max < ar [i] )
				max = ar [i];
			s.max = max;
		}


	}
	void setSales (Sales& s) {
		double min = s.sales [0];
		for ( int i = 0; i < 4; i++ ) {

			if ( min > s.sales [i] )
				min = s.sales [i];
			s.min = min;

		}

		double ave = 0;
		for ( int i = 0; i < 4; i++ ) {
			ave = ave + s.sales [i];
			s.average = ave / 4;
		}

		double max = s.sales [0];
		for ( int i = 0; i < 4; i++ ) {
			if ( max < s.sales [i] )
				max = s.sales [i];
			s.max = max;
		}


	}
	void showSales (const Sales& s) {
		std::cout << "srednia: " << s.average << std::endl;
		std::cout << "max: " << s.max << std::endl;
		std::cout << "min: " << s.min << std::endl;
		//std::cout << "sales: " << s.sales << std::endl; // nie wiem jak to zrobić. 
	}


}