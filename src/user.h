#pragma once
#include <string>

class user
{
	std::string name;
	bool status;
public:
	user(std::string _name, bool stat): name(_name), status(stat){}
	user(std::string _name) : name(_name), status(false){}
	std::string get_name() { return name; }
	bool get_status() { return status; }
	void activate() { status = true; }
	void deactivate() { status = false; }
	void change_name(std::string new_name) { name = new_name; }
};

