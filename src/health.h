#pragma once
#include "expanse.h"
class health :
    public expanse
{
public:
	health(
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: expanse("Zdrowie", u_id, p_id, s_id, amt, day, month, year) {}

	health(
		int _id,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: expanse(_id, "Zdrowie", u_id, p_id, s_id, amt, day, month, year) {}
	static info_list health_subcat;
	std::string get_all();
	std::string get_allToFile();
	std::string get_categoryName() { return category; }
	std::string get_subcatName() { return health_subcat.get_name(subcat_id); }
	std::string get_modelName() { return "null"; }
	void set_all(int u_id, int p_id, int s_id, double amt, int day, int month, int year);
};

