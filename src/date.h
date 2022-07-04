#pragma once
#include <string>
#include <sstream>
class date
{
	int quantity[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day;
	int month;
	int year;
public:
	date():day(0),month(0),year(0){}
	date(int _day, int _month, int year) : day(_day), month(_month), year(year) {}

	date& operator=(const date& d);		//operator przypisania
	date operator+(const int days);		//dodaje do daty podan� liczb� dni
	bool operator==(const date& d);		//zwraca true gdy daty s� takie same
	bool operator<=(const date& d);		//zwraca true, gdy data obiektu na rzecz kt�rego metoda zostala wykonana jest wcze�niejsz od por�wnywanej daty
	bool operator>=(const date& d);		//zwraca true, gdy data obiektu na rzecz kt�rego metoda zostala wykonana jest p�niejsza od por�wnywanej daty
	bool operator>(const date& d);
	bool operator<(const date& d);
	/*void get()
	{
		std::cout << day << "." << month << "." << year << std::endl;
	}*/
	void set_all(int new_day, int new_month, int new_year) { day = new_day; month = new_month; year = new_year; }
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	std::string get_all();
};

