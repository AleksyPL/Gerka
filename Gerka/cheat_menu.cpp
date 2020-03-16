#include "tabelka.h"
#include "zakres.h"
#include "level_up.h"
#include "cheat_menu.h"

int loadValueInt(int height, int startPoint, bool& succes, string comment, int active0,string mark,int min, int active1, string mark1, int max)
{
	int number = 0;
	if (active0 == 1 && active1 == 1)
	{
		try
		{
			int number = stoi(tabSubmenuInputField(height, startPoint, comment));
			if (mark == "<" && mark1 == ">")
			{
				while (number<min || number>max)
				{
					number = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (number > min || number < max)
				{
					number = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		catch (std::exception)
		{
			succes = false;
		}
	}
	else if (active0 == 1 && active1 == 0)
	{
		try
		{
			int number = stoi(tabSubmenuInputField(height, startPoint, comment));
			if (mark == "<")
			{
				while (number < min)
				{
					number = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">")
			{
				while (number > min)
				{
					number = stoi(tabSubmenuInputField(height, startPoint, comment));
				}
			}
		}
		catch (std::exception)
		{
			succes = false;
		}
	}
	return number;
}
__int64 loadValue__int64(int height, int startPoint, bool& succes, string comment, int active0, string mark, int min, int active1, string mark1, int max)
{
	__int64 number = 0;
	if (active0 == 1 && active1 == 1)
	{
		try
		{
			long long temp = stoll(tabSubmenuInputField(height, startPoint, comment));
			if (mark == "<" && mark1 == ">")
			{
				while (temp<min || temp>max)
				{
					temp = stoll(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (temp > min || temp < max)
				{
					temp = stoll(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			number = temp;
		}
		catch (std::exception)
		{
			succes = false;
		}
	}
	else if (active0 == 1 && active1 == 0)
	{
		try
		{
			long long temp = stoll(tabSubmenuInputField(height, startPoint, comment));
			if (mark == "<")
			{
				while (temp < min)
				{
					temp = stoll(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			else if (mark == ">")
			{
				while (temp > min)
				{
					temp = stoll(tabSubmenuInputField(height, startPoint, comment));
				}
			}
			number = temp;
		}
		catch (std::exception)
		{
			succes = false;
		}
	}
	return number;
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
			if (gracz.isTheWeaponRare == true)
			{
				rightSide[5] = "Weapon name: [RARE]" + gracz.weaponName;
			}
			else
			{
				rightSide[5] = "Weapon name: " + gracz.weaponName;
			}
			rightSide[6] = "Weapon points: " + to_string(gracz.weaponDamage);
			rightSide[7] = "Gold: " + to_string(gracz.gold);
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
		bool succes = true;
		if (highlight < 20)
		{
			switch (highlight)
			{
			case 0:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new health points value: ", 1, "<", 0, 1, ">", gracz.max_hp);
					if (succes == true)
					{
						gracz.hp = temp;
					}
					
				}
				break;
			}
			case 1:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new maximum health points value: ", 1, "<", 0, 1, ">", gracz.hp);
					if (succes == true)
					{
						gracz.max_hp = temp;
					}
				}
				break;
			}
			case 2:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new experience points value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.exp = temp;
					}
				}
				break;
			}
			case 3:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new maximum experience points value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.exp_to_next_level = temp;
					}
				}
				break;
			}
			case 4:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new nutrition level value: ", 1, "<", 0, 1, ">", 10);
					if (succes == true)
					{
						gracz.hunger = temp;
					}
				}
				break;
			}
			case 5:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new drunk level value: ", 1, "<", 0, 1, ">", 10);
					if (succes == true)
					{
						gracz.alko = temp;
					}
				}
				break;
			}
			case 6:
			{
				if (leftSideCard == 0)
				{
					__int64 temp = loadValue__int64(27, 28, succes, "Enter the new gold amount value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.gold = temp;
					}
				}
				break;
			}
			case 7:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new character level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.level = temp;
					}
				}
				break;
			}
			case 8:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new strength level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.str = temp;
					}
				}
				break;
			}
			case 9:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new agility level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.agility = temp;
					}
				}
				break;
			}
			case 10:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new inteligence level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.intel = temp;
					}
				}
				break;
			}
			case 11:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new charisma level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.charisma = temp;
					}
				}
				break;
			}
			case 12:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new luck level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.luck = temp;
					}
				}
				break;
			}
			case 13:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new weapon damage value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.weaponDamage = temp;
					}
				}
				break;
			}
			case 14:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new helmet level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.helmet = temp;
					}
				}
				break;
			}
			case 15:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new chestplate level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.chestplate = temp;
					}
				}
				break;
			}
			case 16:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new gloves level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.gloves = temp;
					}
				}
				break;
			}
			case 17:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new pants level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.pants = temp;
					}
				}
				break;
			}
			case 18:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new shoes level value: ", 1, "<", 0);
					if (succes == true)
					{
						gracz.shoes = temp;
					}
				}
				break;
			}
			case 19:
			{
				if (leftSideCard == 0)
				{
					int temp = loadValueInt(27, 28, succes, "Enter the new hour: ", 1, "<", 0, 1, ">", 23);
					int temp2 = loadValueInt(27, 28, succes, "Enter the new minute: ", 1, "<", 0, 1, ">", 59);
					if (succes == true)
					{
						gracz.hour = temp;
						gracz.minute = temp2;
					}
				}
				break;
			}
			}
			if (succes == true)
			{
				sound_cheat_activated();
			}
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