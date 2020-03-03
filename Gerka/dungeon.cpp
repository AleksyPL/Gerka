#include "dungeon.h"
#include "tabelka.h"
#include "mobki1.h"


bool loadDungeon(player gracz, char (&tabOriginal)[32][114], char(&tabCopy)[32][114], int &playerX, int &playerY, int &dungeonLevel, int &decorsPerLevel, int &monstersPerLevel)
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
			if (nr_linii < 33)
			{
				for (int i = 0; i < linia.size(); i++)
				{
					tabOriginal[nr_linii - 1][i] = linia[i];
				}
			}
			else
			{
				if (nr_linii == 34)
				{
					decorsPerLevel = stoi(linia);
				}
				if (nr_linii == 36)
				{
					monstersPerLevel = stoi(linia);
				}
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
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < sizeof(tabOriginal[i]); j++)
			{
				if (tabOriginal[i][j] == 'e')
				{
					playerX = j;
					playerY = i+1;
					tabOriginal[playerY][playerX] = '!';
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
void loadMonsters(int dungeonLevel, char(&tabOriginal)[32][114], int monstersPerLevel)
{
	int playerX = 0;
	int playerY = 0;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < sizeof(tabOriginal[i]); j++)
		{
			if (tabOriginal[i][j] == '!')
			{
				playerY = i;
				playerX = j;
			}
		}
	}
	srand((unsigned int)time(NULL));
	int monsterX = 0;
	int monsterY = 0;
	while (monstersPerLevel > 0)
	{
		do
		{
			monsterY = (rand() % 31) + 1;
			monsterX = (rand() % 114) + 1;
		} while (tabOriginal[monsterY][monsterX] != ' ' || (!(!(playerX - 6 <= monsterX) || !(playerX + 6 >= monsterX) || !(playerY - 6 <= monsterY) || !(playerY + 6 >= monsterY))));
		tabOriginal[monsterY][monsterX] = 'B';
		monstersPerLevel--;
	}
}
void loadDecorItems(char(&tabOriginal)[32][114], int decorItemsPerLevel)
{
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
		for (int i = 0; i < 32; i++)
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
			tabOriginal[itemY][itemX] = 'd';
			decorItemsPerLevel--;
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
		return highlight;
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
		return highlight;
	}
	return 1;
}
void destroyDecorItem(int height, int startPoint, string item, int droprate1_100, int decorY, int decorX, char(&tabOriginal)[32][114])
{
	vector <string> message = {"Do you want to destroy " + item + "?"};
	vector <string> options = { "Yes","No" };
	int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
	if (highlight == 0)
	{
		int drop = rand() % 100;
		if (drop < droprate1_100)
		{
			tabOriginal[decorY][decorX] = '?';
		}
		else
		{
			tabOriginal[decorY][decorX] = ' ';
		}
	}
}
int movement(int height, int startPoint, int dungeonLevel, player& gracz, char(&tabOriginal)[32][114], int impulse, int& playerX, int& playerY)
{
	if (impulse == 28)
	{
		if (playerY != 0 && tabOriginal[playerY - 1][playerX]==' ')
		{
			playerY -= 1;
			tabOriginal[playerY+1][playerX] = ' ';
		}
		else if (playerY != 0 && tabOriginal[playerY - 1][playerX] == 'e')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel,'e');
			if (highlight == 0)
			{
				return -1;
			}
		}
		else if (playerY != 0 && tabOriginal[playerY - 1][playerX] == 'E')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'E');
			if (highlight == 0)
			{
				return 1;
			}
		}
		else if (playerY != 0 && tabOriginal[playerY - 1][playerX] == 'd')
		{
			int item = rand() & 3;
			if (item == 0)
			{
				destroyDecorItem(11, 44, "Crate", 50, playerY - 1, playerX, tabOriginal);
			}
			else if (item == 1)
			{
				destroyDecorItem(11, 44, "Canvas sack", 30, playerY - 1, playerX, tabOriginal);
			}
			else
			{
				destroyDecorItem(11, 44, "barrel", 30, playerY - 1, playerX, tabOriginal);
			}
		}
		else if (playerY != 0 && tabOriginal[playerY - 1][playerX] == '?')
		{
			if (dungeonLevel == 1)
			{

			}
		}
	}
	if (impulse == 22)
	{
		if (playerY != 32 && tabOriginal[playerY +1][playerX] == ' ')
		{
			playerY += 1;
			tabOriginal[playerY - 1][playerX] = ' ';
		}
		else if (playerY != 32 && tabOriginal[playerY + 1][playerX] == 'e')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'e');
			if (highlight == 0)
			{
				return -1;
			}
		}
		else if (playerY != 32 && tabOriginal[playerY + 1][playerX] == 'E')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'E');
			if (highlight == 0)
			{
				return 1;
			}
		}
		else if (playerY != 0 && tabOriginal[playerY + 1][playerX] == 'd')
		{
			int item = rand() & 3;
			if (item == 0)
			{
				destroyDecorItem(11, 44, "Crate", 50, playerY + 1, playerX, tabOriginal);
			}
			else if (item == 1)
			{
				destroyDecorItem(11, 44, "Canvas sack", 30, playerY + 1, playerX, tabOriginal);
			}
			else
			{
				destroyDecorItem(11, 44, "barrel", 30, playerY + 1, playerX, tabOriginal);
			}
		}
	}
	if (impulse == 24)
	{
		if (playerX != 0 && tabOriginal[playerY][playerX-1] == ' ')
		{
			playerX -= 1;
			tabOriginal[playerY][playerX + 1] = ' ';
		}
		else if (tabOriginal[playerY][playerX - 1] == 'e')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'e');
			if (highlight == 0)
			{
				return -1;
			}
		}
		else if (tabOriginal[playerY][playerX - 1] == 'E')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'E');
			if (highlight == 0)
			{
				return 1;
			}
		}
		else if (tabOriginal[playerY][playerX - 1] == 'd')
		{
			int item = rand() & 3;
			if (item == 0)
			{
				destroyDecorItem(11, 44, "Crate", 50, playerY, playerX - 1, tabOriginal);
			}
			else if (item == 1)
			{
				destroyDecorItem(11, 44, "Canvas sack", 30, playerY, playerX - 1, tabOriginal);
			}
			else
			{
				destroyDecorItem(11, 44, "barrel", 30, playerY, playerX - 1, tabOriginal);
			}
		}
	}
	if (impulse == 26)
	{
		if (playerX != 113 && tabOriginal[playerY][playerX + 1] == ' ')
		{
			playerX += 1;
			tabOriginal[playerY][playerX - 1] = ' ';
		}
		else if (tabOriginal[playerY][playerX + 1] == 'e')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'e');
			if (highlight == 0)
			{
				return -1;
			}
		}
		else if (tabOriginal[playerY][playerX + 1] == 'E')
		{
			int highlight = transitionBetweenLevels(height, startPoint, dungeonLevel, 'E');
			if (highlight == 0)
			{
				return 1;
			}
		}
		else if (tabOriginal[playerY][playerX + 1] == 'd')
		{
			int item = rand() & 3;
			if (item == 0)
			{
				destroyDecorItem(11, 44, "Crate", 50, playerY, playerX + 1, tabOriginal);
			}
			else if (item == 1)
			{
				destroyDecorItem(11, 44, "Canvas sack", 30, playerY, playerX + 1, tabOriginal);
			}
			else
			{
				destroyDecorItem(11, 44, "barrel", 30, playerY, playerX + 1, tabOriginal);
			}
		}
	}
	tabOriginal[playerY][playerX] = '!';
	return 0;
}
void fogOfWar(bool fogOfWarEnabled, char tabOriginal [32][114], char(&tabFog)[32][114])
{
	if (fogOfWarEnabled == true)
	{
		int playerX = 0;
		int playerY = 0;
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < sizeof(tabOriginal[i]) - 1; j++)
			{
				if (tabOriginal[i][j] == '!')
				{
					playerY = i;
					playerX = j;
				}
			}
		}
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < sizeof(tabFog[i]); j++)
			{
				if (!(!(playerX - 5 <= j) || !(playerX + 5 >= j) || !(playerY - 3 <= i) || !(playerY + 3 >= i)))
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
	int playerX = 0;
	int playerY = 0;
	int mode = 0;
	int highlight = 0;
	int dungeonLevel = 1;
	int decorsPerLevel = 0;
	int monstersPerLevel = 0;
	bool fogOfWarEnabled = false;
	info[0] = "Close game";
	info[1] = "Save game";
	info[2] = "Equipment & Stats";
	info[3] = "Skills";
	info[4] = "Quests";
	info[5] = "Crafting";
	info[6] = "Wait";
	info[7] = "Test";
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
	bool levelLoaded = loadDungeon(gracz, tabOriginal, tabFog, playerX, playerY, dungeonLevel, decorsPerLevel, monstersPerLevel);
	loadMonsters(dungeonLevel,tabOriginal, monstersPerLevel);
	loadDecorItems(tabOriginal, decorsPerLevel);
	if (levelLoaded == false)
	{
		return gracz;
	}
	fogOfWar(fogOfWarEnabled, tabOriginal, tabFog);
	highlight = tabDungeon(gracz, mode, "Level " + to_string(dungeonLevel), info, tabFog);
	while (1)
	{
		int result = movement(11, 44, 1, gracz, tabOriginal, highlight, playerX, playerY);
		if (result == -1)
		{
			if (dungeonLevel == 1)
			{
				return gracz;
			}
			else
			{
				dungeonLevel -= 1;
			}
		}
		else if (result == 1)
		{

		}
		fogOfWar(fogOfWarEnabled, tabOriginal, tabFog);
		highlight = tabDungeon(gracz, mode, "Level " + to_string(dungeonLevel), info, tabFog);
	}
}