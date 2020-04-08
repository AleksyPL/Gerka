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
		plik << "Weapon name" << endl << gracz.weaponName;//13-14
		plik << "Weapon price" << endl << gracz.weaponPrice;//15-16
		plik << "Is the weapon rare?" << endl << gracz.isTheWeaponRare;//17-18
		plik.close();
		remove("./txt/mix/Zapis_gry_backpack.txt");
		gracz.sortUsageBackpack();
		gracz.sortCraftingAlchemyBackpack();
		gracz.sortCraftingForgeBackpack();
		plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::out);
		plik << "Usable item number 1" << endl << gracz.inventory_usage[0] << endl << gracz.inventory_usage_amount[0] << endl;//1-3
		plik << "Usable item number 2" << endl << gracz.inventory_usage[1] << endl << gracz.inventory_usage_amount[1] << endl;//4-6
		plik << "Usable item number 3" << endl << gracz.inventory_usage[2] << endl << gracz.inventory_usage_amount[2] << endl;//7-9
		plik << "Usable item number 4" << endl << gracz.inventory_usage[3] << endl << gracz.inventory_usage_amount[3] << endl;//10-12
		plik << "Usable item number 5" << endl << gracz.inventory_usage[4] << endl << gracz.inventory_usage_amount[4] << endl;//13-15
		plik << "Usable item number 6" << endl << gracz.inventory_usage[5] << endl << gracz.inventory_usage_amount[5] << endl;//16-18
		plik << "Usable item number 7" << endl << gracz.inventory_usage[6] << endl << gracz.inventory_usage_amount[6] << endl;//19-21
		plik << "Usable item number 8" << endl << gracz.inventory_usage[7] << endl << gracz.inventory_usage_amount[7] << endl;//22-24
		plik << "Usable item number 9" << endl << gracz.inventory_usage[8] << endl << gracz.inventory_usage_amount[8] << endl;//25-27
		plik << "Usable item number 10" << endl << gracz.inventory_usage[9] << endl << gracz.inventory_usage_amount[9] << endl;//28-30
		plik << "Usable item number 11" << endl << gracz.inventory_usage[10] << endl << gracz.inventory_usage_amount[10] << endl;//31-33
		plik << "Usable item number 12" << endl << gracz.inventory_usage[11] << endl << gracz.inventory_usage_amount[11] << endl;//34-36
		plik << "Usable item number 13" << endl << gracz.inventory_usage[12] << endl << gracz.inventory_usage_amount[12] << endl;//37-39
		plik << "Usable item number 14" << endl << gracz.inventory_usage[13] << endl << gracz.inventory_usage_amount[13] << endl;//40-42
		plik << "Usable item number 15" << endl << gracz.inventory_usage[14] << endl << gracz.inventory_usage_amount[14] << endl;//43-45
		plik << "Usable item number 16" << endl << gracz.inventory_usage[15] << endl << gracz.inventory_usage_amount[15] << endl;//46-48
		plik << "Usable item number 17" << endl << gracz.inventory_usage[16] << endl << gracz.inventory_usage_amount[16] << endl;//49-51
		plik << "Usable item number 18" << endl << gracz.inventory_usage[17] << endl << gracz.inventory_usage_amount[17] << endl;//52-54
		plik << "Usable item number 19" << endl << gracz.inventory_usage[18] << endl << gracz.inventory_usage_amount[18] << endl;//55-57
		plik << "Usable item number 20" << endl << gracz.inventory_usage[19] << endl << gracz.inventory_usage_amount[19] << endl;//58-60
		plik << "Crafing item - alchemy number 1" << endl << gracz.inventory_crafting[0] << endl << gracz.inventory_crafting_amount[0] << endl;//61-63
		plik << "Crafing item - alchemy number 2" << endl << gracz.inventory_crafting[1] << endl << gracz.inventory_crafting_amount[1] << endl;//64-66
		plik << "Crafing item - alchemy number 3" << endl << gracz.inventory_crafting[2] << endl << gracz.inventory_crafting_amount[2] << endl;//67-69
		plik << "Crafing item - alchemy number 4" << endl << gracz.inventory_crafting[3] << endl << gracz.inventory_crafting_amount[3] << endl;//70-72
		plik << "Crafing item - alchemy number 5" << endl << gracz.inventory_crafting[4] << endl << gracz.inventory_crafting_amount[4] << endl;//73-75
		plik << "Crafing item - alchemy number 6" << endl << gracz.inventory_crafting[5] << endl << gracz.inventory_crafting_amount[5] << endl;//76-78
		plik << "Crafing item - alchemy number 7" << endl << gracz.inventory_crafting[6] << endl << gracz.inventory_crafting_amount[6] << endl;//79-80
		plik << "Crafing item - alchemy number 8" << endl << gracz.inventory_crafting[7] << endl << gracz.inventory_crafting_amount[7] << endl;//82-84
		plik << "Crafing item - alchemy number 9" << endl << gracz.inventory_crafting[8] << endl << gracz.inventory_crafting_amount[8] << endl;//85-87
		plik << "Crafing item - alchemy number 10" << endl << gracz.inventory_crafting[9] << endl << gracz.inventory_crafting_amount[9] << endl;//88-90
		plik << "Crafing item - alchemy number 11" << endl << gracz.inventory_crafting[10] << endl << gracz.inventory_crafting_amount[10] << endl;//91-92
		plik << "Crafing item - alchemy number 12" << endl << gracz.inventory_crafting[11] << endl << gracz.inventory_crafting_amount[11] << endl;//94-96
		plik << "Crafing item - alchemy number 13" << endl << gracz.inventory_crafting[12] << endl << gracz.inventory_crafting_amount[12] << endl;//97-99
		plik << "Crafing item - alchemy number 14" << endl << gracz.inventory_crafting[13] << endl << gracz.inventory_crafting_amount[13] << endl;//100-102
		plik << "Crafing item - alchemy number 15" << endl << gracz.inventory_crafting[14] << endl << gracz.inventory_crafting_amount[14] << endl;//103-105
		plik << "Crafing item - alchemy number 16" << endl << gracz.inventory_crafting[15] << endl << gracz.inventory_crafting_amount[15] << endl;//106-108
		plik << "Crafing item - alchemy number 17" << endl << gracz.inventory_crafting[16] << endl << gracz.inventory_crafting_amount[16] << endl;//109-111
		plik << "Crafing item - alchemy number 18" << endl << gracz.inventory_crafting[17] << endl << gracz.inventory_crafting_amount[17] << endl;//112-114
		plik << "Crafing item - alchemy number 19" << endl << gracz.inventory_crafting[18] << endl << gracz.inventory_crafting_amount[18] << endl;//115-117
		plik << "Crafing item - alchemy number 20" << endl << gracz.inventory_crafting[19] << endl << gracz.inventory_crafting_amount[19] << endl;//118-120
		plik << "Crafing item - smithery number 1" << endl << gracz.inventory_crafting[20] << endl << gracz.inventory_crafting_amount[20] << endl;//121-123
		plik << "Crafing item - smithery number 2" << endl << gracz.inventory_crafting[21] << endl << gracz.inventory_crafting_amount[21] << endl;//124-126
		plik << "Crafing item - smithery number 3" << endl << gracz.inventory_crafting[22] << endl << gracz.inventory_crafting_amount[22] << endl;//127-129
		plik << "Crafing item - smithery number 4" << endl << gracz.inventory_crafting[23] << endl << gracz.inventory_crafting_amount[23] << endl;//130-132
		plik << "Crafing item - smithery number 5" << endl << gracz.inventory_crafting[24] << endl << gracz.inventory_crafting_amount[24] << endl;//133-135
		plik << "Crafing item - smithery number 6" << endl << gracz.inventory_crafting[25] << endl << gracz.inventory_crafting_amount[25] << endl;//136-138
		plik << "Crafing item - smithery number 7" << endl << gracz.inventory_crafting[26] << endl << gracz.inventory_crafting_amount[26] << endl;//139-141
		plik << "Crafing item - smithery number 8" << endl << gracz.inventory_crafting[27] << endl << gracz.inventory_crafting_amount[27] << endl;//142-144
		plik << "Crafing item - smithery number 9" << endl << gracz.inventory_crafting[28] << endl << gracz.inventory_crafting_amount[28] << endl;//145-147
		plik << "Crafing item - smithery number 10" << endl << gracz.inventory_crafting[29] << endl << gracz.inventory_crafting_amount[29] << endl;//148-150
		plik << "Crafing item - smithery number 11" << endl << gracz.inventory_crafting[30] << endl << gracz.inventory_crafting_amount[30] << endl;//151-153
		plik << "Crafing item - smithery number 12" << endl << gracz.inventory_crafting[31] << endl << gracz.inventory_crafting_amount[31] << endl;//154-156
		plik << "Crafing item - smithery number 13" << endl << gracz.inventory_crafting[32] << endl << gracz.inventory_crafting_amount[32] << endl;//157-159
		plik << "Crafing item - smithery number 14" << endl << gracz.inventory_crafting[33] << endl << gracz.inventory_crafting_amount[33] << endl;//160-162
		plik << "Crafing item - smithery number 15" << endl << gracz.inventory_crafting[34] << endl << gracz.inventory_crafting_amount[34] << endl;//163-165
		plik << "Crafing item - smithery number 16" << endl << gracz.inventory_crafting[35] << endl << gracz.inventory_crafting_amount[35] << endl;//166-168
		plik << "Crafing item - smithery number 17" << endl << gracz.inventory_crafting[36] << endl << gracz.inventory_crafting_amount[36] << endl;//169-171
		plik << "Crafing item - smithery number 18" << endl << gracz.inventory_crafting[37] << endl << gracz.inventory_crafting_amount[37] << endl;//172-174
		plik << "Crafing item - smithery number 19" << endl << gracz.inventory_crafting[38] << endl << gracz.inventory_crafting_amount[38] << endl;//175-177
		plik << "Crafing item - smithery number 20" << endl << gracz.inventory_crafting[39] << endl << gracz.inventory_crafting_amount[39];//178-180
		plik.close();
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
		krzynka.sortUsage();
		krzynka.sortAlchemy();
		krzynka.sortForge();
		plik.open("./txt/mix/Zapis_gry_chest.txt", ios::out);
		plik << "Usable item number 1" << endl << krzynka.menu[0] << endl << krzynka.menu_amount[0] << endl;//1-3
		plik << "Usable item number 2" << endl << krzynka.menu[1] << endl << krzynka.menu_amount[1] << endl;//4-6
		plik << "Usable item number 3" << endl << krzynka.menu[2] << endl << krzynka.menu_amount[2] << endl;//7-9
		plik << "Usable item number 4" << endl << krzynka.menu[3] << endl << krzynka.menu_amount[3] << endl;//10-12
		plik << "Usable item number 5" << endl << krzynka.menu[4] << endl << krzynka.menu_amount[4] << endl;//13-15
		plik << "Usable item number 6" << endl << krzynka.menu[5] << endl << krzynka.menu_amount[5] << endl;//16-18
		plik << "Usable item number 7" << endl << krzynka.menu[6] << endl << krzynka.menu_amount[6] << endl;//19-21
		plik << "Usable item number 8" << endl << krzynka.menu[7] << endl << krzynka.menu_amount[7] << endl;//22-24
		plik << "Usable item number 9" << endl << krzynka.menu[8] << endl << krzynka.menu_amount[8] << endl;//25-27
		plik << "Usable item number 10" << endl << krzynka.menu[9] << endl << krzynka.menu_amount[9] << endl;//28-30
		plik << "Usable item number 11" << endl << krzynka.menu[10] << endl << krzynka.menu_amount[10] << endl;//31-33
		plik << "Usable item number 12" << endl << krzynka.menu[11] << endl << krzynka.menu_amount[11] << endl;//34-36
		plik << "Usable item number 13" << endl << krzynka.menu[12] << endl << krzynka.menu_amount[12] << endl;//37-39
		plik << "Usable item number 14" << endl << krzynka.menu[13] << endl << krzynka.menu_amount[13] << endl;//40-42
		plik << "Usable item number 15" << endl << krzynka.menu[14] << endl << krzynka.menu_amount[14] << endl;//43-45
		plik << "Usable item number 16" << endl << krzynka.menu[15] << endl << krzynka.menu_amount[15] << endl;//46-48
		plik << "Usable item number 17" << endl << krzynka.menu[16] << endl << krzynka.menu_amount[16] << endl;//49-51
		plik << "Usable item number 18" << endl << krzynka.menu[17] << endl << krzynka.menu_amount[17] << endl;//52-54
		plik << "Usable item number 19" << endl << krzynka.menu[18] << endl << krzynka.menu_amount[18] << endl;//55-57
		plik << "Usable item number 20" << endl << krzynka.menu[19] << endl << krzynka.menu_amount[19] << endl;//58-60
		plik << "Crafing item - alchemy number 1" << endl << krzynka.menu[20] << endl << krzynka.menu_amount[20] << endl;//61-63
		plik << "Crafing item - alchemy number 2" << endl << krzynka.menu[21] << endl << krzynka.menu_amount[21] << endl;//64-66
		plik << "Crafing item - alchemy number 3" << endl << krzynka.menu[22] << endl << krzynka.menu_amount[22] << endl;//67-69
		plik << "Crafing item - alchemy number 4" << endl << krzynka.menu[23] << endl << krzynka.menu_amount[23] << endl;//70-72
		plik << "Crafing item - alchemy number 5" << endl << krzynka.menu[24] << endl << krzynka.menu_amount[24] << endl;//73-75
		plik << "Crafing item - alchemy number 6" << endl << krzynka.menu[25] << endl << krzynka.menu_amount[25] << endl;//76-78
		plik << "Crafing item - alchemy number 7" << endl << krzynka.menu[26] << endl << krzynka.menu_amount[26] << endl;//79-80
		plik << "Crafing item - alchemy number 8" << endl << krzynka.menu[27] << endl << krzynka.menu_amount[27] << endl;//82-84
		plik << "Crafing item - alchemy number 9" << endl << krzynka.menu[28] << endl << krzynka.menu_amount[28] << endl;//85-87
		plik << "Crafing item - alchemy number 10" << endl << krzynka.menu[29] << endl << krzynka.menu_amount[29] << endl;//88-90
		plik << "Crafing item - alchemy number 11" << endl << krzynka.menu[30] << endl << krzynka.menu_amount[30] << endl;//91-92
		plik << "Crafing item - alchemy number 12" << endl << krzynka.menu[31] << endl << krzynka.menu_amount[31] << endl;//94-96
		plik << "Crafing item - alchemy number 13" << endl << krzynka.menu[32] << endl << krzynka.menu_amount[32] << endl;//97-99
		plik << "Crafing item - alchemy number 14" << endl << krzynka.menu[33] << endl << krzynka.menu_amount[33] << endl;//100-102
		plik << "Crafing item - alchemy number 15" << endl << krzynka.menu[34] << endl << krzynka.menu_amount[34] << endl;//103-105
		plik << "Crafing item - alchemy number 16" << endl << krzynka.menu[35] << endl << krzynka.menu_amount[35] << endl;//106-108
		plik << "Crafing item - alchemy number 17" << endl << krzynka.menu[36] << endl << krzynka.menu_amount[36] << endl;//109-111
		plik << "Crafing item - alchemy number 18" << endl << krzynka.menu[37] << endl << krzynka.menu_amount[37] << endl;//112-114
		plik << "Crafing item - alchemy number 19" << endl << krzynka.menu[38] << endl << krzynka.menu_amount[38] << endl;//115-117
		plik << "Crafing item - alchemy number 20" << endl << krzynka.menu[39] << endl << krzynka.menu_amount[39] << endl;//118-120
		plik << "Crafing item - smithery number 1" << endl << krzynka.menu[40] << endl << krzynka.menu_amount[40] << endl;//121-123
		plik << "Crafing item - smithery number 2" << endl << krzynka.menu[41] << endl << krzynka.menu_amount[41] << endl;//124-126
		plik << "Crafing item - smithery number 3" << endl << krzynka.menu[42] << endl << krzynka.menu_amount[42] << endl;//127-129
		plik << "Crafing item - smithery number 4" << endl << krzynka.menu[43] << endl << krzynka.menu_amount[43] << endl;//130-132
		plik << "Crafing item - smithery number 5" << endl << krzynka.menu[44] << endl << krzynka.menu_amount[44] << endl;//133-135
		plik << "Crafing item - smithery number 6" << endl << krzynka.menu[45] << endl << krzynka.menu_amount[45] << endl;//136-138
		plik << "Crafing item - smithery number 7" << endl << krzynka.menu[46] << endl << krzynka.menu_amount[46] << endl;//139-141
		plik << "Crafing item - smithery number 8" << endl << krzynka.menu[47] << endl << krzynka.menu_amount[47] << endl;//142-144
		plik << "Crafing item - smithery number 9" << endl << krzynka.menu[48] << endl << krzynka.menu_amount[48] << endl;//145-147
		plik << "Crafing item - smithery number 10" << endl << krzynka.menu[49] << endl << krzynka.menu_amount[49] << endl;//148-150
		plik << "Crafing item - smithery number 11" << endl << krzynka.menu[50] << endl << krzynka.menu_amount[50] << endl;//151-153
		plik << "Crafing item - smithery number 12" << endl << krzynka.menu[51] << endl << krzynka.menu_amount[51] << endl;//154-156
		plik << "Crafing item - smithery number 13" << endl << krzynka.menu[52] << endl << krzynka.menu_amount[52] << endl;//157-159
		plik << "Crafing item - smithery number 14" << endl << krzynka.menu[53] << endl << krzynka.menu_amount[53] << endl;//160-162
		plik << "Crafing item - smithery number 15" << endl << krzynka.menu[54] << endl << krzynka.menu_amount[54] << endl;//163-165
		plik << "Crafing item - smithery number 16" << endl << krzynka.menu[55] << endl << krzynka.menu_amount[55] << endl;//166-168
		plik << "Crafing item - smithery number 17" << endl << krzynka.menu[56] << endl << krzynka.menu_amount[56] << endl;//169-171
		plik << "Crafing item - smithery number 18" << endl << krzynka.menu[57] << endl << krzynka.menu_amount[57] << endl;//172-174
		plik << "Crafing item - smithery number 19" << endl << krzynka.menu[58] << endl << krzynka.menu_amount[58] << endl;//175-177
		plik << "Crafing item - smithery number 20" << endl << krzynka.menu[59] << endl << krzynka.menu_amount[59];//178-180
		plik.close();
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