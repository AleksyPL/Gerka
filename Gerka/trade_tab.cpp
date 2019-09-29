#include "trade_tab.h"

table::table()
{
	strona_1 = 0;
	strona_2 = 0;
	counter_selected_to_buy_usage = 0;
	counter_selected_to_buy_alchemy = 0;
	counter_selected_to_buy_forge = 0;
	licznik = 0;
	licznik1 = 0;
	licznik3 = 0;
	licznik4 = 0;
	info[0] = "";
	info[1] = "";
	info[2] = "W: ZAKOÑCZ HANDEL";
	info[3] = "Z: ZAAKCEPTUJ";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	for (int i = 0; i < 80; i++)
	{
		temp_table[i] = "";
		temp_table_amount[i] = 0;
		temp_table_price[i] = 0;
	}
}
void table::load_merch_trader(seller &handlarz, player &gracz)
{
	handlarz.load_merch();
	handlarz.add_prices(gracz);
	for (int i = 0; i < 20; i++)
	{
		temp_table_price[20 + i] = 0;
		temp_table_price[60 + i] = 0;
		temp_table[20 + i] = handlarz.menu_items[i];
		temp_table_price[20 + i] = handlarz.menu_price[i];
		temp_table[60 + i] = gracz.inventory_usage[i];
		temp_table_price[60 + i] = gracz.inventory_usage_price[i];
		temp_table_amount[60 + i] = gracz.inventory_usage_amount[i];
	}
}
void table::switch_page_next(player gracz, seller handlarz, string wyb)
{
	if (wyb[1] == '1')
	{
		if (strona_1 == 0)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[20 + i] = handlarz.menu_items[20 + i];
				temp_table_price[20 + i] = handlarz.menu_price[20 + i];
			}
			strona_1 = 1;
		}
		else if (strona_1 == 1 && gracz.level > 10)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[20 + i] = handlarz.menu_items[40 + i];
				temp_table_price[20 + i] = handlarz.menu_price[40 + i];
			}
			strona_1 = 2;
		}
		else if (strona_1 == 2 && gracz.level > 20)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[20 + i] = handlarz.menu_items[60 + i];
				temp_table_price[20 + i] = handlarz.menu_price[60 + i];
			}
			strona_1 = 3;
		}
	}
	if (wyb[1] == '2')
	{
		if (strona_2 == 0)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[60 + i] = gracz.inventory_crafting[i];
				temp_table_price[60 + i] = gracz.inventory_crafting_price[i];
				temp_table_amount[60 + i] = gracz.inventory_crafting_amount[i];
			}
			strona_2 = 1;
		}
		else if (strona_2 == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[60 + i] = gracz.inventory_crafting[20 + i];
				temp_table_price[60 + i] = gracz.inventory_crafting_price[20 + i];
				temp_table_amount[60 + i] = gracz.inventory_crafting_amount[20 + i];
			}
			strona_2 = 2;
		}
	}
}
void table::switch_page_previous(player gracz, seller handlarz, string wyb)
{
	//0 - no_level_req
	//1 - no_level_req
	//2 - 10 level
	//3 - 20 level
	if (wyb[1] == '1')
	{
		if (strona_1 == 3 && gracz.level > 20)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[20 + i] = handlarz.menu_items[40 + i];
				temp_table_price[20 + i] = handlarz.menu_price[40 + i];
			}
			strona_1 = 2;
		}
		else if (strona_1 == 2 && gracz.level > 10)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[20 + i] = handlarz.menu_items[20 + i];
				temp_table_price[20 + i] = handlarz.menu_price[20 + i];
			}
			strona_1 = 1;
		}
		else if (strona_1 == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[20 + i] = handlarz.menu_items[i];
				temp_table_price[20 + i] = handlarz.menu_price[i];
			}
			strona_1 = 0;
		}
	}
	if (wyb[1] == '2')
	{
		if (strona_2 == 2)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[60 + i] = gracz.inventory_crafting[i];
				temp_table_price[60 + i] = gracz.inventory_crafting_price[i];
				temp_table_amount[60 + i] = gracz.inventory_crafting_amount[i];
			}
			strona_2 = 1;
		}
		else if (strona_2 == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				temp_table[60 + i] = gracz.inventory_usage[i];
				temp_table_price[60 + i] = gracz.inventory_usage_price[i];
				temp_table_amount[60 + i] = gracz.inventory_usage_amount[i];
			}
			strona_2 = 0;
		}
	}
}
void table::check_free_fields()
{
	for (int i = 0; i < 20; i++)
	{
		//wybrane itemy do transakcji
		if (temp_table[i] == "" && temp_table_amount[i] == 0 && temp_table_price[i] == 0)
		{
			licznik++;
		}
		if (temp_table[40 + i] == "" && temp_table_amount[40 + i] == 0 && temp_table_price[40 + i] == 0)
		{
			licznik1++;
		}
		if (licznik == 20)
		{
			temp_table[0] = "BRAK WYBRANYCH PRZEDMIOTÓW";
		}
		if (licznik1 == 20)
		{
			temp_table[40] = "BRAK WYBRANYCH PRZEDMIOTÓW";
		}
		//reszta itemów z plecaka
		if (temp_table[20 + i] == "" && temp_table_amount[20 + i] == 0)
		{
			temp_table_price[20 + i] = 0;
			licznik3++;
		}
		if (temp_table[60 + i] == "" && temp_table_amount[60 + i] == 0)
		{
			temp_table_price[60 + i] = 0;
			licznik4++;
		}
		if (licznik3 == 20)
		{
			temp_table[20] = "HANDLARZ NIC NIE SPRZEDAJE";
		}
		if (licznik4 == 20 && strona_2 == 0)
		{
			temp_table[60] = "PLECAK JEST PUSTY";
		}
		else if (licznik4 == 20 && strona_2 == 1)
		{
			temp_table[60] = "BRAK SK£ADNIKÓW DO ALCHEMII";
		}
		else if (licznik4 == 20 && strona_2 == 2)
		{
			temp_table[60] = "BRAK SK£ADNIKÓW DO KOWALSTWA";
		}
	}
	licznik = 0;
	licznik1 = 0;
	licznik3 = 0;
	licznik4 = 0;
}
void table::check_info_boxes()
{
	if (strona_1 == 0)
	{
		info[0] = "";
		info[1] = "N1: NASTÊPNA STR";
	}
	else if (strona_1 == 3)
	{
		info[0] = "P1: POPRZEDNIA STR";
		info[1] = "";
	}
	else
	{
		info[0] = "P1: POPRZEDNIA STR";
		info[1] = "N1: NASTÊPNA STR";
	}
	if (strona_2 == 0)
	{
		info[5] = "";
		info[6] = "N2: NASTÊPNA STR";
	}
	else if (strona_2 == 2)
	{
		info[5] = "P2: POPRZEDNIA STR";
		info[6] = "";
	}
	else
	{
		info[5] = "P2: POPRZEDNIA STR";
		info[6] = "N2: NASTÊPNA STR";
	}
}
void table::sort_player_field()
{
	for (int i = 0; i < 20; i++)
	{
		if (temp_table[60 + i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (temp_table[60 + j] != "")
				{
					temp_table[60 + i] = temp_table[60 + j];
					temp_table_amount[60 + i] = temp_table_amount[60 + j];
					temp_table_price[60 + i] = temp_table_price[60 + j];
					temp_table[60 + j] = "";
					temp_table_amount[60 + j] = 0;
					temp_table_price[60 + j] = 0;
					break;
				}
			}
		}
	}
}
void table::select_item_to_buy(int numer, player gracz, seller handlarz)
{
	numer = numer - 1;
	if (can_be_selected(gracz, handlarz, temp_table[numer]) == 1)
	{
		for (int i = 0; i < 20; i++)
		{
			if (temp_table[i] == temp_table[numer])
			{
				temp_table_amount[i]++;
				temp_table_price[i] = temp_table_price[numer];
				break;
			}
			else if (temp_table[i] == "BRAK WYBRANYCH PRZEDMIOTÓW")
			{
				temp_table[i] = temp_table[numer];
				temp_table_price[i] = temp_table_price[numer];
				temp_table_amount[i]++;
				break;
			}
			else if (temp_table[i] == "")
			{
				temp_table[i] = temp_table[numer];
				temp_table_price[i] = temp_table_price[numer];
				temp_table_amount[i]++;
				break;
			}
		}
	}
	else
	{
		sound_rejection();
		cout << "Nie mo¿esz wybraæ tego przedmiotu, nie zmieœcisz go do plecaka" << endl;
		system("PAUSE");
	}
}
void table::select_item_to_sell(int numer)
{
	numer = numer - 1;
	for (int i = 0; i < 20; i++)
	{
		if (temp_table[40 + i] == temp_table[numer])
		{
			temp_table_amount[40 + i]++;
			temp_table_price[40 + i] = temp_table_price[numer];
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				if (strona_2 == 0)
				{
					sort_player_field();
				}
				else if (strona_2 == 1)
				{
					sort_player_field();
				}
			}
			break;
		}
		else if (temp_table[40 + i] == "BRAK WYBRANYCH PRZEDMIOTÓW")
		{
			temp_table[40 + i] = temp_table[numer];
			temp_table_price[40 + i] = temp_table_price[numer];
			temp_table_amount[40 + i]++;
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				if (strona_2 == 0)
				{
					sort_player_field();
				}
				else if (strona_2 == 1)
				{
					sort_player_field();
				}
			}
			break;
		}
		else if (temp_table[40 + i] == "")
		{
			temp_table[40 + i] = temp_table[numer];
			temp_table_price[40 + i] = temp_table_price[numer];
			temp_table_amount[40 + i]++;
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				if (strona_2 == 0)
				{
					sort_player_field();
				}
				else if (strona_2 == 1)
				{
					sort_player_field();
				}
			}
			break;
		}
	}
}
void table::sort_buying_field()
{
	for (int i = 0; i < 20; i++)
	{
		if (temp_table[i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (temp_table[j] != "")
				{
					temp_table[i] = temp_table[j];
					temp_table_amount[i] = temp_table_amount[j];
					temp_table_price[i] = temp_table_price[j];
					temp_table[j] = "";
					temp_table_amount[j] = 0;
					temp_table_price[j] = 0;
					break;
				}
			}
		}
	}
}
void table::delete_from_selected_to_buy(int numer)
{
	numer = numer - 1;
	if (temp_table[0] != "BRAK WYBRANYCH PRZEDMIOTÓW")
	{
		if (temp_table[numer] != "" && temp_table_amount[numer] != 0)
		{
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				temp_table_price[numer] = 0;
			}
			sort_buying_field();
		}
	}
}
void table::delete_from_selected_to_sell(int numer, player gracz, seller handlarz)
{
	numer = numer - 1;
	if (temp_table[40] != "BRAK WYBRANYCH PRZEDMIOTÓW")
	{
		if (handlarz.search_on_lists(temp_table[numer]) == 0 && strona_2 == 0)
		{
			for (int i = 0; i < 20; i++)
			{
				if (temp_table[60 + i] == temp_table[numer])
				{
					temp_table_amount[60 + i] = temp_table_amount[60 + i] + temp_table_amount[numer];
					temp_table[numer] = "";
					temp_table_amount[numer] = 0;
					temp_table_price[numer] = 0;
				}
				else if (temp_table[60 + i] == "")
				{
					temp_table[60 + i] = temp_table[numer];
					temp_table_price[60 + i] = temp_table_price[numer];
					temp_table_amount[60 + i] = temp_table_amount[numer];
					temp_table[numer] = "";
					temp_table_amount[numer] = 0;
					temp_table_price[numer] = 0;
				}
			}
		}
		else if(handlarz.search_on_lists(temp_table[numer]) == 0 && strona_2 != 0)
		{
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				temp_table_price[numer] = 0;
			}
		}
		if (handlarz.search_on_lists(temp_table[numer]) == 1 && strona_2 == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				if (temp_table[60 + i] == temp_table[numer])
				{
					temp_table_amount[60 + i] = temp_table_amount[60 + i] + temp_table_amount[numer];
					temp_table[numer] = "";
					temp_table_amount[numer] = 0;
					temp_table_price[numer] = 0;
				}
				else if (temp_table[60 + i] == "")
				{
					temp_table[60 + i] = temp_table[numer];
					temp_table_price[60 + i] = temp_table_price[numer];
					temp_table_amount[60 + i] = temp_table_amount[numer];
					temp_table[numer] = "";
					temp_table_amount[numer] = 0;
					temp_table_price[numer] = 0;
				}
			}
		}
		else if (handlarz.search_on_lists(temp_table[numer]) == 1 && strona_2 != 1)
		{
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				temp_table_price[numer] = 0;
			}
		}
		if (handlarz.search_on_lists(temp_table[numer]) == 2 && strona_2 == 2)
		{
			for (int i = 0; i < 20; i++)
			{
				if (temp_table[60 + i] == temp_table[numer])
				{
					temp_table_amount[60 + i] = temp_table_amount[60 + i] + temp_table_amount[numer];
					temp_table[numer] = "";
					temp_table_amount[numer] = 0;
					temp_table_price[numer] = 0;
				}
				else if (temp_table[60 + i] == "")
				{
					temp_table[60 + i] = temp_table[numer];
					temp_table_price[60 + i] = temp_table_price[numer];
					temp_table_amount[60 + i] = temp_table_amount[numer];
					temp_table[numer] = "";
					temp_table_amount[numer] = 0;
					temp_table_price[numer] = 0;
				}
			}
		}
		else if (handlarz.search_on_lists(temp_table[numer]) == 2 && strona_2 != 2)
		{
			temp_table_amount[numer]--;
			if (temp_table_amount[numer] == 0)
			{
				temp_table[numer] = "";
				temp_table_price[numer] = 0;
			}
		}
	}
}
int table::exit_trade_mode()
{
	while (1)
	{
		cout << "Transakcja nie zostanie zaakceptowana" << endl;
		cout << "Czy na pewno chcesz j¹ zakoñczyæ?" << endl;
		cout << "1. Tak" << endl;
		cout << "2. Nie" << endl;
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			return 1;
		}
		case '2':
		{
			return 0;
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}
void table::check_selected_to_buy_field(player gracz,seller handlarz)
{
	counter_selected_to_buy_usage = 0;
	counter_selected_to_buy_alchemy = 0;
	counter_selected_to_buy_forge = 0;
	for (int i = 0; i < 20; i++)
	{
		if (handlarz.search_on_lists(temp_table[i]) == 0)
		{
			if (gracz.find_usage_item(temp_table[i]) == 0)
			{
				counter_selected_to_buy_usage++;
			}
		}
		if (handlarz.search_on_lists(temp_table[i]) == 1)
		{
			if (gracz.find_crafting_alchemy_item(temp_table[i]) == 0)
			{
				counter_selected_to_buy_alchemy++;
			}
		}
		if (handlarz.search_on_lists(temp_table[i]) == 2)
		{
			if (gracz.find_crafting_forge_item(temp_table[i]) == 0)
			{
				counter_selected_to_buy_forge++;
			}
		}
	}
}
int table::can_be_selected(player gracz, seller handlarz, string nazwa)
{
	if (nazwa == "PLECAK JEST PUSTY" || nazwa == "BRAK SK£ADNIKÓW DO ALCHEMII" || nazwa == "BRAK SK£ADNIKÓW DO KOWALSTWA" || nazwa == "BRAK WYBRANYCH PRZEDMIOTÓW" || nazwa == "HANDLARZ NIC NIE SPRZEDAJE")
	{
		return 0;
	}
	else
	{
		check_selected_to_buy_field(gracz,handlarz);
		if (handlarz.search_on_lists(nazwa) == 0)
		{
			int pomoc = gracz.count_free_fields_usage() - counter_selected_to_buy_usage;
			if (gracz.find_usage_item(nazwa) == 1)
			{
				return 1;
			}
			else if (pomoc > 0 && pomoc >= counter_selected_to_buy_usage)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (handlarz.search_on_lists(nazwa) == 1)
		{
			int pomoc = gracz.count_free_fields_alchemy() - counter_selected_to_buy_alchemy;
			if (gracz.find_crafting_alchemy_item(nazwa) == 1)
			{
				return 1;
			}
			else if (pomoc > 0 && pomoc >= counter_selected_to_buy_alchemy)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (handlarz.search_on_lists(nazwa) == 2)
		{
			int pomoc = gracz.count_free_fields_forge() - counter_selected_to_buy_forge;
			if (gracz.find_crafting_forge_item(nazwa) == 1)
			{
				return 1;
			}
			else if (pomoc > 0 && pomoc >= counter_selected_to_buy_forge)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
void table::accept_transaction(player &gracz, seller handlarz)
{
	int tryb = 1;
	if (temp_table[0] == "BRAK WYBRANYCH PRZEDMIOTÓW" && temp_table[40] == "BRAK WYBRANYCH PRZEDMIOTÓW")
	{
		cout << endl << "Transakcja nie mo¿e zostaæ sfinalizowana poniewa¿ nie wybra³eœ przedmiotów do wymiany" << endl;
		system("PAUSE");
	}
	else
	{
		do
		{
			cout << "Czy na pewno chcesz sfinalizowaæ transakcje?" << endl;
			cout << "1. Tak" << endl;
			cout << "2. Nie" << endl;
			cout << "Twój wybór to:";
			string wyb;
			cin >> wyb;
			switch (wyb[0])
			{
			case '1':
			{
				//sprzedarz
				int sum = 0;
				//kupno
				int sum1 = 0;
				for (int i = 0; i < 20; i++)
				{
					sum = sum + (temp_table_price[40 + i] * temp_table_amount[40 + i]);
				}
				for (int i = 0; i < 20; i++)
				{
					sum1 = sum1 + (temp_table_price[i] * temp_table_amount[i]);
				}
				if (gracz.gold >= (sum1 - sum))
				{
					cout << endl << "Transakcja sfinalizowana" << endl;
					//sprzeda¿
					{
						for (int i = 0; i < 20; i++)
						{
							if (gracz.find_usage_item(temp_table[40 + i]) == 1)
							{
								int index = gracz.find_usage_item_index(temp_table[40 + i]);
								gracz.gold = gracz.gold + (temp_table_price[40 + i] * temp_table_amount[40 + i]);
								if (gracz.inventory_usage_amount[index] == temp_table_amount[40 + i])
								{
									gracz.inventory_usage[index] = "";
									gracz.inventory_usage_price[index] = 0;
									gracz.inventory_usage_amount[index] = 0;
								}
								else
								{
									gracz.inventory_usage_amount[index] = gracz.inventory_usage_amount[index] - temp_table_amount[40 + i];
								}
								temp_table[40 + i] = "";
								temp_table_amount[40 + i] = 0;
								temp_table_price[40 + i] = 0;
								gracz.sort_usage_backpack();
							}
							else if (gracz.find_crafting_alchemy_item(temp_table[40 + i]) == 1)
							{
								int index = gracz.find_crafting_alchemy_item_index(temp_table[40 + i]);
								gracz.gold = gracz.gold + (temp_table_price[40 + i] * temp_table_amount[40 + i]);
								if (gracz.inventory_crafting_amount[index] == temp_table_amount[40 + i])
								{
									gracz.inventory_crafting[index] = "";
									gracz.inventory_crafting_amount[index] = 0;
									gracz.inventory_crafting_price[index] = 0;
								}
								else
								{
									gracz.inventory_crafting_amount[index] = gracz.inventory_crafting_amount[index] - temp_table_amount[40 + i];
								}
								temp_table[40 + i] = "";
								temp_table_amount[40 + i] = 0;
								temp_table_price[40 + i] = 0;
								gracz.sort_crafting_alchemy_backpack();
							}
							else if (gracz.find_crafting_forge_item(temp_table[40 + i]) == 1)
							{
								int index = gracz.find_crafting_forge_item_index(temp_table[40 + i]);
								gracz.gold = gracz.gold + (temp_table_price[40 + i] * temp_table_amount[40 + i]);
								if (gracz.inventory_crafting_amount[index] == temp_table_amount[40 + i])
								{
									gracz.inventory_crafting[index] = "";
									gracz.inventory_crafting_amount[index] = 0;
									gracz.inventory_crafting_price[index] = 0;
								}
								else
								{
									gracz.inventory_crafting_amount[index] = gracz.inventory_crafting_amount[index] - temp_table_amount[40 + i];
								}
								temp_table[40 + i] = "";
								temp_table_amount[40 + i] = 0;
								temp_table_price[40 + i] = 0;
								gracz.sort_crafting_forge_backpack();
							}
						}
					}
					//kupno
					{
						for (int i = 0; i < 20; i++)
						{
							if (handlarz.search_on_lists(temp_table[i]) == 0)
							{
								int suma = temp_table_amount[i] * temp_table_price[i];
								gracz.add_usage_item(temp_table[i], suma, temp_table_amount[i],1);
								temp_table[i] = "";
								temp_table_amount[i] = 0;
								temp_table_price[i] = 0;
								gracz.sort_usage_backpack();
							}
							else if (handlarz.search_on_lists(temp_table[i]) == 1)
							{
								int suma = temp_table_amount[i] * temp_table_price[i];
								gracz.add_crafting_alchemy_item(temp_table[i], suma, temp_table_amount[i],1);
								temp_table[i] = "";
								temp_table_amount[i] = 0;
								temp_table_price[i] = 0;
								gracz.sort_crafting_alchemy_backpack();
							}
							else if (handlarz.search_on_lists(temp_table[i]) == 2)
							{
								int suma = temp_table_amount[i] * temp_table_price[i];
								gracz.add_crafting_forge_item(temp_table[i], suma, temp_table_amount[i],1);
								temp_table[i] = "";
								temp_table_amount[i] = 0;
								temp_table_price[i] = 0;
								gracz.sort_crafting_forge_backpack();
							}
						}
					}
					load_merch_trader(handlarz, gracz);
				}
				else
				{
					cout << endl << "Brak wystarczajej iloœci pieniêdzy do zakoñczenia transakcji" << endl;
				}
				tryb = 0;
				system("PAUSE");
				break;
			}
			case '2':
			{
				cout << endl << "Transakcja nie sfinalizowana" << endl;
				tryb = 0;
				system("PAUSE");
				break;
			}
			default:
			{
				system("cls");
				break;
			}
			}
		} while (tryb = 0);
	}
}