#include "shopping.h"
#include <iomanip>

std::string shopping::get_all()
{
	std::stringstream all_ss;
	std::string all;
	date d = get_date();

	std::string subcat = get_subcatName();
	std::string user = get_userName();
	std::string place = get_placeName();

	//all_ss<<"   " << id << "   " << category << "   " << subcat << "   " << amount << "zl" << "   " << user << "   " << place << "   " << d.get_all() << std::endl;
	all_ss << std::setw(4) << id << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << amount << "zl" << std::setw(10) << user << std::setw(12) << place << std::setw(13) << d.get_all() << std::setw(20) << "-" << std::endl;
	
	getline(all_ss, all);
	return all;

}

std::string shopping::get_allToFile()
{
	std::stringstream all_ss;
	std::string all;
	date d = get_date();

	all_ss << id << "," << user_id << "," << subcat_id << "," << place_id << "," << d.get_all() << "," << category << "," << amount << std::endl;
	getline(all_ss, all);
	return all;

}

void shopping::set_all(int u_id, int p_id, int s_id, double amt, int day, int month, int year)
{
	user_id = u_id;
	subcat_id = s_id;
	place_id = p_id;
	amount = amt;
	d = date(day, month, year);
}