#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class info_list
{
	std::string file_name;
	std::vector<std::string> list;
public:
	info_list(std::string file) : file_name(file){}
	void save_list();
	void load_list();
	bool add(std::string new_elem);
	bool change_name(int id, std::string new_);
	std::string get_name(int id) { return list[id]; }
	int get_id(std::string name);
	int get_list_size() { return list.size(); }
};

