#include "tabelka.h"
#include "zakres.h"
#include "level_up.h"
#include "cheat_menu.h"

int load_value(int height, int startPoint, string comment, string type, int active0,string mark,int min, int active1, string mark1, int max)
{
	if (type == "int")
	{
		int numer = stoi(tabSubmenuInputField(height, startPoint, comment));
		if (active0 == 1 && active1 == 1)
		{
			if (mark == "<" && mark1 == ">")
			{
				while (numer<min || numer>max)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (numer>min || numer<max)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		else if (active0 == 1 && active1 == 0)
		{
			if (mark == "<")
			{
				while (numer<min)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">")
			{
				while (numer>min)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		return numer;
	}
	else if (type == "long")
	{
		long numer = stoi(tabSubmenuInputField(height, startPoint, comment));
		if (active0 == 1 && active1 == 1)
		{
			if (mark == "<" && mark1 == ">")
			{
				while (numer<min || numer>max)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (numer>min || numer<max)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		else if (active0 == 1 && active1 == 0)
		{
			if (mark == "<")
			{
				while (numer<min)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">")
			{
				while (numer>min)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		return numer;
	}
	else if (type == "long long")
	{
		long long numer = stoi(tabSubmenuInputField(height, startPoint, comment));
		if (active0 == 1 && active1 == 1)
		{
			if (mark == "<" && mark1 == ">")
			{
				while (numer<min || numer>max)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (numer>min || numer<max)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		else if (active0 == 1 && active1 == 0)
		{
			if (mark == "<")
			{
				while (numer<min)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">")
			{
				while (numer>min)
				{
					numer = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		return numer;
	}
}
player enter_cheat_menu(player &gracz)
{
	int leftSideCard = 0;
	int rightSideCard = 0;
	int highlight = 0;
	while (1)
	{
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		range(gracz);
		levelUp(23, 32, gracz);
		string leftSide[21];
		string rightSide[21];
		vector <string> bottomSide = { "<-","->","Return","<-","->" };
		for (int i = 0; i < 20; i++)
		{
			leftSide[i] = "";
			rightSide[i] = "";
		}
		if (leftSideCard == 0)
		{
			/* 1*/leftSide[0] = "Change HP";
			/* 2*/leftSide[1] = "Change max HP";
			/* 3*/leftSide[2] = "Change XP points";
			/* 4*/leftSide[3] = "Change max XP points";
			/* 5*/leftSide[4] = "Change nutrition level";
			/* 6*/leftSide[5] = "Change drunk level";
			/* 7*/leftSide[6] = "Change gold amount";
			/* 8*/leftSide[7] = "Change character level";
			/* 9*/leftSide[8] = "Change strength level";
			/*10*/leftSide[9] = "Change agility level";
			/*11*/leftSide[10] = "Change intelligence level";
			/*12*/leftSide[11] = "Change charisma level";
			/*13*/leftSide[12] = "Change luck level";
			/*14*/leftSide[13] = "Change weapon damage";
			/*15*/leftSide[14] = "Change helmet points";
			/*16*/leftSide[15] = "Change chestplate points";
			/*17*/leftSide[16] = "Change gloves points";
			/*18*/leftSide[17] = "Change pants points";
			/*19*/leftSide[18] = "Change shoes points";
			/*20*/leftSide[19] = "Change time";
			leftSide[20] = "Cheats - page 1";
		}
		if (rightSideCard == 0)
		{
			rightSide[20] = "Character - Main statistics";
			rightSide[0] = "Character name: " + gracz.nazwa;
			rightSide[1] = "Level: " + to_string(gracz.level);
			rightSide[2] = "Alias: " + gracz.pseudonym;
			rightSide[3] = "Health points: " + to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
			rightSide[4] = "Experience points: " + to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level);
			rightSide[5] = "Nutrition points: " + to_string(gracz.hunger) + "/" + to_string(10);
			rightSide[6] = "Drunk Level: " + to_string(gracz.alko) + "/" + to_string(10);
			if (gracz.before_boost_str != 0)
			{
				rightSide[7] = "Strength Level: " + to_string(gracz.str) + "(" + to_string(gracz.before_boost_str) + ")";
			}
			else if (gracz.before_nerf_str != 0)
			{
				rightSide[7] = "Strength Level: " + to_string(gracz.str) + "(" + to_string(gracz.before_nerf_str) + ")";
			}
			else
			{
				rightSide[7] = "Strength Level: " + to_string(gracz.str);
			}
			if (gracz.before_boost_agility != 0)
			{
				rightSide[8] = "Agility Level: " + to_string(gracz.agility) + "(" + to_string(gracz.before_boost_agility) + ")";
			}
			else if (gracz.before_nerf_agility != 0)
			{
				rightSide[8] = "Agility Level: " + to_string(gracz.agility) + "(" + to_string(gracz.before_nerf_agility) + ")";
			}
			else
			{
				rightSide[8] = "Agility Level: " + to_string(gracz.intel);
			}
			if (gracz.before_boost_agility != 0)
			{
				rightSide[9] = "Inteligence Level: " + to_string(gracz.intel) + "(" + to_string(gracz.before_boost_intel) + ")";
			}
			else if (gracz.before_nerf_agility != 0)
			{
				rightSide[9] = "Inteligence Level: " + to_string(gracz.intel) + "(" + to_string(gracz.before_nerf_intel) + ")";
			}
			else
			{
				rightSide[9] = "Inteligence Level: " + to_string(gracz.intel);
			}
			if (gracz.before_boost_charisma != 0)
			{
				rightSide[10] = "Charisma Level: " + to_string(gracz.charisma) + "(" + to_string(gracz.before_boost_charisma) + ")";
			}
			else if (gracz.before_nerf_charisma != 0)
			{
				rightSide[10] = "Charisma Level: " + to_string(gracz.charisma) + "(" + to_string(gracz.before_nerf_charisma) + ")";
			}
			else
			{
				rightSide[10] = "Charisma Level: " + to_string(gracz.charisma);
			}
			if (gracz.before_boost_luck != 0)
			{
				rightSide[11] = "Luck Level: " + to_string(gracz.luck) + "(" + to_string(gracz.before_boost_luck) + ")";
			}
			else if (gracz.before_nerf_luck != 0)
			{
				rightSide[11] = "Luck Level: " + to_string(gracz.luck) + "(" + to_string(gracz.before_nerf_luck) + ")";
			}
			else
			{
				rightSide[11] = "Luck Level: " + to_string(gracz.luck);
			}
			rightSide[12] = "";
			rightSide[13] = "";
			rightSide[14] = "";
			rightSide[15] = "";
			rightSide[16] = "";
			rightSide[17] = "";
			rightSide[18] = "";
			rightSide[19] = "";
		}
		else if (rightSideCard == 1)
		{
			rightSide[20] = "Character - Equipment";
			rightSide[0] = "Helmet points: " + to_string(gracz.helmet);
			rightSide[1] = "Chestplate points: " + to_string(gracz.chestplate);
			rightSide[2] = "Gloves points: " + to_string(gracz.gloves);
			rightSide[3] = "Pants points: " + to_string(gracz.pants);
			rightSide[4] = "Shoes points: " + to_string(gracz.shoes);
			rightSide[5] = "Weapon name: " + gracz.weapon_name;
			rightSide[6] = "Weapon points: " + to_string(gracz.weapon);
			rightSide[7] = "";
			rightSide[8] = "";
			rightSide[9] = "";
			rightSide[10] = "";
			rightSide[11] = "";
			rightSide[12] = "";
			rightSide[13] = "";
			rightSide[14] = "";
			rightSide[15] = "";
			rightSide[16] = "";
			rightSide[17] = "";
			rightSide[18] = "";
			rightSide[19] = "";
		}
		range(gracz);
		highlight = tabItemsLeftOnly(highlight, "Cheat Menu", leftSide, rightSide, bottomSide);
		if (highlight < 20)
		{
			switch (highlight)
			{
			case 0:
			{
				if (leftSideCard == 0)
				{
					gracz.hp = load_value(27, 28, "Enter the new health points value: ", "int", 1, "<", 0, 1, ">", gracz.max_hp);
				}
				break;
			}
			case 1:
			{
				if (leftSideCard == 0)
				{
					gracz.max_hp = load_value(27, 28, "Enter the new maximum health points value: ", "int", 1, "<", 0, 1, ">", gracz.hp);
				}
				break;
			}
			case 2:
			{
				if (leftSideCard == 0)
				{
					gracz.exp = load_value(27, 28, "Enter the new experience points value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 3:
			{
				if (leftSideCard == 0)
				{
					gracz.exp_to_next_level = load_value(27, 28, "Enter the new maximum experience points value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 4:
			{
				if (leftSideCard == 0)
				{
					gracz.hunger = load_value(27, 28, "Enter the new nutrition level value: ", "int", 1, "<", 0, 1, ">", 10);
				}
				break;
			}
			case 5:
			{
				if (leftSideCard == 0)
				{
					gracz.alko = load_value(27, 28, "Enter the new drunk level value: ", "int", 1, "<", 0, 1, ">", 10);
				}
				break;
			}
			case 6:
			{
				if (leftSideCard == 0)
				{
					gracz.gold = load_value(27, 28, "Enter the new gold amount value: ", "long long", 1, "<", 0);
				}
				break;
			}
			case 7:
			{
				if (leftSideCard == 0)
				{
					gracz.level = load_value(27, 28, "Enter the new character level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 8:
			{
				if (leftSideCard == 0)
				{
					gracz.str = load_value(27, 28, "Enter the new strength level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 9:
			{
				if (leftSideCard == 0)
				{
					gracz.agility = load_value(27, 28, "Enter the new agility level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 10:
			{
				if (leftSideCard == 0)
				{
					gracz.intel = load_value(27, 28, "Enter the new inteligence level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 11:
			{
				if (leftSideCard == 0)
				{
					gracz.charisma = load_value(27, 28, "Enter the new charisma level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 12:
			{
				if (leftSideCard == 0)
				{
					gracz.luck = load_value(27, 28, "Enter the new luck level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 13:
			{
				if (leftSideCard == 0)
				{
					gracz.weapon = load_value(27, 28, "Enter the new weapon damage value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 14:
			{
				if (leftSideCard == 0)
				{
					gracz.helmet = load_value(27, 28, "Enter the new helmet level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 15:
			{
				if (leftSideCard == 0)
				{
					gracz.chestplate = load_value(27, 28, "Enter the new chestplate level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 16:
			{
				if (leftSideCard == 0)
				{
					gracz.gloves = load_value(27, 28, "Enter the new gloves level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 17:
			{
				if (leftSideCard == 0)
				{
					gracz.pants = load_value(27, 28, "Enter the new pants level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 18:
			{
				if (leftSideCard == 0)
				{
					gracz.shoes = load_value(27, 28, "Enter the new shoes level value: ", "int", 1, "<", 0);
				}
				break;
			}
			case 19:
			{
				if (leftSideCard == 0)
				{
					gracz.hour = load_value(27, 28, "Enter the new hour: ", "int", 1, "<", 0, 1, ">", 23);
					gracz.minute = load_value(27, 28, "Enter the new minute: ", "int", 1, "<", 0, 1, ">", 59);
				}
				break;
			}
			}
			sound_cheat_activated();
		}
		else
		{
			switch (highlight)
			{
			case 20:
			{
				if (leftSideCard != 0)
				{
					leftSideCard--;
				}
				break;
			}
			case 21:
			{
				if (leftSideCard != 0)
				{
					leftSideCard++;
				}
				break;
			}
			case 22:
			{
				return gracz;
			}
			case 23:
			{
				if (rightSideCard != 0)
				{
					rightSideCard--;
				}
				break;
			}
			case 24:
			{
				if (rightSideCard < 1)
				{
					rightSideCard++;
				}
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
}