#pragma once
//#include "biblioteki.h"
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
	int baseDealingDamageRate;
	int additionalDealingDamageRate;
	int baseGettingHitRate;
	int additionalGettingHitRate;
	string fightInfo[18];
	bool stunned;
	bool bleeding;
	bool bonesCrushed;
	void isThisMobCanDropTheItem();
	void loadData(string path);
	void updateFightInfo();
	int returnDroppedGold();
	int returnDealingDamageRate();
	int returnGettingHitRate();
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