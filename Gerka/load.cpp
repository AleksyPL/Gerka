#include "load.h"

void loadGame(player &gracz, barman &bobby, generalStoreSeller &handlarz, blacksmith &kowal, alchemist &alchemik, chest &krzynka)
{
string linia;
fstream plik;
int nr_linii = 1;
plik.open("./txt/mix/Zapis_gry_basic.txt", ios::in);
while (getline(plik, linia))
{
	switch (nr_linii)
	{
	case 2:gracz.nazwa = linia; break;
	case 4:gracz.level = atoi(linia.c_str()); break;
	case 6:gracz.gold = atoll(linia.c_str()); break;
	case 8:gracz.hp = atoi(linia.c_str()); break;
	case 10:gracz.max_hp = atoi(linia.c_str()); break;
	case 12:gracz.str = atoi(linia.c_str()); break;
	case 14:gracz.agility = atoi(linia.c_str()); break;
	case 16:gracz.intel = atoi(linia.c_str()); break;
	case 18:gracz.charisma = atoi(linia.c_str()); break;
	case 20:gracz.luck = atoi(linia.c_str()); break;
	case 22:gracz.hunger = atoi(linia.c_str()); break;
	case 24:gracz.alko = atoi(linia.c_str()); break;
	case 26:gracz.exp = atoi(linia.c_str()); break;
	case 28:gracz.exp_to_next_level = atoi(linia.c_str()); break;
	case 30:gracz.licznik_dnia = atoi(linia.c_str()); break;
	case 32:gracz.hour = atoi(linia.c_str()); break;
	case 34:gracz.minute = atoi(linia.c_str()); break;
	case 36:gracz.quest_name = linia; break;
	case 38:gracz.skill = linia; break;
	}
	nr_linii++;
}
plik.close();
nr_linii = 1;
plik.open("./txt/mix/Zapis_gry_eq.txt", ios::in);
while (getline(plik, linia))
{
	switch (nr_linii)
	{
	case 2:gracz.helmet = atoi(linia.c_str()); break;
	case 4:gracz.chestplate = atoi(linia.c_str()); break;
	case 6:gracz.gloves = atoi(linia.c_str()); break;
	case 8:gracz.pants = atoi(linia.c_str()); break;
	case 10:gracz.shoes = atoi(linia.c_str()); break;
	case 12:gracz.weaponDamage = atoi(linia.c_str()); break;
	case 14:gracz.weaponName = linia; break;
	case 16:gracz.weaponPrice= atoi(linia.c_str()); break;
	case 18:
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
	case 20:gracz.availableWeaponUpgradePoints = atoi(linia.c_str()); break;
	}
	nr_linii++;
}
plik.close();
nr_linii = 0;
plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::in);
while (getline(plik, linia))
{
	if (nr_linii < 60)
	{
		if (nr_linii % 3 == 1)
		{
			gracz.inventory_usage[nr_linii / 3] = linia;
		}
		else if (nr_linii % 3 == 2)
		{
			gracz.inventory_usage_amount[nr_linii / 3] = atoi(linia.c_str());
		}
	}
	else if (nr_linii >= 60 && nr_linii < 120)
	{
		if (nr_linii % 3 == 1)
		{
			gracz.inventory_crafting[(nr_linii / 3) - 20] = linia;
		}
		else if (nr_linii % 3 == 2)
		{
			gracz.inventory_crafting_amount[(nr_linii / 3) - 20] = atoi(linia.c_str());
		}
	}
	else if (nr_linii >= 120)
	{
		if (nr_linii % 3 == 1)
		{
			gracz.inventory_crafting[(nr_linii / 3) - 20] = linia;
		}
		else if (nr_linii % 3 == 2)
		{
			gracz.inventory_crafting_amount[(nr_linii / 3) - 20] = atoi(linia.c_str());
		}
	}
	nr_linii++;
}
plik.close();
gracz.sortUsageBackpack();
gracz.sortCraftingAlchemyBackpack();
gracz.sortCraftingSmitheryBackpack();
nr_linii = 1;
plik.open("./txt/mix/Zapis_gry_npc.txt", ios::in);
while (getline(plik, linia))
{
	switch (nr_linii)
	{
	case 2:bobby.repLevelSet(atoi(linia.c_str())); break;
	case 4:bobby.repPointsSet(atoi(linia.c_str())); break;
	case 6:bobby.repPointsToNextLevelSet(atoi(linia.c_str())); break;
	case 8:bobby.goldSet(atoi(linia.c_str())); break;
	case 10:handlarz.repLevelSet(atoi(linia.c_str())); break;
	case 12:handlarz.repPointsSet(atoi(linia.c_str())); break;
	case 14:handlarz.repPointsToNextLevelSet(atoi(linia.c_str())); break;
	case 16:handlarz.goldSet(atoi(linia.c_str())); break;
	case 18:kowal.repLevelSet(atoi(linia.c_str())); break;
	case 20:kowal.repPointsSet(atoi(linia.c_str())); break;
	case 22:kowal.repPointsToNextLevelSet(atoi(linia.c_str())); break;
	case 24:kowal.goldSet(atoi(linia.c_str())); break;
	case 26:alchemik.repLevelSet(atoi(linia.c_str())); break;
	case 28:alchemik.repPointsSet(atoi(linia.c_str())); break;
	case 30:alchemik.repPointsToNextLevelSet(atoi(linia.c_str())); break;
	case 32:alchemik.goldSet(atoi(linia.c_str())); break;
	}
	nr_linii++;
}
plik.close();
nr_linii = 1;
plik.open("./txt/mix/Zapis_gry_boost.txt", ios::in);
while (getline(plik, linia))
{
	switch (nr_linii)
	{
	case 2:gracz.counter_nerf_str = atoi(linia.c_str()); break;
	case 4:gracz.before_nerf_str = atoi(linia.c_str()); break;
	case 6:gracz.counter_boost_str = atoi(linia.c_str()); break;
	case 8:gracz.before_boost_str = atoi(linia.c_str()); break;
	case 10:gracz.counter_nerf_agility = atoi(linia.c_str()); break;
	case 12:gracz.before_nerf_agility = atoi(linia.c_str()); break;
	case 14:gracz.counter_boost_agility = atoi(linia.c_str()); break;
	case 16:gracz.before_boost_agility = atoi(linia.c_str()); break;
	case 18:gracz.counter_nerf_intel = atoi(linia.c_str()); break;
	case 20:gracz.before_nerf_intel = atoi(linia.c_str()); break;
	case 22:gracz.counter_boost_intel = atoi(linia.c_str()); break;
	case 24:gracz.before_boost_intel = atoi(linia.c_str()); break;
	case 26:gracz.counter_nerf_charisma = atoi(linia.c_str()); break;
	case 28:gracz.before_nerf_charisma = atoi(linia.c_str()); break;
	case 30:gracz.counter_boost_charisma = atoi(linia.c_str()); break;
	case 32:gracz.before_boost_charisma = atoi(linia.c_str()); break;
	case 34:gracz.counter_nerf_luck = atoi(linia.c_str()); break;
	case 36:gracz.before_nerf_luck = atoi(linia.c_str()); break;
	case 38:gracz.counter_boost_luck = atoi(linia.c_str()); break;
	case 40:gracz.before_boost_luck = atoi(linia.c_str()); break;
	}
	nr_linii++;
}
plik.close();
nr_linii = 0;
plik.open("./txt/mix/Zapis_gry_chest.txt", ios::in);
while (getline(plik, linia))
{
	if (nr_linii % 3 == 1)
	{
		krzynka.menu[nr_linii / 3] = linia;
	}
	else if (nr_linii % 3 == 2)
	{
		krzynka.menu_amount[nr_linii / 3] = atoi(linia.c_str());
	}
	nr_linii++;
}
plik.close();
}