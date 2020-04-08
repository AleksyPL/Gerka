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
	plik << "Weapon name" << endl << gracz.weaponName;//13-14
	plik << "Weapon price" << endl << gracz.weaponPrice;//15-16
	plik << "Is the weapon rare?" << endl << gracz.isTheWeaponRare;//17-18
	plik.close();
	remove("./txt/mix/player_temp_backpack.txt");
	gracz.sortUsageBackpack();
	gracz.sortCraftingAlchemyBackpack();
	gracz.sortCraftingForgeBackpack();
	plik.open("./txt/mix/player_temp_backpack.txt", ios::out);
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
	nr_linii = 1;
	plik.open("./txt/mix/player_temp_backpack.txt", ios::in);
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
}