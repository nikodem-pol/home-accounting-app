#include "interface.h"
#include "shopping.h"
//
bool interface_::menu()
{
	char input;
	bool isValid = true;
	bool end = false;
	data_base.load_list();
	set_limit.load_limit();
	do
	{
		std::cout << "MENU\n\n";
		std::cout << "1. Raport\n"
			<< "2. Dodaj/Edytuj\n"
			<< "3. Uzytkownicy\n\n"
			<< "0. Zapisz i wyjdz\n\n";

		if (isValid)
			std::cout << "Wybor: ";
		else
			std::cout << "Wybierz jeszcze raz: ";

		std::cin >> input;
		system("CLS");

		switch (input)
		{
		case 49:	// 49 = '1'
			//raport();
			break;
		case 50:	// 50 = '2'
			//add_modify();
			break;
		case 51:	// 51 = '3'
			//users();
			break;
		case 48:	 // 48 = '0'

			data_base.save_list();
			set_limit.save_limit();
			expanse::places.save_list();
			expanse::users.save_list();
			shopping::shopping_subcat.save_list();
			bills::bills_subcat.save_list();
			car::car_subcat.save_list();
			health::health_subcat.save_list();
			other::other_subcat.save_list();

			end = true;
			break;
		default:
			isValid = false;
			break;
		}
		system("CLS");


	} while (!end);

		return true;
}
//
//void interface_::raport()
//{
//	char input;
//	bool isValid = true;
//	bool go_back = false;
//	do
//	{
//		std::cout << "RAPORT\n\n"
//			<< "1. Ostatnie wydatki\n"
//			<< "2. Filtruj\n"
//			<< "3. Limit\n\n"
//			<< "0. Powrot do menu\n\n";
//
//		if (isValid)
//			std::cout << "Wybor: ";
//		else
//			std::cout << "Wybierz jeszcze raz: ";
//
//		std::cin >> input;
//		system("CLS");
//
//		switch (input)
//		{
//		case 49:	// 49 = '1'
//			last();
//			break;
//		case 50:	// 50 = '2'
//			find();
//			break;
//		case 51:	// 51 = '3'
//			limit();
//			break;
//		case 48:	//48 = '0'
//			go_back = true;
//			break;
//		default:
//			isValid = false;
//			break;
//		}
//		system("CLS");
//	} while (!go_back);
//}
//
//void interface_::last()
//{
//	std::vector<std::shared_ptr<expanse>> exp;
//	char input = 0;
//	int how_much = 0;
//	bool goBack = false;
//	do
//	{
//		system("cls");
//		std::cout << "OSTATNIE WYDATKI\n\n";
//		std::cout << "Podaj ilosc wydatkow do wyswietlenia: ";
//		std::cin >> how_much;
//	} while (how_much <= 0);
//
//	exp = data_base.last(how_much);
//
//	do
//	{
//		system("CLS");
//		std::cout << "OSTATNIE WYDATKI\n\n";
//		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//		std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//		for (auto& ptr : exp)
//		{
//			std::cout << ptr->get_all() << "\n" << std::endl;
//		}
//		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//		std::cout << "\n  4. Powrot\n" << std::endl;
//		std::cout << "Wybor: ";
//		std::cin >> input;
//		if (input == 52)		// 52 = '4'
//			goBack = true;
//	} while (!goBack);	
//}
//
//void interface_::find()
//{
//	std::vector<std::shared_ptr<expanse>> find_list;
//	bool isValid = false, condition = true;
//	int day1, month1, year1, day2, month2, year2, user,  input;
//	char cat_in, user_in;
//	double sum = 0;
//	date start, end;
//	std::string category;	
//	do {
//		do
//		{
//			system("CLS");
//			std::cout << "FILTRUJ\n\n";
//			if (!condition)
//			{
//				std::cout << "Pierwsza data musi byc wczesniejsza niz druga!\n\n";
//			}
//			std::cout << "Podaj daty\n\n";
//			std::cout << "Szukaj od:\n";
//			std::cout << "Dzien: ";
//			std::cin >> day1;
//			if (day1 > 0 && day1 < 32)
//				isValid = true;
//			else
//				isValid = false;
//
//		} while (!isValid);
//
//		do
//		{
//			system("CLS");
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Podaj daty:\n\n";
//			std::cout << "Szukaj od:\n";
//			std::cout << "Dzien: " << day1;
//			std::cout << "\nMiesiac: ";
//			std::cin >> month1;
//			if (month1 > 0 && month1 < 13)
//				isValid = true;
//			else
//				isValid = false;
//		} while (!isValid);
//
//		do
//		{
//			system("CLS");
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Podaj daty:\n\n";
//			std::cout << "Szukaj od:\n";
//			std::cout << "Dzien: " << day1;
//			std::cout << "\nMiesiac: " << month1;
//			std::cout << "\nRok: ";
//			std::cin >> year1;
//			if (year1 > 0)
//				isValid = true;
//			else
//				isValid = false;
//		} while (!isValid);
//
//		do
//		{
//			system("CLS");
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Podaj daty:\n\n";
//			std::cout << "Szukaj od: " << day1 << "," << month1 << "," << year1 << "r.\n";
//			std::cout << "Do:\n";
//			std::cout << "Dzien: ";
//			std::cin >> day2;
//			if (day2 > 0 && day2 < 32)
//				isValid = true;
//			else
//				isValid = false;
//		} while (!isValid);
//
//		do
//		{
//			system("CLS");
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Podaj daty:\n\n";
//			std::cout << "Szukaj od: " << day1 << "," << month1 << "," << year1 << "r.\n";
//			std::cout << "Do:\n";
//			std::cout << "Dzien: " << day2;
//			std::cout << "\nMiesiac: ";
//			std::cin >> month2;
//			if (month2 > 0 && month2 < 13)
//				isValid = true;
//			else
//				isValid = false;
//		} while (!isValid);
//
//		do
//		{
//			system("CLS");
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Podaj daty:\n\n";
//			std::cout << "Szukaj od: " << day1 << "," << month1 << "," << year1 << "r.\n";
//			std::cout << "Do:\n";
//			std::cout << "Dzien: " << day2;
//			std::cout << "\nMiesiac: " << month2;
//			std::cout << "\nRok: ";
//			std::cin >> year2;
//			if (year2 > 0)
//				isValid = true;
//			else
//				isValid = false;
//		} while (!isValid);
//
//		 start.set_all(day1, month1, year1);
//		 end.set_all(day2, month2, year2);
//
//	     condition = start <= end;
//	} while (!condition);
//
//	do
//	{
//		system("CLS");
//		std::cout << "FILTRUJ\n\n";
//		std::cout << "Szukaj od: " << day1 << "," << month1 << "," << year1 << "r.\n";
//		std::cout<<"Do: "<< day2 << "," << month2 << "," << year2 << "r.\n\n";
//		std::cout << "Podaj kategorie:\n";
//		std::cout << "1. Wszystkie\n"
//			<< "2. Zakupy\n"
//			<< "3. Zdrowie\n"
//			<< "4. Samochod\n"
//			<< "5. Rachunki\n"
//			<< "6. Inne\n\n";
//		std::cout << "Wybor: ";
//		std::cin >> cat_in;
//
//		if (cat_in > 48 && cat_in < 55)
//			isValid = true;
//		else
//			isValid = false;
//
//	} while (!isValid);
//
//	switch (cat_in)
//	{
//	case 49:
//		category = "Wszystkie";
//		break;
//	case 50:
//		category = "Zakupy";
//		break;
//	case 51:
//		category = "Zdrowie";
//		break;
//	case 52:
//		category = "Samochod";
//		break;
//	case 53:
//		category = "Rachunki";
//		break;
//	case 54:
//		category = "Inne";
//		break;
//	}
//
//	do
//	{
//		system("CLS");
//		std::cout << "FILTRUJ\n\n";
//		std::cout << "Szukaj od: " << day1 << "," << month1 << "," << year1 << "r.\n";
//		std::cout << "Do: " << day2 << "," << month2 << "," << year2 << "r.\n\n";
//		std::cout << "Kategoria: " << category;
//		std::cout << "\n\nWybierz uzytkownika: \n";
//
//		int i = 2;
//		std::cout << "1.Wszyscy\n";
//		for (int j = 0; j < expanse::users.list_size(); j++)
//		{
//			std::cout << i << ". " << expanse::users.get_name(j) << std::endl;
//			i++;
//		}
//		std::cout << "\nWybor: ";
//
//		std::cin >> user_in;
//		user = (int)user_in - 48;
//
//		if (user > 0 && user < expanse::users.list_size()+1)
//			isValid = true;
//		else
//			isValid = false;
//		user -= 2;
//	
//	} while (!isValid);
//
//	find_list = data_base.get_expanses_between(start, end);
//	
//	
//	if (user == -1 && cat_in != 49) //49 = '1'
//	{
//		find_list = data_base.get_expanses(category, find_list);
//	}
//	else if (user != -1 && cat_in == 49)	//49 = '1'
//	{
//		find_list = data_base.get_expanses(user, find_list);
//	}
//	else if (user != -1 && cat_in != 49)	//49 = '1'
//	{
//		find_list = data_base.get_expanses(category, find_list);
//		find_list = data_base.get_expanses(user, find_list);
//	}
//	do 
//	{
//		system("CLS");
//		if (find_list.size() > 0)
//		{
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Od: " << start.get_all() << "r. \nDo: " << end.get_all() << "r.\n\n";
//			std::cout << "Kategoria: " << category << std::endl << std::endl;
//
//			if (user == -1)
//				std::cout << "Uzytkownik: " << "Wszyscy" << std::endl << std::endl;
//			else
//				std::cout << "Uzytkownik: " << expanse::users.get_name(user) << std::endl << std::endl;
//
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//
//			for (auto& ptr : find_list)
//			{
//				std::cout << ptr->get_all() << "\n" << std::endl;
//				sum = sum + ptr->get_amount();
//			}
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "SUMA: " << sum << "zl\n\n";
//
//			std::cout << "4. Powrot\n" << std::endl;
//			std::cout << "Wybor: ";
//			std::cin >> input;
//		}
//		else
//		{			
//			std::cout << "FILTRUJ\n\n";
//			std::cout << "Od: " << start.get_all() << "r. \nDo: " << end.get_all() << "r.\n\n";
//			std::cout << "Kategoria: " << category << std::endl << std::endl;
//
//			if (user == -1)
//				std::cout << "Uzytkownik: " << "Wszyscy" << std::endl << std::endl;
//			else
//				std::cout << "Uzytkownik: " << expanse::users.get_name(user) << std::endl << std::endl;
//
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "Brak wynikow.\n";
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "4. Powrot\n" << std::endl;
//			std::cout << "Wybor: ";
//			std::cin >> input;
//		}
//	} while (input != 4);
//}
//
//void interface_::add_modify()
//{
//	char input;
//	bool isValid = true, goBack = false;
//	do {
//		
//		std::cout << "DODAJ/EDYTUJ\n\n"
//			<< "Edytuj:" << std::endl
//			<< "\t1. Nazwa miejsca" << std::endl
//			<< "\t2. Nazwa podkategorii" << std::endl
//			<< "\t3. Wydatek" << std::endl
//			<< "\nDodaj:" << std::endl
//			<< "\t4. Miejsce" << std::endl
//			<< "\t5. Podkategoria" << std::endl
//			<< "\t6. Wydatek" << std::endl
//			<< "\n\n0. Powrot do menu\n" << std::endl;
//
//		if (isValid) 
//			std::cout << "Wybor: ";
//		else
//			std::cout << "Wybierz jeszce raz:";
//
//		std::cin >> input;
//
//		system("cls");
//		switch (input)
//		{
//		case 49:	//49 = '1'
//			change_place_name();
//			break;
//		case 50:	//50 = '2'
//			change_subcat_name();
//			break;
//		case 51:	//51 = '3'
//			edit_expanse();
//			break;
//		case 52:	//52 = '4'
//			add_place();
//			break;
//		case 53:	//53 = '5'
//			add_subcat();
//			break;
//		case 54:	//54 = '6'
//			add_expanse();
//			break;
//		case 48:	//48 = '0'
//			goBack = true;
//			break;
//
//		default:
//			isValid = false;
//			break;
//		}
//		system("cls");
//	} while (!goBack); //55 = '7'
//}
//
//void interface_::change_place_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE MIEJSCA\n\n";
//		std::cout << "Miejsca:" << std::endl;
//		for (int i = 1; i <= expanse::places.get_list_size(); i++)
//		{
//			std::cout << i << ". " << expanse::places.get_name(i-1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < expanse::places.get_list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "EDYTUJ NAZWE MIEJSCA\n\n"
//					<< "Wybrano: " << expanse::places.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!expanse::places.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (true); 
//}
//
//void interface_::change_subcat_name() 
//{
//	char input;
//	int chosen;
//	bool goBack = false, isValid = true;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n"
//			<< "Kategorie: \n"
//			<< "1. Zakupy\n"
//			<< "2. Zdrowie\n"
//			<< "3. Samochod\n"
//			<< "4. Rachunki\n"
//			<< "5. Inne\n\n"
//			<<"0. Powrot\n\n"
//			<< "Wybierz kategorie w ktorej chcesz dokonac zmian: ";
//
//			std::cin >> input;
//			chosen = (int)input - 48;
//
//			system("cls");
//
//			switch (chosen)
//			{
//			case 0:
//					return;
//				break;
//			case 1:
//				shopping_change_name();
//				break;
//			case 2:
//				health_change_name();
//				break;
//			case 3:
//				car_change_name();
//				break;
//			case 4:
//				bills_change_name();
//				break;
//			case 5:
//				other_change_name();
//				break;
//			default:
//				break;
//			}
//			system("cls");
//
//	} while (!goBack);
//}
//
//void interface_::shopping_change_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false, goBack = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n";
//		std::cout << "Podkategorie:" << std::endl;
//		for (int i = 1; i <= shopping::shopping_subcat.get_list_size(); i++)
//		{
//			std::cout << i << ". " << shopping::shopping_subcat.get_name(i-1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < shopping::shopping_subcat.get_list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n"
//					<< "Wybrano: " << shopping::shopping_subcat.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!shopping::shopping_subcat.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//					goBack = true;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (!goBack);
//}
//
//void interface_::health_change_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false, goBack = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n";
//		std::cout << "Podkategorie:" << std::endl;
//		for (int i = 1; i <= health::health_subcat.get_list_size(); i++)
//		{
//			std::cout << i << ". " << health::health_subcat.get_name(i - 1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < health::health_subcat.get_list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n"
//					<< "Wybrano: " << health::health_subcat.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!health::health_subcat.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//				goBack = true;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (!goBack);
//}
//
//void interface_::car_change_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false, goBack = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n";
//		std::cout << "Podkategorie:" << std::endl;
//		for (int i = 1; i <= car::car_subcat.get_list_size(); i++)
//		{
//			std::cout << i << ". " << car::car_subcat.get_name(i - 1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < car::car_subcat.get_list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n"
//					<< "Wybrano: " << car::car_subcat.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!car::car_subcat.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//				goBack = true;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (!goBack);
//}
//
//void interface_::bills_change_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false, goBack = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n";
//		std::cout << "Podkategorie:" << std::endl;
//		for (int i = 1; i <= bills::bills_subcat.get_list_size(); i++)
//		{
//			std::cout << i << ". " << bills::bills_subcat.get_name(i - 1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < bills::bills_subcat.get_list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n"
//					<< "Wybrano: " << bills::bills_subcat.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!bills::bills_subcat.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//				goBack = true;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (!goBack);
//}
//
//void interface_::other_change_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false, goBack = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n";
//		std::cout << "Podkategorie:" << std::endl;
//		for (int i = 1; i <= other::other_subcat.get_list_size(); i++)
//		{
//			std::cout << i << ". " << other::other_subcat.get_name(i - 1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < other::other_subcat.get_list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "EDYTUJ NAZWE PODKATEGORII\n\n"
//					<< "Wybrano: " << other::other_subcat.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!other::other_subcat.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//				goBack = true;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (!goBack);
//}
//
//void interface_::edit_expanse()
//{
//	int id, input;
//	do {
//		std::cout << "EDYTUJ WYDATEK\n\n"
//			<< "Podaj numer id wydatku: ";
//		std::cin >> id;
//		if (modify_expanse(id))
//			return;
//		else
//			std::cout << "Nie ma takiego wydatku." << std::endl << std::endl;
//		std::cout << "0. Powrot\n"
//			<< "1. Jeszcze raz\n\n";
//		std::cout << "Wybor: ";
//		std::cin >> input;
//		system("cls");
//	} while (input != 0);
//}
//
//bool interface_::modify_expanse(int id)
//{
//	char input;
//	int chosen;
//	bool isValid = true;
//	std::shared_ptr<expanse> ptr = data_base.get_expanse(id);
//	if (ptr == nullptr)
//		return false;
//	do
//	{
//		
//		system("cls");
//		std::cout << "EDYTUJ WYDATEK\n\n";
//		std::cout << "Wybrany wydatek" << std::endl;
//		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//		std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//		std::cout << ptr->get_all() << std::endl;
//		std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
//		std::cout << "Wybierz: \n"
//			<< "1. Zmien miejsce\n"
//			<< "2. Zmien uzytkownika\n"
//			<< "3. Zmien podkategorie\n"
//			<< "4. Zmien kwote\n"
//			<< "5. Zmien date\n";
//		std::cout << "\n0. Powrot\n\n";
//		std::cout << "Wybor:\n ";
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		system("cls");
//		switch (chosen)
//		{
//		case 0:
//			data_base.sort();
//			return true;
//			break;
//		case 1:
//			change_exp_pl(ptr);
//			break;
//		case 2:
//			change_exp_us(ptr);
//			break;
//		case 3:
//			change_exp_sub(ptr);
//			break;
//		case 4:
//			change_exp_amt(ptr);
//			break;
//		case 5:
//			change_exp_date(ptr);
//			break;
//		default:
//			break;
//		}
//	} while (1);
//}
//
//void interface_::change_exp_pl(std::shared_ptr<expanse>& ptr)
//{
//	char input;
//	int chosen, u_id, s_id, day, month, year;
//	double amt = ptr->get_amount();
//	bool isValid = true;
//	
//		u_id = ptr->get_userId();
//		s_id = ptr->get_subcatId();
//		day = ptr->get_day();
//		month = ptr->get_month();
//		year = ptr->get_year();
//	do{
//		std::cout << "EDYTUJ WYDATEK\n\n";
//		std::cout << "Wybierz miejsce:\n " << std::endl;
//		for (int i = 0; i < expanse::places.get_list_size(); i++)
//		{
//			std::cout << i << ". " << expanse::places.get_name(i) << std::endl;
//		}
//		std::cout << "Wybor: ";
//		std::cin >> input;
//		chosen = (int)input - 48;
//		if (chosen >= 0 && chosen < expanse::places.get_list_size())
//		{
//			ptr->set_all(u_id, chosen, s_id, amt, day, month, year);
//			isValid = true;
//		}
//		else
//			isValid = false;
//		system("cls");
//	} while (!isValid);
//}
//
//void interface_::change_exp_us(std::shared_ptr<expanse>& ptr)
//{
//	char input;
//	int chosen, s_id, p_id, day, month, year;
//	double amt = ptr->get_amount();
//	bool isValid = true;
//	
//		s_id = ptr->get_subcatId();
//		p_id = ptr->get_placeId();
//		day = ptr->get_day();
//		month = ptr->get_month();
//		year = ptr->get_year();
//	do
//	{
//		std::cout << "EDYTUJ WYDATEK\n\n";
//		std::cout << "Wybierz uzytkownika:\n" << std::endl;
//		for (int i = 0; i < expanse::users.list_size(); i++)
//		{
//			std::cout << i << ". " << expanse::users.get_name(i) << std::endl;
//		}
//		std::cout << "Wybor: ";
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen >= 0 && chosen < expanse::users.list_size())
//		{
//			ptr->set_all(chosen, p_id, s_id, amt, day, month, year);
//			isValid = true;
//		}
//		else
//			isValid = false;
//		system("cls");
//	} while (!isValid);
//}
//
//void interface_::change_exp_sub(std::shared_ptr<expanse>& ptr)
//{
//	char input;
//	int chosen, u_id, p_id, day, month, year;
//	double amt = ptr->get_amount();
//	bool isValid = true;
//
//	u_id = ptr->get_userId();
//	p_id = ptr->get_placeId();
//	day = ptr->get_day();
//	month = ptr->get_month();
//	year = ptr->get_year();
//	do
//	{
//		std::cout << "EDYTUJ WYDATEK\n\n";
//		std::cout << "Wybierz podkategorie:\n" << std::endl;
//		if (ptr->get_categoryName() == "Zakupy")
//		{
//			for (int i = 0; i < shopping::shopping_subcat.get_list_size(); i++)
//			{
//				std::cout << i << ". " << shopping::shopping_subcat.get_name(i) << std::endl;
//			}
//		}else if (ptr->get_categoryName() == "Rachunki")
//		{
//			for (int i = 0; i < bills::bills_subcat.get_list_size(); i++)
//			{
//				std::cout << i << ". " << bills::bills_subcat.get_name(i) << std::endl;
//			}
//		}else if (ptr->get_categoryName() == "Samochod")
//		{
//			for (int i = 0; i < car::car_subcat.get_list_size(); i++)
//			{
//				std::cout << i << ". " << car::car_subcat.get_name(i) << std::endl;
//			}
//		}else if (ptr->get_categoryName() == "Zdrowie")
//		{
//			for (int i = 0; i < health::health_subcat.get_list_size(); i++)
//			{
//				std::cout << i << ". " << health::health_subcat.get_name(i) << std::endl;
//			}
//		}
//		else
//		{
//			for (int i = 0; i < other::other_subcat.get_list_size(); i++)
//			{
//				std::cout << i << ". " << other::other_subcat.get_name(i) << std::endl;
//			}
//		}
//		std::cout << "Wybor: ";
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen >= 0 && chosen < expanse::users.list_size())
//		{
//			ptr->set_all(u_id, p_id, chosen, amt, day, month, year);
//			isValid = true;
//		}
//		else
//			isValid = false;
//
//		system("cls");
//	} while (!isValid);
//}
//
//void interface_::change_exp_date(std::shared_ptr<expanse>& ptr)
//{
//	int u_id, s_id, p_id, day, month, year;
//	double amt = ptr->get_amount();
//	bool isValid = true;
//
//	u_id = ptr->get_userId();
//	s_id = ptr->get_subcatId();
//	p_id = ptr->get_placeId();
//
//	do
//	{
//		std::cout << "EDYTUJ WYDATEK\n\n";
//		std::cout << "Wprowadz date:\n " << std::endl;
//		std::cout << "Dzien: ";
//		std::cin >> day;
//		std::cout << "Miesiac: ";
//		std::cin >> month;
//		std::cout << "Rok: ";
//		std::cin >> year;
//		if (day > 0 && day < 32 && month>0 && month < 13 && year>0)
//		{
//			ptr->set_all(u_id, p_id, s_id, amt, day, month, year);
//			isValid = true;
//		}
//		else
//			isValid = false;
//
//		system("cls");
//	} while (!isValid);
//}
//
//void interface_::change_exp_amt(std::shared_ptr<expanse>& ptr)
//{
//	int u_id, s_id, p_id, day, month, year;
//	double amt;
//	bool isValid = true;
//
//	u_id = ptr->get_userId();
//	s_id = ptr->get_subcatId();
//	p_id = ptr->get_placeId();
//	day = ptr->get_day();
//	month = ptr->get_month();
//	year = ptr->get_year();
//	do
//	{
//		std::cout << "EDYTUJ WYDATEK\n\n";
//		std::cout << "Wprowadz kwote: " << std::endl;
//
//		std::cin >> amt;
//
//		if (amt >= 0)
//		{
//			ptr->set_all(u_id, p_id, s_id, amt, day, month, year);
//			isValid = true;
//		}
//		else
//			isValid = false;
//
//		system("cls");
//	} while (!isValid);
//}
//
//void interface_::add_expanse()
//{
//	int u_id = expanse::users.get_active();
//	int s_id = 0, p_id = 0, day = 0, month = 0, year = 0, chosen;
//	double amt = 0;
//	char input;
//	std::string category, subcat = "-";
//	std::string model = "-";
//	bool isValid = true;
//	do {
//		do
//		{
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Wybierz kategorie: \n"
//				<< "1. Zakupy\n"
//				<< "2. Zdrowie\n"
//				<< "3. Samochod\n"
//				<< "4. Rachunki\n"
//				<< "5. Inne\n\n"
//				<< "0. Powrot\n\n";
//			std::cout << "Wybor: ";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			switch (chosen)
//			{
//			case 0:
//				return;
//				break;
//			case 1:
//				category = "Zakupy";
//				isValid = true;
//				break;
//			case 2:
//				category = "Zdrowie";
//				isValid = true;
//				break;
//			case 3:
//				category = "Samochod";
//				isValid = true;
//				break;
//			case 4:
//				category = "Rachunki";
//				isValid = true;
//				break;
//			case 5:
//				category = "Inne";
//				isValid = true;
//				break;
//			default:
//				isValid = false;
//				break;
//			}
//			system("cls");
//		} while (!isValid);
//
//		do
//		{
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Nowy wydatek:" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "-" << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << "-" << std::setw(10) << expanse::users.get_name(u_id) << std::setw(13) << expanse::places.get_name(s_id) << std::setw(13) << "-,-,-" << std::setw(20) << model << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "Wybierz podkategorie:\n" << std::endl;
//
//			int size;
//
//			if (category == "Zakupy")
//			{
//				size = shopping::shopping_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << shopping::shopping_subcat.get_name(i) << std::endl;
//				}
//
//			}
//			else if (category == "Rachunki")
//			{
//				size = bills::bills_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << bills::bills_subcat.get_name(i) << std::endl;
//				}
//
//			}
//			else if (category == "Samochod")
//			{
//				size = car::car_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << car::car_subcat.get_name(i) << std::endl;
//				}
//
//			}
//			else if (category == "Zdrowie")
//			{
//				size = health::health_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << health::health_subcat.get_name(i) << std::endl;
//				}
//			}
//			else
//			{
//				size = other::other_subcat.get_list_size();
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << other::other_subcat.get_name(i) << std::endl;
//				}
//			}
//			std::cout << "Wybor: ";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			if (chosen >= 0 && chosen < size)
//			{
//				s_id = chosen;
//				isValid = true;
//			}
//			else
//			{
//				isValid = false;
//			}
//			system("cls");
//		} while (!isValid);
//
//		if (category == "Zakupy")
//		{
//			subcat = shopping::shopping_subcat.get_name(s_id);
//		}
//		else if (category == "Rachunki")
//		{
//			subcat = bills::bills_subcat.get_name(s_id);
//		}
//		else if (category == "Samochod")
//		{
//			subcat = car::car_subcat.get_name(s_id);
//		}
//		else if (category == "Zdrowie")
//		{
//			subcat = health::health_subcat.get_name(s_id);
//		}
//		else
//		{
//			subcat = other::other_subcat.get_name(s_id);
//		}
//
//		do
//		{
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Nowy wydatek:" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "-" << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << "-" << std::setw(10) << expanse::users.get_name(u_id) << std::setw(12) << expanse::places.get_name(p_id) << std::setw(13) << "-,-,-" << std::setw(20) << model << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "Wybierz miejsce: \n";
//			for (int i = 0; i < expanse::places.get_list_size(); i++)
//			{
//				std::cout << i << ". " << expanse::places.get_name(i) << std::endl;
//			}
//			std::cout << "\nWybor: ";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			if (chosen >= 0 && chosen < expanse::places.get_list_size())
//			{
//				p_id = chosen;
//				isValid = true;
//			}
//			else
//			{
//				isValid = false;
//			}
//			system("cls");
//		} while (!isValid);
//
//		do
//		{
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Nowy wydatek:" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "-" << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << "-" << std::setw(10) << expanse::users.get_name(u_id) << std::setw(12) << expanse::places.get_name(p_id) << std::setw(13) << "-,-,-" << std::setw(20) << model << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "Wprowadz kwote: ";
//			std::cin >> amt;
//			if (amt > 0)
//				isValid = true;
//			else
//				isValid = false;
//			system("cls");
//		} while (!isValid);
//
//		do
//		{
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Nowy wydatek:" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "-" << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << amt << std::setw(10) << expanse::users.get_name(u_id) << std::setw(12) << expanse::places.get_name(p_id) << std::setw(13) << "-,-,-" << std::setw(20) << model << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "Wprowadz date: \n";
//			std::cout << "Dzien: ";
//			std::cin >> day;
//			std::cout << "Miesiac: ";
//			std::cin >> month;
//			std::cout << "Rok: ";
//			std::cin >> year;
//
//			if (day > 0 && day < 32 && month>0 && month < 13 && year>0)
//				isValid = true;
//			else
//				isValid = false;
//			system("cls");
//		} while (!isValid);
//
//
//		if (category == "Samochod")
//		{
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Wprowadz nazwe samochodu: \n";
//			std::cout << "Nowy wydatek:" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "-" << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << amt << std::setw(10) << expanse::users.get_name(u_id) << std::setw(13) << expanse::places.get_name(p_id) << std::setw(13) << day << ',' << month << "," << year << std::setw(20) << model << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "\nSamochod: ";
//			std::cin >> model;
//			//data_base.add_car(u_id, p_id, s_id, amt, day, month, year, model);
//		}
//		/*else
//		{
//			data_base.add(category, u_id, p_id, s_id, amt, day, month, year);
//		}*/
//		do
//		{
//			system("cls");
//			std::cout << "DODAJ WYDATEK\n\n";
//			std::cout << "Nowy wydatek:" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "Id" << std::setw(10) << "Kat." << std::setw(18) << "Podkat." << "  " << std::setw(6) << "Kwota" << std::setw(10) << "Uzytk." << std::setw(12) << "Miejsce" << std::setw(13) << "Data" << std::setw(20) << "Samochod" << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << std::setw(4) << "-" << std::setw(10) << category << std::setw(18) << subcat << std::setw(6) << amt << std::setw(10) << expanse::users.get_name(u_id) << std::setw(13) << expanse::places.get_name(p_id) << std::setw(13) << day << ',' << month << "," << year << std::setw(20) << model << std::endl;
//			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
//			std::cout << "1. Dodaj\n"
//				<< "2. Dodaj i wprowadz kolejny\n"
//				<< "3. Wprowadz dane jeszcze raz\n"
//				<< "4. Odrzuc\n";
//			std::cout << "\nWybor: ";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			if(chosen>0&&chosen<5)
//			switch (chosen)
//			{case 1:
//				if (category == "Samochod")
//					data_base.add_car(u_id, p_id, s_id, amt, day, month, year, model);
//				else
//					data_base.add(category, u_id, p_id, s_id, amt, day, month, year);
//				data_base.sort();
//				return;
//				break;
//			case 2:
//				if (category == "Samochod")
//					data_base.add_car(u_id, p_id, s_id, amt, day, month, year, model);
//				else
//					data_base.add(category, u_id, p_id, s_id, amt, day, month, year);
//				data_base.sort();
//				break;
//			case 3:
//				break;
//			case 4:
//				return;
//				break;
//			default:
//				isValid = false;
//				break;
//			}
//		} while (!isValid);
//		system("cls");
//	}while (true);
//}
//
//void interface_::add_place()
//{
//	int chosen;
//	char input;
//	bool isValid = true;
//	std::string new_place = "";
//	do
//	{
//		do
//		{
//			std::cout << "DODAJ MIEJSCE\n\n";
//			std::cout << "Zapisane miejsca: \n";
//			for (int i = 0; i < expanse::places.get_list_size(); i++)
//			{
//				std::cout << i + 1 << ". " << expanse::places.get_name(i) << std::endl;
//			}
//			std::cout << "\n1. Dodaj nowe miejsce" << std::endl;
//			std::cout << "0. Powrot" << std::endl;
//			std::cout << "Wybor: ";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			if (chosen == 1 || chosen == 0)
//				isValid = true;
//			else
//				isValid = false;
//			system("cls");
//		} while (!isValid);
//
//	if (chosen == 0)
//		return;
//
//		do
//		{
//			std::cout << "DODAJ MIEJSCE\n\n";
//			std::cout << "Zapisane miejsca: \n";
//			for (int i = 0; i < expanse::places.get_list_size(); i++)
//			{
//				std::cout << i + 1 << ". " << expanse::places.get_name(i) << std::endl;
//			}
//			if (isValid)
//				std::cout << "\nNowe miejsce: ";
//			else
//				std::cout << "Pozycja " << new_place << " juz istnieje. Podaj inna nazwe: ";
//			std::cin >> new_place;
//			if (expanse::places.add(new_place))
//				isValid = true;
//			else
//				isValid = false;
//
//			system("cls");
//		} while (!isValid);
//
//	} while (true);
//}
//
//void interface_::add_subcat()
//{
//	int chosen, cat;
//	char input;
//	bool isValid = true, again = true;
//	std::string new_sub;
//	do
//	{
//		do
//		{
//			do
//			{
//				std::cout << "DODAJ PODKATEGORIE\n\n";
//				std::cout << "Wybierz kategoriê do której chcesz dodaæ podkategorie:\n"
//					<< "1. Zakupy\n"
//					<< "2. Rachunki\n"
//					<< "3. Samochod\n"
//					<< "4. Zdrowie\n"
//					<< "5. Inne\n\n"
//					<< "0. Powrot\n\n";
//				std::cout << "Wybor: ";
//				std::cin >> input;
//				chosen = (int)input - 48;
//				if (chosen > 0 && chosen < 6)
//				{
//					cat = chosen;
//					isValid = true;
//				}
//				else if (chosen == 0)
//					return;
//				else
//					isValid = false;
//				system("cls");
//			} while (!isValid);
//
//			do
//			{
//				std::cout << "DODAJ PODKATEGORIE\n\n";
//				std::cout << "Zapisane podkategorie: \n";
//				if (cat == 1)
//				{
//					int size = shopping::shopping_subcat.get_list_size();
//
//					for (int i = 0; i < size; i++)
//					{
//						std::cout << i << ". " << shopping::shopping_subcat.get_name(i) << std::endl;
//					}
//
//				}
//				else if (cat == 2)
//				{
//					int size = bills::bills_subcat.get_list_size();
//
//					for (int i = 0; i < size; i++)
//					{
//						std::cout << i << ". " << bills::bills_subcat.get_name(i) << std::endl;
//					}
//
//				}
//				else if (cat == 3)
//				{
//					int size = car::car_subcat.get_list_size();
//
//					for (int i = 0; i < size; i++)
//					{
//						std::cout << i << ". " << car::car_subcat.get_name(i) << std::endl;
//					}
//
//				}
//				else if (cat == 4)
//				{
//					int size = health::health_subcat.get_list_size();
//
//					for (int i = 0; i < size; i++)
//					{
//						std::cout << i << ". " << health::health_subcat.get_name(i) << std::endl;
//					}
//				}
//				else
//				{
//					int size = other::other_subcat.get_list_size();
//					for (int i = 0; i < size; i++)
//					{
//						std::cout << i << ". " << other::other_subcat.get_name(i) << std::endl;
//					}
//				}
//				std::cout << "\n1. Dodaj nowa podkategorie\n"
//					<< "0. Powrot\n\n";
//				std::cout << "Wybor: ";
//				std::cin >> input;
//				chosen = (int)input - 48;
//				if (chosen == 0)
//				{
//					again = true;
//					isValid = true;
//				}
//				else if (chosen == 1)
//				{
//					again = false;
//					isValid = true;
//				}
//				else
//				{
//					isValid = false;
//				}
//			} while (!isValid);
//			system("cls");
//		} while (again);
//		do
//		{
//			std::cout << "DODAJ PODKATEGORIE\n\n";
//			std::cout << "Zapisane podkategorie: \n";
//			if (cat == 1)
//			{
//				int size = shopping::shopping_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << shopping::shopping_subcat.get_name(i) << std::endl;
//				}
//
//			}
//			else if (cat == 2)
//			{
//				int size = bills::bills_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << bills::bills_subcat.get_name(i) << std::endl;
//				}
//
//			}
//			else if (cat == 3)
//			{
//				int size = car::car_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << car::car_subcat.get_name(i) << std::endl;
//				}
//
//			}
//			else if (cat == 4)
//			{
//				int size = health::health_subcat.get_list_size();
//
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << health::health_subcat.get_name(i) << std::endl;
//				}
//			}
//			else
//			{
//				int size = other::other_subcat.get_list_size();
//				for (int i = 0; i < size; i++)
//				{
//					std::cout << i << ". " << other::other_subcat.get_name(i) << std::endl;
//				}
//			}
//			if (isValid)
//				std::cout << "\nPodaj now¹ podkategorie: ";
//			else
//				std::cout << "\nRekord " << new_sub << " juz istnieje. Podaj inna nazwe: ";
//			std::cin >> new_sub;
//			if (cat == 1)
//			{
//				if (shopping::shopping_subcat.add(new_sub))
//					isValid = true;
//				else
//					isValid = false;
//			}
//			else if (cat == 2)
//			{
//				if (bills::bills_subcat.add(new_sub))
//					isValid = true;
//			}
//			else if (cat == 3)
//			{
//				if (car::car_subcat.add(new_sub))
//					isValid = true;
//				else
//					isValid = false;
//			}
//			else if (cat == 4)
//			{
//				if (health::health_subcat.add(new_sub))
//					isValid = true;
//				else
//					isValid = false;
//			}
//			else
//			{
//				if (other::other_subcat.add(new_sub))
//					isValid = true;
//				else
//					isValid = false;
//			}
//			system("cls");
//		} while (!isValid);
//	}while (true);
//}
//
//void interface_::users()
//{
//	char input;
//	int chosen;
//	do
//	{
//		std::cout << "UZYTKOWNICY\n\n";
//		std::cout << "1. Dodaj uzytkownika\n"
//			<< "2. Zmien uzytkownika\n"
//			<< "3. Edytuj nazwe uzytkownka\n\n"
//			<< "0. Powrot do menu\n\n"
//			<< "Wybor: ";
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		system("cls");
//		switch (chosen)
//		{
//		case 1:
//			add_user();
//			break;
//		case 2:
//			switch_user();
//			break;
//		case 3:
//			change_user_name();
//			break;
//		case 0:
//			return;
//			break;
//		default:
//			break;
//		}
//		system("cls");
//	} while (true);
//}
//
//void interface_::add_user()
//{
//
//	int chosen;
//	char input;
//	bool isValid = true;
//	std::string new_user = "";
//	do
//	{
//		do
//		{
//			std::cout << "DODAJ UZYTKOWNIKA\n\n";
//			std::cout << "Uzytkownicy: \n";
//			for (int i = 0; i < expanse::users.list_size(); i++)
//			{
//				std::cout << i + 1 << ". " << expanse::users.get_name(i) << std::endl;
//			}
//			std::cout << "\n1. Dodaj nowego uzytkownika" << std::endl;
//			std::cout << "0. Powrot" << std::endl;
//			std::cout << "Wybor: ";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			if (chosen == 1 || chosen == 0)
//				isValid = true;
//			else
//				isValid = false;
//			system("cls");
//		} while (!isValid);
//
//		if (chosen == 0)
//			return;
//
//		do
//		{
//			std::cout << "DODAJ UZYTKOWNIKA\n\n";
//			std::cout << "Uzytkownicy: \n";
//			for (int i = 0; i < expanse::places.get_list_size(); i++)
//			{
//				std::cout << i + 1 << ". " << expanse::places.get_name(i) << std::endl;
//			}
//			if (isValid)
//				std::cout << "\nNowy uzytkownik: ";
//			else
//				std::cout << "Uzytkownik " << new_user << " juz istnieje. Podaj inna nazwe: ";
//			std::cin >> new_user;
//			if (expanse::users.add(new_user))
//				isValid = true;
//			else
//				isValid = false;
//
//			system("cls");
//		} while (!isValid);
//
//	} while (true);
//}
//
//void interface_::switch_user()
//{
//	char input;
//	int chosen;
//	bool active = false;
//	do
//	{
//		int active_id = expanse::users.get_active();
//		std::cout << "ZMIEN UZYTKOWNIKA\n\n";
//
//		for (int i = 0; i < expanse::users.list_size(); i++)
//		{
//			if (i != active_id)
//				std::cout << i + 1 << ". " << expanse::users.get_name(i) << std::endl;
//			else
//				std::cout << ">> " << expanse::users.get_name(i) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n\n";
//		if (!active)
//			std::cout << "Wybierz uzytkownika: ";
//		else
//			std::cout << "Uzytkownik jest juz aktywny. Wybierz innego uzytkownika: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//		if (chosen == active_id)
//			active = true;
//		else if (chosen > 0 && chosen <= expanse::users.list_size())
//		{
//			expanse::users.change_status(active_id, 0);
//			expanse::users.change_status(chosen - 1, 1);
//		}
//		else if (chosen == 0)
//			return;
//		system("cls");
//	} while (true);
//}
//
//void interface_::change_user_name()
//{
//	char input;
//	int chosen;
//	bool isValid = true, error = false;
//	std::string new_name;
//	do
//	{
//		std::cout << "ZMIEN NAZWE UZYTKOWNIKA\n\n";
//		std::cout << "Uzytkownicy:" << std::endl;
//		for (int i = 1; i <= expanse::users.list_size(); i++)
//		{
//			std::cout << i << ". " << expanse::users.get_name(i-1) << std::endl;
//		}
//		std::cout << "\n0. Powrot\n";
//		std::cout << "\nWybor: ";
//
//		std::cin >> input;
//		chosen = (int)input - 48;
//
//		if (chosen == 0)
//			return;
//
//		chosen--;
//
//		if (chosen >= 0 && chosen < expanse::users.list_size())
//		{
//			do
//			{
//				system("cls");
//				std::cout << "ZMIEN NAZWE UZYTKOWNIKA\n\n"
//					<< "Wybrano: " << expanse::users.get_name(chosen) << std::endl;
//				if (!error)
//					std::cout << "\nPodaj nowa nazwe: ";
//				else
//					std::cout << "\nPodana nazwa jest juz uzywana. Podaj inna nazwe: ";
//				std::cin >> new_name;
//				if (!expanse::users.change_name(chosen, new_name))
//					error = true;
//				else
//					error = false;
//
//			} while (error);
//		}
//		else
//			isValid = false;
//
//	} while (true); 
//}
//
//void interface_::limit()
//{
//	char input;
//	int chosen;
//	bool isValid = true;
//	
//	do
//	{
//		if (set_limit.get_status())
//		{
//			do
//			{
//				std::cout << "LIMIT\n\n"
//					<< "Status: ";
//				std::cout << "aktywny\n";
//
//				set_limit.check_dates();
//				set_limit.calculate_spend(data_base);
//
//				std::cout << "-------------------------------------------------------------" << std::endl;
//				std::cout << std::setw(12) << "Od" << std::setw(12) << "Do" << std::setw(10) << "Limit" << std::setw(10) << "Wydano" << std::setw(10) << "Do wydania" << std::endl;
//				std::cout << "-------------------------------------------------------------" << std::endl;
//				std::cout << std::setw(12) << set_limit.get_start() << std::setw(12) << set_limit.get_end() << std::setw(10) << set_limit.get_limit() << std::setw(10) << set_limit.get_spend() << std::setw(10) << set_limit.get_difference() << std::endl;
//				std::cout << "-------------------------------------------------------------" << std::endl;
//				std::cout << "1. Wylacz limit\n"
//					<< "0. Powrot do menu\n\n";
//				std::cout << "Wybor: ";
//				std::cin >> input;
//				chosen = (int)input - 48;
//				if (chosen == 0)
//					return;
//				else if (chosen == 1)
//				{
//					isValid = true;
//					set_limit.turn_off();
//				}
//				else
//					isValid = false;
//				system("cls");
//			} while (!isValid);
//		}
//		else
//		{
//			do {
//				std::cout << "LIMIT\n\n"
//					<< "Status: ";
//				std::cout << "nieaktywny\n\n"
//					<< "1. Ustaw limit\n"
//					<< "0. Powrot\n\n";
//				std::cout << "Wybor: ";
//				std::cin >> input;
//				chosen = (int)input - 48;
//				if (chosen == 0)
//					return;
//				else if (chosen == 1)
//				{
//					isValid = true;
//					system("cls");
//					set_up_limit();
//				}
//				else
//					isValid = false;
//				system("cls");
//			} while (!isValid);
//		}
//	} while (true);
//}
//
//void interface_::set_up_limit()
//{
//	char input;
//	int d, m, y, chosen;
//	double limit;
//	bool isValid = true;
//
//	struct tm current_time;
//	time_t now = time(0);
//	localtime_s(&current_time, &now);
//
//	int day = current_time.tm_mday;
//	int month = current_time.tm_mon + 1;
//	int year = current_time.tm_year + 1900;
//	date current_date(day, month, year);
//
//	do
//	{
//		system("cls");
//		do
//		{
//			std::cout << "USTAW LIMIT\n\n"
//				<< "Podaj date poczatkowa limitu: \n"
//				<< "Dzien: ";
//			std::cin >> d;
//
//			system("cls");
//			std::cout << "USTAW LIMIT\n\n"
//				<< "Podaj date poczatkowa limitu: \n"
//				<< "Dzien: " << d << std::endl
//				<< "Miesiac: ";
//			std::cin >> m;
//
//			system("cls");
//			std::cout << "USTAW LIMIT\n\n"
//				<< "Podaj date poczatkowa limitu: \n"
//				<< "Dzien: " << d << std::endl
//				<< "Miesiac: " << m << std::endl
//				<< "Rok: ";
//			std::cin >> y;
//
//			date start(d, m, y);
//			if (start + 30 < current_date)
//				isValid = false;
//			else
//				isValid = true;
//
//		} while (!isValid);
//
//		do
//		{
//			system("cls");
//			std::cout << "USTAW LIMIT\n\n"
//				<< "Data poczatkowa: " << d << "," << m << "," << y << "r." << std::endl;
//			std::cout << "Podaj limit: ";
//			std::cin >> limit;
//			if (limit < 0)
//				isValid = false;
//			else
//				isValid = true;
//		} while (!isValid);
//
//		do
//		{
//			system("cls");
//			std::cout << "USTAW LIMIT\n\n"
//				<< "Data poczatkowa: " << d << "," << m << "," << y << "r." << std::endl;
//			std::cout << "Podaj limit: " << limit << " zl\n\n"
//				<< "1. Wprowadz dane jeszcze raz\n"
//				<< "0. Zakoñcz";
//			std::cin >> input;
//			chosen = (int)input - 48;
//			if (chosen == 0)
//			{
//
//				set_limit.turn_on();
//				set_limit.set_start(d, m, y);
//				set_limit.set_limit(limit);
//				return;
//			}
//			else if (chosen == 1)
//				isValid = true;
//			else
//				isValid = false;
//
//		} while (!isValid);
//
//	} while (true);
//}