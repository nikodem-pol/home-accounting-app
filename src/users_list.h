#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include "user.h"

class users_list
{
	std::string file_name;
	std::vector<std::shared_ptr<user>> list;
public:
	users_list(std::string file): file_name(file){}
	void save_list();
	void load_list();
	void add(std::string name, bool status);
	bool add(std::string name);
	int get_id(std::string name);
	std::string get_name(int id) { return list[id]->get_name(); }
	bool get_status(int id) { return list[id]->get_status(); }
	bool get_status(std::string name);
	bool change_name(int old_id, std::string new_);
	void change_status(int id, bool status) 
	{
		if (status)
			list[id]->activate();
		else
			list[id]->deactivate();
	}
	void change_status(std::string name, bool status);
	int list_size(){ return list.size(); }
	int get_active();

};

