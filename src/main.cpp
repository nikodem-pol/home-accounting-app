#include <iostream>
#include "date.h"
#include "expanse.h"
#include "info_list.h"
#include "shopping.h"
#include "users_list.h"
#include "bills.h"
#include "health.h"
#include "other.h"
#include "car.h"
#include "interface.h"
#include "expanses_list.h"

int expanse::nr = 0;

info_list expanse::places("Miejsca.txt");
users_list expanse::users("Uzytkownicy.txt");

info_list shopping::shopping_subcat("Shop_subcat.txt");
info_list health::health_subcat("Heal_subcat.txt");
info_list bills::bills_subcat("Bill_subcat.txt");
info_list car::car_subcat("Car_subcat.txt");
info_list other::other_subcat("Other_subcat.txt");

int main()
{

	expanse::places.load_list();
	expanse::users.load_list();

	shopping::shopping_subcat.load_list();
	health::health_subcat.load_list();
	bills::bills_subcat.load_list();
	car::car_subcat.load_list();
	other::other_subcat.load_list();

	interface_ program("Wydatki.txt", "Limit.txt");
	
	
	
	program.menu();
}
