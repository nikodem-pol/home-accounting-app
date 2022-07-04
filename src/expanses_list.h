#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include "expanse.h"
#include "bills.h"
#include "health.h"
#include "shopping.h"
#include "other.h"
#include "car.h"

class expanses_list
{
	std::string file_name;
	std::vector<std::shared_ptr<expanse>> list;
public:
	expanses_list(std::string file) : file_name(file) {};
	void save_list();
	void load_list();
	std::shared_ptr<expanse> get_expanse(int id);
	std::vector<std::shared_ptr<expanse>> get_expanses(std::string category, std::vector<std::shared_ptr<expanse>>& find);
	std::vector<std::shared_ptr<expanse>> get_expanses(int user_id, std::vector<std::shared_ptr<expanse>>& find);
	std::vector<std::shared_ptr<expanse>> get_expanses_between(date d_start, date d_end);
	std::vector<std::shared_ptr<expanse>> last(int quantity);

	//bool modify(int id);
	void sort();
	


	/*void add(
		std::string cat,
		int _id,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year);*/

	void add(
		std::string cat,
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year);

	void add_car(
		int u_id,
		int p_id,
		int s_id,
		double amt,
		int day,
		int month,
		int year,
		std::string _model);
};

