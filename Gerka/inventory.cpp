#include "inventory.h"
#include "tabelka.h"
#include "level_up.h"
#include "items.h"

player enterInventory(player &gracz)
{
	int leftSideCard = 0;
	int rightSideCard = 0;
	int highlight = 0;
	string leftSide[21];
	string rightSide[21];
	vector <string> bottomSide = { "<-","->","Return","<-","->" };
	levelUp(23, 32, gracz);
	while (1)
	{
		for (int i = 0; i < 20; i++)
		{
			leftSide[i] = "";
			rightSide[i] = "";
		}
		if (leftSideCard == 0)
		{
			leftSide[20] = "Items - Usable";
			if (gracz.countFreeFieldsUsage() == 20)
			{
				leftSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (gracz.inventory_usage[i] != "" && gracz.inventory_usage_amount[i] != 1)
					{
						leftSide[i] = gracz.inventory_usage[i] + " x" + to_string(gracz.inventory_usage_amount[i]);
					}
					else if (gracz.inventory_usage[i] != "" && gracz.inventory_usage_amount[i] == 1)
					{
						leftSide[i] = gracz.inventory_usage[i];
					}
				}
			}
		}
		else if (leftSideCard == 1)
		{
			leftSide[20] = "Items - Alchemy";
			if (gracz.countFreeFieldsAlchemy() == 20)
			{
				leftSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (gracz.inventory_crafting[i] != "" && gracz.inventory_crafting_amount[i] != 1)
					{
						leftSide[i] = gracz.inventory_crafting[i] + " x" + to_string(gracz.inventory_crafting_amount[i]);
					}
					else if (gracz.inventory_crafting[i] != "" && gracz.inventory_crafting_amount[i] == 1)
					{
						leftSide[i] = gracz.inventory_crafting[i];
					}
				}
			}
		}
		else if (leftSideCard == 2)
		{
			leftSide[20] = "Items - Smithery";
			if (gracz.countFreeFieldsForge() == 20)
			{
				leftSide[0] = "No items";
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					if (gracz.inventory_crafting[20 + i] != "" && gracz.inventory_crafting_amount[20 + i] != 1)
					{
						leftSide[i] = gracz.inventory_crafting[20 + i] + " x" + to_string(gracz.inventory_crafting_amount[20 + i]);
					}
					else if (gracz.inventory_crafting[20 + i] != "" && gracz.inventory_crafting_amount[20 + i] == 1)
					{
						leftSide[i] = gracz.inventory_crafting[20 + i];
					}
				}
			}
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
			rightSide[6] = "Weapon damage: " + to_string((int)(0.2 * gracz.str * gracz.agility)+gracz.weaponDamage);
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
		highlight = tabItemsLeftOnly(highlight, "Equipment and Statistics", leftSide, rightSide, bottomSide);
		if (highlight < 20 && leftSide[highlight]!="No items")
		{
			string nazwa;
			int ilosc = 0;
			if (leftSideCard == 0)
			{
				nazwa = gracz.inventory_usage[highlight];
				ilosc = gracz.inventory_usage_amount[highlight];
			}
			if (leftSideCard == 1)
			{
				nazwa = gracz.inventory_crafting[highlight];
				ilosc = gracz.inventory_crafting_amount[highlight];
			}
			if (leftSideCard == 2)
			{
				nazwa = gracz.inventory_crafting[highlight + 20];
				ilosc = gracz.inventory_crafting_amount[highlight + 20];
			}
			vector<string> message;
			message.push_back("What do you want to do with: " + nazwa + " (" + to_string(ilosc) + ") ?");
			vector<string> options;
			options.push_back("Use item");
			options.push_back("Drop item");
			options.push_back("Information about item");
			options.push_back("Return");
			int highlight2 = tabSubmenuOneColumnChoice(27,28,message,options);
			string item_name;
			if (leftSideCard == 0)
			{
				item_name = gracz.inventory_usage[highlight];
			}
			else if (leftSideCard == 1)
			{
				item_name = gracz.inventory_crafting[highlight];
			}
			else if (leftSideCard == 2)
			{
				item_name = gracz.inventory_crafting[highlight + 20];
			}
			switch (highlight2)
			{
			case 0:
			{
				useItem(27,28,item_name, 1, gracz);
				break;
			}
			case 1:
			{
				useItem(27,28,item_name, 2, gracz);
				break;
			}
			case 2:
			{
				useItem(27,28,item_name, 3, gracz);
				break;
			}
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
				if (leftSideCard < 2)
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
	return gracz;
}