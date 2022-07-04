#pragma once
#include "expanse.h"
class car :
    public expanse
{
	std::string model;
public:
	car(
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year,
		std::string _model
	)
		: expanse("Samochod", u_id, p_id, s_id, amt, day, month, year), model(_model) {}

	car(
		int _id,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year,
		std::string _model
	)
		: expanse(_id, "Samochod", u_id, p_id, s_id, amt, day, month, year), model(_model) {}
	static info_list car_subcat;
	std::string get_all();
	std::string get_allToFile();
	std::string get_categoryName() { return category; }
	std::string get_subcatName() { return car_subcat.get_name(subcat_id); }
	std::string get_modelName() { return model; }
	void set_all(int u_id, int p_id, int s_id, double amt, int day, int month, int year);
};

