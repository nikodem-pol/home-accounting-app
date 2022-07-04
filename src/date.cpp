#include "date.h"

date& date::operator=(const date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;

	return *this;
}

bool date::operator==(const date& d)
{
	if (day == d.day && month == d.month && year == d.year)
		return true;
	else
		return false;
}

bool date::operator<=(const date& d)
{
	if (*this == d)
		return true;

	if (year < d.year)
		return true;

	if (year > d.year)
		return false;

	if (month < d.month)
		return true;

	if (month > d.month)
		return false;

	if (day < d.day)
		return true;

	return false;

}

bool date::operator>=(const date& d)
{
	if (*this == d)
		return true;

	if (year < d.year)
		return false;

	if (year > d.year)
		return true;

	if (month < d.month)
		return false;

	if (month > d.month)
		return true;

	if (day < d.day)
		return false;

	return true;

}

date date::operator+(const int days)
{
	int last_day;

	if (year % 4 == 0 && month == 2)
		last_day = 29;
	else
		last_day = quantity[month - 1];

	if (day + days > last_day)
	{
		day = (day + days) - last_day;
		if (++month > 12)
		{
			month = 1;
			year++;
		}
	}
	else
	{
		day = day + days;
	}

	return *this;
}

bool date::operator>(const date& d)
{
	if (year < d.year)
		return false;

	if (year > d.year)
		return true;

	if (month < d.month)
		return false;

	if (month > d.month)
		return true;

	if (day < d.day)
		return false;

	if (day > d.day)
		return true;

	return false;
}

bool date::operator<(const date& d)
{
	if (year < d.year)
		return true;

	if (year > d.year)
		return false;

	if (month < d.month)
		return true;

	if (month > d.month)
		return false;

	if (day < d.day)
		return true;

	if (day > d.day)
		return false;

	return false;
}

std::string date::get_all()
{
	std::stringstream all_ss;
	std::string all;
	all_ss << day << "," << month << "," << year;
	all_ss >> all;
	return all;
}