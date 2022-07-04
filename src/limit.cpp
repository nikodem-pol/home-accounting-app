#include "limit.h"

void limit::check_dates()
{
	struct tm current_time;
	time_t now = time(0);
	localtime_s(&current_time, &now);

	int day = current_time.tm_mday;
	int month = current_time.tm_mon + 1;
	int year = current_time.tm_year + 1900;
	date current_date(day, month, year);

	if (current_date > end)
	{
		start = end + 1;
		end = start + 30;
	}
}

void limit::calculate_spend( expanses_list& base)
{
	std::vector<std::shared_ptr<expanse>> list = base.get_expanses_between(start, end);
	spend = 0;
	for (auto& ptr : list)
		spend = spend + ptr->get_amount();
}

void limit::save_limit()
{
	std::fstream fout;
	fout.open(file_name, std::ios::out);
	fout << start.get_all() << "," << limit_ << "," << status;
	fout.close();
}

void limit::load_limit()
{
	std::string limit_str, day_str, month_str, year_str, status_str;
	std::stringstream day_ss, month_ss, year_ss, status_ss, limit_ss;
	int day, month, year;
	double limit_;
	bool status;

	std::fstream  fin;

	fin.open(file_name, std::ios::in);
	getline(fin, day_str,',');
	getline(fin, month_str, ',');
	getline(fin, year_str, ',');
	getline(fin, limit_str, ',');
	getline(fin, status_str, '\n');
	day_ss << day_str;
	day_ss >> day;

	month_ss << month_str;
	month_ss >> month;

	year_ss << year_str;
	year_ss >> year;

	limit_ss << limit_str;
	limit_ss >> limit_;

	status_ss << status_str;
	status_ss >> status;

	if (status)
		this->turn_on();
	else
		this->turn_off();

	this->set_limit(limit_);
	this->set_start(day, month, year);
}