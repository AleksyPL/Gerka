#include "playerTransport.h"

void savePlayerTemp(player gracz)
{
	fstream plik;
	remove("./txt/mix/player_temp_basic.txt");
	plik.open("./txt/mix/player_temp_basic.txt", ios::out);
	plik << "Character name" << endl << gracz.nazwa << endl;//1-2
	plik << "Character level" << endl << gracz.level << endl;//3-4
	plik << "Gold" << endl << gracz.gold << endl;//5-6
	plik << "Health points" << endl << gracz.hp << endl;//7-8
	plik << "Max health points" << endl << gracz.max_hp << endl;//9-10
	plik << "Strength level" << endl << gracz.str << endl;//11-12
	plik << "Agility level" << endl << gracz.agility << endl;//13-14
	plik << "Inteligence level" << endl << gracz.intel << endl;//15-16
	plik << "Charisma level" << endl << gracz.charisma << endl;//17-18
	plik << "Luck level" << endl << gracz.luck << endl;//19-20
	plik << "Nutrition points" << endl << gracz.hunger << endl;//21-22
	plik << "Drunk level" << endl << gracz.alko << endl;//23-24
	plik << "Experience points" << endl << gracz.exp << endl;//25-26
	plik << "Experience points to the next level" << endl << gracz.exp_to_next_level << endl;//27-28
	plik << "Day counter" << endl << gracz.licznik_dnia << endl;//29-30
	plik << "Day hour" << endl << gracz.hour << endl;//31-32
	plik << "Day minute" << endl << gracz.minute << endl;//33-34
	plik << "Quest" << endl << gracz.quest_name << endl;//35-36
	plik << "Character skill" << endl << gracz.skill;//37-38
	plik.close();
	remove("./txt/mix/player_temp_eq.txt");
	plik.open("./txt/mix/player_temp_eq.txt", ios::out);
	plik << "Helmet points" << endl << gracz.helmet << endl;//1-2
	plik << "Chestplate points" << endl << gracz.chestplate << endl;//3-4
	plik << "Gloves points" << endl << gracz.gloves << endl;//5-6
	plik << "Pants points" << endl << gracz.pants << endl;//7-8
	plik << "Shoes points" << endl << gracz.shoes << endl;//9-10
	plik << "Weapon damage" << endl << gracz.weaponDamage << endl;//11-12
	plik << "Weapon name" << endl << gracz.weaponName << endl;//13-14
	plik << "Weapon price" << endl << gracz.weaponPrice << endl;//15-16
	plik << "Is the weapon rare?" << endl << gracz.isTheWeaponRare << endl;//17-18
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
	gracz.sortCraftingForgeBackpack();
	plik.close();
}
void loadPlayerTemp(player& gracz)
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	plik.open("./txt/mix/player_temp_basic.txt", ios::in);
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
	plik.open("./txt/mix/player_temp_eq.txt", ios::in);
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
		case 16:gracz.weaponPrice = atoi(linia.c_str()); break;
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
				gracz.inventory_crafting[(nr_linii / 2) - 40] = linia;
			}
			else
			{
				gracz.inventory_crafting_amount[(nr_linii / 2) - 40] = atoi(linia.c_str());
			}
		}
		nr_linii++;
	}
	plik.close();
	gracz.sortUsageBackpack();
	gracz.sortCraftingAlchemyBackpack();
	gracz.sortCraftingForgeBackpack();
	remove("./txt/mix/player_temp_basic.txt");
	remove("./txt/mix/player_temp_eq.txt");
	//remove("./txt/mix/player_temp_backpack.txt");
}