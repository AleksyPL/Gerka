#pragma once
#include "player.h"

bool loadDungeon(player gracz, char(&tabOriginal)[32][114], char(&tabCopy)[32][114], int& playerX, int& playerY, int &dungeonLevel, int &decorsPerLevel, int &monstersPerLevel);
void loadMonsters(int dungeonLevel, char(&tabOriginal)[32][114], int monstersPerLevel);
void loadDecorItems(char(&tabOriginal)[32][114], int decorItemsPerLevel);
void destroyDecorItem(int height, int startPoint, string item, int droprate1_100, int decorY, int decorX, char(&tabOriginal)[32][114]);
int transitionBetweenLevels(int height, int startPoint, int Level, char symbol);
void fogOfWar(bool fogOfWarEnabled, char tabOriginal[32][114], char(&tabFog)[32][114]);
int movement(int height, int startPoint, int dungeonLevel, player& gracz, char(&tabOriginal)[32][114], int impulse, int& playerX, int& playerY);
player enterDungeon(player gracz);