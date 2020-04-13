#include "dungeon.h"
#include "playerTransport.h"
#include "tabelka.h"
#include "mobki1.h"
#include "inventory.h"
#include "fight_mode.h"
#include "czas.h"
#include "items.h"

dungeonSupervisior::dungeonSupervisior(player gracz)
{
	dungeonLevel = 1;
	this->playerName = gracz.nazwa;
	string playerName = stringToLower(gracz.nazwa);
	loadVistedData();
}
void dungeonSupervisior::loadVistedData()
{
	for (int i = 0; i < 10; i++)
	{
		string levelName = "./txt/dungeons/lvl" + to_string(i + 1) + "_" + playerName + ".txt";
		if (fileExist(levelName) == true)
		{
			this->dungeonVisited[i] = true;
		}
		else
		{
			this->dungeonVisited[i] = false;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (this->dungeonVisited[i] == false)
		{
			clearVisitedData(i);
			break;
		}
	}
}
void dungeonSupervisior::clearVisitedData(int counterStarter)
{
	for (int i = counterStarter; i < 10; i++)
	{
		this->dungeonVisited[i] = false;
		string levelName = "./txt/dungeons/lvl" + to_string(i + 1) + "_" + playerName + ".txt";
		remove(levelName.c_str());
		this->dungeonVisited[i] = false;
	}
}
bool dungeonSupervisior::loadDungeon(character& hero)
{
	string linia;
	fstream plik;
	int nr_linii = 1;
	string path;
	if (dungeonVisited[dungeonLevel] == true)
	{
		path = "./txt/dungeons/lvl" + to_string(dungeonLevel) + "_" + playerName + ".txt";
	}
	else
	{
		path = "./txt/dungeons/lvl" + to_string(dungeonLevel) + ".txt";
	}
	if (dungeonLevel >= 1)
	{
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
				tabFog[nr_linii - 1][i] = linia[i];
			}
			nr_linii++;
		}
		plik.close();
		for (int i = 0; i < sizeof(tabOriginal) / sizeof(tabOriginal[0]); i++)
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
		loadDecorItems();
		loadMonsters(dungeonLevel, hero);
		return true;
	}
	else
	{
		return false;
	}
}
void dungeonSupervisior::loadMonsters(int dungeonLevel, character hero)
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
		else if (nr_linii >= 3)
		{
			monstersInfo.push_back(linia);
			levelMonsterSymbols.push_back(linia[0]);
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
void dungeonSupervisior::loadDecorItems()
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
				int lanternEnabled = rand() % 2;
				if (lanternEnabled == 0)
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
				if (temp < levelItems[i].dropRate)
				{
					levelItems[i].fake = true;
				}
			}
		}
	}
}
int dungeonSupervisior::transitionBetweenLevels(int height, int startPoint, char symbol)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	if (symbol == 'e')
	{
		if (dungeonLevel == 1)
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
		if (dungeonLevel == 9)
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
void dungeonSupervisior::destroyDecorItem(int height, int startPoint, int decorY, int decorX)
{
	vector <string> items = { "Crate","Canvas sack", "Barrel" };
	vector <int> dropRate = { 50,30,30 };
	int itemRand = rand() % items.size();
	vector <string> message = { "Do you want to destroy " + items[itemRand] + "?" };
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
void dungeonSupervisior::pickUpItem(int height, int startPoint, int itemY, int itemX, player& gracz)
{
	vector <string> message;
	vector <string> options = { "Yes","No" };
	for (int i = 0; i < levelItems.size(); i++)
	{
		if (itemX == levelItems[i].positionX && itemY == levelItems[i].positionY && levelItems[i].symbol == '?')
		{
			/*if (levelItems[i].itemName != "" && findItemOnList(levelItems[i].itemName) == "Usable")
			{
				if (gracz.countFreeFieldsUsage() != 0)
				{
					vector <string> message = { "Do you want to take " + levelItems[i].itemName + "?" };
					int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
					if (highlight == 0)
					{
						gracz.addUsageItem(levelItems[i].itemName, 0, 1, height, startPoint);
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
				if (gracz.countFreeFieldsAlchemy() != 0)
				{
					vector <string> message = { "Do you want to take " + levelItems[i].itemName + "?" };
					int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
					if (highlight == 0)
					{
						gracz.addCraftingAlchemyItem(levelItems[i].itemName, 0, 1, height, startPoint);
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
				if (gracz.countFreeFieldsSmithery() != 0)
				{
					vector <string> message = { "Do you want to take " + levelItems[i].itemName + "?" };
					int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
					if (highlight == 0)
					{
						gracz.addCraftingSmitheryItem(levelItems[i].itemName, 0, 1, height, startPoint);
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
			}*/
			if (gracz.pickUpItemWithNotificationMenu(levelItems[i].itemName, 1, height, startPoint) == true)
			{
				tabOriginal[itemY][itemX] = ' ';
				levelItems.erase(levelItems.begin() + i);
			}
		}
	}
}
void dungeonSupervisior::openDoor(int height, int startPoint, int doorY, int doorX, player& gracz)
{
	if (useItem(height, startPoint, "Lockpick", 0, gracz) == true)
	{
		tabOriginal[doorY][doorX] = ' ';
	}
}
int dungeonSupervisior::movement(int height, int startPoint, player& gracz, int impulse, character& hero)
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
			tabOriginal[newY + 1][newX] = ' ';
		}
		else if (newY >= 0 && symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, symbol);
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
			tabOriginal[newY - 1][newX] = ' ';
		}
		else if (newY < sizeof(tabOriginal) / sizeof(tabOriginal[0]) && symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, symbol);
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
			tabOriginal[newY][newX + 1] = ' ';
		}
		else if (symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, symbol);
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
			tabOriginal[newY][newX - 1] = ' ';
		}
		else if (symbol == 'e' || symbol == 'E')
		{
			return transitionBetweenLevels(height, startPoint, symbol);
		}
	}
	{
		if (symbol == 'd')
		{
			destroyDecorItem(11, 44, newY, newX);
		}
		else if (symbol == '?')
		{
			pickUpItem(11, 44, newY, newX, gracz);
		}
		else if (symbol == '0')
		{
			openDoor(11, 44, newY, newX, gracz);
		}
		for (int i = 0; i < levelMonsters.size(); i++)
		{
			if (newY == levelMonsters[i].positionY && newX == levelMonsters[i].positionX)
			{
				bool victory;
				string itemName = "";
				enterFightMode(gracz, levelMonsters[i].name, true, victory, itemName);
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
	int monsterIndex = moveMonster(height, startPoint);
	if (monsterIndex != -1)
	{
		bool victory;
		string itemName = "";
		enterFightMode(gracz, levelMonsters[monsterIndex].name, false, victory, itemName);
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
int dungeonSupervisior::moveMonster(int height, int startPoint)
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
				vector <string> message = { "You has been attacked by " + levelMonsters[i].name + "!" };
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
void dungeonSupervisior::fogOfWar(bool fogOfWarEnabled, character hero)
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
extern "C" DLLFUNCEX void enterDungeon()
{
	player gracz;
	loadPlayerTemp(gracz);
	string info[20];
	dungeonSupervisior dungeonMaster(gracz);
	character hero;
	bool menuMode = false;
	int highlight = 0;
	bool fogOfWarEnabled = false;
	bool exit = false;
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
	bool levelLoaded = dungeonMaster.loadDungeon(hero);
	if (levelLoaded == false)
	{
		exit = true;
		savePlayerTemp(gracz);
	}
	if (exit == false)
	{
		dungeonMaster.fogOfWar(fogOfWarEnabled, hero);
		highlight = tabDungeon(gracz, menuMode, "Level " + to_string(dungeonMaster.dungeonLevel), info, dungeonMaster.tabFog, dungeonMaster.levelMonsterSymbols);
		while (exit == false)
		{
			if (gracz.hp <= 0)
			{
				exit = true;
				savePlayerTemp(gracz);
			}
			if (menuMode == true && highlight == 0)
			{
				menuMode = false;
			}
			else if (menuMode == true && highlight == 1)
			{
				enterInventory(gracz);
			}
			else if (menuMode == true && highlight == 4)
			{
				waitNHours(23, 32, gracz);
			}
			int result = dungeonMaster.movement(11, 44, gracz, highlight, hero);
			if (gracz.hp <= 0)
			{
				exit = true;
				savePlayerTemp(gracz);
			}
			if (result == -1)
			{
				if (dungeonMaster.dungeonLevel == 1)
				{
					exit = true;
					savePlayerTemp(gracz);
				}
				else
				{
					dungeonMaster.levelItems.clear();
					dungeonMaster.levelMonsters.clear();
					dungeonMaster.levelMonsterSymbols.clear();
					dungeonMaster.dungeonLevel -= 1;
					dungeonMaster.loadDungeon(hero);
				}
			}
			else if (result == 1)
			{
				dungeonMaster.levelItems.clear();
				dungeonMaster.levelMonsters.clear();
				dungeonMaster.levelMonsterSymbols.clear();
				dungeonMaster.dungeonLevel += 1;
				dungeonMaster.loadDungeon(hero);
			}
			if (exit == false)
			{
				dungeonMaster.fogOfWar(fogOfWarEnabled, hero);
				highlight = tabDungeon(gracz, menuMode, "Level " + to_string(dungeonMaster.dungeonLevel), info, dungeonMaster.tabFog, dungeonMaster.levelMonsterSymbols);
			}
		}
	}
}