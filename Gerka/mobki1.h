#pragma once
#include "biblioteki.h"
#include "player.h"

class Mob
{
public:
	int HP;
	int maxHP;
	int damage;
	int defence;
	int XP;
	string skill;
	string mobName;
	string droppedItem;
	bool thisMonsterAreAbleToDropItem;
	int dropRateForItem;
	int baseDroppedGold;
	int additionalDroppedGold;
	string fightInfo[18];
	void isThisMobCanDropTheItem();
	void loadData(string path);
	int returnDroppedGold();
	Mob(string path)
	{
		for (int i = 0; i < 18; i++)
		{
			this->fightInfo[i] = "";
		}
		loadData(path);
		isThisMobCanDropTheItem();
	}
};