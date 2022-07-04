#include "expanses_list.h"
#include<iostream>

void expanses_list::save_list()
{	
	std::fstream fout;
	fout.open(file_name,std::ios::out);
	for (auto& ptr : list)
	{
		fout << ptr->get_allToFile() << std::endl;
	}
	fout.close();
}

void expanses_list::load_list()
{
	std::string line, temp, category, model;
	std::stringstream row, element;
	std::fstream fin;
	int id, user_id, subcat_id, place_id, day, month, year, tab[7] = { 0,0,0,0,0,0,0 };
	double amount;
	fin.open(file_name, std::ios::in);
	while (getline(fin, line))
	{
		;
		row << line;
		for (int i = 0; i < 7; i++)
		{
			getline(row, temp, ',');
			element << temp;
			element >> tab[i];
			element.clear();
			temp.clear();
		}

		id = tab[0];
		user_id = tab[1];
		subcat_id = tab[2];
		place_id = tab[3];
		day = tab[4];
		month = tab[5];
		year = tab[6];

		getline(row, category, ',');
	
		if (category == "Samochod")
		{
			getline(row, temp, ',');
			element << temp;
			element >> amount;
			element.clear();
			temp.clear();
			getline(row, model, '\n');

			list.push_back(std::shared_ptr<car>(new car(id, user_id, place_id, subcat_id, amount, day, month, year, model)));
		}
		else
		{
			getline(row, temp, '\n');
			element << temp;
			element >> amount;
			element.clear();
			temp.clear();

			if (category == "Zakupy")
			{
				list.push_back(std::shared_ptr<shopping>(new shopping(id, user_id, place_id, subcat_id, amount, day, month, year)));
			}
			else if (category == "Rachunki")
			{
				list.push_back(std::shared_ptr<bills>(new bills(id, user_id, place_id, subcat_id, amount, day, month, year)));
			}
			else if (category == "Inne")
			{
				list.push_back(std::shared_ptr<other>(new other(id, user_id, place_id, subcat_id, amount, day, month, year)));
			}
			else if (category == "Zdrowie")
			{
				list.push_back(std::shared_ptr<health>(new health (id, user_id, place_id, subcat_id, amount, day, month, year)));
			}
		}
		row.clear();
	}

	
}

void expanses_list::sort()
{
	int i, N = list.size();
	
	for (int j = N - 2; j >= 0; j--)
	{
		std::shared_ptr<expanse> x = list[j];
		i = j + 1;
		while ((i < N) && (x->get_date() > list[i]->get_date()))
		{
			list[i - 1] = list[i];
			i++;
		}
		list[i - 1] = x;
	}
}

std::shared_ptr<expanse> expanses_list::get_expanse(int id)
{
	for (auto& ptr : list)
	{
		if (ptr->get_id() == id)
		{
			return ptr;
		}
	}
	return nullptr;
}

std::vector<std::shared_ptr<expanse>> expanses_list::get_expanses(std::string category, std::vector<std::shared_ptr<expanse>>& find)
{
	std::vector<std::shared_ptr<expanse>> new_list;
	for (std::shared_ptr<expanse> ptr : find)
	{
		if (ptr->get_categoryName() == category)
		{
			new_list.push_back(ptr);
		}
	}
	return new_list;
}

std::vector<std::shared_ptr<expanse>> expanses_list::get_expanses(int user_id, std::vector<std::shared_ptr<expanse>>& find)
{
	std::vector<std::shared_ptr<expanse>> new_list;
	for (std::shared_ptr<expanse> ptr : find)
	{
		if (ptr->get_userId() == user_id)
		{
			new_list.push_back(ptr);
		}
	}
	return new_list;
}

std::vector<std::shared_ptr<expanse>> expanses_list::get_expanses_between(date d_start, date d_end)
{
	std::vector<std::shared_ptr<expanse>> new_list;

	for (std::shared_ptr<expanse> ptr : list)
	{
		date d_ptr = ptr->get_date();
		if (d_ptr >= d_start && d_ptr <= d_end)
		{
			new_list.push_back(ptr);
		}
	}
	return new_list;
}

void expanses_list::add(
	std::string cat,
	int u_id,
	int p_id,
	int s_id,
	double amt,
	int day,
	int month,
	int year)
{
	if (cat == "Zakupy")
	{
		list.push_back(std::shared_ptr<shopping>(new shopping(u_id, p_id, s_id, amt, day, month, year)));
	}
	else if (cat == "Rachunki")
	{
		list.push_back(std::shared_ptr<bills>(new bills(u_id, p_id, s_id, amt, day, month, year)));
	}
	else if (cat == "Inne")
	{
		list.push_back(std::shared_ptr<other>(new other(u_id, p_id, s_id, amt, day, month, year)));
	}
	else if (cat == "Zdrowie")
	{
		list.push_back(std::shared_ptr<health>(new health(u_id, p_id, s_id, amt, day, month, year)));
	}
}

std::vector<std::shared_ptr<expanse>> expanses_list::last(int quantity)
{
	std::vector<std::shared_ptr<expanse>> last;
	int i = list.size() - 1;
	int c = list.size() - quantity - 1;
	
	while (i >= 0 && i > c )
	{
		
		last.push_back(list[i]);
		--i;
	}
	return last;
}

void expanses_list::add_car(
	int u_id,
	int p_id,
	int s_id,
	double amt,
	int day,
	int month,
	int year,
	std::string model)
{
	list.push_back(std::shared_ptr<car>(new car(u_id, p_id, s_id, amt, day, month, year, model)));
}