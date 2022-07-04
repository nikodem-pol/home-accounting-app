#pragma once
#include <ctime>
#include "date.h"
#include "expanses_list.h"
#include "expanse.h"


class limit
{
	std::string file_name;
	date start, end;
	double spend, limit_, difference;
	bool status;
public:
	limit(std::string file) : file_name(file), start(), end(), limit_(0), difference(0), spend(0), status(false) {}
	void set_limit(double new_lim) { limit_ = new_lim; }
	void set_start(int day, int month, int year) { start.set_all(day, month, year); end = start + 30; }
	void turn_on() { status = true; }
	void turn_off() { status = false; }
	double get_difference() { return limit_-spend; }
	double get_spend() { return spend; }
	double get_limit() { return limit_; }
	bool get_status() { return status; }
	std::string get_start() { return start.get_all(); }
	std::string get_end() { return end.get_all(); }
	void check_dates();
	void calculate_spend( expanses_list& base);
	void save_limit();
	void load_limit();

};

