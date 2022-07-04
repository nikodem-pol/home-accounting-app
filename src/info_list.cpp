#include "info_list.h"
#include <iostream>


void info_list::save_list()
{
	std::fstream fout;
	fout.open(file_name, std::fstream::out);
	for (std::string name : list)
	{
		fout << name << std::endl;
	}
	fout.close();
}

void info_list::load_list()
{
	std::fstream fin;
	std::string line;
	fin.open(file_name, std::fstream::in);

	while (std::getline(fin, line))
	{
		list.push_back(line);
	}
	fin.close();
}

bool info_list::add(std::string new_elem)
{

	for (std::string name : list)
	{
		if (new_elem == name)
		{
			return false;
		}
	}
	list.push_back(new_elem);
	return true;
}

bool info_list::change_name(int id, std::string new_)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == new_)
			return false;
	}
	list[id] = new_;
	return true;
}

int info_list::get_id(std::string name)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == name)
			return i;
	}
	return -1;
}