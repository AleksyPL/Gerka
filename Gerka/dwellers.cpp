#include "dwellers.h"
#include "boost_syf.h"
#include "level_up.h"
#include "sleep.h"
#include "quest.h"
#include "czas.h"
#include "tabelka.h"


dweller::dweller()
{
	rep_level = 1;
	rep_points = 0;
	rep_points_to_next_level = 500;
	gold = 5000;
	name = "";
	quest_id = "";
	gold_for_complete_quest = 0;
	exp_for_complete_quest = 0;
}
int dweller::gold_info()
{
	return this->gold;
}
int dweller::rep_level_info()
{
	return this->rep_level;
}
int dweller::rep_points_info()
{
	return this->rep_points;
}
int dweller::rep_points_to_next_level_info()
{
	return this->rep_points_to_next_level;
}
string dweller::quest_id_info()
{
	return this->quest_id;
}
int dweller::gold_for_complete_quest_info()
{
	return this->gold_for_complete_quest;
}
int dweller::exp_for_complete_quest_info()
{
	return this->exp_for_complete_quest;
}
string dweller::name_info()
{
	return this->name;
}
void dweller::gold_set(int a)
{
	this->gold = a;
}
void dweller::rep_level_set(int a)
{
	this->rep_level = a;
}
void dweller::rep_points_set(int a)
{
	this->rep_points = a;
}
void dweller::rep_points_to_next_level_set(int a)
{
	this->rep_points_to_next_level = a;
}
void dweller::quest_id_set(string a)
{
	this->quest_id = a;
}
void dweller::gold_for_complete_quest_set(int a)
{
	this->gold_for_complete_quest = a;
}
void dweller::exp_for_complete_quest_set(int a)
{
	this->exp_for_complete_quest = a;
}
void dweller::weAreClosing(player gracz)
{
	WINDOW* topbar = newwin(3, 47, 0, 46);
	wborder(topbar, 0, 0, 0, 0, ACS_TTEE, ACS_TTEE, ACS_PLUS, ACS_BTEE);
	{
		string temp = "Day " + to_string(gracz.licznik_dnia) + " - ";
		if (gracz.hour < 10)
		{
			temp += "0" + to_string(gracz.hour);
		}
		else
		{
			temp += to_string(gracz.hour);
		}
		temp += ":";
		if (gracz.minute < 10)
		{
			temp += "0" + to_string(gracz.minute);
		}
		else
		{
			temp += to_string(gracz.minute);
		}
		windowDrawOnCenter(topbar, 1, 44, temp.c_str());
	}
	wrefresh(topbar);
}
void dweller::reject_quest_giving(int height, int startPoint)
{
	vector <string> message = { "You're already doing some task" };
	sound_rejection();
	tabSubmenuTextOnly(height,startPoint,message);
}
barman::barman()
{
	name = "BARMAN";
	info[0] = "End the conversation";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[8] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[18] = "";
	info[19] = "";
	menu[0] = "Listen to gossip";
	menu[1] = "Ask for a place to stay the night";
	menu[2] = "Buy a meal";
	menu[3] = "Buy a beer";
	menu[4] = "";
	menu[5] = "";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 0;
	ceny[1] = 10;
	ceny[2] = 5;
	ceny[3] = 5;
	ceny[4] = 0;
	ceny[5] = 0;
	ceny[6] = 0;
	ceny[7] = 0;
	ceny[8] = 0;
	ceny[9] = 0;
	ceny[10] = 0;
	ceny[11] = 0;
	ceny[12] = 0;
	ceny[13] = 0;
	ceny[14] = 0;
	ceny[15] = 0;
	ceny[16] = 0;
	ceny[17] = 0;
	ceny[18] = 0;
	ceny[19] = 0;
}
void barman::gossip(int height, int startPoint, player &gracz)
{
	srand((unsigned int)time(NULL));
	int ran = rand() % 11;
	string linia;
	int nr_linii = 1;
	fstream plik;
	vector<string> message;
	if (ran == 0)
	{
		plik.open("./txt/tawerna/plota0.txt", ios::in);
	}
	else if (ran == 1)
	{
		plik.open("./txt/tawerna/plota1.txt", ios::in);
	}
	else if (ran == 2)
	{
		plik.open("./txt/tawerna/plota2.txt", ios::in);
	}
	else if (ran == 3)
	{
		plik.open("./txt/tawerna/plota3.txt", ios::in);
	}
	else if (ran == 4)
	{
		plik.open("./txt/tawerna/plota4.txt", ios::in);
	}
	else if (ran == 5)
	{
		plik.open("./txt/tawerna/plota5.txt", ios::in);
	}
	else if (ran == 6)
	{
		plik.open("./txt/tawerna/plota6.txt", ios::in);
	}
	else if (ran == 7)
	{
		plik.open("./txt/tawerna/plota7.txt", ios::in);
	}
	else if (ran == 8)
	{
		plik.open("./txt/tawerna/plota8.txt", ios::in);
	}
	else if (ran == 9)
	{
		plik.open("./txt/tawerna/plota9.txt", ios::in);
	}
	else if (ran == 10)
	{
		plik.open("./txt/tawerna/plota10.txt", ios::in);
	}
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	tabSubmenuFancyTextOnly(height, startPoint, message,50);
	change_time(height, startPoint, gracz, 0, 1);
}
void barman::give_room(int height, int startPoint, player &gracz)
{
	if (gracz.hunger >= 5)
	{
		vector<string> message;
		if (gracz.gold >= ceny[1])
		{
			message.push_back("The barman leads you to the free room");
			change_time(height, startPoint, gracz, 0, 5);
			sleep(gracz, ceny[1], 8, 0, height, startPoint,message);
		}
		else
		{
			message.push_back(no_money());
		}
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void barman::sell_food(int height, int startPoint, player &gracz, int ilosc)
{
	vector<string> message;
	if (gracz.hunger == 10)
	{
		message.push_back("You're not hungry");
	}
	else
	{
		if (gracz.gold >= ceny[2])
		{
			message.push_back("You're having a meal");
			gracz.gold = gracz.gold - ceny[2];
			gracz.hunger = gracz.hunger + ilosc;
			gracz.hp = gracz.hp + (0.01*gracz.max_hp);
			if (gracz.hp > gracz.max_hp)
			{
				gracz.hp = gracz.max_hp;
			}
			if (gracz.hunger > 10)
			{
				gracz.hunger = 10;
			}
			change_time(height, startPoint, gracz, 0, 10);
		}
		else
		{
			message.push_back(no_money());
		}
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
void barman::sell_beer(int height, int startPoint, player &gracz)
{
	vector<string> message;
	if (gracz.alko == 10)
	{
		message.push_back("You're too drunk to drink more");
	}
	else if (gracz.gold >= ceny[3])
	{
		message.push_back("You're drinking a cold beer");
		message.push_back("");
		gracz.gold = gracz.gold - ceny[3];
		sound_beer();
		gracz.alko = gracz.alko + 1;
		change_time(height, startPoint, gracz, 0, 10, 0, 1);
		if (gracz.alko == 2 || gracz.alko == 4 || gracz.alko == 6 || gracz.alko == 8 || gracz.alko == 10)
		{
			gracz.hunger = gracz.hunger - 1;
		}
		string linia;
		int nr_linii = 1;
		fstream plik;
		plik.open("./txt/tawerna/beer.txt", ios::in);
		while (!plik.eof())
		{
			getline(plik, linia);
			message.push_back(linia);
		}
		plik.close();
	}
	else
	{
		message.push_back(no_money());
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
seller::seller()
{
	name = "HANDLARZ";
	info[0] = "End the conversation";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[9] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[19] = "";
	menu[0] = "Start to trade";
	menu[1] = "";
	menu[2] = "";
	menu[3] = "";
	menu[4] = "";
	menu[5] = "";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 0;
	ceny[1] = 0;
	ceny[2] = 0;
	ceny[3] = 0;
	ceny[4] = 0;
	ceny[5] = 0;
	ceny[6] = 0;
	ceny[7] = 0;
	ceny[8] = 0;
	ceny[9] = 0;
	ceny[10] = 0;
	ceny[11] = 0;
	ceny[12] = 0;
	ceny[13] = 0;
	ceny[14] = 0;
	ceny[15] = 0;
	ceny[16] = 0;
	ceny[17] = 0;
	ceny[18] = 0;
	ceny[19] = 0;
	for (int i = 0; i < 20; i++)
	{
		menu_items[i] = "";
		menu_price[i] = 0;
	}
}
void seller::loadMerch(int leftSideCard)
{
	for (int i = 0; i < 20; i++)
	{
		menu_items[i] = "";
	}
	string linia;
	fstream plik;
	int nr_linii = 1;
	if (leftSideCard == 0)
	{
		plik.open("./txt/trader/items_trash.txt", ios::in);
		while (getline(plik, linia))
		{
			menu_items[nr_linii - 1] = linia;
			nr_linii++;
		}
		plik.close();
	}
	else if (leftSideCard == 1)
	{
		plik.open("./txt/trader/items_low.txt", ios::in);
		while (getline(plik, linia))
		{
			menu_items[nr_linii - 1] = linia;
			nr_linii++;
		}
		plik.close();
	}
	else if (leftSideCard == 2)
	{
		plik.open("./txt/trader/items_mid.txt", ios::in);
		while (getline(plik, linia))
		{
			menu_items[nr_linii - 1] = linia;
			nr_linii++;
		}
		plik.close();
	}
	else if (leftSideCard == 3)
	{
		plik.open("./txt/trader/items_high.txt", ios::in);
		while (getline(plik, linia))
		{
			menu_items[nr_linii - 1] = linia;
			nr_linii++;
		}
		plik.close();
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			menu_items[i] = "";
			menu_price[i] = 0;
		}
	}
}
int seller::loadPrices(string item)
{
	for (int i = 0; i < 20; i++)
	{
		menu_price[i] = 0;
	}
	string linia;
	fstream plik;
	int nr_linii = 1;
	int price = 0;
	plik.open("./txt/mix/items_prices.txt", ios::in);
	while (getline(plik, linia))
	{
		if (linia == item)
		{
			nr_linii++;
			getline(plik, linia);
			price = atoi(linia.c_str());
			break;
		}
		nr_linii++;
	}
	plik.close();
	return price;
}
string seller::makeString(int howLong, string item, int amount, int price)
{
	string price_string="";
	string amount_string="";
	string temp="";
	if (price <= 0)
	{
		price_string = "[WORTHLESS]";
	}
	else
	{
		price_string = "[" + to_string(price) + " GOLD]";
	}
	if (amount > 1)
	{
		amount_string = " x" + to_string(amount);
	}
	else
	{

	}
	howLong -= (item.length() + amount_string.length() + price_string.length());
	temp = item + amount_string;
	for (int i = 0; i < howLong; i++)
	{
		temp += " ";
	}
	temp += price_string;
	return temp;
}
void seller::buyItem(int height, int startPoint, player& gracz, string item, int amount, int price, bool &anythingSoldOrBought)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (item != "" && findItemOnList(item) == "Usable" && amount != 0)
	{
		if (gracz.count_free_fields_usage() !=0)
		{
			if (price > gracz.gold)
			{
				message.push_back("You don't have enough gold to buy " + item);
			}
			else
			{
				gracz.add_usage_item(item,price,amount,height,startPoint);
				gold += price;
			}
		}
		else
		{
			message.push_back("Your backpack is full");
		}
	}
	else if (item != "" && findItemOnList(item) == "Alchemy" && amount != 0)
	{
		if (gracz.count_free_fields_alchemy() != 0)
		{
			if (price > gracz.gold)
			{
				message.push_back("You don't have enough gold to buy " + item);
			}
			else
			{
				gracz.add_crafting_alchemy_item(item, price, amount, height, startPoint);
				gold += price;
			}
		}
		else
		{
			message.push_back("Your backpack is full");
		}
	}
	else if (item != "" && findItemOnList(item) == "Smithery" && amount != 0)
	{
		if (gracz.count_free_fields_forge() != 0)
		{
			if (price > gracz.gold)
			{
				message.push_back("You don't have enough gold to buy " + item);
			}
			else
			{
				gracz.add_crafting_forge_item(item, price, amount, height, startPoint);
				gold += price;
			}
		}
		else
		{
			message.push_back("Your backpack is full");
		}
	}
	else
	{
		message.push_back("Error");
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void seller::sellItem(int height, int startPoint, player &gracz, string item, int amount, int price, bool &anythingSoldOrBought)
{
	vector <string> message;
	vector <string> options = {"Yes","No"};
	int priceForItems = 0;
	if (item != "" && gracz.find_usage_item(item) == 1 && amount != 0)
	{
		if (price > 0)
		{
			string temp = "Are you sure you want to sell " + item + " for " + to_string(price) + " gold";
			if (amount > 1)
			{
				temp += " each?";
			}
			else
			{
				temp += "?";
			}
			message.push_back(temp);
			message.push_back("This transaction cannot be undone.");
			int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
			if (highlight == 0)
			{
				int index = gracz.find_usage_item_index(item);
				if (amount > 1)
				{
					temp = "How many " + item + " you want to sell? ";
					int amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (amountWritten <= 0 || amountWritten > gracz.inventory_usage_amount[index] || price * amountWritten > gold)
					{
						if (price * amountWritten > gold)
						{
							message.clear();
							message.push_back(name + " does not have enough gold to buy " + item + " from you.");
							tabSubmenuTextOnly(height, startPoint, message);
						}
						amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					if (amountWritten == gracz.inventory_usage_amount[index])
					{
						gracz.inventory_usage[index] = "";
						gracz.inventory_usage_amount[index] = 0;
						gracz.sort_usage_backpack();
					}
					else
					{
						gracz.inventory_usage_amount[index] -= amountWritten;
					}
					gracz.gold += price * amountWritten;
					gold -= price * amountWritten;
					anythingSoldOrBought = true;
				}
				else
				{
					if (gold > price* amount)
					{
						if (amount == gracz.inventory_usage_amount[index])
						{
							gracz.inventory_usage[index] = "";
							gracz.inventory_usage_amount[index] = 0;
							gracz.sort_usage_backpack();
						}
						else
						{
							gracz.inventory_usage_amount[index] -= amount;
						}
						gracz.gold += price * amount;
						gold -= price * amount;
						anythingSoldOrBought = true;
					}
					else
					{
						message.clear();
						message.push_back(name + " does not have enough gold to buy " + item + " from you.");
						tabSubmenuTextOnly(height, startPoint, message);
					}
				}
			}
		}
		else
		{
			message.push_back("Are you sure you want to give " + item + " for free?");
			message.push_back("This transaction cannot be undone.");
			int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
			if (highlight == 0)
			{
				int index = gracz.find_usage_item_index(item);
				if (amount > 1)
				{
					string temp = "How many " + item + " you want to give? ";
					int amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (amountWritten <= 0 || amountWritten > gracz.inventory_usage_amount[index])
					{
						amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					if (amountWritten == gracz.inventory_usage_amount[index])
					{
						gracz.inventory_usage[index] = "";
						gracz.inventory_usage_amount[index] = 0;
						gracz.sort_usage_backpack();
					}
					else
					{
						gracz.inventory_usage_amount[index] -= amountWritten;
					}
					anythingSoldOrBought = true;
				}
				else
				{
					if (amount == gracz.inventory_usage_amount[index])
					{
						gracz.inventory_usage[index] = "";
						gracz.inventory_usage_amount[index] = 0;
						gracz.sort_usage_backpack();
					}
					else
					{
						gracz.inventory_usage_amount[index] -= amount;
					}
					anythingSoldOrBought = true;
				}
			}
		}
	}
	else if (item != "" && gracz.find_crafting_alchemy_item(item) == 1 && amount != 0)
	{
	if (price > 0)
	{
		string temp = "Are you sure you want to sell " + item + " for " + to_string(price) + " gold";
		if (amount > 1)
		{
			temp += " each?";
		}
		else
		{
			temp += "?";
		}
		message.push_back(temp);
		message.push_back("This transaction cannot be undone.");
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			int index = gracz.find_crafting_alchemy_item_index(item);
			if (amount > 1)
			{
				temp = "How many " + item + " you want to sell? ";
				int amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (amountWritten <= 0 || amountWritten > gracz.inventory_crafting_amount[index] || price * amountWritten > gold)
				{
					if (price * amountWritten > gold)
					{
						message.clear();
						message.push_back(name + " does not have enough gold to buy " + item + " from you.");
						tabSubmenuTextOnly(height, startPoint, message);
					}
					amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				if (amountWritten == gracz.inventory_crafting_amount[index])
				{
					gracz.inventory_crafting[index] = "";
					gracz.inventory_crafting_amount[index] = 0;
					gracz.sort_crafting_alchemy_backpack();
				}
				else
				{
					gracz.inventory_crafting_amount[index] -= amountWritten;
				}
				gracz.gold += price * amountWritten;
				gold -= price * amountWritten;
				anythingSoldOrBought = true;
			}
			else
			{
				if (gold > price* amount)
				{
					if (amount == gracz.inventory_crafting_amount[index])
					{
						gracz.inventory_crafting[index] = "";
						gracz.inventory_crafting_amount[index] = 0;
						gracz.sort_crafting_alchemy_backpack();
					}
					else
					{
						gracz.inventory_crafting_amount[index] -= amount;
					}
					gracz.gold += price * amount;
					gold -= price * amount;
					anythingSoldOrBought = true;
				}
				else
				{
					message.clear();
					message.push_back(name + " does not have enough gold to buy " + item + " from you.");
					tabSubmenuTextOnly(height, startPoint, message);
				}
			}
		}
	}
	else
	{
		message.push_back("Are you sure you want to give " + item + " for free?");
		message.push_back("This transaction cannot be undone.");
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			int index = gracz.find_crafting_alchemy_item_index(item);
			if (amount > 1)
			{
				string temp = "How many " + item + " you want to give? ";
				int amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (amountWritten <= 0 || amountWritten > gracz.inventory_crafting_amount[index])
				{
					amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				if (amountWritten == gracz.inventory_crafting_amount[index])
				{
					gracz.inventory_crafting[index] = "";
					gracz.inventory_crafting_amount[index] = 0;
					gracz.sort_crafting_alchemy_backpack();
				}
				else
				{
					gracz.inventory_crafting_amount[index] -= amountWritten;
				}
				anythingSoldOrBought = true;
			}
			else
			{
				if (amount == gracz.inventory_crafting_amount[index])
				{
					gracz.inventory_crafting[index] = "";
					gracz.inventory_crafting_amount[index] = 0;
					gracz.sort_crafting_alchemy_backpack();
				}
				else
				{
					gracz.inventory_crafting_amount[index] -= amount;
				}
				anythingSoldOrBought = true;
			}
		}
	}
	}
	else if(item != "" && gracz.find_crafting_forge_item(item) == 1 && amount != 0)
	{
	if (price > 0)
	{
		string temp = "Are you sure you want to sell " + item + " for " + to_string(price) + " gold";
		if (amount > 1)
		{
			temp += " each?";
		}
		else
		{
			temp += "?";
		}
		message.push_back(temp);
		message.push_back("This transaction cannot be undone.");
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			int index = gracz.find_crafting_forge_item_index(item);
			if (amount > 1)
			{
				temp = "How many " + item + " you want to sell? ";
				int amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (amountWritten <= 0 || amountWritten > gracz.inventory_crafting_amount[20 + index] || price * amountWritten > gold)
				{
					if (price * amountWritten > gold)
					{
						message.clear();
						message.push_back(name + " does not have enough gold to buy " + item + " from you.");
						tabSubmenuTextOnly(height, startPoint, message);
					}
					amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				if (amountWritten == gracz.inventory_crafting_amount[20 + index])
				{
					gracz.inventory_crafting[20 + index] = "";
					gracz.inventory_crafting_amount[20 + index] = 0;
					gracz.sort_crafting_forge_backpack();
				}
				else
				{
					gracz.inventory_crafting_amount[20 + index] -= amountWritten;
				}
				gracz.gold += price * amountWritten;
				gold -= price * amountWritten;
				anythingSoldOrBought = true;
			}
			else
			{
				if (gold > price* amount)
				{
					if (amount == gracz.inventory_crafting_amount[20 + index])
					{
						gracz.inventory_crafting[20 + index] = "";
						gracz.inventory_crafting_amount[20 + index] = 0;
						gracz.sort_crafting_forge_backpack();
					}
					else
					{
						gracz.inventory_crafting_amount[20 + index] -= amount;
					}
					gracz.gold += price * amount;
					gold -= price * amount;
					anythingSoldOrBought = true;
				}
				else
				{
					message.clear();
					message.push_back(name + " does not have enough gold to buy " + item + " from you.");
					tabSubmenuTextOnly(height, startPoint, message);
				}
			}
		}
	}
	else
	{
		message.push_back("Are you sure you want to give " + item + " for free?");
		message.push_back("This transaction cannot be undone.");
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			int index = gracz.find_crafting_forge_item_index(item);
			if (amount > 1)
			{
				string temp = "How many " + item + " you want to give? ";
				int amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (amountWritten <= 0 || amountWritten > gracz.inventory_crafting_amount[20 + index])
				{
					amountWritten = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				if (amountWritten == gracz.inventory_crafting_amount[20 + index])
				{
					gracz.inventory_crafting[20 + index] = "";
					gracz.inventory_crafting_amount[20 + index] = 0;
					gracz.sort_crafting_forge_backpack();
				}
				else
				{
					gracz.inventory_crafting_amount[20 + index] -= amountWritten;
				}
				anythingSoldOrBought = true;
			}
			else
			{
				if (amount == gracz.inventory_crafting_amount[20 + index])
				{
					gracz.inventory_crafting[20 + index] = "";
					gracz.inventory_crafting_amount[20 + index] = 0;
					gracz.sort_crafting_forge_backpack();
				}
				else
				{
					gracz.inventory_crafting_amount[20 + index] -= amount;
				}
				anythingSoldOrBought = true;
			}
		}
	}
	}
	else
	{
		message.push_back("No item");
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
/*
int seller::find_item_index(string nazwa)
{
	for (int i = 0; i < 120; i++)
	{
		if (menu_items[i] == nazwa)
		{
			return i;
		}
	}
}
void seller::add_prices(player &gracz)
{
	for (int i = 0; i < 20; i++)
	{
		if (gracz.inventory_usage[i] == "")
		{
			continue;
		}
		else
		{
			for (int j = 0; j < 120; j++)
			{
				if (gracz.inventory_usage[i] == menu_items[j])
				{
					gracz.inventory_usage_price[i] = menu_price[j];
				}
			}
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (gracz.inventory_crafting[i] == "")
		{
			continue;
		}
		else
		{
			for (int j = 0; j < 120; j++)
			{
				if (gracz.inventory_crafting[i] == menu_items[j])
				{
					gracz.inventory_crafting_price[i] = menu_price[j];
				}
			}
		}
	}
}
int seller::search_on_lists(string nazwa)
{
	for (int i = 0; i < 120; i++)
	{
		if (menu_items[i] == nazwa)
		{
			if (i < 80)
			{
				return 0;
			}
			else if (i < 100 && i >= 80)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
}
*/
blacksmith::blacksmith(player gracz)
{
	name = "KOWAL";
	info[0] = "End the conversation";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[8] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[18] = "";
	info[19] = "";
	menu[0] = "Upgrade helmet";
	menu[1] = "Upgrade chestplate";
	menu[2] = "Upgrade gloves";
	menu[3] = "Upgrade pants";
	menu[4] = "Upgrade shoes";
	menu[5] = "Upgrade weapon";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 500;
	ceny[1] = 500;
	ceny[2] = 500;
	ceny[3] = 500;
	ceny[4] = 500;
	ceny[5] = 500;
	ceny[6] = 0;
	ceny[7] = 0;
	ceny[8] = 0;
	ceny[9] = 0;
	ceny[10] = 0;
	ceny[11] = 0;
	ceny[12] = 0;
	ceny[13] = 0;
	ceny[14] = 0;
	ceny[15] = 0;
	ceny[16] = 0;
	ceny[17] = 0;
	ceny[18] = 0;
	ceny[19] = 0;
	for (int i = 0; i < 20; i++)
	{
		weapons[i] = "";
		weapon_dmg[i] = 0;
	}
}
void blacksmith::load_weapons()
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	plik.open("./txt/kowal/weapons_blunt.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1:
		{
			weapons[0] = linia;
			break;
		}
		case 2:
		{
			weapons[1] = linia;
			break;
		}
		case 3:
		{
			weapons[2] = linia;
			break;
		}
		case 4:
		{
			weapons[3] = linia;
			break;
		}
		case 5:
		{
			weapons[4] = linia;
			break;
		}
		case 6:
		{
			weapons[5] = linia;
			break;
		}
		}
		nr_linii++;
	}
	plik.close();
	nr_linii = 1;
	plik.open("./txt/kowal/weapons_stabbing.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1:
		{
			weapons[6] = linia;
			break;
		}
		case 2:
		{
			weapons[7] = linia;
			break;
		}
		case 3:
		{
			weapons[8] = linia;
			break;
		}
		case 4:
		{
			weapons[9] = linia;
			break;
		}
		case 5:
		{
			weapons[10] = linia;
			break;
		}
		}
		nr_linii++;
	}
	plik.close();
	nr_linii = 1;
	plik.open("./txt/kowal/weapons_cutting.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1:
		{
			weapons[11] = linia;
			break;
		}
		case 2:
		{
			weapons[12] = linia;
			break;
		}
		case 3:
		{
			weapons[13] = linia;
			break;
		}
		case 4:
		{
			weapons[14] = linia;
			break;
		}
		case 5:
		{
			weapons[15] = linia;
			break;
		}
		case 6:
		{
			weapons[16] = linia;
			break;
		}
		case 7:
		{
			weapons[17] = linia;
			break;
		}
		case 8:
		{
			weapons[18] = linia;
			break;
		}
		case 9:
		{
			weapons[19] = linia;
			break;
		}
		}
		nr_linii++;
	}
	plik.close();
}
void blacksmith::generate_merch(player gracz)
{
	for (int i = 0; i < 20; i++)
	{
		int pomoc = rand() % 3;
		if (pomoc == 0)
		{
			weapon_dmg[i] = gracz.level * 5;
		}
		else if(pomoc==1)
		{
			int pomoc2 = rand() % 2;
			if (pomoc2 == 0)
			{
				weapon_dmg[i] = (gracz.level * 5) - 1;
			}
			else if (pomoc2 == 1)
			{
				weapon_dmg[i] = (gracz.level * 5) + 1;
			}
		}
		else if (pomoc == 2)
		{
			int pomoc2 = rand() % 4;
			if (pomoc2 == 0)
			{
				weapon_dmg[i] = (gracz.level * 5) - 2;
			}
			else if (pomoc2 == 1)
			{
				weapon_dmg[i] = (gracz.level * 5) - 1;
			}
			else if (pomoc2 == 2)
			{
				weapon_dmg[i] = (gracz.level * 5) + 1;
			}
			else if (pomoc2 == 3)
			{
				weapon_dmg[i] = (gracz.level * 5) + 2;
			}
		}
	}
}
void blacksmith::load_player_points(player gracz)
{
	menu[0] = "Upgrade helmet";
	menu[1] = "Upgrade chestplate";
	menu[2] = "Upgrade gloves";
	menu[3] = "Upgrade pants";
	menu[4] = "Upgrade shoes";
	menu[5] = "Upgrade weapon";
	ceny[0] = 500;
	ceny[1] = 500;
	ceny[2] = 500;
	ceny[3] = 500;
	ceny[4] = 500;
	ceny[5] = 500;
	this->menu[0] = menu[0] + " (" + to_string(gracz.helmet) + ")";
	this->ceny[0] = ceny[0] + (100*gracz.helmet);
	this->menu[1] = menu[1] + " (" + to_string(gracz.chestplate) + ")";
	this->ceny[1] = ceny[1] + (100 * gracz.chestplate);
	this->menu[2] = menu[2] + " (" + to_string(gracz.gloves) + ")";
	this->ceny[2] = ceny[2] + (100 * gracz.gloves);
	this->menu[3] = menu[3] + " (" + to_string(gracz.pants) + ")";
	this->ceny[3] = ceny[3] + (100 * gracz.pants);
	this->menu[4] = menu[4] + " (" + to_string(gracz.shoes) + ")";
	this->ceny[4] = ceny[4] + (100 * gracz.shoes);
	this->menu[5] = menu[5] + " (" + to_string(gracz.weapon) + ")";
	this->ceny[5] = ceny[5] + (100 * gracz.weapon);
}
void blacksmith::print_image(vector <string>& message)
{
	string linia;
	fstream plik;
	plik.open("./txt/kowal/kowal.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	sound_blacksmith();
}
void blacksmith::power_up(int height, int startPoint, player &gracz, int tryb)
{
	vector <string> message;
	switch (tryb)
	{
	case 0:
	{
		if (gracz.gold >= ceny[0])
		{
			message.push_back("The helmet has been strengthened");
			message.push_back("");
			print_image(message);
			gracz.helmet = gracz.helmet + 1;
			gracz.gold = gracz.gold - ceny[0];
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
		break;
	}
	case 1:
	{
		if (gracz.gold >= ceny[1])
		{
			message.push_back("The chestplate has been strengthened");
			message.push_back("");
			print_image(message);
			gracz.chestplate = gracz.chestplate + 1;
			gracz.gold = gracz.gold - ceny[1];
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
		break;
	}
	case 2:
	{
		if (gracz.gold >= ceny[2])
		{
			message.push_back("The gloves have been strengthened");
			message.push_back("");
			print_image(message);
			gracz.gloves = gracz.gloves + 1;
			gracz.gold = gracz.gold - ceny[2];
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
		break;
	}
	case 3:
	{
		if (gracz.gold >= ceny[3])
		{
			message.push_back("The pants have been strengthened");
			message.push_back("");
			print_image(message);
			gracz.pants = gracz.pants + 1;
			gracz.gold = gracz.gold - ceny[3];
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
		break;
	}
	case 4:
	{
		if (gracz.gold >= ceny[4])
		{
			message.push_back("The shoes have been strengthened");
			message.push_back("");
			print_image(message);
			gracz.shoes = gracz.shoes + 1;
			gracz.gold = gracz.gold - ceny[4];
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
		break;
	}
	case 5:
	{
		if (gracz.gold >= ceny[5])
		{
			message.push_back("The weapon (" + gracz.weapon_name + ") have been strengthened");
			message.push_back("");
			print_image(message);
			gracz.weapon = gracz.weapon + 1;
			gracz.gold = gracz.gold - ceny[5];
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
		break;
	}
	}
	tabSubmenuTextOnly(23, 32, message);
}
alchemist::alchemist()
{
	name = "ALCHEMIK";
	info[0] = "End the conversation";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[8] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[18] = "";
	info[19] = "";
	menu[0] = "Buy a level up potion";
	menu[1] = "Buy health points potion";
	menu[2] = "";
	menu[3] = "";
	menu[4] = "";
	menu[5] = "";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 0;
	ceny[1] = 100;
	ceny[2] = 0;
	ceny[3] = 0;
	ceny[4] = 0;
	ceny[5] = 0;
	ceny[6] = 0;
	ceny[7] = 0;
	ceny[8] = 0;
	ceny[9] = 0;
	ceny[10] = 0;
	ceny[11] = 0;
	ceny[12] = 0;
	ceny[13] = 0;
	ceny[14] = 0;
	ceny[15] = 0;
	ceny[16] = 0;
	ceny[17] = 0;
	ceny[18] = 0;
	ceny[19] = 0;
}
void alchemist::show_image(vector <string> &message)
{
	string linia;
	fstream plik;
	plik.open("./txt/alchemik/alchemik.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	sound_alchemy();
}
void alchemist::buy_new_level_potion(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.gold > (gracz.level * 100))
	{
		message.push_back("You bought a level up potion");
		message.push_back("");
		gracz.add_usage_item("Mikstura nowego poziomu", (gracz.level * 100), 23,32,1);
		change_time(height, startPoint, gracz, 0, 5);
		show_image(message);
	}
	else
	{
		message.push_back(no_money());
	}
	tabSubmenuTextOnly(height,startPoint,message);
}
void alchemist::buy_hp_potion(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.gold > ceny[1])
	{
		message.push_back("You bought a health points potion");
		message.push_back("");
		gracz.add_usage_item("Mikstura ¿ycia", ceny[1], 23,32, 1);
		change_time(height, startPoint, gracz, 0, 5);
		show_image(message);
	}
	else
	{
		message.push_back(no_money());
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
shaman::shaman()
{
	name = "SZAMAN";
	info[0] = "End the conversation";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[8] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[18] = "";
	info[19] = "";
	menu[0] = "Ask for strength upgrade";
	menu[1] = "Ask for agility upgrade";
	menu[2] = "Ask for intelligence upgrade";
	menu[3] = "Ask for charisma upgrade";
	menu[4] = "Ask for luck upgrade";
	menu[5] = "QUEST";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 200;
	ceny[1] = 200;
	ceny[2] = 200;
	ceny[3] = 200;
	ceny[4] = 200;
	ceny[5] = 0;
	ceny[6] = 0;
	ceny[7] = 0;
	ceny[8] = 0;
	ceny[9] = 0;
	ceny[10] = 0;
	ceny[11] = 0;
	ceny[12] = 0;
	ceny[13] = 0;
	ceny[14] = 0;
	ceny[15] = 0;
	ceny[16] = 0;
	ceny[17] = 0;
	ceny[18] = 0;
	ceny[19] = 0;
	quest_id = "s00";
}
void shaman::show_image(vector <string> &message)
{
	string linia;
	fstream plik;
	plik.open("./txt/dom_szamana/shaman.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	sound_shaman();
}
void shaman::add_boost(int height, int startPoint, player &gracz, int tryb)
{
	vector <string> message;
	switch (tryb)
	{
	case 0:
	{
		if (gracz.counter_boost_str == 0)
		{
			if (gracz.gold >= ceny[0])
			{
				message.push_back("Your strength has been temporarily strengthened");
				add_boost_str(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[0];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else
		{
			message.push_back("Your strength is already temporarily strengthened.");
			message.push_back("It's dangerous to apply another effect.");
		}
		break;
	}
	case 1:
	{
		if (gracz.counter_boost_agility == 0)
		{
			if (gracz.gold >= ceny[1])
			{
				message.push_back("Your agility has been temporarily strengthened");
				add_boost_agility(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[1];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else
		{
			message.push_back("Your agility is already temporarily strengthened.");
			message.push_back("It's dangerous to apply another effect.");
		}
		break;
	}
	case 2:
	{
		if (gracz.counter_boost_intel == 0)
		{
			if (gracz.gold >= ceny[2])
			{
				message.push_back("Your inteligence has been temporarily strengthened");
				add_boost_intel(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[2];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else
		{
			message.push_back("Your inteligence is already temporarily strengthened.");
			message.push_back("It's dangerous to apply another effect.");
		}
		break;
	}
	case 3:
	{
		if (gracz.counter_boost_charisma == 0)
		{
			if (gracz.gold >= ceny[3])
			{
				message.push_back("Your charisma has been temporarily strengthened");
				add_boost_charisma(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[3];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else
		{
			message.push_back("Your charisma is already temporarily strengthened.");
			message.push_back("It's dangerous to apply another effect.");
		}
		break;
	}
	case 4:
	{
		if (gracz.counter_boost_luck == 0)
		{
			if (gracz.gold >= ceny[4])
			{
				message.push_back("Your luck has been temporarily strengthened");
				add_boost_luck(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[4];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else
		{
			message.push_back("Your luck is already temporarily strengthened.");
			message.push_back("It's dangerous to apply another effect.");
		}
		break;
	}
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
int shaman::dialog_box(int height, int startPoint)
{
	vector <string> message = {"Could you do that for me?"};
	vector <string> options = {"Yes","No"};
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	return highlight;
}
void shaman::everything_about_quests(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.quest_name == "" && gracz.quest_id == "")
	{
		if (quest_id_info() == "s00")
		{
			gold_for_complete_quest_set(1000);
			exp_for_complete_quest_set(100);
			message.push_back("To make a magic amulet I need three human teeth.");
			message.push_back("I will give you 1000 gold if you bring me these teeth.");
			tabSubmenuFancyTextOnly(height, startPoint, message, 50);
			if (dialog_box(height,startPoint) == 0)
			{
				gracz.add_quest("Zdob¹dŸ trzy ludzkie zêby", "s00");
			}
			else
			{
				message.clear();
				message.push_back("Well, maybe someone else will come forward.");
				tabSubmenuFancyTextOnly(height, startPoint, message, 50);
			}
		}
	}
	else if(gracz.quest_name != "" && gracz.quest_id !=quest_id_info())
	{
		reject_quest_giving(height,startPoint);
	}
	else if (gracz.quest_name != "" && gracz.quest_id == quest_id_info())
	{
		if (gracz.quest_complete == 1 && gracz.quest_failed == 0)
		{
			if (quest_id_info() == "s00")
			{
				message.clear();
				message.push_back("Thank you, this is your gold.");
				tabSubmenuFancyTextOnly(height, startPoint, message, 50);
				gracz.remove_usage_item(height,startPoint,"Ludzki z¹b",3);
				quest_id_set("s01");
			}
			gracz.gold = gracz.gold + this->gold_for_complete_quest_info();
			this->gold_for_complete_quest_set(0);
			gracz.exp = gracz.exp + this->exp_for_complete_quest_info();
			this->exp_for_complete_quest_set(0);
			gracz.remove_quest();
		}
		else if(gracz.quest_complete == 0 && gracz.quest_failed == 1)
		{
			message.clear();
			message.push_back("You didn't make it this time but you can try again");
			tabSubmenuFancyTextOnly(height, startPoint, message, 50);
			gracz.remove_quest();
		}
	}
}
doctor::doctor()
{
	name = "LEKARZ";
	info[0] = "End the conversation";
	info[1] = "";
	info[2] = "";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[8] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[18] = "";
	info[19] = "";
	menu[0] = "Ask for wounds healing";
	menu[1] = "Ask for alcohol detox";
	menu[2] = "Ask for strength restore";
	menu[3] = "Ask for agility restore";
	menu[4] = "Ask for intelligence restore";
	menu[5] = "Ask for charisma restore";
	menu[6] = "Ask for luck restore";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 300;
	ceny[1] = 50;
	ceny[2] = 100;
	ceny[3] = 100;
	ceny[4] = 100;
	ceny[5] = 100;
	ceny[6] = 100;
	ceny[7] = 0;
	ceny[8] = 0;
	ceny[9] = 0;
	ceny[10] = 0;
	ceny[11] = 0;
	ceny[12] = 0;
	ceny[13] = 0;
	ceny[14] = 0;
	ceny[15] = 0;
	ceny[16] = 0;
	ceny[17] = 0;
	ceny[18] = 0;
	ceny[19] = 0;
}
void doctor::show_image(vector <string>& message)
{
	string linia;
	fstream plik;
	plik.open("./txt/szpital/lekarz.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	sound_heal_up();
}
void doctor::heal(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.hp < gracz.max_hp)
	{
		if (gracz.gold >= ceny[0])
		{
			message.push_back("Your wounds have been healed");
			gracz.hp = gracz.max_hp;
			gracz.gold = gracz.gold - ceny[0];
			show_image(message);
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
	}
	else
	{
		message.push_back("You are fine");
	}
	tabSubmenuTextOnly(height,startPoint,message);
}
void doctor::sober(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.alko != 0)
	{
		if (gracz.gold >= ceny[1])
		{
			message.push_back("You sober up");
			gracz.alko = 0;
			gracz.gold = gracz.gold - ceny[1];
			show_image(message);
			change_time(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(no_money());
		}
	}
	else
	{
		message.push_back("You are sober");
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
void doctor::remove_nerf(int height, int startPoint, player &gracz, int tryb)
{
	vector <string> message;
	switch (tryb)
	{
	case 0:
	{
		if (gracz.counter_nerf_str != 0)
		{
			if (gracz.gold >= ceny[2])
			{
				message.push_back("Your strength is returning to normal");
				remove_nerf_str(gracz);
				gracz.gold = gracz.gold - ceny[2];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else if (gracz.counter_boost_str != 0)
		{
			message.push_back("You are fine, and it's even better than normal");
		}
		else
		{
			message.push_back("You are fine");
		}
		break;
	}
	case 1:
	{
		if (gracz.counter_nerf_agility != 0)
		{
			if (gracz.gold >= ceny[3])
			{
				message.push_back("Your agility is returning to normal");
				remove_nerf_agility(gracz);
				gracz.gold = gracz.gold - ceny[3];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else if (gracz.counter_boost_agility != 0)
		{
			message.push_back("You are fine, and it's even better than normal");
		}
		else
		{
			message.push_back("You are fine");
		}
		break;
	}
	case 2:
	{
		if (gracz.counter_nerf_intel != 0)
		{
			if (gracz.gold >= ceny[4])
			{
				message.push_back("Your inteligence is returning to normal");
				remove_nerf_intel(gracz);
				gracz.gold = gracz.gold - ceny[4];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else if (gracz.counter_boost_intel != 0)
		{
			message.push_back("You are fine, and it's even better than normal");
		}
		else
		{
			message.push_back("You are fine");
		}
		break;
	}
	case 3:
	{
		if (gracz.counter_nerf_charisma != 0)
		{
			if (gracz.gold >= ceny[5])
			{
				message.push_back("Your charisma is returning to normal");
				remove_nerf_charisma(gracz);
				gracz.gold = gracz.gold - ceny[5];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else if (gracz.counter_boost_charisma != 0)
		{
			message.push_back("You are fine, and it's even better than normal");
		}
		else
		{
			message.push_back("You are fine");
		}
		break;
	}
	case 4:
	{
		if (gracz.counter_nerf_luck != 0)
		{
			if (gracz.gold >= ceny[6])
			{
				message.push_back("Your luck is returning to normal");
				remove_nerf_luck(gracz);
				gracz.gold = gracz.gold - ceny[6];
				show_image(message);
				change_time(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(no_money());
			}
		}
		else if (gracz.counter_boost_luck != 0)
		{
			message.push_back("You are fine, and it's even better than normal");
		}
		else
		{
			message.push_back("You are fine");
		}
		break;
	}
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
chest::chest()
{
	for (int i = 0; i < 60; i++)
	{
		menu[i] = "";
		menu_amount[i] = 0;
	}
}
int chest::count_free_fields_usage()
{
	int licznik = 0;
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] == "" && menu_amount[i] == 0)
		{
			licznik++;
		}
	}
	return licznik;
}
int chest::count_free_fields_alchemy()
{
	int licznik = 0;
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] == "" && menu_amount[20 + i] == 0)
		{
			licznik++;
		}
	}
	return licznik;
}
int chest::count_free_fields_forge()
{
	int licznik = 0;
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] == "" && menu_amount[40 + i] == 0)
		{
			licznik++;
		}
	}
	return licznik;
}
int chest::is_in_chest_usage(player gracz,string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[i]==nazwa)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int chest::find_free_usage_index()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] == "")
		{
			return i;
		}
	}
}
int chest::find_selected_usage_index(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] == nazwa)
		{
			return i;
		}
	}
}
int chest::is_in_chest_alchemy(player gracz, string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] == nazwa)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int chest::find_free_alchemy_index()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] == "")
		{
			return (20 + i);
		}
	}
}
int chest::find_selected_alchemy_index(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] == nazwa)
		{
			return (20 + i);
		}
	}
}
int chest::is_in_chest_forge(player gracz, string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] == nazwa)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int chest::find_free_forge_index()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] == "")
		{
			return (40 + i);
		}
	}
}
int chest::find_selected_forge_index(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] == nazwa)
		{
			return (40 + i);
		}
	}
}
void chest::sort_usage()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (menu[j] != "")
				{
					menu[i] = menu[j];
					menu_amount[i] = menu_amount[j];
					menu[j] = "";
					menu_amount[j] = 0;
					break;
				}
			}
		}
	}
}
void chest::sort_alchemy()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (menu[20 + j] != "")
				{
					menu[20 + i] = menu[20 + j];
					menu_amount[20 + i] = menu_amount[20 + j];
					menu[20 + j] = "";
					menu_amount[20 + j] = 0;
					break;
				}
			}
		}
	}
}
void chest::sort_forge()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (menu[40 + j] != "")
				{
					menu[40 + i] = menu[40 + j];
					menu_amount[40 + i] = menu_amount[40 + j];
					menu[40 + j] = "";
					menu_amount[40 + j] = 0;
					break;
				}
			}
		}
	}
}
void chest::move_to_player(int height, int startPoint, int numer, player &gracz)
{
	vector <string> message;
	if (numer < 20)
	{
		if (gracz.count_free_fields_usage() == 0)
		{
			message.push_back("You cannot move this item to your inventory because it is full.");
		}
		else if (menu[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (menu_amount[numer] > 1)
			{
				string temp = "In the chest is more than one item of this type (" + to_string(gracz.inventory_usage_amount[numer]) + "), how many of them you want to transfer to your inventory? ";
				int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (ile<0 || ile>menu_amount[numer])
				{
					ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				menu_amount[numer] = menu_amount[numer] - ile;
				gracz.add_usage_item(menu[numer], 0,ile, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sort_usage();
				}
			}
			else
			{
				menu_amount[numer]--;
				gracz.add_usage_item(menu[numer], 0,1, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sort_usage();
				}
			}
		}
	}
	else if (numer < 40 && numer >= 20)
	{
		if (gracz.count_free_fields_alchemy() == 0)
		{
			message.push_back("You cannot move this item to your inventory because it is full.");
		}
		else if (menu[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (menu_amount[numer] > 1)
			{
				string temp = "In the chest is more than one item of this type (" + to_string(gracz.inventory_usage_amount[numer]) + "), how many of them you want to transfer to your inventory? ";
				int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (ile<0 || ile>menu_amount[numer])
				{
					ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				menu_amount[numer] = menu_amount[numer] - ile;
				gracz.add_crafting_alchemy_item(menu[numer], 0, ile, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sort_alchemy();
				}
			}
			else
			{
				menu_amount[numer]--;
				gracz.add_crafting_alchemy_item(menu[numer], 0, 1, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sort_alchemy();
				}
			}
		}
	}
	else if (numer >= 40)
	{
		if (gracz.count_free_fields_forge() == 0)
		{
			message.push_back("You cannot move this item to your inventory because it is full.");
		}
		else if (menu[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (menu_amount[numer] > 1)
			{
				string temp = "In the chest is more than one item of this type (" + to_string(gracz.inventory_usage_amount[numer]) + "), how many of them you want to transfer to your inventory? ";
				int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (ile<0 || ile>menu_amount[numer])
				{
					ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				menu_amount[numer] = menu_amount[numer] - ile;
				gracz.add_crafting_forge_item(menu[numer], 0, ile, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sort_forge();
				}
			}
			else
			{
				menu_amount[numer]--;
				gracz.add_crafting_forge_item(menu[numer], 0, 1, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sort_forge();
				}
			}
		}
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void chest::move_to_chest(int height, int startPoint, int numer, player &gracz)
{
	vector <string> message;
	if (numer < 20)
	{
		if (count_free_fields_usage() == 0)
		{
			message.push_back("You cannot move this item to the chest because the chest is full.");
		}
		else if (gracz.inventory_usage[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (is_in_chest_usage(gracz, gracz.inventory_usage[numer]) == 1)
			{
				if (gracz.inventory_usage_amount[numer] > 1)
				{
					string temp = "You have more than one item of this type (" + to_string(gracz.inventory_usage_amount[numer]) + "), how many of them you want to transfer to the chest? ";
					int ile = stoi(tabSubmenuInputField(height, startPoint,temp));
					while (ile<0 || ile>gracz.inventory_usage_amount[numer])
					{
						ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					gracz.inventory_usage_amount[numer] = gracz.inventory_usage_amount[numer] - ile;
					menu_amount[find_selected_usage_index(gracz.inventory_usage[numer])] = menu_amount[find_selected_usage_index(gracz.inventory_usage[numer])] + ile;
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sort_usage_backpack();
					}
				}
				else
				{
					gracz.inventory_usage_amount[numer]--;
					menu_amount[find_selected_usage_index(gracz.inventory_usage[numer])]++;
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sort_usage_backpack();
					}
				}
			}
			else
			{
				if (gracz.inventory_usage_amount[numer] > 1)
				{
					string temp = "You have more than one item of this type (" + to_string(gracz.inventory_usage_amount[numer]) + "), how many of them you want to transfer to the chest? ";
					int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (ile<0 || ile>gracz.inventory_usage_amount[numer])
					{
						ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					gracz.inventory_usage_amount[numer] = gracz.inventory_usage_amount[numer] - ile;
					menu_amount[find_free_usage_index()] = menu_amount[find_free_usage_index()] + ile;
					menu[find_free_usage_index()] = gracz.inventory_usage[numer];
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sort_usage_backpack();
					}
				}
				else
				{
					gracz.inventory_usage_amount[numer]--;
					menu_amount[find_free_usage_index()]++;
					menu[find_free_usage_index()] = gracz.inventory_usage[numer];
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sort_usage_backpack();
					}
				}
			}
		}
	}
	else if (numer < 40 && numer >= 20)
	{
		numer = numer - 20;
		if (count_free_fields_alchemy() == 0)
		{
			message.push_back("You cannot move this item to the chest because the chest is full.");
		}
		else if (gracz.inventory_crafting[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (is_in_chest_alchemy(gracz, gracz.inventory_crafting[numer]) == 1)
			{
				if (gracz.inventory_crafting_amount[numer] > 1)
				{
					string temp = "You have more than one item of this type (" + to_string(gracz.inventory_crafting_amount[numer]) + "), how many of them you want to transfer to the chest? ";
					int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (ile<0 || ile>gracz.inventory_crafting_amount[numer])
					{
						ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					gracz.inventory_crafting_amount[numer] = gracz.inventory_crafting_amount[numer] - ile;
					menu_amount[find_selected_alchemy_index(gracz.inventory_crafting[numer])] = menu_amount[find_selected_alchemy_index(gracz.inventory_crafting[numer])] + ile;
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sort_crafting_alchemy_backpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[numer]--;
					menu_amount[find_selected_alchemy_index(gracz.inventory_crafting[numer])]++;
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sort_crafting_alchemy_backpack();
					}
				}
			}
			else
			{
				if (gracz.inventory_crafting_amount[numer] > 1)
				{
					string temp = "You have more than one item of this type (" + to_string(gracz.inventory_crafting_amount[numer]) + "), how many of them you want to transfer to the chest? ";
					int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (ile<0 || ile>gracz.inventory_crafting_amount[numer])
					{
						ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					gracz.inventory_crafting_amount[numer] = gracz.inventory_crafting_amount[numer] - ile;
					menu_amount[find_free_alchemy_index()] = menu_amount[find_free_alchemy_index()] + ile;
					menu[find_free_alchemy_index()] = gracz.inventory_crafting[numer];
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sort_crafting_alchemy_backpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[numer]--;
					menu_amount[find_free_alchemy_index()]++;
					menu[find_free_alchemy_index()] = gracz.inventory_crafting[numer];
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sort_crafting_alchemy_backpack();
					}
				}
			}
		}
	}
	else if(numer >= 40)
	{
		numer = numer - 20;
		if (count_free_fields_forge() == 0)
		{
			message.push_back("You cannot move this item to the chest because the chest is full.");
		}
		else if (gracz.inventory_crafting[20 + numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (is_in_chest_forge(gracz, gracz.inventory_crafting[20 + numer]) == 1)
			{
				if (gracz.inventory_crafting_amount[20 + numer] > 1)
				{
					string temp = "You have more than one item of this type (" + to_string(gracz.inventory_crafting_amount[20 + numer]) + "), how many of them you want to transfer to the chest? ";
					int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (ile<0 || ile>gracz.inventory_crafting_amount[20 + numer])
					{
						ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					gracz.inventory_crafting_amount[20 + numer] = gracz.inventory_crafting_amount[20 + numer] - ile;
					menu_amount[find_selected_forge_index(gracz.inventory_crafting[20 + numer])] = menu_amount[find_selected_forge_index(gracz.inventory_crafting[20 + numer])] + ile;
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sort_crafting_forge_backpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[20 + numer]--;
					menu_amount[find_selected_forge_index(gracz.inventory_crafting[20 + numer])]++;
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sort_crafting_forge_backpack();
					}
				}
			}
			else
			{
				if (gracz.inventory_crafting_amount[20 + numer] > 1)
				{
					string temp = "You have more than one item of this type (" + to_string(gracz.inventory_crafting_amount[20 + numer]) + "), how many of them you want to transfer to the chest? ";
					int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					while (ile<0 || ile>gracz.inventory_crafting_amount[20 + numer])
					{
						ile = stoi(tabSubmenuInputField(height, startPoint, temp));
					}
					gracz.inventory_crafting_amount[20 + numer] = gracz.inventory_crafting_amount[20 + numer] - ile;
					menu_amount[find_free_forge_index()] = menu_amount[find_free_forge_index()] + ile;
					menu[find_free_forge_index()] = gracz.inventory_crafting[20 + numer];
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sort_crafting_forge_backpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[20 + numer]--;
					menu_amount[find_free_forge_index()]++;
					menu[find_free_forge_index()] = gracz.inventory_crafting[20 + numer];
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sort_crafting_forge_backpack();
					}
				}
			}
		}
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}	
}