#pragma once
#include "expanse.h"

class other :
	public expanse
{
public:
	other(
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: expanse("Inne", u_id, p_id, s_id, amt, day, month, year) {}

	other(
		int _id,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: expanse(_id, "Inne", u_id, p_id, s_id, amt, day, month, year) {}

	static info_list other_subcat;
	std::string get_all();
	std::string get_allToFile();
	std::string get_categoryName() { return category; }
	std::string get_subcatName() { return other_subcat.get_name(subcat_id); }
	std::string get_modelName() { return "null"; }
	void set_all(int u_id, int p_id, int s_id, double amt, int day, int month, int year);
};