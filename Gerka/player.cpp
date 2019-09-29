#include "player.h"

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
	exp_to_next_level = 1000;
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
	weapon = 1;
	weapon_name = "PIʌCI";
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
void player::a_bit_sober()
{
	alko = alko - 1;
	if (alko < 0)
	{
		alko = 0;
	}
}
void player::a_bit_hungry(int number)
{
	hunger = hunger - number;
	if (hunger<0)
	{
		hunger = 0;
	}
	if (hunger == 0)
	{
		hp = hp - 10;
		sound_damage();
		cout << "Jeste� g�odyny, musisz co� zje��!!!" << endl;
	}
}
int player::find_usage_item(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_usage[i] == nazwa)
		{
			return 1;
		}
		else if (inventory_usage[i] != nazwa)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
}
int player::find_crafting_alchemy_item(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] == nazwa)
		{
			return 1;
		}
		else if (inventory_crafting[i] != nazwa)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
}
int player::find_crafting_forge_item(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[20 + i] == nazwa)
		{
			return 1;
		}
		else if (inventory_crafting[20 + i] != nazwa)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
}
int player::find_usage_item_index(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_usage[i] == nazwa)
		{
			return i;
		}
	}
}
int player::find_crafting_alchemy_item_index(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[i] == nazwa)
		{
			return i;
		}
	}
}
int player::find_crafting_forge_item_index(string nazwa)
{
	for (int i = 0; i < 20; i++)
	{
		if (inventory_crafting[20 + i] == nazwa)
		{
			return i;
		}
	}
}
void player::drop_item(string nazwa, string ending)
{
	int index = find_usage_item_index(nazwa);
	if (inventory_usage_amount[index] > 0)
	{
		inventory_usage_amount[index] =inventory_usage_amount[index] - 1;
		sound_drop_item();
		cout << endl << "Wyrzucasz jedn" << ending << endl;
		system("PAUSE");
		if (inventory_usage_amount[index] == 0)
		{
			inventory_usage[index] = "";
			sort_usage_backpack();
		}
	}
	else
	{
		cout << endl << "Nie ma czego wyrzuca�" << endl;
		system("PAUSE");
	}
}
void player::use_item(string nazwa, string komunikat)
{
	int index = find_usage_item_index(nazwa);
	cout << endl << komunikat << endl;
	system("PAUSE");
	inventory_usage_amount[index] = inventory_usage_amount[index] - 1;
	if (inventory_usage_amount[index] == 0)
	{
		inventory_usage[index] = "";
		sort_usage_backpack();
	}
}
void player::add_usage_item(string nazwa, int cena, int ilosc, int tryb)
{
	if (tryb == 1)
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
		if (count_free_fields_usage() == 0)
		{
			cout << "TW�J PLECAK JEST PE�EN, NIE MO�ESZ WZI�� TEGO PRZEDMIOTU" << endl;
			system("PAUSE");
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
}
void player::add_crafting_alchemy_item(string nazwa, int cena, int ilosc, int tryb)
{
	if (tryb == 1)
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
		if (count_free_fields_alchemy() == 0)
		{
			cout << "TW�J PLECAK JEST PE�EN, NIE MO�ESZ WZI�� TEGO PRZEDMIOTU" << endl;
			system("PAUSE");
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
void player::add_crafting_forge_item(string nazwa, int cena, int ilosc, int tryb)
{
	if (tryb == 1)
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
		if (count_free_fields_forge() == 0)
		{
			cout << "TW�J PLECAK JEST PE�EN, NIE MO�ESZ WZI�� TEGO PRZEDMIOTU" << endl;
			system("PAUSE");
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
void player::remove_usage_item(string nazwa, int ilosc)
{
	int i=find_usage_item_index(nazwa);
	if (ilosc > inventory_usage_amount[i])
	{
		cout << "Chcesz usun�� za du�o przedmiot�w" << endl;
		cout << "Podaj ilo��: ";
		cin >> ilosc;
		while (cin.fail() || ilosc<0 || ilosc>inventory_usage_amount[i])
		{
			cout << "Podaj ilo��: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> ilosc;
		}
	}
	inventory_usage_amount[i] = inventory_usage_amount[i] - ilosc;
	if (inventory_usage_amount[i] == 0)
	{
		inventory_usage[i] = "";
		inventory_usage_price[i] = 0;
		sort_usage_backpack();
	}
}
void player::sort_usage_backpack()
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
void player::sort_crafting_alchemy_backpack()
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
void player::sort_crafting_forge_backpack()
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
int player::count_free_fields_usage()
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
int player::count_free_fields_alchemy()
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
int player::count_free_fields_forge()
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
void player::add_quest(string nazwa,string id)
{
	quest_name = nazwa;
	quest_id = id;
	quest_complete = 0;
	quest_failed = 0;

}
void player::remove_quest()
{
	quest_name = "";
	quest_id = "";
	quest_complete = 0;
	quest_failed = 0;
}
