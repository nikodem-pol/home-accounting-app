#pragma once
#include "expanse.h"

class shopping :
    public expanse
{

public:
	shopping(
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: expanse("Zakupy",u_id,p_id,s_id,amt,day,month,year){}

	shopping(
		int _id,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: expanse(_id,"Zakupy", u_id, p_id, s_id, amt, day, month, year) {}

	static info_list shopping_subcat;

	std::string get_all();
	std::string get_allToFile();
	std::string get_categoryName() { return category; }
	std::string get_subcatName(){ return shopping_subcat.get_name(subcat_id); }
	std::string get_modelName() { return "null"; }
	void set_all(int u_id, int p_id, int s_id, double amt, int day, int month, int year);
};

