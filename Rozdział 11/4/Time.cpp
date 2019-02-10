#include "pch.h"
#include "Time.h"
#include <iostream>

Time::Time () {
	hours = minutes = 0;
}

Time::Time (int h, int m) {
	hours = h;
	minutes = m;
}

void Time::AddMin (int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr (int h) {
	hours += h;
}

void Time::Reset (int h, int m) {
	hours = h;
	minutes = m;
}

Time operator+ (const Time& n, const Time & t) {
	Time sum;
	sum.minutes = n.minutes + t.minutes;
	sum.hours = n.hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator- (const Time&n, const Time& t) {
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = n.minutes + 60 * n.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;

}

Time operator*(const Time& t, double mult) {

	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

ostream& operator << (ostream & os, const Time& t) {
	os << t.hours << " godzin, " << t.minutes << " minut";
	return os;
}

