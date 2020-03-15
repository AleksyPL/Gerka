#pragma once
#include "player.h"

class character
{
public:
	char symbol;
	int positionX;
	int positionY;
	character()
	{
		symbol = '!';
		positionX = 0;
		positionY = 0;
	}
};

class item
{
public:
	int positionX;
	int positionY;
	string itemName;
	char symbol;
	int dropRate;
	bool fake;
	item()
	{
		positionX = 0;
		positionY = 0;
		itemName = "";
		symbol = 'd';
		dropRate = 0;
		fake = false;
	}
	bool changeSymbol(int playerRandom)
	{
		if (playerRandom > dropRate)
		{
			this->symbol = '?';
			return true;
		}
		else
		{
			return false;
		}
	}
};

class monster
{
public:
	char symbol;
	string name;
	int positionX;
	int positionY;
	monster()
	{
		symbol = ' ';
		name = "";
		positionX = 0;
		positionY = 0;
	}
};

bool loadDungeon(char(&tabOriginal)[32][114], char(&tabCopy)[32][114], int& dungeonLevel, character& hero, vector <monster>& levelMonsters, vector <char>& levelMonstersSymbols, vector <item>& levelItems);
void loadMonsters(int dungeonLevel, char(&tabOriginal)[32][114], character hero, vector <monster>& levelMonsters, vector <char>& levelMonstersSymbols);
void loadDecorItems(char(&tabOriginal)[32][114], int dungeonLevel, vector <item>& levelItems);
void destroyDecorItem(int height, int startPoint, int decorY, int decorX, char(&tabOriginal)[32][114], vector <item>& levelItems);
int transitionBetweenLevels(int height, int startPoint, int Level, char symbol);
void pickUpItem(int height, int startPoint, int itemY, int itemX, char(&tabOriginal)[32][114], vector <item>& levelItems, player& gracz);
void openDoor(int height, int startPoint, int doorY, int doorX, char(&tabOriginal)[32][114], player& gracz);
void fogOfWar(bool fogOfWarEnabled, char tabOriginal[32][114], char(&tabFog)[32][114], character hero);
int moveMonster(int height, int startPoint, char tabOriginal[32][114], vector <monster>& levelMonsters);
int movement(int height, int startPoint, int dungeonLevel, player& gracz, char(&tabOriginal)[32][114], int impulse, character& hero, vector <monster>& levelMonsters, vector <item>& levelItems);
player enterDungeon(player gracz);