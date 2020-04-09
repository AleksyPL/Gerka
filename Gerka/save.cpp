#include "save.h"
#include "tabelka.h"

void save(int height, int startPoint, player gracz,barman bobby,generalStoreSeller handlarz,blacksmith kowal, alchemist alchemik, chest krzynka)
{
	vector <string> message;
	vector <string> options;
	message.push_back("Are you sure you want to save the gameplay?");
	options.push_back("Yes");
	options.push_back("No");
	int highlight2 = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	switch (highlight2)
	{
	case 0:
	{
		fstream plik;
		remove("./txt/mix/Zapis_gry_basic.txt");
		plik.open("./txt/mix/Zapis_gry_basic.txt", ios::out);
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
		remove("./txt/mix/Zapis_gry_eq.txt");
		plik.open("./txt/mix/Zapis_gry_eq.txt", ios::out);
		plik << "Helmet points" << endl << gracz.helmet << endl;//1-2
		plik << "Chestplate points" << endl << gracz.chestplate << endl;//3-4
		plik << "Gloves points" << endl << gracz.gloves << endl;//5-6
		plik << "Pants points" << endl << gracz.pants << endl;//7-8
		plik << "Shoes points" << endl << gracz.shoes << endl;//9-10
		plik << "Weapon damage" << endl << gracz.weaponDamage << endl;//11-12
		plik << "Weapon name" << endl << gracz.weaponName << endl;//13-14
		plik << "Weapon price" << endl << gracz.weaponPrice << endl;//15-16
		plik << "Is the weapon rare?" << endl << gracz.isTheWeaponRare;//17-18
		plik.close();
		remove("./txt/mix/Zapis_gry_backpack.txt");
		plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::out);
		for (int i = 0; i++; i < 20)
		{
			plik << "Usable item number " + (i+1) << endl << gracz.inventory_usage[i] << endl << gracz.inventory_usage_amount[i] << endl;
		}
		for (int i = 0; i++; i < 20)
		{
			plik << "Crafing item - alchemy number " + (i+1) << endl << gracz.inventory_crafting[i] << endl << gracz.inventory_crafting_amount[i] << endl;
		}
		for (int i = 0; i++; i < 20)
		{
			plik << "Crafing item - smithery number " + (i+1) << endl << gracz.inventory_crafting[20 + i] << endl << gracz.inventory_crafting_amount[20 + i] << endl;
		}
		plik.close();
		gracz.sortUsageBackpack();
		gracz.sortCraftingAlchemyBackpack();
		gracz.sortCraftingForgeBackpack();
		remove("./txt/mix/Zapis_gry_npc.txt");
		plik.open("./txt/mix/Zapis_gry_npc.txt", ios::out);
		plik << "Barman - reputation level" << endl << bobby.repLevelInfo() << endl;//1-2
		plik << "Barman - reputation points" << endl << bobby.repPointsInfo() << endl;//3-4
		plik << "Barman - reputation points to the next level" << endl << bobby.repPointsToNextLevelInfo() << endl;//5-6
		plik << "Barman - gold" << endl << bobby.goldInfo() << endl;//7-8
		plik << "Merchant - reputation level" << endl << handlarz.repLevelInfo() << endl;//9-10
		plik << "Merchant - reputation points" << endl << handlarz.repPointsInfo() << endl;//11-12
		plik << "Merchant - reputation points to the next level" << endl << handlarz.repPointsToNextLevelInfo() << endl;//13-14
		plik << "Merchant - gold" << endl << handlarz.goldInfo() << endl;//15-16
		plik << "Blacksmith - reputation level" << endl << kowal.repLevelInfo() << endl;//17-18
		plik << "Blacksmith - reputation points" << endl << kowal.repPointsInfo() << endl;//19-20
		plik << "Blacksmith - reputation points to the next level" << endl << kowal.repPointsToNextLevelInfo() << endl;//21-22
		plik << "Blacksmith - gold" << endl << kowal.goldInfo() << endl;//23-24
		plik << "Alchemist - reputation level" << endl << alchemik.repLevelInfo() << endl;//25-26
		plik << "Alchemist - reputation points" << endl << alchemik.repPointsInfo() << endl;//27-28
		plik << "Alchemist - reputation points to the next level" << endl << alchemik.repPointsToNextLevelInfo() << endl;//29-30
		plik << "Alchemist - gold" << endl << alchemik.goldInfo();//31-32
		plik.close();
		remove("./txt/mix/Zapis_gry_boost.txt");
		plik.open("./txt/mix/Zapis_gry_boost.txt", ios::out);
		plik << "Strength weakness - counter" << endl << gracz.counter_nerf_str << endl;//1-2
		plik << "Strength weakness - before effect" << endl << gracz.before_nerf_str << endl;//3-4
		plik << "Strength boost - counter" << endl << gracz.counter_boost_str << endl;//5-6
		plik << "Strength boost - before effect" << endl << gracz.before_boost_str << endl;//7-8
		plik << "Agility weakness - counter" << endl << gracz.counter_nerf_agility << endl;//9-10
		plik << "Agility weakness - before effect" << endl << gracz.before_nerf_agility << endl;//11-12
		plik << "Agility boost - counter" << endl << gracz.counter_boost_agility << endl;//13-14
		plik << "Agility boost - before effect" << endl << gracz.before_boost_agility << endl;//15-16
		plik << "Inteligence weakness - counter" << endl << gracz.counter_nerf_intel << endl;//17-18
		plik << "Inteligence weakness - before effect" << endl << gracz.before_nerf_intel << endl;//19-20
		plik << "Inteligence boost - counter" << endl << gracz.counter_boost_intel << endl;//21-22
		plik << "Inteligence boost - before effect" << endl << gracz.before_boost_intel << endl;//23-24
		plik << "Charisma weakness - counter" << endl << gracz.counter_nerf_charisma << endl;//25-26
		plik << "Charisma weakness - before effect" << endl << gracz.before_nerf_charisma << endl;//27-28
		plik << "Charisma boost - counter" << endl << gracz.counter_boost_charisma << endl;//29-30
		plik << "Charisma boost - before effect" << endl << gracz.before_boost_charisma << endl;//31-32
		plik << "Luck weakness - counter" << endl << gracz.counter_nerf_luck << endl;//33-34
		plik << "Luck weakness - before effect" << endl << gracz.before_nerf_luck << endl;//35-36
		plik << "Luck boost - counter" << endl << gracz.counter_boost_luck << endl;//37-38
		plik << "Luck boost - before effect" << endl << gracz.before_boost_luck << endl;//39-40
		
		plik.close();
		remove("./txt/mix/Zapis_gry_chest.txt");
		plik.open("./txt/mix/Zapis_gry_chest.txt", ios::out);
		for (int i = 0; i < 20; i++)
		{
			plik << "Usable item number " + (i+1) << endl << krzynka.menu[i] << endl << krzynka.menu_amount[i] << endl;
		}
		for (int i = 0; i < 20; i++)
		{
			plik << "Crafing item - alchemy number " + (i+1) << endl << krzynka.menu[20 + i] << endl << krzynka.menu_amount[20 + i] << endl;
		}
		for (int i = 0; i < 20; i++)
		{
			plik << "Crafing item - smithery number " + (i+1) << endl << krzynka.menu[40 + i] << endl << krzynka.menu_amount[40 + i] << endl;
		}
		plik.close();
		krzynka.sortUsage();
		krzynka.sortAlchemy();
		krzynka.sortForge();
		message.clear();
		message.push_back("Your gameplay has been saved");
		tabSubmenuTextOnly(height, startPoint, message);
		break;
	}
	case 1:
	{
		message.clear();
		message.push_back("Your gameplay has not been saved");
		tabSubmenuTextOnly(height, startPoint, message);
		break;
	}
	default:
	{
		break;
	}
	break;
	}
}