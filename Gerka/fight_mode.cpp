#include "fight_mode.h"
#include "tabelka.h"
#include "zakres.h"


void victoryCondition(int height, int startPoint, Mob enemy, player& gracz, bool &victory, string &itemName)
{
	if (enemy.HP <= 0)
	{
		soundSuccess();
		vector <string> message;
		message.push_back("You won!");
		message.push_back("Next to the " + enemy.mobName + " you found " + to_string(enemy.returnDroppedGold()) + " gold.");
		message.push_back("You get " + to_string(enemy.XP) + " experience points for the fight.");
		gracz.exp += enemy.XP;
		gracz.gold += enemy.returnDroppedGold();
		tabSubmenuTextOnly(height, startPoint, message);
		range(gracz);
		pickUpItemDroppedByEnemy(11, 44, enemy, gracz, itemName);
		victory = true;
	}
	else
	{
		victory = false;
	}
}
void pickUpItemDroppedByEnemy(int height, int startPoint, Mob enemy, player& gracz, string& itemName)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (enemy.thisMonsterAreAbleToDropItem == true)
	{
		if (findItemOnList(enemy.droppedItem) == "Usable")
		{
			if (gracz.countFreeFieldsUsage() != 0)
			{
				vector <string> message = { "Do you want to take " + enemy.droppedItem + "?" };
				int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (highlight == 0)
				{
					gracz.addUsageItem(enemy.droppedItem, 0, 1, height, startPoint);
				}
				else
				{
					message.push_back("You leave " + enemy.droppedItem + " on the ground.");
					itemName = enemy.droppedItem;
				}
			}
			else
			{
				message.push_back("Your backpack is full");
				message.push_back("You leave " + enemy.droppedItem + " on the ground.");
				itemName = enemy.droppedItem;
			}
		}
		else if (findItemOnList(enemy.droppedItem) == "Alchemy")
		{
			if (gracz.countFreeFieldsAlchemy() != 0)
			{
				vector <string> message = { "Do you want to take " + enemy.droppedItem + "?" };
				int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (highlight == 0)
				{
					gracz.addCraftingAlchemyItem(enemy.droppedItem, 0, 1, height, startPoint);
				}
				else
				{
					message.push_back("You leave " + enemy.droppedItem + " on the ground.");
					itemName = enemy.droppedItem;
				}
			}
			else
			{
				message.push_back("Your backpack is full");
				message.push_back("You leave " + enemy.droppedItem + " on the ground.");
				itemName = enemy.droppedItem;
			}
		}
		else if (findItemOnList(enemy.droppedItem) == "Smithery")
		{
			if (gracz.countFreeFieldsForge() != 0)
			{
				vector <string> message = { "Do you want to take " + enemy.droppedItem + "?" };
				int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
				if (highlight == 0)
				{
					gracz.addCraftingForgeItem(enemy.droppedItem, 0, 1, height, startPoint);
				}
				else
				{
					message.push_back("You leave " + enemy.droppedItem + " on the ground.");
					itemName = enemy.droppedItem;
				}
			}
			else
			{
				message.push_back("Your backpack is full");
				message.push_back("You leave " + enemy.droppedItem + " on the ground.");
				itemName = enemy.droppedItem;
			}
		}
		else
		{
			message.push_back("Error");
		}
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
void dealingDamage(int height, int startPoint, player &gracz, Mob &enemy,bool &isItThePlayersTurnNow)
{
	vector <string> message;
	if (isItThePlayersTurnNow == true)
	{
		if (gracz.returnChancesOfDealingDamage() > enemy.returnGettingHitRate())
		{
			int dealedDamage = (int)(0.2 * gracz.str * gracz.agility) + gracz.weaponDamage;
			if ((rand() % 100) < 5)
			{
				message.push_back("Critical hit!");
				dealedDamage *= 2;
			}
			message.push_back("You have dealt " + to_string(dealedDamage) + " points of damage to " + enemy.mobName + ".");
			enemy.HP -= dealedDamage;
			enemy.updateFightInfo();
		}
		else
		{
			message.push_back("Your attack missed a " + enemy.mobName);
		}
		isItThePlayersTurnNow = !isItThePlayersTurnNow;
	}
	else if (isItThePlayersTurnNow == false)
	{
		if (enemy.returnDealingDamageRate() > gracz.returnChancesOfGettingHit())
		{
			int dealedDamage = enemy.damage;
			if ((rand() % 100) < 5)
			{
				message.push_back("Critical hit!");
				dealedDamage *= 2;
			}
			message.push_back(enemy.mobName + " have dealt " + to_string(dealedDamage) + " points of damage to you.");
			gracz.hp -= dealedDamage;
		}
		else
		{
			message.push_back(enemy.mobName + " missed his attack on you");
		}
		isItThePlayersTurnNow = !isItThePlayersTurnNow;
	}
	if (message.size() != 0)
	{
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
Mob loadMonsterData(string monsterName)
{
	string path;
	if (monsterName == "Citizen")
	{
		int random = rand() % 3;
		if (random == 0)
		{
			path = "./txt/mobki/citizen_small.txt";
		}
		else if (random == 1)
		{
			path = "./txt/mobki/citizen_medium.txt";
		}
		else
		{
			path = "./txt/mobki/citizen_high.txt";
		}
	}
	else if (monsterName == "Bandit")
	{
		path = "./txt/mobki/bandit.txt";
	}
	else if (monsterName == "Skeleton")
	{
		path = "./txt/mobki/skeleton.txt";
	}
	else if (monsterName == "Dog")
	{
		path = "./txt/mobki/dog.txt";
	}	
	else
	{
		path = "./txt/mobki/default.txt";
	}
	Mob enemy(path);
	return enemy;
}
string makeString(int howLong, string function, int chances)
{
	string chancesString = "[" + to_string(chances) + " PERCENT]";
	howLong -= (function.length() + chancesString.length());
	string temp = function;
	for (int i = 0; i < howLong; i++)
	{
		temp += " ";
	}
	temp += chancesString;
	return temp;
}
player enterFightMode(player gracz, string monsterName, bool playerGoesFirst, bool &victory, string &itemName)
{
	soundStartFight();
	int highlight = 0;
	string playerInfo[18];
	string shortcuts[20];
	string actions[20];
	Mob enemy = loadMonsterData(monsterName);
	bool isItThePlayersTurnNow = playerGoesFirst;
	bool nonLethalFight;
	if (enemy.mobName == "Citizen")
	{
		nonLethalFight = true;
	}
	else
	{
		nonLethalFight = false;
	}
	victoryCondition(12, 43, enemy, gracz, victory, itemName);
	while (victory==false)
	{
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		//inserting data
		{
			playerInfo[0] = "Health points: " + to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
			playerInfo[1] = "Experience points: " + to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level) + "(" + to_string(gracz.level) + ")";
			if (gracz.before_boost_str != 0)
			{
				playerInfo[2] = "Strength Level: " + to_string(gracz.str) + "(" + to_string(gracz.before_boost_str) + ")";
			}
			else if (gracz.before_nerf_str != 0)
			{
				playerInfo[2] = "Strength Level: " + to_string(gracz.str) + "(" + to_string(gracz.before_nerf_str) + ")";
			}
			else
			{
				playerInfo[2] = "Strength Level: " + to_string(gracz.str);
			}
			if (gracz.before_boost_agility != 0)
			{
				playerInfo[3] = "Agility Level: " + to_string(gracz.agility) + "(" + to_string(gracz.before_boost_agility) + ")";
			}
			else if (gracz.before_nerf_agility != 0)
			{
				playerInfo[3] = "Agility Level: " + to_string(gracz.agility) + "(" + to_string(gracz.before_nerf_agility) + ")";
			}
			else
			{
				playerInfo[3] = "Agility Level: " + to_string(gracz.intel);
			}
			if (gracz.before_boost_agility != 0)
			{
				playerInfo[4] = "Inteligence Level: " + to_string(gracz.intel) + "(" + to_string(gracz.before_boost_intel) + ")";
			}
			else if (gracz.before_nerf_agility != 0)
			{
				playerInfo[4] = "Inteligence Level: " + to_string(gracz.intel) + "(" + to_string(gracz.before_nerf_intel) + ")";
			}
			else
			{
				playerInfo[4] = "Inteligence Level: " + to_string(gracz.intel);
			}
			if (gracz.before_boost_charisma != 0)
			{
				playerInfo[5] = "Charisma Level: " + to_string(gracz.charisma) + "(" + to_string(gracz.before_boost_charisma) + ")";
			}
			else if (gracz.before_nerf_charisma != 0)
			{
				playerInfo[5] = "Charisma Level: " + to_string(gracz.charisma) + "(" + to_string(gracz.before_nerf_charisma) + ")";
			}
			else
			{
				playerInfo[5] = "Charisma Level: " + to_string(gracz.charisma);
			}
			if (gracz.before_boost_luck != 0)
			{
				playerInfo[6] = "Luck Level: " + to_string(gracz.luck) + "(" + to_string(gracz.before_boost_luck) + ")";
			}
			else if (gracz.before_nerf_luck != 0)
			{
				playerInfo[6] = "Luck Level: " + to_string(gracz.luck) + "(" + to_string(gracz.before_nerf_luck) + ")";
			}
			else
			{
				playerInfo[6] = "Luck Level: " + to_string(gracz.luck);
			}
			if (gracz.isTheWeaponRare == true)
			{
				playerInfo[7] = "Weapon: [RARE]" + gracz.weaponName + " (" + to_string(gracz.weaponDamage) + ")";
			}
			else
			{
				playerInfo[7] = "Weapon: " + gracz.weaponName + " (" + to_string((int)(0.2 * gracz.str * gracz.agility) + gracz.weaponDamage) + ")";
			}
			playerInfo[8] = "Defence: " + to_string(gracz.helmet + gracz.chestplate + gracz.gloves + gracz.pants + gracz.shoes);
			playerInfo[9] = "";
			playerInfo[10] = "";
			playerInfo[11] = "";
			playerInfo[12] = "";
			playerInfo[13] = "";
			playerInfo[14] = "";
			playerInfo[15] = "";
			playerInfo[16] = "";
			playerInfo[17] = "";
			shortcuts[0] = "Escape";
			shortcuts[1] = "";
			shortcuts[2] = "";
			shortcuts[3] = "";
			shortcuts[4] = "";
			shortcuts[5] = "";
			shortcuts[6] = "";
			shortcuts[7] = "";
			shortcuts[8] = "";
			shortcuts[9] = "";
			shortcuts[10] = "";
			shortcuts[11] = "";
			shortcuts[12] = "";
			shortcuts[13] = "";
			shortcuts[14] = "";
			shortcuts[15] = "";
			shortcuts[16] = "";
			shortcuts[17] = "";
			shortcuts[18] = "";
			shortcuts[19] = "";
			actions[0] = makeString(113, "Hit", gracz.returnChancesOfDealingDamage());
			actions[1] = "";
			actions[2] = "";
			actions[3] = "";
			actions[4] = "";
			actions[5] = "";
			actions[6] = "";
			actions[7] = "";
			actions[8] = "";
			actions[9] = "";
			actions[10] = "";
			actions[11] = "";
			actions[12] = "";
			actions[13] = "";
			actions[14] = "";
			actions[15] = "";
			actions[16] = "";
			actions[17] = "";
			actions[18] = "";
			actions[19] = "";
		}
		tabFight(gracz, enemy, highlight, playerInfo, shortcuts, actions);
		if (highlight == 20)
		{
			dealingDamage(12, 43, gracz, enemy, isItThePlayersTurnNow);
		}
		victoryCondition(12, 43, enemy, gracz, victory, itemName);
		if (victory == false)
		{
			dealingDamage(12, 43, gracz, enemy, isItThePlayersTurnNow);
			victoryCondition(12, 43, enemy, gracz, victory, itemName);
		}
	}
	return gracz;
}