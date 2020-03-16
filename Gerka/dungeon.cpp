#include "dungeon.h"
#include "tabelka.h"
#include "mobki1.h"
#include "inventory.h"
#include "fight_mode.h"
#include "czas.h"


bool loadDungeon(char (&tabOriginal)[32][114], char(&tabCopy)[32][114], int& dungeonLevel, character &hero, vector <monster> &levelMonsters, vector <char>& levelMonstersSymbols, vector <item>& levelItems)
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	string path;
	if (dungeonLevel >= 1)
	{
		if (dungeonLevel == 1)
		{
			path = "./txt/dungeons/lvl1.txt";
		}
		else
		{
			return false;
		}
		plik.open(path, ios::in);
		while (getline(plik, linia))
		{
			for (int i = 0; i < linia.size(); i++)
			{
				tabOriginal[nr_linii - 1][i] = linia[i];
			}
			nr_linii++;
		}
		plik.close();
		nr_linii = 1;
		path = "./txt/dungeons/fullfog.txt";
		plik.open(path, ios::in);
		while (getline(plik, linia))
		{
			for (int i = 0; i < linia.size(); i++)
			{
				tabCopy[nr_linii - 1][i] = linia[i];
			}
			nr_linii++;
		}
		plik.close();
		for (int i = 0; i < sizeof(tabOriginal)/sizeof(tabOriginal[0]); i++)
		{
			for (int j = 0; j < sizeof(tabOriginal[i]); j++)
			{
				if (tabOriginal[i][j] == 'e')
				{
					hero.positionX = j;
					hero.positionY = i + 1;
					tabOriginal[hero.positionY][hero.positionX] = '!';
				}
			}
		}
		loadMonsters(dungeonLevel, tabOriginal, hero, levelMonsters, levelMonstersSymbols);
		loadDecorItems(tabOriginal, dungeonLevel, levelItems);
		return true;
	}
	else
	{
		return false;
	}
}
void loadMonsters(int dungeonLevel, char(&tabOriginal)[32][114], character hero, vector <monster> &levelMonsters, vector <char>& levelMonstersSymbols)
{
	int monstersPerLevel = 0;
	string linia;
	fstream plik;
	int nr_linii = 1;
	string path = "./txt/dungeons/lvl" + to_string(dungeonLevel) + "monsters.txt";
	vector <string> monstersInfo;
	plik.open(path, ios::in);
	while (getline(plik, linia))
	{
		if (nr_linii == 2)
		{
			monstersPerLevel = stoi(linia);
		}
		else if (nr_linii>=3)
		{
			monstersInfo.push_back(linia);
			levelMonstersSymbols.push_back(linia[0]);
		}
		nr_linii++;
	}
	plik.close();
	srand((unsigned int)time(NULL));
	int monsterX = 0;
	int monsterY = 0;
	while (monstersPerLevel > 0)
	{
		do
		{
			monsterY = (rand() % sizeof(tabOriginal) / sizeof(tabOriginal[0])) + 1;
			monsterX = (rand() % sizeof(tabOriginal[0])) + 1;
		} while (tabOriginal[monsterY][monsterX] != ' ' || (!(!(hero.positionX - 6 <= monsterX) || !(hero.positionX + 6 >= monsterX) || !(hero.positionY - 6 <= monsterY) || !(hero.positionY + 6 >= monsterY))));
		int monsterId = rand() % monstersInfo.size();
		monster something;
		something.name = monstersInfo[monsterId];
		something.symbol = something.name[0];
		something.positionX = monsterX;
		something.positionY = monsterY;
		levelMonsters.push_back(something);
		monstersPerLevel--;
	}
	for (int i = 0; i < levelMonsters.size(); i++)
	{
		tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX] = levelMonsters[i].symbol;
	}
}
void loadDecorItems(char(&tabOriginal)[32][114], int dungeonLevel, vector <item> &levelItems)
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	int decorItemsPerLevel = 0;
	string path = "./txt/dungeons/lvl" + to_string(dungeonLevel) + "items.txt";
	vector <string> itemsInfo;
	vector <int> itemsInfoDropRate;
	plik.open(path, ios::in);
	while (getline(plik, linia))
	{
		if (nr_linii == 2)
		{
			decorItemsPerLevel = stoi(linia);
		}
		else if (nr_linii > 2 && nr_linii % 2 == 1)
		{
			itemsInfo.push_back(linia);
		}
		else if (nr_linii > 2 && nr_linii % 2 == 0)
		{
			itemsInfoDropRate.push_back(stoi(linia));
		}
		nr_linii++;
	}
	plik.close();
	//lanterns
	{
		if (tabOriginal[0][0] == ' ')
		{
			tabOriginal[0][0] = 'l';
		}
		if (tabOriginal[0][113] == ' ')
		{
			tabOriginal[0][113] = 'l';
		}
		if (tabOriginal[31][0] == ' ')
		{
			tabOriginal[31][0] = 'l';
		}
		if (tabOriginal[31][113] == ' ')
		{
			tabOriginal[31][113] = 'l';
		}
		for (int i = 0; i < sizeof(tabOriginal) / sizeof(tabOriginal[0]); i++)
		{
			for (int j = 0; j < sizeof(tabOriginal[i]); j++)
			{
				if (tabOriginal[i][j] == '1' && tabOriginal[i + 1][j + 1] == ' ')
				{
					tabOriginal[i + 1][j + 1] = 'l';
				}
				else if (tabOriginal[i][j] == '2' && tabOriginal[i + 1][j - 1] == ' ')
				{
					tabOriginal[i + 1][j - 1] = 'l';
				}
				else if (tabOriginal[i][j] == '3' && tabOriginal[i - 1][j + 1] == ' ')
				{
					tabOriginal[i - 1][j + 1] = 'l';
				}
				else if (tabOriginal[i][j] == '4' && tabOriginal[i - 1][j - 1] == ' ')
				{
					tabOriginal[i - 1][j - 1] = 'l';
				}
				if (tabOriginal[i][j] == '5' && tabOriginal[i - 1][j] == ' ')
				{
					tabOriginal[i - 1][j] = 'l';
				}
				if (tabOriginal[i][j] == '5' && tabOriginal[i + 1][j] == ' ')
				{
					tabOriginal[i + 1][j] = 'l';
				}
				if (tabOriginal[i][j] == '6' && tabOriginal[i - 1][j] == ' ')
				{
					tabOriginal[i - 1][j] = 'l';
				}
				if (tabOriginal[i][j] == '6' && tabOriginal[i + 1][j] == ' ')
				{
					tabOriginal[i + 1][j] = 'l';
				}
				if (tabOriginal[i][j] == '7' && tabOriginal[i][j - 1] == ' ')
				{
					tabOriginal[i][j - 1] = 'l';
				}
				if (tabOriginal[i][j] == '7' && tabOriginal[i][j + 1] == ' ')
				{
					tabOriginal[i][j + 1] = 'l';
				}
				if (tabOriginal[i][j] == '8' && tabOriginal[i][j - 1] == ' ')
				{
					tabOriginal[i][j - 1] = 'l';
				}
				if (tabOriginal[i][j] == '8' && tabOriginal[i][j + 1] == ' ')
				{
					tabOriginal[i][j + 1] = 'l';
				}
			}
		}
	}
	//decorItems
	{
		srand((unsigned int)time(NULL));
		while (decorItemsPerLevel > 0)
		{
			int itemY = 0;
			int itemX = 0;
			do
			{
				itemY = (rand() % 31) + 1;
				itemX = (rand() % 113) + 1;
			} while (tabOriginal[itemY][itemX] != ' ' || (tabOriginal[itemY - 1][itemX] != '-' && tabOriginal[itemY + 1][itemX] != '-' && tabOriginal[itemY][itemX - 1] != '|' && tabOriginal[itemY][itemX + 1] != '|'));
			decorItemsPerLevel--;
			item something;
			something.positionX = itemX;
			something.positionY = itemY;
			levelItems.push_back(something);
			tabOriginal[something.positionY][something.positionX] = something.symbol;
		}
		//applying data to objects
		{
			for (int i = 0; i < levelItems.size(); i++)
			{
				int temp = rand() % itemsInfo.size();
				levelItems[i].itemName = itemsInfo[temp];
				levelItems[i].dropRate = itemsInfoDropRate[temp];
				temp = rand() % 100;
				if (temp< levelItems[i].dropRate)
				{
					levelItems[i].fake = true;
				}
			}
		}
	}
}
int transitionBetweenLevels(int height, int startPoint, int Level, char symbol)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (symbol == 'e')
	{
		if (Level == 1)
		{
			message.push_back("Do you want to leave dungeons ?");
		}
		else
		{
			message.push_back("Do you want to return to a higher level of dungeons");
		}
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			return -1;
		}
	}
	else if (symbol == 'E')
	{
		if (Level == 9)
		{
			message.push_back("Are you ready to face the greatest evil?");
		}
		else
		{
			message.push_back("Do you want to go down to a lower dungeon level?");
		}
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			return 1;
		}
	}
	return 0;
}
void destroyDecorItem(int height, int startPoint, int decorY, int decorX, char(&tabOriginal)[32][114], vector <item>& levelItems)
{
	vector <string> items = { "Crate","Canvas sack", "Barrel"};
	vector <int> dropRate = {50,30,30};
	int itemRand = rand() % items.size();
	vector <string> message = {"Do you want to destroy " + items[itemRand] + "?"};
	vector <string> options = { "Yes","No" };
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	if (highlight == 0)
	{
		for (int i = 0; i < levelItems.size(); i++)
		{
			if (decorX == levelItems[i].positionX && decorY == levelItems[i].positionY)
			{
				
				if (levelItems[i].fake == false)
				{
					levelItems[i].symbol = '?';
					tabOriginal[decorY][decorX] = '?';
				}
				else
				{
					levelItems.erase(levelItems.begin() + i);
					tabOriginal[decorY][decorX] = ' ';
				}
				break;
			}
		}
	}
}
void pickUpItem(int height, int startPoint, int itemY, int itemX, char(&tabOriginal)[32][114], vector <item>& levelItems, player &gracz)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	for (int i = 0; i < levelItems.size(); i++)
	{
		if (itemX == levelItems[i].positionX && itemY == levelItems[i].positionY && levelItems[i].symbol == '?')
		{
			if (levelItems[i].itemName != "" && findItemOnList(levelItems[i].itemName) == "Usable")
			{
				if (gracz.count_free_fields_usage() != 0)
				{
					vector <string> message = { "Do you want to take " + levelItems[i].itemName + "?" };
					int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
					if (highlight == 0)
					{
						gracz.add_usage_item(levelItems[i].itemName, 0, 1, height, startPoint);
						tabOriginal[itemY][itemX] = ' ';
						levelItems.erase(levelItems.begin() + i);
					}
				}
				else
				{
					message.push_back("Your backpack is full");
				}
			}
			else if (levelItems[i].itemName != "" && findItemOnList(levelItems[i].itemName) == "Alchemy")
			{
				if (gracz.count_free_fields_alchemy() != 0)
				{
					vector <string> message = { "Do you want to take " + levelItems[i].itemName + "?" };
					int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
					if (highlight == 0)
					{
						gracz.add_crafting_alchemy_item(levelItems[i].itemName, 0, 1, height, startPoint);
						tabOriginal[itemY][itemX] = ' ';
						levelItems.erase(levelItems.begin() + i);
					}
				}
				else
				{
					message.push_back("Your backpack is full");
				}
			}
			else if (levelItems[i].itemName != "" && findItemOnList(levelItems[i].itemName) == "Smithery")
			{
				if (gracz.count_free_fields_forge() != 0)
				{
					vector <string> message = { "Do you want to take " + levelItems[i].itemName + "?" };
					int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
					if (highlight == 0)
					{
						gracz.add_crafting_forge_item(levelItems[i].itemName, 0, 1, height, startPoint);
						tabOriginal[itemY][itemX] = ' ';
						levelItems.erase(levelItems.begin() + i);
					}
				}
				else
				{
					message.push_back("Your backpack is full");
				}
			}
			else
			{
				message.push_back("Error");
			}
			if (message.size() != 0)
			{
				tabSubmenuTextOnly(height, startPoint, message);
			}
		}
	}
}
void openDoor(int height, int startPoint, int doorY, int doorX, char(&tabOriginal)[32][114], player& gracz)
{
	if (gracz.find_usage_item("Lockpick") == true)
	{
		vector <string> message = {"Do you want to open this door with a lockpick"};
		vector <string> options = {"Yes","No"};
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		if (highlight == 0)
		{
			int test = rand() % 100;
			int playerTestValue = rand() % 100 + gracz.luck + gracz.agility;
			if (playerTestValue > test)
			{
				message.clear();
				message.push_back("You managed to open the door without destroying the lockpick.");
				tabSubmenuTextOnly(height, startPoint, message);
				tabOriginal[doorY][doorX] = ' ';
			}
			else
			{
				message.clear();
				message.push_back("You broke the lockpick while you opened the door, you throw it away.");
				gracz.removeItemWithoutNotification("Lockpick");
				tabSubmenuTextOnly(height, startPoint, message);
			}
		}
	}
	else
	{
		vector <string> message = { "You don't have a lockpick in your inventory" };
		tabSubmenuTextOnly(height, startPoint, message);
	}
}
int movement(int height, int startPoint, int dungeonLevel, player& gracz, char(&tabOriginal)[32][114], int impulse, character &hero, vector <monster>& levelMonsters, vector <item>& levelItems)
{
	int newY = 0;
	int newX = 0;
	char symbol = ' ';
	if (impulse == 28)
	{
		newY = hero.positionY - 1;
		newX = hero.positionX;
		symbol = tabOriginal[newY][newX];
		if (newY >= 0 && symbol == ' ')
		{
			hero.positionY = newY;
			tabOriginal[newY+1][newX] = ' ';
		}
		else if (newY >= 0 && symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, dungeonLevel,symbol);
		}
	}
	if (impulse == 22)
	{
		newY = hero.positionY + 1;
		newX = hero.positionX;
		symbol = tabOriginal[newY][newX];
		if (newY < sizeof(tabOriginal) / sizeof(tabOriginal[0]) && symbol == ' ')
		{
			hero.positionY = newY;
			tabOriginal[newY-1][newX] = ' ';
		}
		else if (newY < sizeof(tabOriginal) / sizeof(tabOriginal[0]) && symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, dungeonLevel, symbol);
		}
	}
	if (impulse == 24)
	{
		newY = hero.positionY;
		newX = hero.positionX - 1;
		symbol = tabOriginal[newY][newX];
		if (newX >= 0 && symbol == ' ')
		{
			hero.positionX = newX;
			tabOriginal[newY][newX+1] = ' ';
		}
		else if (symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, dungeonLevel, symbol);
		}
	}
	if (impulse == 26)
	{
		newY = hero.positionY;
		newX = hero.positionX + 1;
		symbol = tabOriginal[newY][newX];
		if (hero.positionX != 113 && symbol == ' ')
		{
			hero.positionX = newX;
			tabOriginal[newY][newX-1] = ' ';
		}
		else if (symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, dungeonLevel, symbol);
		}
	}
	{
		if (symbol == 'd')
		{
			destroyDecorItem(11, 44, newY, newX, tabOriginal, levelItems);
		}
		else if (symbol == '?')
		{
			pickUpItem(11, 44, newY, newX, tabOriginal, levelItems, gracz);
		}
		else if (symbol == '0')
		{
			openDoor(11, 44, newY, newX, tabOriginal, gracz);
		}
		for (int i = 0; i < levelMonsters.size(); i++)
		{
			if (newY == levelMonsters[i].positionY && newX == levelMonsters[i].positionX)
			{
				bool victory;
				string itemName = "";
				gracz = enterFightMode(gracz, levelMonsters[i].name, true, victory, itemName);
				if (victory == true)
				{
					levelMonsters.erase(levelMonsters.begin() + i);
					if (itemName != "")
					{
					item something;
					something.positionX = newX;
					something.positionY = newY;
					something.symbol = '?';
					something.itemName = itemName;
					something.fake = false;
					something.dropRate = 100;
					levelItems.push_back(something);
					tabOriginal[something.positionY][something.positionX] = something.symbol;
					}
					else
					{
						tabOriginal[newY][newX] = ' ';
					}
				}
			}
		}
	}
	tabOriginal[hero.positionY][hero.positionX] = '!';
	int monsterIndex = moveMonster(height, startPoint, tabOriginal, levelMonsters);
	if (monsterIndex != -1)
	{
		bool victory;
		string itemName = "";
		gracz = enterFightMode(gracz, levelMonsters[monsterIndex].name, false, victory, itemName);
		if (victory == true)
		{
			levelMonsters.erase(levelMonsters.begin() + monsterIndex);
			if (itemName != "")
			{
				item something;
				something.positionX = levelMonsters[monsterIndex].positionX;
				something.positionY = levelMonsters[monsterIndex].positionY;
				something.symbol = '?';
				something.itemName = itemName;
				something.fake = false;
				something.dropRate = 100;
				levelItems.push_back(something);
				tabOriginal[something.positionY][something.positionX] = something.symbol;
			}
			else
			{
				tabOriginal[levelMonsters[monsterIndex].positionY][levelMonsters[monsterIndex].positionX] = ' ';
			}
		}
	}
	for (int i = 0; i < levelItems.size(); i++)
	{
		tabOriginal[levelItems[i].positionY][levelItems[i].positionX] = levelItems[i].symbol;
	}
	for (int i = 0; i < levelMonsters.size(); i++)
	{
		tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX] = levelMonsters[i].symbol;
	}
	return 0;
}
int moveMonster(int height, int startPoint, char tabOriginal[32][114], vector <monster>& levelMonsters)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < levelMonsters.size(); i++)
	{
		int direction = rand() % 5;
		switch (direction)
		{
			case 0:
			{
				//do nothing
				break;
			}
			case 1:
			{
				if (tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX - 1] == '!')
				{
					vector <string> message = {"You has been attacked by " + levelMonsters[i].name + "!"};
					tabSubmenuTextOnly(height, startPoint, message);
					return i;
				}
				else if (tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX - 1] == ' ' && levelMonsters[i].positionX - 1 >= 0)
				{
					levelMonsters[i].positionX--;
					tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX + 1] = ' ';
				}
				break;
			}
			case 2:
			{
				
				if (tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX + 1] == '!')
				{
					vector <string> message = { "You has been attacked by " + levelMonsters[i].name + "!" };
					tabSubmenuTextOnly(height, startPoint, message);
					return i;
				}
				else if (tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX + 1] == ' ' && levelMonsters[i].positionX + 1 <= sizeof(tabOriginal[levelMonsters[i].positionY]))
				{
					levelMonsters[i].positionX++;
					tabOriginal[levelMonsters[i].positionY][levelMonsters[i].positionX - 1] = ' ';
				}
				break;
			}
			case 3:
			{
				if (tabOriginal[levelMonsters[i].positionY - 1][levelMonsters[i].positionX] == '!')
				{
					vector <string> message = { "You has been attacked by " + levelMonsters[i].name + "!" };
					tabSubmenuTextOnly(height, startPoint, message);
					return i;
				}
				else if (tabOriginal[levelMonsters[i].positionY - 1][levelMonsters[i].positionX] == ' ' && levelMonsters[i].positionY - 1 >= 0)
				{
					levelMonsters[i].positionY--;
					tabOriginal[levelMonsters[i].positionY + 1][levelMonsters[i].positionX] = ' ';
				}
				break;
			}
			case 4:
			{
				if (tabOriginal[levelMonsters[i].positionY + 1][levelMonsters[i].positionX] == '!')
				{
					vector <string> message = { "You has been attacked by " + levelMonsters[i].name + "!" };
					tabSubmenuTextOnly(height, startPoint, message);
					return i;
				}
				else if (tabOriginal[levelMonsters[i].positionY + 1][levelMonsters[i].positionX] == ' ' && levelMonsters[i].positionY + 1 <= 31)
				{
					levelMonsters[i].positionY++;
					tabOriginal[levelMonsters[i].positionY - 1][levelMonsters[i].positionX] = ' ';
				}
				break;
			}
		}
	}
	return -1;
}
void fogOfWar(bool fogOfWarEnabled, char tabOriginal [32][114], char(&tabFog)[32][114], character hero)
{
	if (fogOfWarEnabled == true)
	{
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < sizeof(tabFog[i]); j++)
			{
				if (!(!(hero.positionX - 5 <= j) || !(hero.positionX + 5 >= j) || !(hero.positionY - 3 <= i) || !(hero.positionY + 3 >= i)))
				{
					tabFog[i][j] = tabOriginal[i][j];
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < sizeof(tabFog[i]); j++)
			{
				tabFog[i][j] = tabOriginal[i][j];
			}
		}
	}
}
player enterDungeon(player gracz)
{
	char tabOriginal[32][114];
	char tabFog[32][114];
	string info[20];
	vector <item> levelItems;
	vector <monster> levelMonsters;
	vector <char> levelMonsterSymbols;
	character hero;
	bool mode = false;
	int highlight = 0;
	int dungeonLevel = 1;
	bool fogOfWarEnabled = false;
	info[0] = "Return to the game";
	info[1] = "Equipment & Stats";
	info[2] = "Skills";
	info[3] = "Quests";
	info[4] = "Wait";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	info[8] = "";
	info[9] = "";
	info[10] = "";
	info[11] = "";
	info[12] = "";
	info[13] = "";
	info[14] = "";
	info[15] = "";
	info[16] = "";
	info[17] = "";
	info[18] = "";
	info[19] = "";
	bool levelLoaded = loadDungeon(tabOriginal, tabFog, dungeonLevel, hero, levelMonsters, levelMonsterSymbols, levelItems);
	if (levelLoaded == false)
	{
		return gracz;
	}
	fogOfWar(fogOfWarEnabled, tabOriginal, tabFog, hero);
	highlight = tabDungeon(gracz, mode, "Level " + to_string(dungeonLevel), info, tabFog, levelMonsterSymbols);
	while (1)
	{
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		if (mode == true && highlight == 0)
		{
			mode = false;
		}
		else if (mode == true && highlight == 1)
		{
			gracz = enter_inventory(gracz);
		}
		else if (mode == true && highlight == 4)
		{
			wait_n_hours(23, 32, gracz);
		}
		int result = movement(11, 44, 1, gracz, tabOriginal, highlight, hero, levelMonsters, levelItems);
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		if (result == -1)
		{
			if (dungeonLevel == 1)
			{
				return gracz;
			}
			else
			{
				levelItems.clear();
				levelMonsters.clear();
				levelMonsterSymbols.clear();
				dungeonLevel -= 1;
			}
		}
		else if (result == 1)
		{
			levelItems.clear();
			levelMonsters.clear();
			levelMonsterSymbols.clear();
			dungeonLevel += 1;
		}
		fogOfWar(fogOfWarEnabled, tabOriginal, tabFog, hero);
		highlight = tabDungeon(gracz, mode, "Level " + to_string(dungeonLevel), info, tabFog, levelMonsterSymbols);
	}
}