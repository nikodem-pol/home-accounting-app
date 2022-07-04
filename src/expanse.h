#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include "date.h"
#include "info_list.h"
#include "users_list.h"
class expanse
{
protected:
	static int nr;
	std::string category;
	int id;
	int user_id, place_id, subcat_id;
	double amount;
	date d;
public:
	static info_list places;
	static users_list users;

	expanse(
		std::string cat,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	) 
		: d(day, month, year),
		user_id(u_id),
		place_id(p_id),
		subcat_id(s_id),
		amount(amt),
		category(cat),
		id(nr++) {}

	expanse(
		int _id,
		std::string cat,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year
	)
		: d(day, month, year),
		user_id(u_id),
		place_id(p_id),
		subcat_id(s_id),
		amount(amt),
		category(cat),
		id(_id) {
		nr++;
	}

	virtual std::string get_all() = 0;
	virtual std::string get_allToFile() = 0;
	virtual std::string get_categoryName() = 0;
	virtual std::string get_subcatName() = 0;
	virtual std::string get_modelName() = 0;
	virtual void set_all(int u_id, int p_id, int s_id, double amt, int day, int month, int year) = 0;
	double get_amount() { return amount; }
	int get_id() { return id;}
	int get_userId() { return user_id; }
	int get_subcatId() { return subcat_id; }
	int get_placeId() { return place_id; }
	int get_day() { return d.get_day(); }
	int get_month() { return d.get_month(); }
	int get_year() { return d.get_year(); }
	std::string get_placeName(){ return places.get_name(place_id); }
	std::string get_userName() {return  users.get_name(user_id); }
	date get_date() { return d; }

};

