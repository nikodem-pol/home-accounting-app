#include "users_list.h"

void users_list::save_list()
{
	std::fstream fout;
	fout.open(file_name, std::fstream::out);

	for (auto& ptr : list)
	{
		fout << ptr->get_name() << "," << ptr->get_status() << std::endl;
	}
	fout.close();
}

void users_list::load_list()
{
	std::fstream fin;
	std::string line, name, stat_str;
	std::stringstream row, stat_ss;
	bool status;

	fin.open(file_name, std::fstream::in);
	while (std::getline(fin,line))
	{
		row << line;
		std::getline(row, name, ',');
		std::getline(row, stat_str, '\n');
		stat_ss << stat_str;
		stat_ss >> status;
		add(name, status);
		row.clear();
		stat_ss.clear();
	}
	fin.close();
}

void users_list::add(std::string name, bool status)
{
	list.push_back(std::shared_ptr<user>(new user(name, status)));
}

bool users_list::add(std::string name)
{
	if (list.size() != 0)
	{
		for (auto& ptr : list)
		{
			if (name == ptr->get_name())
				return false;
		}
	}
	add(name, false);
	return true;
}

int users_list::get_id(std::string name)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i]->get_name() == name)
			return i;
	}
	return -1;
}

bool users_list::get_status(std::string name)
{
	return list[get_id(name)]->get_status();
}

bool users_list::change_name(int old_id, std::string new_)
{
	
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i]->get_name() == new_)
			return false;
	}
	list[old_id]->change_name(new_);
	return true;
}

void users_list::change_status(std::string name, bool status)
{
	if (status)
		list[get_id(name)]->activate();
	else
		list[get_id(name)]->deactivate();
}

int users_list::get_active()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i]->get_status())
			return i;
	}
	return 0;
}