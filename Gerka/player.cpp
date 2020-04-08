#include "player.h"
#include "tabelka.h"

player::player()
{
	nazwa = "";
	str = 5;
	hp = 50;
	max_hp = hp;
	agility = 5;
	intel = 5;
	luck = 5;
	charisma = 5;
	level = 1;
	exp = 0;
	exp_to_next_level = 100;
	gold = 0;
	licznik_dnia = 1;
	alko = 0;
	hour = 6;
	minute = 0;
	helmet = 0;
	chestplate = 0;
	gloves = 0;
	pants = 0;
	shoes = 0;
	weaponDamage = 1;
	weaponName = "Fists";
	isTheWeaponRare = false;
	weaponPrice = 0;
	skill = "";
	hunger = 10;
	pseudonym = "";
	counter_nerf_str = 0;
	counter_boost_str = 0;
	before_nerf_str = 0;
	before_boost_str = 0;
	counter_nerf_agility = 0;
	counter_boost_agility = 0;
	before_nerf_agility = 0;
	before_boost_agility = 0;
	counter_nerf_intel = 0;
	counter_boost_intel = 0;
	before_nerf_intel = 0;
	before_boost_intel = 0;
	counter_nerf_luck = 0;
	counter_boost_luck = 0;
	before_nerf_luck = 0;
	before_boost_luck = 0;
	counter_nerf_charisma = 0;
	counter_boost_charisma = 0;
	before_nerf_charisma = 0;
	before_boost_charisma = 0;
	quest_name = "";
	quest_id = "";
	quest_complete = 0;
	quest_failed = 0;
	fight_complete = 0;
	fight_failed = 0;
	last_dungeon = 0;
	for (int i = 0; i < 20; i++)
	{
		inventory_usage[i] = "";
		inventory_usage_amount[i] = 0;
		inventory_usage_price[i] = 0;
		inventory_crafting[i] = "";
		inventory_crafting[20 + i] = "";
		inventory_crafting_amount[i] = 0;
		inventory_crafting_amount[20 + i] = 0;
		inventory_crafting_price[i] = 0;
		inventory_crafting_price[20 + i] = 0;
	}
}
void player::aBitSober()
{
	alko = alko - 1;
	if (alko < 0)
	{
		alko = 0;
	}
}
void player::aBitHungry(int height, int startPoint, int number)
{
	hunger = hunger - number;
	if (hunger<0)
	{
		hunger = 0;
	}
	if (hunger == 0)
	{
		hp = hp - 10;
		soundDamage();
		vector <string> message = { "You are hungry, you have to eat something." };
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
bool player::findUsageItem(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_usage[i] == nazwa)
		{
			return true;
		}
		else if (inventory_usage[i] != nazwa)
		{
			continue;
		}
	}
	return false;
}
bool player::findCraftingAlchemyItem(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] == nazwa)
		{
			return true;
		}
		else if (inventory_crafting[i] != nazwa)
		{
			continue;
		}
	}
	return false;
}
bool player::findCraftingForgeItem(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[20 + i] == nazwa)
		{
			return true;
		}
		else if (inventory_crafting[20 + i] != nazwa)
		{
			continue;
		}
	}
	return false;
}
int player::findUsageItemIndex(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_usage[i] == nazwa)
		{
			return i;
		}
	}
}
int player::findCraftingAlchemyItemIndex(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] == nazwa)
		{
			return i;
		}
	}
}
int player::findCraftingForgeItemIndex(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[20 + i] == nazwa)
		{
			return i;
		}
	}
}
bool player::dropItem(int height, int startPoint, string item)
{
	int index = -1;
	if (findItemOnList(item) == "Usable")
	{
		index = findUsageItemIndex(item);
		if (inventory_usage_amount[index] > 0)
		{
			inventory_usage_amount[index] = inventory_usage_amount[index] - 1;
			soundDropItem();
			vector <string> message = { "You are dropping one " + item };
			tabSubmenuTextOnly(height, startPoint, message);
			if (inventory_usage_amount[index] == 0)
			{
				inventory_usage[index] = "";
				sortUsageBackpack();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (findItemOnList(item) == "Alchemy")
	{
		index = findCraftingAlchemyItemIndex(item);
		if (inventory_crafting_amount[index] > 0)
		{
			inventory_crafting_amount[index] = inventory_crafting_amount[index] - 1;
			soundDropItem();
			vector <string> message = { "You are dropping one " + item };
			tabSubmenuTextOnly(height, startPoint, message);
			if (inventory_crafting_amount[index] == 0)
			{
				inventory_crafting[index] = "";
				sortCraftingAlchemyBackpack();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (findItemOnList(item) == "Smithery")
	{
		index = findCraftingForgeItemIndex(item);
		if (inventory_crafting_amount[20 + index] > 0)
		{
			inventory_crafting_amount[20 + index] = inventory_crafting_amount[20 + index] - 1;
			soundDropItem();
			vector <string> message = { "You are dropping one " + item };
			tabSubmenuTextOnly(height, startPoint, message);
			if (inventory_crafting_amount[20 + index] == 0)
			{
				inventory_crafting[20 + index] = "";
				sortCraftingForgeBackpack();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool player::removeItemWithoutNotification(string item)
{
	int index = -1;
	if (findItemOnList(item) == "Usable")
	{
		index = findUsageItemIndex(item);
		if (inventory_usage_amount[index] > 0)
		{
			inventory_usage_amount[index] = inventory_usage_amount[index] - 1;
			if (inventory_usage_amount[index] == 0)
			{
				inventory_usage[index] = "";
				sortUsageBackpack();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (findItemOnList(item) == "Alchemy")
	{
		index = findCraftingAlchemyItemIndex(item);
		if (inventory_crafting_amount[index] > 0)
		{
			inventory_crafting_amount[index] = inventory_crafting_amount[index] - 1;
			if (inventory_crafting_amount[index] == 0)
			{
				inventory_crafting[index] = "";
				sortCraftingAlchemyBackpack();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (findItemOnList(item) == "Smithery")
	{
		index = findCraftingForgeItemIndex(item);
		if (inventory_crafting_amount[20 + index] > 0)
		{
			inventory_crafting_amount[20 + index] = inventory_crafting_amount[20 + index] - 1;
			if (inventory_crafting_amount[20 + index] == 0)
			{
				inventory_crafting[20 + index] = "";
				sortCraftingForgeBackpack();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
void player::useItem(int height, int startPoint, string item, string message)
{
	vector <string> temp = { message };
	int index = findUsageItemIndex(item);
	tabSubmenuTextOnly(height, startPoint, temp);
	inventory_usage_amount[index] = inventory_usage_amount[index] - 1;
	if (inventory_usage_amount[index] == 0)
	{
		inventory_usage[index] = "";
		sortUsageBackpack();
	}
}
void player::addUsageItem(string nazwa, int cena, int ilosc, int height, int startPoint, int skipBackpackChecking)
{
	if (skipBackpackChecking == 1)
	{
		for (int i = 0; i < 20; i++)
		{
			if (inventory_usage[i] == nazwa)
			{
				gold = gold - cena;
				inventory_usage_amount[i] = inventory_usage_amount[i] + ilosc;
				break;
			}
			else if (inventory_usage[i] == "")
			{
				gold = gold - cena;
				inventory_usage[i] = nazwa;
				inventory_usage_amount[i] = ilosc;
				break;
			}
		}
	}
	else
	{
		vector <string> message;
		if (countFreeFieldsUsage() == 0)
		{
			message.push_back("You cannot take this item, your backpack is full.");
			tabSubmenuTextOnly(height, startPoint, message);
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_usage[i] == nazwa)
				{
					gold = gold - cena;
					inventory_usage_amount[i] = inventory_usage_amount[i] + ilosc;
					break;
				}
				else if (inventory_usage[i] == "")
				{
					gold = gold - cena;
					inventory_usage[i] = nazwa;
					inventory_usage_amount[i] = ilosc;
					break;
				}
			}
		}
	}
	sortUsageBackpack();
}
void player::addCraftingAlchemyItem(string nazwa, int cena, int ilosc, int height, int startPoint, int skipBackpackChecking)
{
	if (skipBackpackChecking == 1)
	{
		for (int i = 0; i < 20; i++)
		{
			if (inventory_crafting[i] == nazwa)
			{
				gold = gold - cena;
				inventory_crafting_amount[i] = inventory_crafting_amount[i] + ilosc;
				break;
			}
			else if (inventory_crafting[i] == "")
			{
				gold = gold - cena;
				inventory_crafting[i] = nazwa;
				inventory_crafting_amount[i] = ilosc;
				break;
			}
		}
	}
	else
	{
		vector <string> message;
		if (countFreeFieldsAlchemy() == 0)
		{
			message.push_back("You cannot take this item, your backpack is full.");
			tabSubmenuTextOnly(height, startPoint, message);
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_crafting[i] == nazwa)
				{
					gold = gold - cena;
					inventory_crafting_amount[i] = inventory_crafting_amount[i] + ilosc;
					break;
				}
				else if (inventory_crafting[i] == "")
				{
					gold = gold - cena;
					inventory_crafting[i] = nazwa;
					inventory_crafting_amount[i] = ilosc;
					break;
				}
			}
		}
	}
}
void player::addCraftingForgeItem(string nazwa, int cena, int ilosc, int height, int startPoint, int skipBackpackChecking)
{
	if (skipBackpackChecking == 1)
	{
		for (int i = 0; i < 20; i++)
		{
			if (inventory_crafting[20 + i] == nazwa)
			{
				gold = gold - cena;
				inventory_crafting_amount[20 + i] = inventory_crafting_amount[20 + i] + ilosc;
				break;
			}
			else if (inventory_crafting[20 + i] == "")
			{
				gold = gold - cena;
				inventory_crafting[20 + i] = nazwa;
				inventory_crafting_amount[20 + i] = ilosc;
				break;
			}
		}
	}
	else
	{
		vector <string> message;
		if (countFreeFieldsForge() == 0)
		{
			message.push_back("You cannot take this item, your backpack is full.");
			tabSubmenuTextOnly(height, startPoint, message);
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (inventory_crafting[20 + i] == nazwa)
				{
					gold = gold - cena;
					inventory_crafting_amount[20 + i] = inventory_crafting_amount[20 + i] + ilosc;
					break;
				}
				else if (inventory_crafting[20 + i] == "")
				{
					gold = gold - cena;
					inventory_crafting[20 + i] = nazwa;
					inventory_crafting_amount[20 + i] = ilosc;
					break;
				}
			}
		}
	}
}
void player::removeUsageItem(int height, int startPoint, string item, int amount)
{
	int i=findUsageItemIndex(item);
	if (amount > inventory_usage_amount[i])
	{
		string temp = "You want to delete more items than you have, enter the correct amount: ";
		amount = stoi(tabSubmenuInputField(height, startPoint, temp));
		while (amount<=0 || amount>inventory_usage_amount[i])
		{
			amount = stoi(tabSubmenuInputField(height, startPoint, temp));
		}
	}
	inventory_usage_amount[i] = inventory_usage_amount[i] - amount;
	if (inventory_usage_amount[i] == 0)
	{
		inventory_usage[i] = "";
		inventory_usage_price[i] = 0;
		sortUsageBackpack();
	}
}
void player::sortUsageBackpack()
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_usage[i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (inventory_usage[j] != "")
				{
					inventory_usage[i] = inventory_usage[j];
					inventory_usage_amount[i] = inventory_usage_amount[j];
					inventory_usage_price[i] = inventory_usage_price[j];
					inventory_usage[j] = "";
					inventory_usage_amount[j] = 0;
					inventory_usage_price[j] = 0;
					break;
				}
			}
		}
	}
}
void player::sortCraftingAlchemyBackpack()
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (inventory_crafting[j] != "")
				{
					inventory_crafting[i] = inventory_crafting[j];
					inventory_crafting_amount[i] = inventory_crafting_amount[j];
					inventory_crafting_price[i] = inventory_crafting_price[j];
					inventory_crafting[j] = "";
					inventory_crafting_amount[j] = 0;
					inventory_crafting_price[j] = 0;
					break;
				}
			}
		}
	}
}
void player::sortCraftingForgeBackpack()
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] != "")
		{
			continue;
		}
		else
		{
			for (int j = i + 1; j < 20; j++)
			{
				if (inventory_crafting[j] != "")
				{
					inventory_crafting[20 + i] = inventory_crafting[20 + j];
					inventory_crafting_amount[20 + i] = inventory_crafting_amount[20 + j];
					inventory_crafting_price[20 + i] = inventory_crafting_price[20 + j];
					inventory_crafting[20 + j] = "";
					inventory_crafting_amount[20 + j] = 0;
					inventory_crafting_price[20 + j] = 0;
					break;
				}
			}
		}
	}
}
int player::countFreeFieldsUsage()
{
	int counter = 0;
	for (int i = 0; i < 20; i++)
	{
		if (inventory_usage[i] == "")
		{
			counter++;
		}
	}
	return counter;
}
int player::countFreeFieldsAlchemy()
{
	int counter = 0;
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] == "")
		{
			counter++;
		}
	}
	return counter;
}
int player::countFreeFieldsForge()
{
	int counter = 0;
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[20 + i] == "")
		{
			counter++;
		}
	}
	return counter;
}
void player::addQuest(string nazwa,string id)
{
	quest_name = nazwa;
	quest_id = id;
	quest_complete = 0;
	quest_failed = 0;

}
void player::removeQuest()
{
	quest_name = "";
	quest_id = "";
	quest_complete = 0;
	quest_failed = 0;
}
void player::resetFightStatus()
{
	fight_complete = 0;
	fight_failed = 0;
}
int player::returnChancesOfDealingDamage()
{
	int chances = 0;
	if (weaponName == "Fists")
	{
		chances = (int)(agility * str * 0.5);
	}
	else if (weaponName == "Sword")
	{
		chances = (int)(agility * str * 0.7);
	}
	else if (weaponName == "Axe")
	{
		chances = (int)(agility * str * 0.4);
	}
	else if (weaponName == "Mace")
	{
		chances = (int)(agility * str * 0.7);
	}
	else if (weaponName == "Hammer")
	{
		chances = (int)(agility * str * 0.4);
	}
	else if (weaponName == "Knife")
	{
		chances = (int)(agility * str * 0.5);
	}
	else if (weaponName == "Spear")
	{
		chances = (int)(agility * str * 0.8);
	}
	if (chances > 99)
	{
		chances = 99;
	}
	return chances;
}
int player::returnChancesOfGettingHit()
{
	int chances = 99;
	if (this->hp == this->max_hp)
	{
		chances = 0.1 * agility;
	}
	else
	{
		chances = (1 - (hp / max_hp)) * agility;
	}
	if (chances > 99)
	{
		chances = 99;
	}
	return chances;
}