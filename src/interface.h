#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "expanses_list.h"
#include"limit.h"

class interface_
{
	expanses_list data_base;
	limit set_limit;
public:
	interface_(std::string exp_file, std::string lim_file) : data_base(exp_file), set_limit(lim_file) {}
	bool menu();
	void raport();
	void last();
	void find();
	void users();
	void add_modify();
	void edit_expanse();
	void change_place_name();
	void change_subcat_name();
	void shopping_change_name();
	void health_change_name();
	void car_change_name();
	void bills_change_name();
	void other_change_name();
	bool modify_expanse(int id);
	void change_exp_pl(std::shared_ptr<expanse>& ptr);
	void change_exp_us(std::shared_ptr<expanse>& ptr);
	void change_exp_sub(std::shared_ptr<expanse>& ptr);
	void change_exp_amt(std::shared_ptr<expanse>& ptr);
	void change_exp_date(std::shared_ptr<expanse>& ptr);
	void add_place();
	void add_subcat();
	void add_expanse();
	void add_user();
	void switch_user();
	void change_user_name();
	void limit();
	void set_up_limit();
};