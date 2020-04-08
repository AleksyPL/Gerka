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
int dweller::goldInfo()
{
	return this->gold;
}
int dweller::repLevelInfo()
{
	return this->rep_level;
}
int dweller::repPointsInfo()
{
	return this->rep_points;
}
int dweller::repPointsToNextLevelInfo()
{
	return this->rep_points_to_next_level;
}
string dweller::questIDInfo()
{
	return this->quest_id;
}
int dweller::goldForCompleteQuestInfo()
{
	return this->gold_for_complete_quest;
}
int dweller::expForCompleteQuestInfo()
{
	return this->exp_for_complete_quest;
}
string dweller::nameInfo()
{
	return this->name;
}
void dweller::goldSet(int a)
{
	this->gold = a;
}
void dweller::repLevelSet(int a)
{
	this->rep_level = a;
}
void dweller::repPointsSet(int a)
{
	this->rep_points = a;
}
void dweller::repPointsToNextLevelSet(int a)
{
	this->rep_points_to_next_level = a;
}
void dweller::questIDSet(string a)
{
	this->quest_id = a;
}
void dweller::goldForCompleteQuestSet(int a)
{
	this->gold_for_complete_quest = a;
}
void dweller::expForCompleteQuestSet(int a)
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
void dweller::rejectQuestGiving(int height, int startPoint)
{
	vector <string> message = { "You're already doing some task" };
	soundRejection();
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
	int gossipNumber = rand() % 9;
	string linia;
	int nr_linii = 1;
	fstream plik;
	vector<string> message;
	string path = "./txt/tawerna/plota" + to_string(gossipNumber) + ".txt";
	plik.open(path, ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	tabSubmenuFancyTextOnly(height, startPoint, message,50);
	changeTime(height, startPoint, gracz, 0, 1);
}
void barman::giveRoom(int height, int startPoint, player &gracz)
{
	if (gracz.hunger >= 5)
	{
		vector<string> message;
		if (gracz.gold >= ceny[1])
		{
			message.push_back("The barman leads you to the free room");
			changeTime(height, startPoint, gracz, 0, 5);
			sleep(gracz, ceny[1], 8, 0, height, startPoint,message);
		}
		else
		{
			message.push_back(noMoney());
		}
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void barman::sellFood(int height, int startPoint, player &gracz, int ilosc)
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
			gracz.hp += (int)(0.01*gracz.max_hp);
			if (gracz.hp > gracz.max_hp)
			{
				gracz.hp = gracz.max_hp;
			}
			if (gracz.hunger > 10)
			{
				gracz.hunger = 10;
			}
			changeTime(height, startPoint, gracz, 0, 10);
		}
		else
		{
			message.push_back(noMoney());
		}
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
void barman::sellBeer(int height, int startPoint, player &gracz)
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
		soundBeer();
		gracz.alko = gracz.alko + 1;
		changeTime(height, startPoint, gracz, 0, 10, 0, 1);
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
		message.push_back(noMoney());
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
void seller::loadItems(string path)
{
	for (int i = 0; i < 20; i++)
	{
		this->itemName[i] = "";
	}
	string linia;
	fstream plik;
	int nr_linii = 1;
	if (path != "")
	{
		plik.open(path, ios::in);
		while (getline(plik, linia))
		{
			this->itemName[nr_linii - 1] = linia;
			nr_linii++;
		}
		plik.close();
	}
}
int seller::loadPrices(string item, string path)
{
	for (int i = 0; i < 20; i++)
	{
		itemPrice[i] = 0;
	}
	string linia;
	fstream plik;
	int nr_linii = 1;
	int price = 0;
	plik.open(path, ios::in);
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
string seller::makeString(int howLong, string item, int amount, int price, bool skipPrice)
{
	string price_string = "";
	string amount_string = "";
	string temp = "";
	if (skipPrice == false)
	{
		if (price <= 0)
		{
			price_string = "[WORTHLESS]";
		}
		else
		{
			price_string = "[" + to_string(price) + " GOLD]";
		}
	}
	if (amount > 1)
	{
		amount_string = " x" + to_string(amount);
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
generalStoreSeller::generalStoreSeller()
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
	menu[0] = "Trade items";
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
		this->itemName[i] = "";
		this->itemPrice[i] = 0;
	}
}
void generalStoreSeller::buyItem(int height, int startPoint, player& gracz, string item, int amount, int price, bool &anythingSoldOrBought)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (item != "" && findItemOnList(item) == "Usable" && amount != 0)
	{
		if (gracz.countFreeFieldsUsage() !=0)
		{
			if (price > gracz.gold)
			{
				message.push_back("You don't have enough gold to buy " + item);
			}
			else
			{
				gracz.addUsageItem(item,price,amount,height,startPoint);
				gold += price;
				soundCash();
			}
		}
		else
		{
			message.push_back("Your backpack is full");
		}
	}
	else if (item != "" && findItemOnList(item) == "Alchemy" && amount != 0)
	{
		if (gracz.countFreeFieldsAlchemy() != 0)
		{
			if (price > gracz.gold)
			{
				message.push_back("You don't have enough gold to buy " + item);
			}
			else
			{
				gracz.addCraftingAlchemyItem(item, price, amount, height, startPoint);
				gold += price;
				soundCash();
			}
		}
		else
		{
			message.push_back("Your backpack is full");
		}
	}
	else if (item != "" && findItemOnList(item) == "Smithery" && amount != 0)
	{
		if (gracz.countFreeFieldsForge() != 0)
		{
			if (price > gracz.gold)
			{
				message.push_back("You don't have enough gold to buy " + item);
			}
			else
			{
				gracz.addCraftingForgeItem(item, price, amount, height, startPoint);
				gold += price;
				soundCash();
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
void generalStoreSeller::sellItem(int height, int startPoint, player &gracz, string item, int amount, int price, bool &anythingSoldOrBought)
{
	vector <string> message;
	vector <string> options = {"Yes","No"};
	int priceForItems = 0;
	if (item != "" && gracz.findUsageItem(item) == 1 && amount != 0)
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
				int index = gracz.findUsageItemIndex(item);
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
						gracz.sortUsageBackpack();
					}
					else
					{
						gracz.inventory_usage_amount[index] -= amountWritten;
					}
					gracz.gold += (__int64)price * amountWritten;
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
							gracz.sortUsageBackpack();
						}
						else
						{
							gracz.inventory_usage_amount[index] -= amount;
						}
						gracz.gold += (__int64)price * amount;
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
				int index = gracz.findUsageItemIndex(item);
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
						gracz.sortUsageBackpack();
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
						gracz.sortUsageBackpack();
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
	else if (item != "" && gracz.findCraftingAlchemyItem(item) == 1 && amount != 0)
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
			int index = gracz.findCraftingAlchemyItemIndex(item);
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
					gracz.sortCraftingAlchemyBackpack();
				}
				else
				{
					gracz.inventory_crafting_amount[index] -= amountWritten;
				}
				gracz.gold += (__int64)price * amountWritten;
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
						gracz.sortCraftingAlchemyBackpack();
					}
					else
					{
						gracz.inventory_crafting_amount[index] -= amount;
					}
					gracz.gold += (__int64)price * amount;
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
			int index = gracz.findCraftingAlchemyItemIndex(item);
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
					gracz.sortCraftingAlchemyBackpack();
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
					gracz.sortCraftingAlchemyBackpack();
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
	else if(item != "" && gracz.findCraftingForgeItem(item) == 1 && amount != 0)
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
			int index = gracz.findCraftingForgeItemIndex(item);
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
					gracz.sortCraftingForgeBackpack();
				}
				else
				{
					gracz.inventory_crafting_amount[20 + index] -= amountWritten;
				}
				gracz.gold += (__int64)price * amountWritten;
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
						gracz.sortCraftingForgeBackpack();
					}
					else
					{
						gracz.inventory_crafting_amount[20 + index] -= amount;
					}
					gracz.gold += (__int64)price * amount;
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
			int index = gracz.findCraftingForgeItemIndex(item);
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
					gracz.sortCraftingForgeBackpack();
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
					gracz.sortCraftingForgeBackpack();
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
blacksmith::blacksmith()
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
}
void blacksmith::loadPlayerPoints(player gracz)
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
	this->menu[5] = menu[5] + " (" + to_string(gracz.weaponDamage) + ")";
	this->ceny[5] = ceny[5] + (100 * gracz.weaponDamage);
}
void blacksmith::printImage(vector <string>& message)
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
	soundBlacksmith();
}
void blacksmith::powerUp(int height, int startPoint, player &gracz, int tryb)
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
			printImage(message);
			gracz.helmet ++;
			gracz.gold -= ceny[0];
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
		break;
	}
	case 1:
	{
		if (gracz.gold >= ceny[1])
		{
			message.push_back("The chestplate has been strengthened");
			message.push_back("");
			printImage(message);
			gracz.chestplate ++;
			gracz.gold -= ceny[1];
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
		break;
	}
	case 2:
	{
		if (gracz.gold >= ceny[2])
		{
			message.push_back("The gloves have been strengthened");
			message.push_back("");
			printImage(message);
			gracz.gloves ++;
			gracz.gold -= ceny[2];
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
		break;
	}
	case 3:
	{
		if (gracz.gold >= ceny[3])
		{
			message.push_back("The pants have been strengthened");
			message.push_back("");
			printImage(message);
			gracz.pants ++;
			gracz.gold -= ceny[3];
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
		break;
	}
	case 4:
	{
		if (gracz.gold >= ceny[4])
		{
			message.push_back("The shoes have been strengthened");
			message.push_back("");
			printImage(message);
			gracz.shoes ++;
			gracz.gold -= ceny[4];
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
		break;
	}
	case 5:
	{
		if (gracz.gold >= ceny[5])
		{
			message.push_back("The weapon (" + gracz.weaponName + ") have been strengthened");
			message.push_back("");
			printImage(message);
			gracz.weaponDamage ++;
			gracz.gold -= ceny[5];
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
		break;
	}
	}
	tabSubmenuTextOnly(23, 32, message);
}
bladesmith::bladesmith()
{
	name = "Bladesmith";
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
	menu[0] = "Trade items";
	menu[1] = "Upgrade weapon";
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
		this->itemName[i] = "";
		this->itemPrice[i] = 0;
		weaponsDamage[i] = 0;
		weaponsRarity[i] = false;
	}
	string linia;
	fstream plik;
	int nr_linii = 1;
	string path = "./txt/bladesmith/weapons.txt";
	plik.open(path, ios::in);
	while (getline(plik, linia))
	{
		this->weaponNames.push_back(linia);
		nr_linii++;
	}
	plik.close();
}
void bladesmith::generateMerch(player gracz)
{
	loadItems("./txt/bladesmith/weapons.txt");
	int weaponsBorder = 20;
	for (int i = 0; i < 20; i++)
	{
		if (itemName[i] == "")
		{
			weaponsBorder--;
		}
	}
	for (int i = 0; i < weaponsBorder; i++)
	{
		int isLegendary = rand() % 100;
		itemPrice[i] = 20;
		if (isLegendary < 5)
		{
			weaponsRarity[i] = true;
			weaponsDamage[i] = (gracz.level * 10);
			itemPrice[i] += gracz.level * 20 + 20;
		}
		else
		{
			weaponsRarity[i] = false;
			int pomoc = rand() % 3;
			if (pomoc == 0)
			{
				weaponsDamage[i] = gracz.level * 5;
				itemPrice[i] += gracz.level * 10;
			}
			else if (pomoc == 1)
			{
				int pomoc2 = rand() % 2;
				if (pomoc2 == 0)
				{
					weaponsDamage[i] = (gracz.level * 5) - 1;
					itemPrice[i] += (gracz.level * 10) - 5;
				}
				else if (pomoc2 == 1)
				{
					weaponsDamage[i] = (gracz.level * 5) + 1;
					itemPrice[i] += (gracz.level * 10) + 5;
				}
			}
			else if (pomoc == 2)
			{
				int pomoc2 = rand() % 4;
				if (pomoc2 == 0)
				{
					weaponsDamage[i] = (gracz.level * 5) - 2;
					itemPrice[i] += (gracz.level * 10) - 10;
				}
				else if (pomoc2 == 1)
				{
					weaponsDamage[i] = (gracz.level * 5) - 1;
					itemPrice[i] += (gracz.level * 10) - 5;
				}
				else if (pomoc2 == 2)
				{
					weaponsDamage[i] = (gracz.level * 5) + 1;
					itemPrice[i] += (gracz.level * 10) + 5;
				}
				else if (pomoc2 == 3)
				{
					weaponsDamage[i] = (gracz.level * 5) + 2;
					itemPrice[i] += (gracz.level * 10) + 10;
				}
			}
		}
	}
}
void bladesmith::upgradeWeapon(int height, int startPoint, player& gracz)
{
	if (gracz.weaponName == "Fists")
	{
		vector <string> message = {"You don't have a weapon to upgrade."};
		tabSubmenuTextOnly(height, startPoint, message);
	}
	else
	{

	}
}
void bladesmith::printImage(vector <string>& message)
{
	string linia;
	fstream plik;
	plik.open("./txt/bladesmith/image.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		message.push_back(linia);
	}
	plik.close();
	soundBlacksmith();
}
void bladesmith::buyItem(int height, int startPoint, player& gracz, int index)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (itemName[index] == "Unavable")
	{
		message.push_back("You cannot buy this weapon.");
	}
	else if (gracz.weaponName != "Fists")
	{
		message.push_back("You already have a weapon, you have to sell the first.");
	}
	else if (gracz.gold >= itemPrice[index] && gracz.weaponName == "Fists")
	{
		if (weaponsRarity[index] == true)
		{
			string temp = "[RARE]" + itemName[index] + "(" + to_string(weaponsDamage[index]) + ")";
			message.push_back("Do you want to buy " + temp + " for " + to_string(itemPrice[index]) + " gold?");
		}
		else
		{
			string temp = itemName[index] + "(" + to_string(weaponsDamage[index]) + ")";
			message.push_back("Do you want to buy " + temp + " for " + to_string(itemPrice[index]) + " gold?");
		}
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			gracz.gold -= itemPrice[index];
			gracz.weaponName = itemName[index];
			if (weaponsRarity[index] == true)
			{
				gracz.isTheWeaponRare = true;
			}
			gracz.weaponDamage = weaponsDamage[index];
			gracz.weaponPrice = (int)(0.8 * itemPrice[index]);
			soundCash();
			itemName[index] = "Unavable";
			itemPrice[index] = 0;
			weaponsDamage[index] = 0;
			weaponsRarity[index] = false;
		}
		message.clear();
	}
	else
	{
		message.push_back("You don't have enough gold to buy " + itemName[index]);
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void bladesmith::sellItem(int height, int startPoint, player& gracz)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if ((std::find(weaponNames.begin(), weaponNames.end(), gracz.weaponName) != weaponNames.end()) && gracz.weaponDamage > 0)
	{
		if (goldInfo() > gracz.weaponPrice)
		{
			if (gracz.weaponName == "Fists")
			{
				message.push_back("You have nothing to sell.");
			}
			else
			{
				if (gracz.isTheWeaponRare == true)
				{
					string temp = "[RARE]" + gracz.weaponName + "(" + to_string(gracz.weaponPrice) + ")";
					message.push_back("Do you want to sell " + temp + " for " + to_string(gracz.weaponPrice) + " gold?");
				}
				else
				{
					string temp = gracz.weaponName + "(" + to_string(gracz.weaponPrice) + ")";
					message.push_back("Do you want to sell " + temp + " for " + to_string(gracz.weaponPrice) + " gold?");
				}
				int hightlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (hightlight == 0)
				{
					soundCash();
					gracz.gold += gracz.weaponPrice;
					gracz.weaponName = "Fists";
					gracz.weaponDamage = 1;
					gracz.weaponPrice = 0;
					gracz.isTheWeaponRare = false;
				}
				message.clear();
			}
		}
		else
		{
			if (gracz.isTheWeaponRare == true)
			{
				message.push_back(name + " does not have enough gold to buy [RARE]" + gracz.weaponName + " from you.");
			}
			else
			{
				message.push_back(name + " does not have enough gold to buy " + gracz.weaponName + " from you.");
			}
		}
		if (message.size() != 0)
		{
			tabSubmenuTextOnly(height, startPoint, message);
		}
	}
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
void alchemist::showImage(vector <string> &message)
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
	soundAlchemy();
}
void alchemist::buyNewLevelPotion(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.gold > ((__int64)gracz.level * 100))
	{
		message.push_back("You bought a level up potion");
		message.push_back("");
		gracz.addUsageItem("Mikstura nowego poziomu", (gracz.level * 100), 23,32,1);
		changeTime(height, startPoint, gracz, 0, 5);
		showImage(message);
	}
	else
	{
		message.push_back(noMoney());
	}
	tabSubmenuTextOnly(height,startPoint,message);
}
void alchemist::buyHpPotion(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.gold > ceny[1])
	{
		message.push_back("You bought a health points potion");
		message.push_back("");
		gracz.addUsageItem("Mikstura ¿ycia", ceny[1], 23,32, 1);
		changeTime(height, startPoint, gracz, 0, 5);
		showImage(message);
	}
	else
	{
		message.push_back(noMoney());
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
void shaman::showImage(vector <string> &message)
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
	soundShaman();
}
void shaman::addBoost(int height, int startPoint, player &gracz, int tryb)
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
				addBoostStrenght(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[0];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(noMoney());
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
				addBoostAgility(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[1];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(noMoney());
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
				addBoostIntelligence(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[2];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(noMoney());
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
				addBoostCharisma(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[3];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(noMoney());
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
				addBoostLuck(gracz, 24, 1);
				gracz.gold = gracz.gold - ceny[4];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 15);
			}
			else
			{
				message.push_back(noMoney());
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
int shaman::dialogBox(int height, int startPoint)
{
	vector <string> message = {"Could you do that for me?"};
	vector <string> options = {"Yes","No"};
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	return highlight;
}
void shaman::everythingAboutQuests(int height, int startPoint, player &gracz)
{
	vector <string> message;
	if (gracz.quest_name == "" && gracz.quest_id == "")
	{
		if (questIDInfo() == "s00")
		{
			goldForCompleteQuestSet(1000);
			expForCompleteQuestSet(100);
			message.push_back("To make a magic amulet I need three human teeth.");
			message.push_back("I will give you 1000 gold if you bring me them.");
			tabSubmenuFancyTextOnly(height, startPoint, message, 50);
			if (dialogBox(height,startPoint) == 0)
			{
				gracz.addQuest("Zdob¹dŸ trzy ludzkie zêby", "s00");
			}
			else
			{
				message.clear();
				message.push_back("Well, maybe someone else will come forward.");
				tabSubmenuFancyTextOnly(height, startPoint, message, 50);
			}
		}
	}
	else if(gracz.quest_name != "" && gracz.quest_id !=questIDInfo())
	{
		rejectQuestGiving(height,startPoint);
	}
	else if (gracz.quest_name != "" && gracz.quest_id == questIDInfo())
	{
		if (gracz.quest_complete == 1 && gracz.quest_failed == 0)
		{
			if (questIDInfo() == "s00")
			{
				message.clear();
				message.push_back("Thank you, this is your gold.");
				tabSubmenuFancyTextOnly(height, startPoint, message, 50);
				gracz.removeUsageItem(height,startPoint,"Ludzki z¹b",3);
				questIDSet("s01");
			}
			gracz.gold = gracz.gold + this->goldForCompleteQuestInfo();
			this->goldForCompleteQuestSet(0);
			gracz.exp = gracz.exp + this->expForCompleteQuestInfo();
			this->expForCompleteQuestSet(0);
			gracz.removeQuest();
		}
		else if(gracz.quest_complete == 0 && gracz.quest_failed == 1)
		{
			message.clear();
			message.push_back("You didn't make it this time but you can try again");
			tabSubmenuFancyTextOnly(height, startPoint, message, 50);
			gracz.removeQuest();
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
	menu[0] = "Ask for medical attention";
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
void doctor::showImage(vector <string>& message)
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
	soundHealUp;
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
			showImage(message);
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
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
			showImage(message);
			changeTime(height, startPoint, gracz, 1, 0);
		}
		else
		{
			message.push_back(noMoney());
		}
	}
	else
	{
		message.push_back("You are sober");
	}
	tabSubmenuTextOnly(height, startPoint, message);
}
void doctor::removeNerf(int height, int startPoint, player &gracz, int tryb)
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
				removeNerfStrenght(gracz);
				gracz.gold = gracz.gold - ceny[2];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(noMoney());
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
				removeNerfAgility(gracz);
				gracz.gold = gracz.gold - ceny[3];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(noMoney());
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
				removeNerfIntelligence(gracz);
				gracz.gold = gracz.gold - ceny[4];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(noMoney());
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
				removeNerfCharisma(gracz);
				gracz.gold = gracz.gold - ceny[5];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(noMoney());
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
				removeNerfLuck(gracz);
				gracz.gold = gracz.gold - ceny[6];
				showImage(message);
				changeTime(height, startPoint, gracz, 0, 30);
			}
			else
			{
				message.push_back(noMoney());
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
		this->menu[i] = "";
		this->menu_amount[i] = 0;
	}
}
int chest::countFreeFieldsUsage()
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
int chest::countFreeFieldsAlchemy()
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
int chest::countFreeFieldsForge()
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
int chest::isInChestUsage(player gracz,string nazwa)
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
int chest::findFreeUsageIndex()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] == "")
		{
			return i;
		}
	}
}
int chest::findSelectedUsageIndex(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] == nazwa)
		{
			return i;
		}
	}
}
int chest::isInChestAlchemy(player gracz, string nazwa)
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
int chest::findFreeAlchemyIndex()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] == "")
		{
			return (20 + i);
		}
	}
}
int chest::findSelectedAlchemyIndex(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[20 + i] == nazwa)
		{
			return (20 + i);
		}
	}
}
int chest::isInChestForge(player gracz, string nazwa)
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
int chest::findFreeForgeIndex()
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] == "")
		{
			return (40 + i);
		}
	}
}
int chest::findSelectedForgeIndex(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (menu[40 + i] == nazwa)
		{
			return (40 + i);
		}
	}
}
void chest::sortUsage()
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
void chest::sortAlchemy()
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
void chest::sortForge()
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
void chest::moveToPlayer(int height, int startPoint, int numer, player &gracz)
{
	vector <string> message;
	if (numer < 20)
	{
		if (gracz.countFreeFieldsUsage() == 0)
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
				gracz.addUsageItem(menu[numer], 0,ile, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sortUsage();
				}
			}
			else
			{
				menu_amount[numer]--;
				gracz.addUsageItem(menu[numer], 0,1, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sortUsage();
				}
			}
		}
	}
	else if (numer < 40 && numer >= 20)
	{
		if (gracz.countFreeFieldsAlchemy() == 0)
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
				string temp = "In the chest is more than one item of this type (" + to_string(gracz.inventory_usage_amount[numer - 40]) + "), how many of them you want to transfer to your inventory? ";
				int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (ile<0 || ile>menu_amount[numer])
				{
					ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				menu_amount[numer] = menu_amount[numer] - ile;
				gracz.addCraftingAlchemyItem(menu[numer], 0, ile, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sortAlchemy();
				}
			}
			else
			{
				menu_amount[numer]--;
				gracz.addCraftingAlchemyItem(menu[numer], 0, 1, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sortAlchemy();
				}
			}
		}
	}
	else if (numer >= 40)
	{
		if (gracz.countFreeFieldsForge() == 0)
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
				string temp = "In the chest is more than one item of this type (" + to_string(gracz.inventory_usage_amount[40 - numer]) + "), how many of them you want to transfer to your inventory? "; 
				int ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				while (ile<0 || ile>menu_amount[numer])
				{
					ile = stoi(tabSubmenuInputField(height, startPoint, temp));
				}
				menu_amount[numer] = menu_amount[numer] - ile;
				gracz.addCraftingForgeItem(menu[numer], 0, ile, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sortForge();
				}
			}
			else
			{
				menu_amount[numer]--;
				gracz.addCraftingForgeItem(menu[numer], 0, 1, height, startPoint, 1);
				if (menu_amount[numer] == 0)
				{
					menu[numer] = "";
					sortForge();
				}
			}
		}
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void chest::moveToChest(int height, int startPoint, int numer, player &gracz)
{
	vector <string> message;
	if (numer < 20)
	{
		if (countFreeFieldsUsage() == 0)
		{
			message.push_back("You cannot move this item to the chest because the chest is full.");
		}
		else if (gracz.inventory_usage[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (isInChestUsage(gracz, gracz.inventory_usage[numer]) == 1)
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
					menu_amount[findSelectedUsageIndex(gracz.inventory_usage[numer])] = menu_amount[findSelectedUsageIndex(gracz.inventory_usage[numer])] + ile;
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sortUsageBackpack();
					}
				}
				else
				{
					gracz.inventory_usage_amount[numer]--;
					menu_amount[findSelectedUsageIndex(gracz.inventory_usage[numer])]++;
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sortUsageBackpack();
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
					menu_amount[findFreeUsageIndex()] = menu_amount[findFreeUsageIndex()] + ile;
					menu[findFreeUsageIndex()] = gracz.inventory_usage[numer];
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sortUsageBackpack();
					}
				}
				else
				{
					gracz.inventory_usage_amount[numer]--;
					menu_amount[findFreeUsageIndex()]++;
					menu[findFreeUsageIndex()] = gracz.inventory_usage[numer];
					if (gracz.inventory_usage_amount[numer] == 0)
					{
						gracz.inventory_usage[numer] = "";
						gracz.inventory_usage_price[numer] = 0;
						gracz.sortUsageBackpack();
					}
				}
			}
		}
	}
	else if (numer < 40 && numer >= 20)
	{
		numer = numer - 20;
		if (countFreeFieldsAlchemy() == 0)
		{
			message.push_back("You cannot move this item to the chest because the chest is full.");
		}
		else if (gracz.inventory_crafting[numer] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (isInChestAlchemy(gracz, gracz.inventory_crafting[numer]) == 1)
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
					menu_amount[findSelectedAlchemyIndex(gracz.inventory_crafting[numer])] = menu_amount[findSelectedAlchemyIndex(gracz.inventory_crafting[numer])] + ile;
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sortCraftingAlchemyBackpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[numer]--;
					menu_amount[findSelectedAlchemyIndex(gracz.inventory_crafting[numer])]++;
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sortCraftingAlchemyBackpack();
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
					menu_amount[findFreeAlchemyIndex()] = menu_amount[findFreeAlchemyIndex()] + ile;
					menu[findFreeAlchemyIndex()] = gracz.inventory_crafting[numer];
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sortCraftingAlchemyBackpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[numer]--;
					menu_amount[findFreeAlchemyIndex()]++;
					menu[findFreeAlchemyIndex()] = gracz.inventory_crafting[numer];
					if (gracz.inventory_crafting_amount[numer] == 0)
					{
						gracz.inventory_crafting[numer] = "";
						gracz.inventory_crafting_price[numer] = 0;
						gracz.sortCraftingAlchemyBackpack();
					}
				}
			}
		}
	}
	else if(numer >= 40)
	{
		numer -= 40;
		if (countFreeFieldsForge() == 0)
		{
			message.push_back("You cannot move this item to the chest because the chest is full.");
		}
		else if (gracz.inventory_crafting[numer+20] == "")
		{
			message.push_back("No item");
		}
		else
		{
			if (isInChestForge(gracz, gracz.inventory_crafting[20 + numer]) == 1)
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
					menu_amount[findSelectedForgeIndex(gracz.inventory_crafting[20 + numer])] = menu_amount[findSelectedForgeIndex(gracz.inventory_crafting[20 + numer])] + ile;
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sortCraftingForgeBackpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[20 + numer]--;
					menu_amount[findSelectedForgeIndex(gracz.inventory_crafting[20 + numer])]++;
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sortCraftingForgeBackpack();
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
					menu_amount[findFreeForgeIndex()] = menu_amount[findFreeForgeIndex()] + ile;
					menu[findFreeForgeIndex()] = gracz.inventory_crafting[20 + numer];
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sortCraftingForgeBackpack();
					}
				}
				else
				{
					gracz.inventory_crafting_amount[20 + numer]--;
					menu_amount[findFreeForgeIndex()]++;
					menu[findFreeForgeIndex()] = gracz.inventory_crafting[20 + numer];
					if (gracz.inventory_crafting_amount[20 + numer] == 0)
					{
						gracz.inventory_crafting[20 + numer] = "";
						gracz.inventory_crafting_price[20 + numer] = 0;
						gracz.sortCraftingForgeBackpack();
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