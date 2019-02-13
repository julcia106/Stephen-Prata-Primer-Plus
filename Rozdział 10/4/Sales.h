#pragma once
#include "pch.h"
#include <iostream>

namespace SALES {
	const int QUARTERS = 4;

	class Sales {
	private:
		double m_sales [QUARTERS];
		double m_average;
		double m_max;
		double m_min;
	public:
		Sales ();
		Sales (const double sales[], double average, double max, double min);
		void setSales ();
		void showSales ()const;
	};
}