#include <ctime>  // time and localtime
#include "date.h"
#include <string>
#include <iostream>
#include <sstream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
    os << dt.year << '-' << dt.month << '-' << dt.day;
    return os;
}

std::istream& operator>>(std::istream& is, Date& dt)
{
	char str[11];
	is.getline(str, 11);
	std::string s(str);
	std::stringstream ss(s);
	if(ss>> dt.year)
	{
		if(ss.get() == '-')
		{
			if(ss>> dt.month)
			{
				if(ss.get() == '-')
				{
					if(ss>> dt.day)
					{
						return is;
					}
				}
			}
		}
	}
	is.setstate(std::ios::failbit);
	return is;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	++day;
	if (day > daysPerMonth[month - 1]) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
}

