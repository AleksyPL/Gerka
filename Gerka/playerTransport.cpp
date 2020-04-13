#include "playerTransport.h"

void savePlayerTemp(player gracz)
{
	fstream plik;
	remove("./txt/mix/player_temp_basic.txt");
	plik.open("./txt/mix/player_temp_basic.txt", ios::out);
	plik << gracz.nazwa << endl;
	plik << gracz.level << endl;
	plik << gracz.gold << endl;
	plik << gracz.hp << endl;
	plik << gracz.max_hp << endl;
	plik << gracz.str << endl;
	plik << gracz.agility << endl;
	plik << gracz.intel << endl;
	plik << gracz.charisma << endl;
	plik << gracz.luck << endl;
	plik << gracz.hunger << endl;
	plik << gracz.alko << endl;
	plik << gracz.exp << endl;
	plik << gracz.exp_to_next_level << endl;
	plik << gracz.licznik_dnia << endl;
	plik << gracz.hour << endl;
	plik << gracz.minute << endl;
	plik << gracz.quest_name << endl;
	plik << gracz.skill;
	plik.close();
	remove("./txt/mix/player_temp_eq.txt");
	plik.open("./txt/mix/player_temp_eq.txt", ios::out);
	plik << gracz.helmet << endl;
	plik << gracz.chestplate << endl;
	plik << gracz.gloves << endl;
	plik << gracz.pants << endl;
	plik << gracz.shoes << endl;
	plik << gracz.weaponDamage << endl;
	plik << gracz.weaponName << endl;
	plik << gracz.weaponPrice << endl;
	plik << gracz.isTheWeaponRare << endl;
	plik << gracz.availableWeaponUpgradePoints << endl;
	plik.close();
	remove("./txt/mix/player_temp_backpack.txt");
	plik.open("./txt/mix/player_temp_backpack.txt", ios::out);
	for (int i = 0; i < 20; i++)
	{
		plik << gracz.inventory_usage[i] << endl << gracz.inventory_usage_amount[i] << endl;
	}
	for (int i = 0; i < 40; i++)
	{
		plik << gracz.inventory_crafting[i] << endl << gracz.inventory_crafting_amount[i] << endl;
	}
	gracz.sortUsageBackpack();
	gracz.sortCraftingAlchemyBackpack();
	gracz.sortCraftingSmitheryBackpack();
	plik.close();
}
void loadPlayerTemp(player& gracz)
{
	string linia;
	fstream plik;
	int nr_linii = 0;
	plik.open("./txt/mix/player_temp_basic.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:gracz.nazwa = linia; break;
		case 1:gracz.level = atoi(linia.c_str()); break;
		case 2:gracz.gold = atoll(linia.c_str()); break;
		case 3:gracz.hp = atoi(linia.c_str()); break;
		case 4:gracz.max_hp = atoi(linia.c_str()); break;
		case 5:gracz.str = atoi(linia.c_str()); break;
		case 6:gracz.agility = atoi(linia.c_str()); break;
		case 7:gracz.intel = atoi(linia.c_str()); break;
		case 8:gracz.charisma = atoi(linia.c_str()); break;
		case 9:gracz.luck = atoi(linia.c_str()); break;
		case 10:gracz.hunger = atoi(linia.c_str()); break;
		case 11:gracz.alko = atoi(linia.c_str()); break;
		case 12:gracz.exp = atoi(linia.c_str()); break;
		case 13:gracz.exp_to_next_level = atoi(linia.c_str()); break;
		case 14:gracz.licznik_dnia = atoi(linia.c_str()); break;
		case 15:gracz.hour = atoi(linia.c_str()); break;
		case 16:gracz.minute = atoi(linia.c_str()); break;
		case 17:gracz.quest_name = linia; break;
		case 18:gracz.skill = linia; break;
		}
		nr_linii++;
	}
	plik.close();
	nr_linii = 0;
	plik.open("./txt/mix/player_temp_eq.txt", ios::in);
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 0:gracz.helmet = atoi(linia.c_str()); break;
		case 1:gracz.chestplate = atoi(linia.c_str()); break;
		case 2:gracz.gloves = atoi(linia.c_str()); break;
		case 3:gracz.pants = atoi(linia.c_str()); break;
		case 4:gracz.shoes = atoi(linia.c_str()); break;
		case 5:gracz.weaponDamage = atoi(linia.c_str()); break;
		case 6:gracz.weaponName = linia; break;
		case 7:gracz.weaponPrice = atoi(linia.c_str()); break;
		case 8:
		{
			linia = stringToLower(linia);
			if (linia == "true")
			{
				gracz.isTheWeaponRare = true;
			}
			else
			{
				gracz.isTheWeaponRare = false;
			}
			break;
		}
		case 9:gracz.availableWeaponUpgradePoints = atoi(linia.c_str()); break;
		}
		nr_linii++;
	}
	plik.close();
	nr_linii = 0;
	plik.open("./txt/mix/player_temp_backpack.txt", ios::in);
	while (getline(plik, linia))
	{
		if (nr_linii < 40)
		{
			if (nr_linii % 2 == 0)
			{
				gracz.inventory_usage[nr_linii / 2] = linia;
			}
			else
			{
				gracz.inventory_usage_amount[nr_linii / 2] = atoi(linia.c_str());
			}
		}
		else if (nr_linii >= 40 && nr_linii <80)
		{
			if (nr_linii % 2 == 0)
			{
				gracz.inventory_crafting[(nr_linii / 2) - 20] = linia;
			}
			else
			{
				gracz.inventory_crafting_amount[(nr_linii / 2) - 20] = atoi(linia.c_str());
			}
		}
		else
		{
			if (nr_linii % 2 == 0)
			{
				gracz.inventory_crafting[(nr_linii / 2) - 20] = linia;
			}
			else
			{
				gracz.inventory_crafting_amount[(nr_linii / 2) - 20] = atoi(linia.c_str());
			}
		}
		nr_linii++;
	}
	plik.close();
	gracz.sortUsageBackpack();
	gracz.sortCraftingAlchemyBackpack();
	gracz.sortCraftingSmitheryBackpack();
	remove("./txt/mix/player_temp_basic.txt");
	remove("./txt/mix/player_temp_eq.txt");
	remove("./txt/mix/player_temp_backpack.txt");
}