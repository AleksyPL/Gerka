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
	}
	nr_linii++;
}
plik.close();
nr_linii = 1;
plik.open("./txt/mix/Zapis_gry_backpack.txt", ios::in);
while (getline(plik, linia))
{
	switch (nr_linii)
	{
	case 2:gracz.inventory_usage[0] = linia; break;
	case 3:gracz.inventory_usage_amount[0] = atoi(linia.c_str()); break;
	case 5:gracz.inventory_usage[1] = linia; break;
	case 6:gracz.inventory_usage_amount[1] = atoi(linia.c_str()); break;
	case 8:gracz.inventory_usage[2] = linia; break;
	case 9:gracz.inventory_usage_amount[2] = atoi(linia.c_str()); break;
	case 11:gracz.inventory_usage[3] = linia; break;
	case 12:gracz.inventory_usage_amount[3] = atoi(linia.c_str()); break;
	case 14:gracz.inventory_usage[4] = linia; break;
	case 15:gracz.inventory_usage_amount[4] = atoi(linia.c_str()); break;
	case 17:gracz.inventory_usage[5] = linia; break;
	case 18:gracz.inventory_usage_amount[5] = atoi(linia.c_str()); break;
	case 20:gracz.inventory_usage[6] = linia; break;
	case 21:gracz.inventory_usage_amount[6] = atoi(linia.c_str()); break;
	case 23:gracz.inventory_usage[7] = linia; break;
	case 24:gracz.inventory_usage_amount[7] = atoi(linia.c_str()); break;
	case 26:gracz.inventory_usage[8] = linia; break;
	case 27:gracz.inventory_usage_amount[8] = atoi(linia.c_str()); break;
	case 29:gracz.inventory_usage[9] = linia; break;
	case 30:gracz.inventory_usage_amount[9] = atoi(linia.c_str()); break;
	case 32:gracz.inventory_usage[10] = linia; break;
	case 33:gracz.inventory_usage_amount[10] = atoi(linia.c_str()); break;
	case 35:gracz.inventory_usage[11] = linia; break;
	case 36:gracz.inventory_usage_amount[11] = atoi(linia.c_str()); break;
	case 38:gracz.inventory_usage[12] = linia; break;
	case 39:gracz.inventory_usage_amount[12] = atoi(linia.c_str()); break;
	case 41:gracz.inventory_usage[13] = linia; break;
	case 42:gracz.inventory_usage_amount[13] = atoi(linia.c_str()); break;
	case 44:gracz.inventory_usage[14] = linia; break;
	case 45:gracz.inventory_usage_amount[14] = atoi(linia.c_str()); break;
	case 47:gracz.inventory_usage[15] = linia; break;
	case 48:gracz.inventory_usage_amount[15] = atoi(linia.c_str()); break;
	case 50:gracz.inventory_usage[16] = linia; break;
	case 51:gracz.inventory_usage_amount[16] = atoi(linia.c_str()); break;
	case 53:gracz.inventory_usage[17] = linia; break;
	case 54:gracz.inventory_usage_amount[17] = atoi(linia.c_str()); break;
	case 56:gracz.inventory_usage[18] = linia; break;
	case 57:gracz.inventory_usage_amount[18] = atoi(linia.c_str()); break;
	case 59:gracz.inventory_usage[19] = linia; break;
	case 60:gracz.inventory_usage_amount[19] = atoi(linia.c_str()); break;
	case 62:gracz.inventory_crafting[0] = linia; break;
	case 63:gracz.inventory_crafting_amount[0] = atoi(linia.c_str()); break;
	case 65:gracz.inventory_crafting[1] = linia; break;
	case 66:gracz.inventory_crafting_amount[1] = atoi(linia.c_str()); break;
	case 68:gracz.inventory_crafting[2] = linia; break;
	case 69:gracz.inventory_crafting_amount[2] = atoi(linia.c_str()); break;
	case 71:gracz.inventory_crafting[3] = linia; break;
	case 72:gracz.inventory_crafting_amount[3] = atoi(linia.c_str()); break;
	case 74:gracz.inventory_crafting[4] = linia; break;
	case 75:gracz.inventory_crafting_amount[4] = atoi(linia.c_str()); break;
	case 77:gracz.inventory_crafting[5] = linia; break;
	case 78:gracz.inventory_crafting_amount[5] = atoi(linia.c_str()); break;
	case 80:gracz.inventory_crafting[6] = linia; break;
	case 81:gracz.inventory_crafting_amount[6] = atoi(linia.c_str()); break;
	case 83:gracz.inventory_crafting[7] = linia; break;
	case 84:gracz.inventory_crafting_amount[7] = atoi(linia.c_str()); break;
	case 86:gracz.inventory_crafting[8] = linia; break;
	case 87:gracz.inventory_crafting_amount[8] = atoi(linia.c_str()); break;
	case 89:gracz.inventory_crafting[9] = linia; break;
	case 90:gracz.inventory_crafting_amount[9] = atoi(linia.c_str()); break;
	case 92:gracz.inventory_crafting[10] = linia; break;
	case 93:gracz.inventory_crafting_amount[10] = atoi(linia.c_str()); break;
	case 95:gracz.inventory_crafting[11] = linia; break;
	case 96:gracz.inventory_crafting_amount[11] = atoi(linia.c_str()); break;
	case 98:gracz.inventory_crafting[12] = linia; break;
	case 99:gracz.inventory_crafting_amount[12] = atoi(linia.c_str()); break;
	case 101:gracz.inventory_crafting[13] = linia; break;
	case 102:gracz.inventory_crafting_amount[13] = atoi(linia.c_str()); break;
	case 104:gracz.inventory_crafting[14] = linia; break;
	case 105:gracz.inventory_crafting_amount[14] = atoi(linia.c_str()); break;
	case 107:gracz.inventory_crafting[15] = linia; break;
	case 108:gracz.inventory_crafting_amount[15] = atoi(linia.c_str()); break;
	case 110:gracz.inventory_crafting[16] = linia; break;
	case 111:gracz.inventory_crafting_amount[16] = atoi(linia.c_str()); break;
	case 113:gracz.inventory_crafting[17] = linia; break;
	case 114:gracz.inventory_crafting_amount[17] = atoi(linia.c_str()); break;
	case 116:gracz.inventory_crafting[18] = linia; break;
	case 117:gracz.inventory_crafting_amount[18] = atoi(linia.c_str()); break;
	case 119:gracz.inventory_crafting[19] = linia; break;
	case 120:gracz.inventory_crafting_amount[19] = atoi(linia.c_str()); break;
	case 122:gracz.inventory_crafting[20] = linia; break;
	case 123:gracz.inventory_crafting_amount[20] = atoi(linia.c_str()); break;
	case 125:gracz.inventory_crafting[21] = linia; break;
	case 126:gracz.inventory_crafting_amount[21] = atoi(linia.c_str()); break;
	case 128:gracz.inventory_crafting[22] = linia; break;
	case 129:gracz.inventory_crafting_amount[22] = atoi(linia.c_str()); break;
	case 131:gracz.inventory_crafting[23] = linia; break;
	case 132:gracz.inventory_crafting_amount[23] = atoi(linia.c_str()); break;
	case 134:gracz.inventory_crafting[24] = linia; break;
	case 135:gracz.inventory_crafting_amount[24] = atoi(linia.c_str()); break;
	case 137:gracz.inventory_crafting[25] = linia; break;
	case 138:gracz.inventory_crafting_amount[25] = atoi(linia.c_str()); break;
	case 140:gracz.inventory_crafting[26] = linia; break;
	case 141:gracz.inventory_crafting_amount[26] = atoi(linia.c_str()); break;
	case 143:gracz.inventory_crafting[27] = linia; break;
	case 144:gracz.inventory_crafting_amount[27] = atoi(linia.c_str()); break;
	case 146:gracz.inventory_crafting[28] = linia; break;
	case 147:gracz.inventory_crafting_amount[28] = atoi(linia.c_str()); break;
	case 149:gracz.inventory_crafting[29] = linia; break;
	case 150:gracz.inventory_crafting_amount[29] = atoi(linia.c_str()); break;
	case 152:gracz.inventory_crafting[30] = linia; break;
	case 153:gracz.inventory_crafting_amount[30] = atoi(linia.c_str()); break;
	case 155:gracz.inventory_crafting[31] = linia; break;
	case 156:gracz.inventory_crafting_amount[31] = atoi(linia.c_str()); break;
	case 158:gracz.inventory_crafting[32] = linia; break;
	case 159:gracz.inventory_crafting_amount[32] = atoi(linia.c_str()); break;
	case 161:gracz.inventory_crafting[33] = linia; break;
	case 162:gracz.inventory_crafting_amount[33] = atoi(linia.c_str()); break;
	case 164:gracz.inventory_crafting[34] = linia; break;
	case 165:gracz.inventory_crafting_amount[34] = atoi(linia.c_str()); break;
	case 167:gracz.inventory_crafting[35] = linia; break;
	case 168:gracz.inventory_crafting_amount[35] = atoi(linia.c_str()); break;
	case 170:gracz.inventory_crafting[36] = linia; break;
	case 171:gracz.inventory_crafting_amount[36] = atoi(linia.c_str()); break;
	case 173:gracz.inventory_crafting[37] = linia; break;
	case 174:gracz.inventory_crafting_amount[37] = atoi(linia.c_str()); break;
	case 176:gracz.inventory_crafting[38] = linia; break;
	case 177:gracz.inventory_crafting_amount[38] = atoi(linia.c_str()); break;
	case 179:gracz.inventory_crafting[39] = linia; break;
	case 180:gracz.inventory_crafting_amount[39] = atoi(linia.c_str()); break;
	}
	nr_linii++;
}
plik.close();
gracz.sortUsageBackpack();
gracz.sortCraftingAlchemyBackpack();
gracz.sortCraftingForgeBackpack();
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
nr_linii = 1;
plik.open("./txt/mix/Zapis_gry_chest.txt", ios::in);
while (getline(plik, linia))
{
	switch (nr_linii)
	{
	case 2:krzynka.menu[0] = linia; break;
	case 3:krzynka.menu_amount[0] = atoi(linia.c_str()); break;
	case 5:krzynka.menu[1] = linia; break;
	case 6:krzynka.menu_amount[1] = atoi(linia.c_str()); break;
	case 8:krzynka.menu[2] = linia; break;
	case 9:krzynka.menu_amount[2] = atoi(linia.c_str()); break;
	case 11:krzynka.menu[3] = linia; break;
	case 12:krzynka.menu_amount[3] = atoi(linia.c_str()); break;
	case 14:krzynka.menu[4] = linia; break;
	case 15:krzynka.menu_amount[4] = atoi(linia.c_str()); break;
	case 17:krzynka.menu[5] = linia; break;
	case 18:krzynka.menu_amount[5] = atoi(linia.c_str()); break;
	case 20:krzynka.menu[6] = linia; break;
	case 21:krzynka.menu_amount[6] = atoi(linia.c_str()); break;
	case 23:krzynka.menu[7] = linia; break;
	case 24:krzynka.menu_amount[7] = atoi(linia.c_str()); break;
	case 26:krzynka.menu[8] = linia; break;
	case 27:krzynka.menu_amount[8] = atoi(linia.c_str()); break;
	case 29:krzynka.menu[9] = linia; break;
	case 30:krzynka.menu_amount[9] = atoi(linia.c_str()); break;
	case 32:krzynka.menu[10] = linia; break;
	case 33:krzynka.menu_amount[10] = atoi(linia.c_str()); break;
	case 35:krzynka.menu[11] = linia; break;
	case 36:krzynka.menu_amount[11] = atoi(linia.c_str()); break;
	case 38:krzynka.menu[12] = linia; break;
	case 39:krzynka.menu_amount[12] = atoi(linia.c_str()); break;
	case 41:krzynka.menu[13] = linia; break;
	case 42:krzynka.menu_amount[13] = atoi(linia.c_str()); break;
	case 44:krzynka.menu[14] = linia; break;
	case 45:krzynka.menu_amount[14] = atoi(linia.c_str()); break;
	case 47:krzynka.menu[15] = linia; break;
	case 48:krzynka.menu_amount[15] = atoi(linia.c_str()); break;
	case 50:krzynka.menu[16] = linia; break;
	case 51:krzynka.menu_amount[16] = atoi(linia.c_str()); break;
	case 53:krzynka.menu[17] = linia; break;
	case 54:krzynka.menu_amount[17] = atoi(linia.c_str()); break;
	case 56:krzynka.menu[18] = linia; break;
	case 57:krzynka.menu_amount[18] = atoi(linia.c_str()); break;
	case 59:krzynka.menu[19] = linia; break;
	case 60:krzynka.menu_amount[19] = atoi(linia.c_str()); break;
	case 62:krzynka.menu[20] = linia; break;
	case 63:krzynka.menu_amount[20] = atoi(linia.c_str()); break;
	case 65:krzynka.menu[21] = linia; break;
	case 66:krzynka.menu_amount[21] = atoi(linia.c_str()); break;
	case 68:krzynka.menu[22] = linia; break;
	case 69:krzynka.menu_amount[22] = atoi(linia.c_str()); break;
	case 71:krzynka.menu[23] = linia; break;
	case 72:krzynka.menu_amount[23] = atoi(linia.c_str()); break;
	case 74:krzynka.menu[24] = linia; break;
	case 75:krzynka.menu_amount[24] = atoi(linia.c_str()); break;
	case 77:krzynka.menu[25] = linia; break;
	case 78:krzynka.menu_amount[25] = atoi(linia.c_str()); break;
	case 80:krzynka.menu[26] = linia; break;
	case 81:krzynka.menu_amount[26] = atoi(linia.c_str()); break;
	case 83:krzynka.menu[27] = linia; break;
	case 84:krzynka.menu_amount[27] = atoi(linia.c_str()); break;
	case 86:krzynka.menu[28] = linia; break;
	case 87:krzynka.menu_amount[28] = atoi(linia.c_str()); break;
	case 89:krzynka.menu[29] = linia; break;
	case 90:krzynka.menu_amount[29] = atoi(linia.c_str()); break;
	case 92:krzynka.menu[30] = linia; break;
	case 93:krzynka.menu_amount[30] = atoi(linia.c_str()); break;
	case 95:krzynka.menu[31] = linia; break;
	case 96:krzynka.menu_amount[31] = atoi(linia.c_str()); break;
	case 98:krzynka.menu[32] = linia; break;
	case 99:krzynka.menu_amount[32] = atoi(linia.c_str()); break;
	case 101:krzynka.menu[33] = linia; break;
	case 102:krzynka.menu_amount[33] = atoi(linia.c_str()); break;
	case 104:krzynka.menu[34] = linia; break;
	case 105:krzynka.menu_amount[34] = atoi(linia.c_str()); break;
	case 107:krzynka.menu[35] = linia; break;
	case 108:krzynka.menu_amount[35] = atoi(linia.c_str()); break;
	case 110:krzynka.menu[36] = linia; break;
	case 111:krzynka.menu_amount[36] = atoi(linia.c_str()); break;
	case 113:krzynka.menu[37] = linia; break;
	case 114:krzynka.menu_amount[37] = atoi(linia.c_str()); break;
	case 116:krzynka.menu[38] = linia; break;
	case 117:krzynka.menu_amount[38] = atoi(linia.c_str()); break;
	case 119:krzynka.menu[39] = linia; break;
	case 120:krzynka.menu_amount[39] = atoi(linia.c_str()); break;
	case 122:krzynka.menu[40] = linia; break;
	case 123:krzynka.menu_amount[40] = atoi(linia.c_str()); break;
	case 125:krzynka.menu[41] = linia; break;
	case 126:krzynka.menu_amount[41] = atoi(linia.c_str()); break;
	case 128:krzynka.menu[42] = linia; break;
	case 129:krzynka.menu_amount[42] = atoi(linia.c_str()); break;
	case 131:krzynka.menu[43] = linia; break;
	case 132:krzynka.menu_amount[43] = atoi(linia.c_str()); break;
	case 134:krzynka.menu[44] = linia; break;
	case 135:krzynka.menu_amount[44] = atoi(linia.c_str()); break;
	case 137:krzynka.menu[45] = linia; break;
	case 138:krzynka.menu_amount[45] = atoi(linia.c_str()); break;
	case 140:krzynka.menu[46] = linia; break;
	case 141:krzynka.menu_amount[46] = atoi(linia.c_str()); break;
	case 143:krzynka.menu[47] = linia; break;
	case 144:krzynka.menu_amount[47] = atoi(linia.c_str()); break;
	case 146:krzynka.menu[48] = linia; break;
	case 147:krzynka.menu_amount[48] = atoi(linia.c_str()); break;
	case 149:krzynka.menu[49] = linia; break;
	case 150:krzynka.menu_amount[49] = atoi(linia.c_str()); break;
	case 152:krzynka.menu[50] = linia; break;
	case 153:krzynka.menu_amount[50] = atoi(linia.c_str()); break;
	case 155:krzynka.menu[51] = linia; break;
	case 156:krzynka.menu_amount[51] = atoi(linia.c_str()); break;
	case 158:krzynka.menu[52] = linia; break;
	case 159:krzynka.menu_amount[52] = atoi(linia.c_str()); break;
	case 161:krzynka.menu[53] = linia; break;
	case 162:krzynka.menu_amount[53] = atoi(linia.c_str()); break;
	case 164:krzynka.menu[54] = linia; break;
	case 165:krzynka.menu_amount[54] = atoi(linia.c_str()); break;
	case 167:krzynka.menu[55] = linia; break;
	case 168:krzynka.menu_amount[55] = atoi(linia.c_str()); break;
	case 170:krzynka.menu[56] = linia; break;
	case 171:krzynka.menu_amount[56] = atoi(linia.c_str()); break;
	case 173:krzynka.menu[57] = linia; break;
	case 174:krzynka.menu_amount[57] = atoi(linia.c_str()); break;
	case 176:krzynka.menu[58] = linia; break;
	case 177:krzynka.menu_amount[58] = atoi(linia.c_str()); break;
	case 179:krzynka.menu[59] = linia; break;
	case 180:krzynka.menu_amount[59] = atoi(linia.c_str()); break;
	}
	nr_linii++;
}
plik.close();
}